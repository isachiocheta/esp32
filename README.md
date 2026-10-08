# ESP32 — LED piscando com PlatformIO

Projeto introdutório para estudar a estrutura de um programa para **ESP32** usando o framework **Arduino** e a extensão **PlatformIO** no Visual Studio Code. O programa em `src/main.cpp` faz o LED conectado ao **GPIO 2** acender e apagar em intervalos de um segundo.

> Em muitas placas ESP32 DevKit o LED interno está ligado ao GPIO 2. Caso o LED da sua placa não pisque, conecte um LED externo ao GPIO 2 ou consulte o esquema/modelo da placa para descobrir o pino do LED interno.

## O que este projeto ensina

- Estrutura básica de um programa para ESP32 com Arduino.
- Uso dos métodos `setup()` e `loop()`.
- Configuração de um pino como saída digital.
- Acionamento de um LED com nível lógico alto e baixo.
- Pausa da execução com `delay()`.
- Compilação, envio e monitoramento serial pelo PlatformIO.

## Funcionamento do código

Arquivo: `src/main.cpp`

```cpp
#include <Arduino.h>
#define pino_led 2

void setup(){
   pinMode(pino_led, OUTPUT);
}

void loop(){
   digitalWrite(pino_led, HIGH);
   delay(1000);
   digitalWrite(pino_led, LOW);
   delay(1000);
}
```

### Explicação linha a linha

| Trecho | O que faz |
| --- | --- |
| `#include <Arduino.h>` | Inclui as funções do framework Arduino, como `pinMode`, `digitalWrite` e `delay`. |
| `#define pino_led 2` | Cria o nome `pino_led` para representar o GPIO 2. Isso evita repetir o número do pino no código. |
| `void setup()` | Função executada **uma única vez**, logo após o ESP32 ligar ou reiniciar. É usada para configurações iniciais. |
| `pinMode(pino_led, OUTPUT)` | Define o GPIO 2 como **saída**, permitindo que ele envie sinal elétrico ao LED. |
| `void loop()` | Função executada repetidamente enquanto a placa estiver ligada. Quando chega ao fim, recomeça automaticamente. |
| `digitalWrite(pino_led, HIGH)` | Coloca o pino em nível lógico alto (aproximadamente 3,3 V), acendendo o LED na ligação usual. |
| `delay(1000)` | Pausa o programa por 1.000 milissegundos, isto é, 1 segundo. |
| `digitalWrite(pino_led, LOW)` | Coloca o pino em nível lógico baixo (0 V), apagando o LED. |
| Segundo `delay(1000)` | Mantém o LED apagado por 1 segundo antes de o ciclo recomeçar. |

Assim, o LED fica **1 segundo aceso** e **1 segundo apagado**, formando um ciclo de 2 segundos.

## Conceitos iniciais importantes do ESP32

### GPIO

GPIO significa *General Purpose Input/Output* (entrada/saída de uso geral). São pinos que podem ler sinais ou controlar componentes externos. Neste projeto, o GPIO 2 é usado como **saída** para controlar um LED.

### Estados digitais

- `HIGH`: nível lógico alto; no ESP32 equivale normalmente a cerca de **3,3 V**.
- `LOW`: nível lógico baixo; equivale a **0 V**.
- `OUTPUT`: modo de operação para enviar sinais pelo pino.
- `INPUT`: modo de operação para ler sinais, por exemplo, de um botão ou sensor.

### `setup()` e `loop()`

No framework Arduino, estas duas funções são obrigatórias:

1. `setup()` roda uma vez para preparar a placa.
2. `loop()` roda infinitamente e contém o comportamento contínuo do projeto.

## Estrutura do projeto

```text
esp32/
├── src/
│   └── main.cpp          # Código principal do ESP32
├── include/              # Arquivos de cabeçalho criados pelo projeto
├── lib/                  # Bibliotecas próprias do projeto
├── test/                 # Testes automatizados, se houver
├── platformio.ini        # Configurações do PlatformIO
└── .gitignore            # Arquivos que não devem ser enviados ao Git
```

## Configuração do PlatformIO no VS Code (Linux)

### 1. Instalar o Visual Studio Code

Caso ainda não tenha o VS Code instalado, baixe-o pelo site oficial ou use o gerenciador de pacotes da sua distribuição Linux.

### 2. Instalar a extensão PlatformIO IDE

1. Abra o VS Code.
2. Clique no ícone de **Extensões** na barra lateral esquerda, ou pressione `Ctrl + Shift + X`.
3. Pesquise por **PlatformIO IDE**.
4. Escolha a extensão publicada por **PlatformIO** e clique em **Install**.
5. Aguarde a instalação dos componentes necessários e reinicie o VS Code se ele solicitar.

### 3. Abrir este projeto

1. No VS Code, selecione **File → Open Folder...**.
2. Escolha a pasta `esp32` — a mesma que contém o arquivo `platformio.ini`.
3. Aguarde o PlatformIO reconhecer e preparar o ambiente `esp32dev`.
4. Abra `src/main.cpp` para ver ou alterar o código.

