# CanSat AESS Challenge 2019
A CanSat is a small satellite the size of a can. Inside it has all the normal components that a satellite has, such as sensors, transmission, batteries, parachuting, etc.

The purpose of this CanSat is to record variables related to movement, altitude and temperature within its container, and for that it was made to participate in the IEEE AESS CanSat Innovation Challenge 2019.

This is a dervided project of the On Board Computer of the POA model rocket made by the ATL research hotbed at  Universidad Distrital Francisco José de Caldas.

### Materials
* Arduino pro mini (5v)
* GY-BME/P 280 (you have to change the I2C address)
* MPU6050
* Xbee S1 (with antenna)
* Xbee explorer
* 9V Battery

![pbc cansat](/img/cansat_pcb.jpg)

### Sensor data:
 * time since it is turned on
 * relative altitude
 * free fall state
 * temperature
 * atmosferic pressure
 * pitch
 * roll
 * yaw
 * acceleration in X
 * acceleration in Y
 * acceleration in Z

 Information is captured every 500 ms.

### Diagrams

#### Circuit diagram
![Circuit diagram made with fritzing](/img/circuit_diagram.png)

#### PCB layout
![pbc layout made with fritzing](/img/pcb_diagram.png)

#### External structure
![External structure made with blender](/img/structure_3D.png)

### Test
The test consist of powering the OBC to send data to the xbee reciver and printing the recived data in XCTU.
![sending data](/img/pcb_battery_9v.jpg)
![sending data](/img/recived_data_xctu.jpg)


## Licence 
MIT.