# Zumo
 Project Systems Engineering groep 3.3
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
# Xbee gebruiken
Als je nu de Xbee hebt ingesteld, en je hebt je Zumo aan een USB kabel hangen, dan heb je twee manieren om te communiceren tussen je lap-top en je Zumo. (Namelijk via de USB kabel en via de Xbee)

Let op, het uploaden van je programma-code naar de ZUMO lukt enkel met de USB kabel!!! De Xbee is hier dus niet bruikbaar voor.

Als je leert hoe je berichtjes tussen je laptop en de ZUMO heen en weer kunt sturen, vind je waarschijnlijk voorbeelden met 'Serial'. Die gebruikt de USB kabel. Als je in plaats daarvan Serial1 gebruikt, loopt de communicatie via de Xbee. 

Als je in de Arduino IDE twee sketches opent kun je in één sketch de  serial monitor gebruiken om de communicatie over de kabel te bekijken, en de andere sketch gebruiken voor de communicatie via Xbee. Wel de goede poorten vinden en selecteren!
