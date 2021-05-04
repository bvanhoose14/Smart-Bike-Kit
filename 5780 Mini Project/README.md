# Project BITbike

### Group Members: **Spencer Durrant, Ben Van Hoose, Tristan Stotesbery**

Our idea and goal was to create an **LED matrix** "License Plate" that could be attached to bicycles or ebikes and it could be used to display messages, turn signals or other useful visuals. This LED matrix was controlled by a microcontroller, the **STM32F072B Discovery board**, which was also interfacing with an **ESP32** microcontroller. The purpose of the ESP32 was to facilitate interactions with a **smartphone** utilizing it's **bluetooth** libraries, giving a biker the ability to control an **IoT** system while riding. This mini project also serves as a starting prototype for our broader senior project.


## Functionality/Milestones

![BITbike Prototype](/images/block2.PNG)

The block diagram above shows a high level functionality of the system. We developed an application using Java for the android to work with the bluetooth classic protocol as well as a simple **GUI**. We completed the other end of the bluetooth connection using the ESP32 built in bluetooth module. Then we transferred the information to the STM32 board and handled the incoming **GPIO** signals, interpreting them for the LED matrix. This functionality satisfied our first milestone of the project, to be able to control the MCU with a phone via bluetooth. Below is the GUI displayed on the phone.

![Phone GUI](/images/phone_gui.png)

The STM32 also served as the controller for the LED matrix and we could display various figures, such as text, or arrows for blinkers. We successfully did this by first using the simpler ESP32 environment to control the LED matrix to understand how to work with it. Then we transitioned to using C with the STM32. Controlling the LED matrix involved writing to it bit-by-bit with precise clocking and following a register address map for the matrix. This took us time to get properly figured out, we utilized **UART** for debugging. We got this working for each MCU demonstrating our success for the second milestone. We also had to use a smaller LED matrix as our STM32 is not fast enough to support the RGB matrix in the image above.

Naturally someone would want all these electrical devices to be powered. So we had to solve our power issue by designing a **power supply PCB** that would safely draw power from a battery pack containing 6 Lithium-Ion battery cells in a 3-Series, 2-Parallel configuration. We first read documents to figure out the maximum power consumption of the two microcontrollers and the LED matrix and we determined the maximum current could potentially reach 4 Amps. The battery and management circuit board we built is rated for 12.6V, 4Ah which is reasonable for our project. Specifically, the PCB would take the battery voltage and use a buck converter IC to drop the voltage to DC 5V. Once we designed, fabricated, and soldered the PCB we plugged it in with our system and it worked as expected. This meant we achieved our third milestone.

We also utilized some of the on-board peripherals of the STM32, specifically the **gyroscope**. As a bike turns it tilts in the direction it is turning. This makes it possible to automatically turn off the blinker signals with the gyroscope. Therefore we used **I2C** to interact with this sensor and turn off the blinker signals once the bike as straightened back out after a turn signal was initiated. This satisfied our goals for our fourth milestone.

# Setup
With several devices on this system, a lot of setup is involved. This requires good detail so as not to mess it up. First, program and flash the ESP32 with the respective code located in one of the two version folders. Then program and flash the STM32 with the respective code one of the same version folder. Another reference that may be helpful which we utilized is [controllers tech](https://controllerstech.com/led-dot-matrix-and-stm32/). 

## Wiring
We have set pins specifically with our designs. See the diagram below to see how to connect the devices together.

![pinout](/images/pinout.PNG)

Additionally, see the image below for the STM32 pins PB15, PB11, and PB13 for the I2C protocol.

![I2C pins](/images/i2c_pins.PNG)

## Schematics
Below is the schematic and PCB layout for the buck converter power supply.

![Power Supply Schematic](/images/power_sch.PNG)

![Power Supply Board](/images/power_board.PNG)

## Power
The assembled power supply is in the image below. All three of the screw terminal connectors are connected to the same 5V line. It is possible to provide power to the board using one of the screw terminals, or the barrel jack. To connect our battery pack to it, we simply connected the wires to one of the screw terminals. For alternative testing it is certainly an option to use a 5V supply with a barrel jack connected to a wall outlet.

![Assembled Power Supply](/images/pcb-built.jpg)

![Battery connected](/images/battery.jpg)

To power the microcontrollers and LED matrix, we used one screw terminal for the ESP32, and the other for the STM32 while the third one was occupied with the battery pack. We fed power into the LED matrix from the STM32 5V pin and thus all our devices could be powered for at least an entire hour by the batteries.
