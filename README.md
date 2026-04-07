 # MaRS-RECRUITMENT_TASK1
 
# SEC-A_Q1_Blinking LED with different time interval
# https://www.tinkercad.com/things/fE9anHA0crX-blinking-led?sharecode=2Jq3e4y21sTH-LKKitNgn9z9kce7MSRspDkJJDJgtOc

In this circuit, each LED is connected to a different Arduino pin, and each one has its own blinking speed. Instead of using delay(), the program uses the millis() timer to keep track of how much time has passed. For each LED, the code checks whether its specific interval has finished. When the time is up, the LED’s state is flipped from ON to OFF (or vice versa), and the timer is reset for that LED. Because millis() lets all these checks happen at the same time, the three LEDs can blink independently at different speeds without stopping the entire program. So the whole idea is that each LED has its own timer running in parallel, and the Arduino controls all of them smoothly using millis().

# SEC-A_Q2_Controlling colour of RGB LED and blinking speed of another LED with potentiometer
# https://www.tinkercad.com/things/apIB20Z61Td-pot-control-led?sharecode=bh6eXey2ahxdK_0jMR5bfHf1Sp9mFWttw15wE2l4f4k

In this circuit, the potentiometer controls two things at the same time: the blinking speed of a separate LED and the colour of the RGB LED. The Arduino reads the potentiometer value and first converts it into a delay time, which decides how fast the blinking LED turns ON and OFF. Then the same potentiometer value is split into three ranges, and each range smoothly adjusts the red, green, and blue brightness levels. Because the values are mapped, the RGB LED fades through different colours as the knob is turned. So the pot acts like a dual controller—turning it changes the blink speed of the small LED and also creates a smooth colour-transition effect on the RGB LED.

# SEC-A_Q3_a reaction time tester
# https://www.tinkercad.com/things/jamVrv4cWqQ-reaction-time-tester?sharecode=vfD8ycwNEN-ggi3SPbmMuJ9HW02q1FAKjpRiUjwQfAw

The Arduino waits for a random time using millis(). When that time is over, the LED turns ON and the timer starts. The button uses INPUT_PULLUP, so it reads LOW only when pressed. The reaction time is calculated as:

reaction time = millis() − ledOnTime

This value is shown on the Serial Monitor. Then the system resets with a new random delay for the next test.

# SEC-B_FIRE AND SMOKE ALARM
# https://www.tinkercad.com/things/20VYZd0C32R-fire-and-smoke-alarm?sharecode=z_Lq0PlrQoW22z66lqB_JMwZiKejUvoybuSWM3DN1YE
# Smoke & Fire Alarm System – Readme
1. What the Project Does & Why I Chose It

This project is a simple smoke and fire alarm that detects two dangers: high temperature and gas/smoke concentration. When the temperature rises above a safe level, an LED turns on as a fire alert. When the gas sensor detects smoke or harmful gases, a piezo buzzer starts beeping.
I chose this project because it is practical, easy to understand, and directly connected to real-life safety systems. It also allowed me to work with both analog sensors and output devices, which made the circuit more meaningful instead of just blinking LEDs.

2.how does the circuit work ?

This circuit checks two things at the same time — temperature and gas concentration. The temperature sensor is connected to A1, and its analog value is converted into degrees Celsius using a small calculation. If the temperature crosses 80°C, the LED on pin 13 switches ON as a warning. At the same time, a gas sensor on A0 keeps reading the gas level. If the gas value goes above 100, the piezo buzzer turns ON to alert the user. Both readings are printed on the serial monitor every second so we can see the live temperature and gas values. Basically, the LED warns about overheating, and the buzzer warns about gas leakage, and the Arduino keeps checking both continuously.

3. Components Used & Their Roles

Arduino Uno – Main controller that reads sensor values and decides when to trigger the alarms.
LM35 Temperature Sensor (A1) – Measures the surrounding temperature in millivolts (10 mV per °C).
MQ Gas Sensor (A0) – Detects smoke or harmful gases and outputs an analog value.
LED (Pin 13) – Lights up when the temperature crosses the safety limit (fire alert).
Piezo Buzzer (Pin 7) – Makes sound when gas levels become high (smoke alert).
Resistors & Jumper Wires – For safe connections.
Breadboard – Used to organize and build the circuit.

4. Challenges Faced & How I Solved Them

a. Incorrect temperature calculations:
At first, the values from the LM35 were not matching real temperature. I realized I was reading raw ADC values, so I converted them properly:

Voltage = (ADC/1023) × 5000

Temperature = (Voltage − 500) / 10

b. Piezo buzzer not responding:
The buzzer stayed silent because I had forgotten to set its pin as OUTPUT. After adding pinMode(piezo, OUTPUT);, it worked correctly.

c. Gas sensor giving unstable readings:
The MQ sensor fluctuates a lot during warm-up. I solved this by choosing a simple threshold value (100) and testing multiple times until the response became stable.

d. Making both sensors work together:
Sometimes only one alert worked because the code logic overlapped. I separated the conditions clearly, so temperature controls the LED and gas concentration controls the buzzer independently.
