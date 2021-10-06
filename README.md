# CBlinklichtSteuerung

PORTB is LED Output

PORTA is Button Input

Set the initialization Variables to modify the default parameters without touching the buttons on PORTA.

If you got a possibility to connect buttons to PORTA you can modificate the LED blink duration (10 ms steps), repeats (1 step increase/decrease) and LED amount (2-8).


Duration (ms)

Button 8 -> + 10 ms

Button 1 -> - 10 ms


Repeats (minimum value: 1 repeat)

Button 7 -> + 1 LED blink Repeat

Button 2 -> - 1 LED Blink Repeat


Blinking LED amount (minimum LEDs: 2, maximum LEDs: 8)

Button 6 -> + 1 LED

Button 3 -> - 1 LED


Turn off & on

Button 5 -> Turn on

Button 4 -> Trun off


Easter-Egg

Button 5 & 4 simultaneously -> Copy signal to all 8 LEDs
