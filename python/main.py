from machine import Pin, I2C
import ssd1306
from time import sleep

led = Pin(2, Pin.OUT)

i2c = I2C(Pin(5), Pin(4))
oled = ssd1306.SSD1306_I2C(128, 32, i2c)

oled.pixel(0, 0, 1)
oled.show()

while True:
  led.value(not led.value())
  sleep(1)
  print("test")
  