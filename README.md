## Get the source code

- You can download the repo as a [zip file](https://github.com/robotixdevteam/CVPRO-Firmware/archive/refs/heads/main.zip) and extract it into a folder of your choice.
- You can clone the Production Test-Code repository from GitHub with the following command:
    ```bash
    git clone https://github.com/robotixdevteam/CVPRO-Firmware.git
    ```

## Test-out Bot functionality

- The `Alpha_Test` folder is firmware for cvpro bot/kit to test peripherals. Open the anyone of the files in `Alpha_Test` folder, it will open all the Alpha_Test files in Arduino IDE. 

    ⚠️ Before user have to install the Ardunio IDE [here](https://www.arduino.cc/en/software). 

1. Install the libraries from Library manager whichs to the left-side of Arduino IDE.
2. Packages are:
    - ***FastLED*** developed by Daniel Garcia
    - ***NewPing*** developed by Tim Eckel

3. After Compling and Uploading the Alpha test firmware to the bot, Go to `Serial Monitor` in the right-side of Arduino IDE and Select the Baud rate `115200`. 
4. Type the below given commands one by one to test the functions as mentioned in the description. (**Note**: All options are `small letters`)
          
    |    ***Menu***    |                       ***Description***                     |
    |:---------------: | :---------------------------------------------------------: |
    |    ***lb***      | only ***Left Back Motor*** will run                         |
    |    ***lf***      | only ***Left Front Motor*** will run                        | 
    |    ***rf***      | only ***Right Front Motor*** will run                       |
    |    ***rb***      | only ***Right Back Motor*** will run                        |
    |    ***us***      | only ***Ultrasonic sensor*** will detect                    |
    |    ***lir***     | only ***Left IR sensor*** will detect                       |
    |    ***rir***     | only ***Right IR sensor*** will detect                      |
    |     ***s***      | ***Swapping Motors*** (Front-Back and Back-Front will run)  |
    |     ***m***      | ***All Motors Running***                                    |
    |    ***of***      | ***Motors reset*** (Running motor to stop)                  |
    |     ***f***      | ***Motors Running Forward***                                |
    |     ***b***      | ***Motors Running Backward***                               |
    |     ***l***      | ***Motors Running Left***                                   |
    |     ***r***      | ***Motors Running Right***                                  |
    |     ***v***      | ***Voltage of the Battery***                                |
    |     ***rt***     | ***Run time of the bot***                                   |
    |    ***led***     | ***LED blinking of the bot***                               |

## Battery Cutoff

- Upload the `Battery_cutoff` files in the Battery_cutoff folder to test-out the runtime of the Bot (Operating Voltage `3.7V-4.0V` of the Bot).

## CVPRO Firmware

- After the peripherals test, open the CV Pro Wireless firmware from the `Firmware` folder to CVPRO Bot/kit and edit the **ssid name** as per serialization of the bot. (Find the name from the line of code: 30 and edit the number below).
- Ensure that the edited number is as per increment of the production chain.
- After editing, Upload the firmware to the bot.
- Once the code is uploaded, turn on the bot. Use a Smart Phone to open it's WiFi settings to see the list of devices and check if the CV Pro name with edited serial number is shown in list of Wifi/Network Connection (***For Example, cvpro0123***).
- Use the GitHub [link](https://github.com/robotixdevteam/Meritus-CVPRO) provided and follow the instructions carefully to test `Object Detection` using CV Pro bot and Smart Phone. 


## CVPRO Platooning
### Master Bot/Kit

- After the peripherals test, open the CV Pro Platooning firmware from the `master` subfolder in `Platooning` folder.
- In The firmware, edit the **ssid name** corresponding to the kit ID (***For Example, cvpro0123***) as per serialization of the bot. (You have to enter ssid name in the line 31 of code).
- Ensure that the edited number is as per increment of the production chain.
- After editing, Upload the firmware to the bot.
- Once the code is uploaded, turn on the bot. Use a Smart Phone to open it's WiFi settings to see the list of devices and check if the CV Pro name with edited serial number is shown in list of Wifi/Network Connection (***For Example, cvpro0123***).
- Use the GitHub [link](https://github.com/robotixdevteam/Meritus-CVPRO) provided and follow the instructions carefully to test `Object Detection` using CV Pro bot and Smart Phone. 

### Follower Bot/Kit

- After the peripherals test, open the CV Pro Platooning firmware from the `follower` subfolder in `Platooning` folder.
- In the firmware, edit the **platoonssid name** corresponding to Master bot/kit ID (***For Example, cvpro0123***) as per serialization of the bot. (You have to enter this ID in the line 31 of code). 
- Now for bot/kit to act as follower, edit the **ssid name** corresponding to Follower bot/kit ID (***For Example, cvpro0124***) as per serialization of the bot. (You have to enter this ID in the line 36 of code). 
- Ensure that the edited number is as per increment of the production chain.
- After editing, Upload the firmware to the bot.
- Once the code is uploaded, turn on the bot and place the bot/kit behind the Master bot/kit. 

### To enable Basic Platooning follow the steps,
1. Connect the Master bot/kit with server (MQTT Server Connection). (Device-1)
2. Place the smartphone in Master bot/kit and Connect to the server. (Device-2)
3. Connect the Follower bot/kit with server. (Device-3)

### To enable Advanced Platooning follow the steps,
1. Connect the Master bot/kit with server (MQTT Server Connection). (Device-1)
2. Place the smartphone in Master bot/kit and Connect to the server. (Device-2)
3. Connect the Follower bot/kit with server. (Device-3)
4. Place another smartphone in Follower bot/kit and connect to server. (Device-4)

⚠️ If order is not followed, ***both the Master and Follower Bot/kit will not work properly (will malfunction)***.

**Important Note:** 
- If the **Follower bot/kit** is not connected with **Master bot/kit**, then it will act as CV Pro Bot/kit (Autonomous Driving and Object Detection).

## Contact

- Contact us via [Email](mailto:development@merituseducation.com)
