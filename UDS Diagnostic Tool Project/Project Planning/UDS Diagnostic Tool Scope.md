# UDS Diagnostic Tool Scope 
- Status: 🟢 Planned | 🟡 In Progress | 🔴 Stalled  
- Deadline: [[YYYY-MM-DD]]  
- Related Notes:  [[RDU Device - RDU Functionality]]

## NEXT STEPS  
- [ ]  Similar to ECA tool 
- [ ]  Third party developed
- [ ] Password calculation, logic to gain secuirty to ecus
- [ ] Getting access to ecu's
- [ ] Sending universal diagnostic commands
- [ ] Ecu responds back, read response if comes back negative, send again
- [ ] diagnostic specs and pass word calcs documentation
- [ ] one of the executables in the tool so you can walk up to vehicle and plug it in.
- [ ] quick tool that someone could 
- [ ] Any documentation on eca itself?
	- [ ] ebs specs and highlighted what they wanted
- [ ] Microcontroller based solution (9 pin on one-side)
- [ ] 3d print enclosure, don't care how big it is just care about it functionality
- [ ] Plugged in tool to power, base to pc, configured over bluetooth previously
- [ ] Want this to be completely open software
- [ ] once it goes to the plant it will stay, dedicated to specific work station
- [ ] all functions written and configure what is needed and send 
- [ ] sending 1939 can commands (diag can commands) for pass calc send command get response, based on data putting into formula, then send password (all 1939 can commands), pass calc wpuld be same between all the tools, and the can diagnostics would be the flexible portion (very similar) just different services inside command. 
- [ ] E8 docs (UDT commands)
- [ ] ping ecu for diagnostics
- [ ] e4 no need for pass calc
- [ ] ebs need pass calc
- [ ] e8 pass calc
## 3/12 Meeting
- [ ] The UDS device should first do password calculation (hardcoded in the firmware)
- [ ] The next thing it should do is open up a diagnostic session (also hardcoded in the firmware)
- [ ] This should then look for routine ID's and based on which one, eventually will have functions specified on the routine ID.
	- [ ] This should be reprogrammable or selection menu on the LCD screen to determine which routine id and service they are looking for.
	- [ ] Should be open software still
- [ ] Dedicated to specific work station in plant
- [ ] Who is it for?
- [ ] Purpose of it?
- [ ] System Design?
- [ ] CAN only interface?
- [ ] Documentations needed
	- [ ] UDS specs - for routine id's?
	- [ ] SAE J1939 overview - the j1939 CAN-based protocol
	- [ ] ABS E8 CAN Matrix - E8 CAN matrix

## PROGRESS LOG  
- [[2025-02-24]]: Started project  
- [[2025-02-25]]: [[RDU Device - RDU Functionality]]
- [[2025-02-28]]: [[RDU Device - RDU Setup]] 
