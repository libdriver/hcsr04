### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

GPIO Pin: Trig/Echo GPIO27/GPIO17.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(hcsr04 REQUIRED)
```

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
./hcsr04 -i

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
./hcsr04 -p

hcsr04: trig pin connected to GPIO27(BCM).
hcsr04: echo pin connected to GPIO17(BCM).
```

```shell
./hcsr04 -t read --times=3

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
hcsr04: distance is 100.979996cm.
hcsr04: distance is 102.391006cm.
hcsr04: distance is 101.506996cm.
hcsr04: finish read test.
```

```shell
./hcsr04 -e read --times=3

hcsr04: 1/3.
hcsr04: distance is 1.0152m.
hcsr04: 2/3.
hcsr04: distance is 1.0193m.
hcsr04: 3/3.
hcsr04: distance is 1.0147m.
```

```shell
./hcsr04 -h

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

