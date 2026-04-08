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

# SEC-B_SMART IRRIGATION SYSTEM
# https://www.tinkercad.com/things/dnXaZJyuoLC-soil-moisture-alarm?sharecode=Q7N1QHzcTE88r7vQsaw20xic0KCWdfNPBRvZX-3J3xA
# Smart Irrigation System – README
What the project does & why I chose it

This project checks how wet or dry the soil is using a soil-moisture sensor. When the soil is dry, the system switches ON the motor/LED, and when the soil is wet, it turns it OFF automatically.
I chose this because it is a very practical and useful idea, and it shows how sensors can help automate farming or plant care.

Components used & their roles

Soil Moisture Sensor – Detects how much water is in the soil and gives an analog value.
Arduino UNO – Reads the sensor value and decides whether to turn the motor/LED ON or OFF.
NPN Transistor / Motor Output – Works like a switch that controls the motor using the Arduino.
LED / Motor – Shows the output state. When the soil is wet, it turns ON.
9V Battery – Gives extra power for the motor.

Challenges faced & how I solved them

At first the sensor value was not stable and was giving random numbers. I fixed it by checking all the ground connections and making sure the sensor VCC went to the correct pin. Another issue was the motor not running because the transistor pins were connected wrongly. After rewiring the base, collector, and emitter properly, the circuit started working and the motor switched ON/OFF exactly based on the soil moisture reading.

# SEC-B_SMART PARKING GATE SYSTEM
# https://www.tinkercad.com/things/6uiLCJIpj0I-smart-parking-gate-system?sharecode=tl8V20WKrjNxcPm_zrDhLwKiymHem4UhblctkzlIodc
# Smoke & Fire Alarm System – README
What the project does & why I chose it

This project is a simple smoke and fire alarm that uses a temperature sensor and a gas sensor to detect any unsafe conditions. When the temperature goes too high, the LED turns on, and when the gas level increases, the piezo buzzer alerts. I chose this project because it is easy to build, useful in real life, and it clearly shows how sensors can be used for safety systems.

Components used & their roles

Gas Sensor (MQ type) – Reads the concentration of smoke or gas in the air.
Temperature Sensor (LM35) – Converts temperature into voltage, which helps calculate the actual temperature value.
LED – Acts as a visual alert when temperature crosses the limit.
Piezo Buzzer – Gives a loud sound when gas level becomes high.
Arduino – Reads both sensors and decides when to turn on the LED or buzzer.

Challenges faced & how I solved them

One issue I had was converting the analog value from the temperature sensor into the correct Celsius value. I fixed it by using the proper formula and checking it on the serial monitor. Another challenge was that the piezo wasn’t reacting at first, and that happened because I forgot to set its pinMode as OUTPUT. After fixing the pinMode and adjusting the threshold values, both alerts started working correctly.
