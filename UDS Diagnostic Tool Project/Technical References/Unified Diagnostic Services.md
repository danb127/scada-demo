
2025-03-12 12:23

Status:

Tags: [[Documentation]] [[ZF]] [[UDS]] [[Project]]

# Unified Diagnostic Services
## Terms

| **Mnemonic** | **Description**                   |
| ------------ | --------------------------------- |
| [[DID]]      | [[Data Identifier]] -             |
| [[DPL]]      | [[Diagnostic Protection Level]] - |
| [[DST]]      | [[Diagnostic Session Type]]       |
| [[ECU]]      | [[Electronical Controlled Unit]]  |
| [[NRC]]      | [[Negative Response Code]] -      |
| [[RID]]      | [[Routine Identifier]] -          |
| [[RT]]       | [[Reset Type]] -                  |
| [[SAT]]      | [[Security Access Type]] -        |
| [[SID]]      | [[Service Identifier]] -          |
## Definitions
**[[Fingerprints]]**:
- Used to identify who has changed data in the non volatile memory and when.
- Sent with the service [[WriteDataByIdentifier]] to the ECU.
- An ECU can support more than one fingerprint
- Size, format, number of fingerprints and the [[DataIdentifier]] are described in chapter 7

- If a diagnostic service requires a fingerprint, and the tester has not sent a fingerprint, the service is rejected with [[NegativeResponseCode]] 22h ([[ConditionsNotCorrect]])
- The fingerprint shall be sent to the ECU after [[diagnosticSessionControl-Service]] and the [[securityAccess-Service]].
- If a new session is started, the fingerprint must be sent again.
- The temporary fingerprint in the volatile memory cannot be read. If the tester wants to read a fingerprint the fingerprint must be saved in the non-volatile memory

**Word / Dword Parameters**:
- Word parameters are 16-bit parameters
- Dword parameters are 32-bit parameters
- If not otherwise specified then the highbyte is transmitted first.
- Word / Dword parameters are indicated in some tables in the table column 'type'.

## Communication Parameters
### CAN Interface

| **ParameterName**      | **Value**     | **Description**                                                                                                                       |
| ---------------------- | ------------- | ------------------------------------------------------------------------------------------------------------------------------------- |
| S3-server (ECU server) | 5000 ms (5 s) | Time for server to keep a diagnostic session other than the defaultSession active while not receiving any diagnostic request message. |
| P2                     | 50 ms         | Max time between client request and any server response                                                                               |
| P2*                    | 5000 ms       | Max time between negative response with response code 78h and next server response                                                    |
|                        |               |                                                                                                                                       |








# References
[[UDS]]