# ESP 8266/32 Sensor Test Code
## ultra basic sketch for internal testing 

### If you are new to the ESP8266 or ESP32 modules, follow these steps to successfully upload the code to the modules:

[0]()) Open the Arduino IDE\
[1]()) Navigate to `Arduino -> Preferences -> Additional Boards Manager URLs` and paste the following:
 ```cpp
http://digistump.com/package_digistump_index.json,
http://arduino.esp8266.com/stable/package_esp8266com_index.json,
https://dl.espressif.com/dl/package_esp32_index.json,
http://digistump.com/package_digistump_index.json
 ```
[2]()) Navigate to `Tools -> Board -> Boards Manager` and install either "esp32" or "esp8266"\
[3]()) Exit and reopen the Arduino IDE\
[4]()) Open the corresponding .ino file found here: [ESP32](https://github.com/mb822/AguaClara-NJIT-Sensor-Code/blob/main/ESP32Sensor.ino) or [ESP8266](https://github.com/mb822/AguaClara-NJIT-Sensor-Code/blob/main/ESP8266Sensor.ino)\
[5]()) Toward the top of the code you will see fields for ssid, password, and sensor id. Replace these fields with that of your network and sensor id\
[6]()) Plug your ESP32/ESP8266 into your computer\
[7]()) Navigate to `Tools -> Board` and select either 'ESP32 Dev Module' or 'Generic ESP8266 Module'\
[8]()) Navigate to `Tools -> Port` and select the correct port (if you are not sure what port to select, unplug you module, take a note of the ports, plug the module back in, and select the port that did not appear when the module was disconnected)(if you dont see a new port, your micro usb cable is likely power only or damaged. If you are sure that the cable is not damaged and supports data transfer and the new port does not appear, you may need to download and install the [USB to UART Driver](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers))\
[9]()) Click 'upload' (circluar button with arrow pointing right, found at the top left-hand side of the window)(with ESP32 you may have to press and hold down the BOOT button during this step; you can release as soon as you see an upload progress percent)\
[10]()) Give it a minute and your all set!
