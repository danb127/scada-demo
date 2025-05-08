
2025-03-17 15:19

Status:

Tags: [[CAN]] [[LIN]] [[ECU]]

# Communication Interfaces
## Introduction
- Usage of more and more electronics in Modern Motor Vehicles
- Usage of dedicated "Electronics Control Units" for each individual functionality
- The need for  information exchange between various ECUs and also to share some sensors in common.
![[Pasted image 20250317152716.png]]
### The communication between ECUs
- By point to point interconnection
![[Pasted image 20250317152846.png]]
- Disadvantages:
	- Unreliability
	- More material cost
	- More production time
### The Solution
- Adopting bus communication instead of point to point
- Adopting a protocol to transmit and receive information through the bus
- Well-established Bus Systems 
	- CAN
	- LIN
	- FlexRay
![[Pasted image 20250317153130.png]]
### LIN - [[Local Interconnect Network]]
- low-cost network with one master control unit and one or more slave control units
- used to integrate intelligent sensor devices or actuators
- The maximum communication speed is 19200 baud
![[Pasted image 20250317164338.png]]
- The [[LIN]] master initiates communication by sending the "[[Header]]". The "[[Data Fields]]" are sent by a LIN master or a LIN slave. Only one unit will respond to a given header.
- The [[slave]] nodes cannot initiate communication: they only respond if triggered by specific identifier fields
### [[FlexRay]]
- Designed to provide high-speed deterministic distributed control for advanced automotive applications
- dual-channel architecture offers system-wide redundancy
- High data rates (Up to 20 Mbit/s)
- Time Division Multiple Access (TDMA) protocol
![[Pasted image 20250317170414.png]]
### [[CAN]] - [[Controller Area Network]]
- CAN is a multi-master broadcast serial bust standard for connecting ECUs
- Unlimited number of bus nodes
- Each node is able to send and receive messages ([[frames]])
- Carrier Sense Multiple Access / Collision Avoidance (CSMA/CA) protocol
- Multiple error detecting mechanisms
- Bitrates up to 1 Mbit/s
![[Pasted image 20250317170708.png]]
## CAN History
- Developed by Bosch in the mid-1980s (1983)
- Officially realesed in 1986 at the Society of Automotive Engineers (SAE) congress in Detroit
- 1987 first can controller chip was introduced by Intel and Philips
- 1991 the first CAN 2.0 specification was released by Bosch
## BUS Levels
- A bit representative either as logic "0" to be dominant or "1" to be recessive.
- Principle of the bitwise bus arbitration: When multiple transmitters send their respective states onto the bus at the same time, the dominant state must always win over the recessive state
![[Pasted image 20250317171538.png]]
## CAN Frames
### Data frame
![[Pasted image 20250317171706.png]]

| Data Frame Format                     |        |                |                |
| ------------------------------------- | ------ | -------------- | -------------- |
| Field                                 | Length | Std (Standard) | Ext (Extended) |
| [[Start of Frame]]                    | 1      | Yes, Must be 0 | Yes, Must be 0 |
| [[Identifier]] A                      | 11     | Yes            | Yes            |
| [[Substitute Remote Request (SRR)]]   | 1      | No             | Yes, Must be 1 |
| [[Identifier Extension Bit (IDE)]]    | 1      | Yes, Must be 0 | Yes, Must be 1 |
| Identifier B                          | 18     | No             | Yes            |
| [[Remote Transmission Request (RTR)]] | 1      | Yes, Must be 0 | Yes, Must be 0 |
| [[Reserved bit]] r0                   | 1      | Yes            | Yes            |
| Reserved bit r1                       | 1      | No             | Yes            |
| [[Data Length Code (DLC)]]            | 4      | Yes            | Yes            |
| [[Data Field]]                        | 0-64   | Yes            | Yes            |
| [[CRC]]                               | 15     | Yes            | Yes            |
| [[CRC Delimiter]]                     | 1      | Yes, Must be 1 | Yes, Must be 1 |
| [[ACK Slot]]                          | 1      | Yes            | Yes            |
| [[ACK Delimiter]]                     | 1      | Yes, Must be 1 | Yes, Must be 1 |
| End-of-frame (EOF)                    | 7      | Yes, Must be 1 | Yes, Must be 1 |

- **Arbitration**
	- Because dominant wins over recessive, low-values identifiers always have higher priority to access the bus
	![[Pasted image 20250317174418.png]]
- **Advantages**
	- No collisions 
	- Transmission of highest priority message without [[latency]] (latency is the time between the request for data and the data being sent))
- **Identifier**
	- Simultaneous usage of Standard and Extended identifiers is allowed
- **Control Field**
	- Data Length Code (DLC) should be in range of binary values 0000 to 1000 (0 to 8 bytes)
	- IDE determines 11-bit or 29-bit identifier
- **Cycle Redundancy Check (CRC)**
	- [[CRC generator polynomial]] is x^15 + x^14 + x^10 + x^8 + x^7 + x^4 + x^3 + 1
- **Acknowledge Field**
	- Every CAN node that receives any error-free transfer must send a dominant bit during the ACK slot
	- If no one receives the message correctly, the ACK slot stays recessive
	- If one or more receivers indicate acknowledgment, all receivers that have declined to acknowledge will indicate their frame rejection by sending an active [[error flag]]. All receivers that originally acknowledged the message and a message transmitter will now detect a dominant bit in EOF (expected to be recessive) and subsequently send an active error flag. Transmitter will automatically re-attempt sending the same message
	- When CAN nodes disagree over the message transfer
		- ACK Field: One or more nodes acknowledge the message (vote YES)
		- Active Error Flag: One or more nodes disagree and send an active error flag (vote NO)
		- Active Error Flag: Earlier acknowledgers (YES voters) and the transmitter must disagree as well and also send an active error flag (vote NO)
        ![[Pasted image 20250317175939.png]]

### Error Frame
- Consists of two fields
	- [[Error Flags]] - 6 - 12 dominant/recessive bits contributed from different nodes
		- Two types of error flags
			- [[Active Error Flag]] - 6 dominant bits transmitted by a node in "error active" state, detecting an error on the network. Nodes in "error active" state, detecting an Active Error flag on the network  will also transmit an Active Error flag.
			- [[Passive Error Flag]] - 6 recessive bits transmitted by a node in "error passive" state, detecting an active error frame on the network.
	- [[Error Delimiter]] - 8 recessive bits
![[Pasted image 20250318133201.png]]
### Overload Frame
- Delay requested by the (slow) receiver, meaning it cannot receive the next message yet
- [[Overload frame]] always starts within the Intermission slot of previous frame
- Frame format equal to the Error Frame






# References
