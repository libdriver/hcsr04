### 1. Chip

#### 1.1 Chip Info

Chip Name: STM32F407ZGT6.

Extern Oscillator: 8MHz.

UART Pin: TX/RX PA9/PA10.

GPIO Pin: Echo/TrigPA8/PA0.

### 2. Development and Debugging

#### 2.1 Integrated Development Environment

LibDriver provides both Keil and IAR integrated development environment projects.

MDK is the Keil ARM project and your Keil version must be 5 or higher.Keil ARM project needs STMicroelectronics STM32F4 Series Device Family Pack and you can download from https://www.keil.com/dd2/stmicroelectronics/stm32f407zgtx.

EW is the IAR ARM project and your IAR version must be 9 or higher.

#### 2.2 Serial Port Parameter

Baud Rate: 115200.

Data Bits : 8.

Stop Bits: 1.

Parity: None.

Flow Control: None.

#### 2.3 Serial Port Assistant

We use '\n' to wrap lines.If your serial port assistant displays exceptions (e.g. the displayed content does not divide lines), please modify the configuration of your serial port assistant or replace one that supports '\n' parsing.

### 3. HCSR04

#### 3.1 Command Instruction

1. Show hcsr04 chip and driver information.

   ```shell
   hcsr04 (-i | --information)
   ```

2. Show hcsr04 help. 

   ```shell
   hcsr04 (-h | --help)
   ```

3. Show hcsr04 pin connections of the current board.

   ```shell
   hcsr04 (-p | --port)
   ```

4. Run hcsr04 read test, num means the test times.

   ```shell
   hcsr04 (-t read | --test=read) [--times=<num>]
   ```

5. Run hcsr04 read function, num means the read times.

   ```shell
   hcsr04 (-e read | --example=read) [--times=<num>]
   ```

#### 3.2 Command Example

```shell
hcsr04 -i

hcsr04: chip is JieShenna HCSR04.
hcsr04: manufacturer is JieShenna.
hcsr04: interface is GPIO.
hcsr04: driver version is 2.0.
hcsr04: min supply voltage is 4.8V.
hcsr04: max supply voltage is 5.0V.
hcsr04: max current is 15.00mA.
hcsr04: max temperature is 85.0C.
hcsr04: min temperature is -40.0C.
```

```shell
hcsr04 -p

hcsr04: trig pin connected to GPIOA PIN0.
hcsr04: echo pin connected to GPIOA PIN8.
```

```shell
hcsr04 -t read --times=3

hcsr04: chip is JieShenna HCSR04.
hcsr04: manufacturer is JieShenna.
hcsr04: interface is GPIO.
hcsr04: driver version is 2.0.
hcsr04: min supply voltage is 4.8V.
hcsr04: max supply voltage is 5.0V.
hcsr04: max current is 15.00mA.
hcsr04: max temperature is 85.0C.
hcsr04: min temperature is -40.0C.
hcsr04: start read test.
hcsr04: distance is 83.555000cm.
hcsr04: distance is 82.722000cm.
hcsr04: distance is 83.521004cm.
hcsr04: finish read test.
```

```shell
hcsr04 -e read --times=3

hcsr04: 1/3.
hcsr04: distance is 0.8184m.
hcsr04: 2/3.
hcsr04: distance is 0.8221m.
hcsr04: 3/3.
hcsr04: distance is 0.8272m.
```

```shell
hcsr04 -h

Usage:
  hcsr04 (-i | --information)
  hcsr04 (-h | --help)
  hcsr04 (-p | --port)
  hcsr04 (-t read | --test=read) [--times=<num>]
  hcsr04 (-e read | --example=read) [--times=<num>]

Options:
  -e <read>, --example=<read>    Run the driver example.
  -h, --help                     Show the help.
  -i, --information              Show the chip information.
  -p, --port                     Display the pin connections of the current board.
  -t <read>, --test=<read>       Run the driver test.
      --times=<num>              Set the running times.([default: 3])
```

