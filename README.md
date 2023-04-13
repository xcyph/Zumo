# Zumo
 Project Systems Engineering
------------------------------
1. Install Arduino van arduino.cc
2. Installeer Zumo drivers van https://www.pololu.com/docs/0J63/all#5.1  tot aan blink maar doe ook stap 6 (Zumo 32U4 Arduino library)
3. Xbee : https://www.hobbytronics.co.uk/xbee-s2c-configuration  
Let op sla "Setup using the new ZIGBEE TH REG firmware" over en ga verder met "Setup using the older 802.15.4 TH firmware". Zie ook Xbee .
Dit is de basis die je nodig hebt.
# Installing the library 
Use the Library Manager in version 1.8.10 or later of the Arduino software (IDE) to install this library:

    1. In the Arduino IDE, open the "Tools" menu and select "Manage Libraries...".
    2. Search for "Zumo32U4".
    3. Click the Zumo32U4 entry in the list.
    4. Click "Install".
    5. If you see a prompt asking to install missing dependencies, click "Install all".
    
    
# Usage

To access all features of this library, you just need these include statements:
```
#include <Wire.h>
#include <Zumo32U4.h>
```
