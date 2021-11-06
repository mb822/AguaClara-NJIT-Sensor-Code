# ESP 8266/32 Sensor Test Code
## ultra basic sketch for testing 

### If you are new to the ESP8266 or ESP32 modules, follow these steps to successfully upload the code to the modules:

0)) Open the Arduino IDE
0.1)) Navigate to 'Arduino -> Preferences -> Additional Boards Manager URLs' and paste the following:
 ```cpp
http://digistump.com/package_digistump_index.json
http://arduino.esp8266.com/stable/package_esp8266com_index.json
https://dl.espressif.com/dl/package_esp32_index.json
http://digistump.com/package_digistump_index.json
 ```
 0.2)) Exit and reopen the Arduino IDE
 
1)) Paste the corresponding version of the code into the editor - [ESP32](https://github.com/mb822/AguaClara-NJIT-Sensor-Code/edit/main/ESP32Code.ino) - [ESP8266](https://github.com/mb822/AguaClara-NJIT-Sensor-Code/edit/main/ESP8266Code.ino)
2)) Toward the top of the code you will see fields for ssid, password, and sensor id. Replace these fields with your network information and sensor id. 
3)) Plug your ESP32/ESP8266 into your computer
4)) Navigate to 'Tools -> Board' and select either 'ESP32 Dev Module' or 'Generic ESP8266 Module'
5)) Navigate to 'Tools -> Port' and select the correct port (if you are not sure what port to select, unplug you module, take a not of the ports, plug the module back in, and selcect the port that did not appear when the module was disconnected)
6)) Click 'upload' (circluar button with arrow pointing right, found at the top left-hand side of the window)(with ESP32 you may have to press and hold down the BOOT button during this step; you can release as soon as you see a upload progress percent)
7)) Give it a minute and your all set!
