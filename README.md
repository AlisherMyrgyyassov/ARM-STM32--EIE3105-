# ARM-STM32--EIE3105-
Lab 5 exercises from EIE3105 made on ARM

For exercises E to I only the source codes are given. Copy and paste them into your main.c file.


Section A:
Test LED

Section B: 
Delay loop function test

Section C:
Repeat Section B but this time you should use the standard peripheral function Systick.

Section D: 
Use the on-board button (PC13) to switch on and off the on-board LED (PA5). When the button is pressed, the LED is on. When the button is released, the LED is off

Section E: 
Use the on-board button (PC13) to change the state of the on-board LED (PA5).
There are two states in the button: State 0 and 1. When it is in State 0, the LED is off. When 
it is in State 1, the LED is on. At the beginning, the button is in State 0. When the button is 
pressed and it is in State 0, it goes to State 1. When the button is pressed and it is in State 1, it goes to State 0.

Section F: 
Write a C Program to simulate the traffic lights
Write a C program to simulate the traffic lights by using different pins. You can use any pins 
to simulate the traffic lights. You must use interrupt to implement the application.
A set of traffic lights for cars (Light 3, 3 LEDs)
A set of traffic lights for cars (Light 2, 3 LEDs) 
A set of traffic lights for people (Light 1, 2 LEDs)
Repeat the following:
Light 1 (RED), Light 2 (GREEN), Light 3 (RED), period (around 5s)
Light 1 (RED), Light 2 (YELLOW), Light 3 (RED), period (around 1s)
Light 1 (RED), Light 2 (RED), Light 3 (RED), period (around 1s)
Light 1 (RED), Light 2 (RED), Light 3 (RED+YELLOW), period (around 1s)
Light 1 (GREEN), Light 2 (RED), Light 3 (GREEN), period (around 5s)
Light 1 (GREEN Blinking), Light 2 (RED), Light 3 (YELLOW), period (around 1s)
Light 1 (RED), Light 2 (RED), Light 3 (RED), period (around 1s)
Light 1 (RED), Light 2 RED+YELLOW), Light 3 (RED), period (around 1s)

Section G: 
Write a C program to count a switch
Connect a switch to a pin and a LED to another pin. There are two states in the switch: State 
0 and 1. When it is in State 0, the LED is off. When it is in State 1, the LED is on. At the 
beginning, the switch is in State 0. When the switch is pressed three times and it is in State 0, it goes to State 1. When the switch is pressed three times and it is in State 1, it goes to State 0. You must use interrupt to implement the application

Section H: 
Use an external hardware interrupt to enable the simulation of the traffic lights. Connect a switch to an external hardware interrupt pin. Write a C program so that the simulation of the traffic lights in Section A can be started by pressing the switch once. If the switch is pressed again, the simulation of the traffic lights will be stopped (i.e., all LEDs are OFF).

Section I: 
Write a C program to keep sending and receiving characters
Write a C program to complete the following tasks by using interrupts:
1. Before you press any keys, character ‘a’ is printed continuously.
2. When you press a key (say ‘b’), 10 characters of this key (i.e., ‘b’) are printed out and 
then stop.
3. After that when you press a key other than the first key (i.e., ‘b’), nothing happens.
4. When you press the key again (i.e., ‘b’), character ‘a’ is printed continuously (i.e., 
resume).
Set the baud rate of the PC terminal (i.e., Tera Term) to 9600.
