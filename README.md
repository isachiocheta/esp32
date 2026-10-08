# ESP32 — Teste inicial com LED

## Sobre o projeto

Este projeto básico foi desenvolvido como um primeiro contato com o ESP32, o framework Arduino e a extensão PlatformIO IDE no Visual Studio Code.

A implementação realiza um teste simples de saída digital: um LED conectado ao GPIO 2 é ligado e desligado continuamente, com intervalos de um segundo. O objetivo foi verificar a configuração do ambiente, a compilação do programa e o envio do código para a placa.

## Funcionalidade

Após o ESP32 ser ligado ou reiniciado, o programa:

1. Configura o GPIO 2 como saída digital.
2. Define o pino como nível lógico alto, acendendo o LED.
3. Aguarda um segundo.
4. Define o pino como nível lógico baixo, apagando o LED.
5. Aguarda mais um segundo e repete o ciclo.

O resultado é um LED que permanece um segundo aceso e um segundo apagado.

> O GPIO do LED interno pode variar conforme o modelo da placa. Neste projeto foi utilizado o GPIO 2, conforme a configuração adotada para o teste.

## Código principal

O programa está localizado em `src/main.cpp`:

```cpp
#include <Arduino.h>

#define pino_led 2

void setup() {
    pinMode(pino_led, OUTPUT);
}

void loop() {
    digitalWrite(pino_led, HIGH);
    delay(1000);

    digitalWrite(pino_led, LOW);
    delay(1000);
}
```

### Organização do programa

- `#include <Arduino.h>` disponibiliza as funções do framework Arduino utilizadas no código.
- `pino_led` representa o GPIO 2, usado para controlar o LED.
- `setup()` configura o pino uma única vez, quando a placa inicia.
- `pinMode(pino_led, OUTPUT)` define o pino como saída.
- `loop()` executa repetidamente a sequência de acionamento.
- `digitalWrite()` altera o estado lógico do pino.
- `delay(1000)` mantém cada estado por 1.000 milissegundos, ou um segundo.

## Tecnologias e ferramentas

- **Placa:** ESP32 Dev Module
- **Framework:** Arduino
- **Plataforma:** Espressif32
- **IDE:** Visual Studio Code
- **Extensão:** PlatformIO IDE
- **Linguagem:** C++

## Configuração do PlatformIO

O arquivo `platformio.ini` contém as configurações usadas para compilar e enviar o programa:

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
```

- `env:esp32dev`: identifica o ambiente de desenvolvimento do projeto.
- `platform = espressif32`: seleciona a plataforma para placas ESP32.
- `board = esp32dev`: define a placa como ESP32 Dev Module.
- `framework = arduino`: utiliza o framework Arduino.
- `monitor_speed = 115200`: configura a velocidade padrão do Monitor Serial.

## Estrutura do projeto

```text
esp32/
├── src/
│   └── main.cpp       # Código principal: acionamento do LED
├── include/           # Arquivos de cabeçalho do projeto
├── lib/               # Bibliotecas locais do projeto
├── test/              # Espaço reservado para testes
├── platformio.ini     # Configurações de compilação e placa
└── .gitignore         # Arquivos e pastas ignorados pelo Git
```

## Compilação e upload

O projeto pode ser compilado e enviado à placa pelos comandos do PlatformIO, executados no terminal dentro da pasta que contém `platformio.ini`.

Para compilar:

```bash
pio run
```

Esse comando compila o código e verifica se o projeto está pronto para gerar o firmware.

Para enviar o programa ao ESP32:

```bash
pio run --target upload
```

Esse comando compila o projeto, se necessário, e envia o firmware para o ESP32 conectado ao computador.

Também é possível realizar essas operações pela interface do PlatformIO no VS Code, usando as opções **Build** e **Upload**.

## Monitor Serial

A configuração do projeto define a velocidade do Monitor Serial como `115200` bauds. O código atual não inicializa a comunicação serial nem envia mensagens; portanto, o Monitor Serial não apresenta informações durante a execução. A configuração permanece disponível para futuras alterações no projeto.

## Resultado

O teste implementa o acionamento intermitente do LED no GPIO 2 e valida o fluxo inicial de desenvolvimento para ESP32 com PlatformIO: organização do projeto, configuração da placa, compilação e upload do programa.

## Possíveis extensões

A partir desta implementação, o projeto pode ser ampliado para incluir outros testes, como leitura de botão, controle de brilho do LED, comunicação pelo Monitor Serial, leitura de sensores ou conexão Wi-Fi.
