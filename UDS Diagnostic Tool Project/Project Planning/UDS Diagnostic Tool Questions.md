
2025-03-05 14:15

Status:

Tags:

# UDS Diagnostic Tool Questions
## Key Questions
- This tool will be used in the field, should i expect harsh environments (for durability concern), still plan to used 3D printed design
- For Data retention, is long-term data storage needed or primarily short-term analysis
- Is there a component I could borrow with documentation for development and prototyping?
- I have to confirm OpenSTLinux has the necessary drivers for CAN peripherals but I believe this can be achieved through something called a device tree
- May need to use RTOS on the M4 while using Linux on A7 core for the UI
- For the LCD, need to determine functionality, such as do you guys want to display decoded diagnostic data, status indicators, or allow user interactions (via touchscreen)
- Do you guys want remote access to this device via SSH and should the tool log messages
- This woud determine a rich user experience while keeping the low-level CAN operations efficient.
- Remind me of what you want the functionality to be for the engineers who use this device
	- Program and change and send UDS command and why
	- Once its disconnected from laptop, should be blackbox
	- Connect to a deutsch connector to a vehicle
	- Voltage can h and can l already there,
	- Key is to be able to reprogram it
		- UDS commands ar ejust 1939 messages
		- First thing is password calc (hardcode)
		- open up diag session (hardcode)
		- Then looking for routine id
			- different routines 
		- calibrate steering sensor command make sure it works
		- might want to clear fault codes in the future
- Ask if I can be sent something to interface mcu with
	- Raspberry pi os, raspberry pi, can transceiver, ecu
![[Pasted image 20250503134027.png]]
- have up in a week then start ap, then raspberry pi os to yocto
- system diagram
- set up gantt chart timeline
# References
