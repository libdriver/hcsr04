### 1. Chip

#### 1.1 Chip Info

chip name : Raspberry Pi 4B.

gpio pin: Trig/Echo GPIO27/GPIO17.

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

​          hcsr04 is a basic command which can test all hcsr04 driver function:

​           -h        show hcsr04 help. 

​           -i         show hcsr04 chip and driver information.

​           -p       show hcsr04 pin connections of the current board.

​           -t read <times>        run hcsr04 read test. times means the test times.

​           -c read <times>        run hcsr04 read function. times means the read times.

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
./hcsr04 -t read 3

hcsr04: chip is JieShenna HCSR04.
hcsr04: manufacturer is JieShenna.
hcsr04: interface is GPIO.
hcsr04: driver version is 2.0.
hcsr04: min supply voltage is 4.8V.
hcsr04: max supply voltage is 5.0V.
hcsr04: max current is 15.00mA.
hcsr04: max temperature is 85.0C.
hcsr04: min temperature is -40.0C.
hcsr04: start register test.
hcsr04: distance is 168.807007 cm.
hcsr04: distance is 167.821045 cm.
hcsr04: distance is 169.044922 cm.
hcsr04: finish register test.
```

```shell
./hcsr04 -c read 3

hcsr04: 1/3.
hcsr04: distance is 1.6760m.
hcsr04: 2/3.
hcsr04: distance is 1.6838m.
hcsr04: 3/3.
hcsr04: distance is 1.6864m.
```

```shell
./hcsr04 -h

hcsr04 -h
	show hcsr04 help.
hcsr04 -i
	show hcsr04 chip and driver information.
hcsr04 -p
	show hcsr04 pin connections of the current board.
hcsr04 -t read <times>
	run hcsr04 read test.times means the test times.
hcsr04 -c read <times>
	run hcsr04 read function.times means the read times.
```

