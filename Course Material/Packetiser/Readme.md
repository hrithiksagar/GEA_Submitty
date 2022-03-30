# Packetizer
* Data packet format as shown in image
![Packect1](Packet1.png)
* Yellow is the Example data and Blue is the valid packet data

* The first 2 bytes are start bytes(0xFF) and last one is the stop byte(0x00).
* Length byte specifies the number of data bytes. 
* Assume that none of the data bytes or extra bytes in the given array are 0xFF or 0x00. 
* Write a function to search for a valid data packet in the passed Data array with at most 1 data packet and extra bytes and return whether a valid data packet exists or not. Also save the extracted valid data if present to the resultant array passed to the function.

* Example input and Extracted valid packets are shown in image
![Packect2](Packet2.png)