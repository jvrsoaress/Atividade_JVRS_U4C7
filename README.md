<img width=100% src="https://capsule-render.vercel.app/api?type=waving&color=02A6F4&height=120&section=header"/>
<h1 align="center">Embarcatech Atividade - U4C7 </h1>

## Objetivo do Projeto

Este projeto tem como objetivo aplicar os conceitos de modulação por largura de pulso (PWM) no microcontrolador RP2040, utilizando a ferramenta Pico SDK. Será desenvolvido um sistema para simular o controle de um servomotor, ajustando o seu ângulo de rotação. A simulação será realizada no simulador de eletrônica online Wokwi, utilizando um motor micro servo padrão. O projeto incluirá o controle preciso do ângulo do servomotor por meio do ajuste da largura do pulso PWM, proporcionando uma forma eficiente de controle de posição com base na sinalização digital.

## 🗒️ Lista de requisitos

- Considerando a GPIO 22, defina a sua frequência de PWM para, aproximadamente, 50Hz – período de 20ms.
- Defina o ciclo ativo do módulo PWM para 2.400µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,12%. Isto ajustará a flange (braço) do servomotor para a posição de, aproximadamente, 180 graus. Aguarde 05 segundos nesta posição.
- Defina o ciclo ativo do módulo PWM para 1.470µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,0735%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 90 graus. Aguarde 05 segundos nesta posição. 
- Defina o ciclo ativo do módulo PWM para 500µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,025%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 0 graus. Aguarde 05 segundos nesta posição.
- Após a realização das proposições anteriores, crie uma rotina para movimentação periódica do braço do servomotor entre os ângulos de 0 e 180 graus.  Obs.: a movimentação da flange deve ser suave, recomenda-se o incremento de ciclo ativo de ±5µs, com um atraso de ajuste de 10ms.
- Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIO 12. O que o discente observou no comportamento da iluminação do referido LED?

## 🛠 Tecnologias

- **Microcontrolador:** Raspberry Pi Pico W – Wokwi 
- **Servomotor** – Motor micro servo padrão – Wokwi
- **Linguagem de Programação:** C  
- **Frameworks:** Pico SDK


## 🔧 Funcionalidades Implementadas:

1. Frequência de PWM configurada para 50Hz (período de 20ms) na GPIO 22.
2. Posição do servomotor ajustada para 180° com ciclo ativo de 2.400µs, aguardando 5 segundos.
3. Posição do servomotor ajustada para 90° com ciclo ativo de 1.470µs, aguardando 5 segundos.
4. Posição do servomotor ajustada para 0° com ciclo ativo de 500µs, aguardando 5 segundos.
5. Rotina de movimentação periódica implementada entre 0° e 180°, com ajustes suaves de ±5µs e atraso de 10ms.

## 🚀 Passos para Compilação e Upload  

1. **Clonar o repositório** 

- sh
- git clone seu repositorio
- cd semaforo-pico


2. **Configurar e compilar o projeto**  

`mkdir build && cd build`
`cmake ..`
`make`

3. **Transferir o firmware para a placa**

- Conectar a placa BitDogLab ao computador
- Copiar o arquivo .uf2 gerado para o drive da placa

4. **Testar o projeto**

🛠🔧🛠🔧🛠🔧


## 🎥 Demonstração: 

- Para ver o funcionamento do projeto, acesse o vídeo de demonstração gravado por José Vinicius em: 

## 💻 Desenvolvedor
 
<table>
  <tr>
    <td align="center"><img style="" src="https://avatars.githubusercontent.com/u/191687774?v=4" width="100px;" alt=""/><br /><sub><b> José Vinicius </b></sub></a><br />👨‍💻</a></td>
  </tr>
</table>