> Abra a **pasta do projeto**, não apenas o arquivo `main.cpp`. O PlatformIO precisa encontrar o arquivo `platformio.ini`.

## Configuração usada no PlatformIO

Arquivo: `platformio.ini`

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
```

| Configuração | Significado |
| --- | --- |
| `[env:esp32dev]` | Nome do ambiente de compilação. |
| `platform = espressif32` | Usa a plataforma dos microcontroladores ESP32 da Espressif. |
| `board = esp32dev` | Seleciona a placa genérica ESP32 Dev Module. |
| `framework = arduino` | Permite programar com as funções e estrutura do Arduino. |
| `monitor_speed = 115200` | Define a velocidade do Monitor Serial em 115200 bauds. |

## Como compilar e enviar o programa pela interface do VS Code

1. Conecte o ESP32 ao computador com um **cabo USB que transmita dados**. Alguns cabos servem apenas para carregamento.
2. Abra a pasta do projeto no VS Code.
3. No rodapé do VS Code, localize os ícones do PlatformIO:
   - ✓: **Build** — compila o projeto;
   - →: **Upload** — compila e envia o programa para a placa;
   - tomada: **Serial Monitor** — abre a comunicação serial.
4. Primeiro clique em **Build** para verificar se não há erros de compilação.
5. Clique em **Upload** para gravar o programa no ESP32.
6. Aguarde a mensagem de sucesso, normalmente semelhante a `SUCCESS`.
7. Após o reinício da placa, o LED deverá piscar.

Se o upload ficar parado em `Connecting...`, mantenha pressionado o botão **BOOT** da placa, inicie o upload e solte o botão quando a gravação começar.

## Comandos Linux pelo terminal

Abra o terminal na pasta do projeto. Exemplo:

```bash
cd ~/Documentos/PlatformIO/Projects/esp32
```

> Ajuste o caminho se você tiver salvo o projeto em outra pasta.

### Compilar

```bash
pio run
```

Esse comando verifica o código e gera o firmware, mas **não envia** nada à placa.

### Enviar para o ESP32

```bash
pio run --target upload
```

O PlatformIO compila (se necessário) e grava o firmware no ESP32.

### Abrir o Monitor Serial

```bash
pio device monitor
```

Para sair do Monitor Serial, pressione `Ctrl + C`.

### Compilar, enviar e abrir o monitor

Execute primeiro o upload e, após terminar, abra o monitor:

```bash
pio run --target upload
pio device monitor
```

Neste projeto não há `Serial.begin()` nem mensagens sendo impressas; portanto, o Monitor Serial ficará sem texto. Ele será útil quando você adicionar comunicação serial em estudos futuros.

### Descobrir a porta da placa

Com o ESP32 conectado, execute:

```bash
ls /dev/ttyUSB* /dev/ttyACM*
```

A placa costuma aparecer como `/dev/ttyUSB0` ou `/dev/ttyACM0`. Para definir a porta manualmente no `platformio.ini`, adicione, por exemplo:

```ini
upload_port = /dev/ttyUSB0
```

Depois use novamente:

```bash
pio run --target upload
```

## Permissão para acessar a porta USB no Linux

Se aparecer erro de permissão, como `Permission denied` ao acessar `/dev/ttyUSB0`, adicione seu usuário ao grupo `dialout`:

```bash
sudo usermod -aG dialout $USER
```

Depois, **encerre a sessão do Linux e entre novamente** (ou reinicie o computador) para a alteração valer. Em seguida, confirme com:

```bash
groups
```

O grupo `dialout` deve aparecer na lista.

## Possíveis problemas no upload

| Problema | O que verificar |
| --- | --- |
| A placa não aparece em `/dev/ttyUSB0` | Troque o cabo USB; muitos cabos carregam, mas não transferem dados. Teste outra porta USB. |
| `Permission denied` | Execute o comando para adicionar seu usuário ao grupo `dialout` e faça login novamente. |
| Upload parado em `Connecting...` | Segure **BOOT** enquanto inicia o upload e solte quando ele começar. |
| LED não pisca | Verifique se sua placa usa o LED interno no GPIO 2. Se necessário, use um LED externo com resistor adequado. |
| Porta ocupada | Feche o Monitor Serial e qualquer outro programa que esteja usando a porta antes do upload. |
| Placa diferente | Altere `board = esp32dev` no `platformio.ini` somente após confirmar o modelo correto da sua placa. |

## Próximos estudos sugeridos

- Controlar um LED externo usando resistor de 220 Ω a 1 kΩ.
- Ler um botão com `pinMode(..., INPUT_PULLUP)` e `digitalRead()`.
- Enviar mensagens ao computador com `Serial.begin(115200)` e `Serial.println()`.
- Usar PWM para controlar o brilho de um LED.
- Conectar o ESP32 ao Wi-Fi.

---

Projeto criado para estudo dos conceitos iniciais do ESP32 com PlatformIO e framework Arduino.
