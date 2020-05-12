# Formula Ino

Formula Ino is a open-source and open-hardware base project to build a remote control car, controlled by a PS4 DualShock controller

## Hardware

![schema](https://raw.githubusercontent.com/igventurelli/formula-ino/master/fritzing/schema.png)

The hardware is composed by:

- 1x Arduino (tests made on UNO)
- 1x USB Host Shield (to connect a Bluetooth USB stick)
- 1x L298N H-Bridge motor driver
- 2x DC Motor 5v
- 1x Servo Motor

The Servo is used to provide the direction (left/right) and the DC motors are used to make the car move

## Software

The software is an ordinary Arduino project.  
If you have an Arduino board, you are probably ready to upload the code to your device.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)