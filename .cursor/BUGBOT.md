# Bugbot rules for F Prime

1. Ground-reachable input (command args, parameters, uplinked files, CFDP PDUs) must never reach `FW_ASSERT`. Reject with `VALIDATION_ERROR` and a warning event.
2. Flag silent truncation wherever a string arriving with a larger declared size is stored in a smaller type, on port arguments as well as command arguments. Example: a `FileNameStringSize` (240-byte) port argument copied into `Fw::CmdStringArg` (`FW_CMD_STRING_MAX_SIZE`, 40 bytes). Include derived names such as `+ ".CRC32"`.
3. Every new rejection path needs a unit test that sends the bad input and asserts the command response and the event.
