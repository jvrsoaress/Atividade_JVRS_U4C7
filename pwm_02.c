#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definições do pino e parâmetros do PWM
#define PWM_PIN         22            // GPIO utilizado para PWM (servo)
#define PWM_FREQ_HZ     50            // Frequência de 50Hz (período de 20ms)
#define PWM_PERIOD_US   20000         // Período do PWM em microsegundos (20ms)

// Configurando para que 1 tick = 1µs:
// Clock do RP2040: 125MHz, logo divisor = 125 -> 125e6 / 125 = 1e6 ticks/segundo
#define PWM_CLK_DIV     125.0f        
#define PWM_WRAP        (PWM_PERIOD_US - 1)   // Valor de wrap: 20000 - 1 = 19999

// Definições dos pulsos (em microsegundos) para as posições do servo:
// Conforme a atividade, mapeamos:
// - 2400 µs para 180° (posição máxima)
// - 1470 µs para 90° (posição intermediária)
// - 500 µs para 0° (posição mínima)
#define SERVO_PULSE_180   2400
#define SERVO_PULSE_90    1470
#define SERVO_PULSE_0     500

// Parâmetros para a movimentação suave:
#define STEP_US           5         // Incremento/decremento de 5µs
#define STEP_DELAY_MS     10        // Atraso de 10ms entre os passos

int main() {
    // Inicializa as funções padrão (USB, UART, etc)
    stdio_init_all();

    // Configuração do pino de PWM
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);

    // Configura o clock divider e o wrap para que cada tick corresponda a 1µs
    pwm_set_clkdiv(slice_num, PWM_CLK_DIV);
    pwm_set_wrap(slice_num, PWM_WRAP);

    // Habilita o PWM no slice correspondente
    pwm_set_enabled(slice_num, true);

    // =========================================================================
    // 1) Configuração inicial para simular o controle do ângulo do servomotor
    // =========================================================================
    printf("Posicionando o servo em 180 graus (pulsos de %d µs)...\n", SERVO_PULSE_180);
    pwm_set_gpio_level(PWM_PIN, SERVO_PULSE_180);
    sleep_ms(5000);  // Aguarda 5 segundos

    printf("Posicionando o servo em 90 graus (pulsos de %d µs)...\n", SERVO_PULSE_90);
    pwm_set_gpio_level(PWM_PIN, SERVO_PULSE_90);
    sleep_ms(5000);  // Aguarda 5 segundos

    printf("Posicionando o servo em 0 graus (pulsos de %d µs)...\n", SERVO_PULSE_0);
    pwm_set_gpio_level(PWM_PIN, SERVO_PULSE_0);
    sleep_ms(5000);  // Aguarda 5 segundos

    // =========================================================================
    // 2) Rotina para movimentação periódica suave do servo entre 0 e 180 graus
    // =========================================================================
    // Inicia a movimentação a partir da posição 0° (pulso mínimo)
    uint16_t pulse_width = SERVO_PULSE_0;
    bool aumentando = true;  // Indica se estamos incrementando (subindo) o pulso

    while (true) {
        // Atualiza o nível do PWM (pulso) para o servo
        pwm_set_gpio_level(PWM_PIN, pulse_width);

        // Para fins de debug, imprime o valor atual do pulso
        printf("Pulso atual: %d µs\n", pulse_width);

        // Aguarda 10ms entre os ajustes
        sleep_ms(STEP_DELAY_MS);

        // Verifica se incrementa ou decrementa o pulso para mover o servo suavemente
        if (aumentando) {
            if (pulse_width + STEP_US <= SERVO_PULSE_180) {
                pulse_width += STEP_US;
            } else {
                pulse_width = SERVO_PULSE_180;
                aumentando = false;  // Inverte a direção: agora passará a diminuir
            }
        } else {  // Diminuindo o pulso
            if (pulse_width >= SERVO_PULSE_0 + STEP_US) {
                pulse_width -= STEP_US;
            } else {
                pulse_width = SERVO_PULSE_0;
                aumentando = true;  // Inverte a direção: agora passará a aumentar
            }
        }
    }

    return 0;
}
