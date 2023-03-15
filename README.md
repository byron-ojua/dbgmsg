# dbgmsg
Tired of adding and removing debug print statements? This tool is for you. Debug message utility is a tool I developed that allows users to easily add debug messages in code and enable and disable them in groups. Forget commenting out messages; just disable them with one line of code!

## Functions
Reference below to see how to use each function. See examples.c for library example.

### Create a Debug Messenger
`struct debugMessenger debugMessenger(char names[][50], int numRows);`
`debugMessenger()` creates a debugMessenger struct object using an array of input group names. Struct instance is referenced in all other functions.

### Set Output Stream
`void dbgSetOutput(struct debugMessenger* dbgMsger, FILE* output);`
`dbgSetOutput()` will redirect where print commands are outputted.

### Print a Debug Message
`void prtDbgMsg(char *msg, FILE* out);`
`prtDbgMsg()` is similar to `fprintf()`, and prints a message to inputed file stream.

### Print a Debug Message with assigned Group
`void prtDbgMsgGp(char *msg, int group, struct debugMessenger* dbgMsger);`
`prtDbgMsgGp()` is the primary function of this utility. A message is assigned to a group, and if a group is enabled by the time the line of code is run, it will print the message. Otherwise, the line will not print and move to the following code. The one exception is if the OVERRIDE group is enabled, it will print regardless of individual group status.

### Enable debug group
`void enblDbgGp(int group, struct debugMessenger* dbgMsger);`
When run, `enblDbgGp()` will enable a debug group, and any messages assigned to that group will be printed. 

### Disable debug group
`void dsblDbgGp(int group, struct debugMessenger* dbgMsger);`
When run, `dsblDbgGp()` will disable a debug group, and any messages assigned to that group will NOT print. 

### Enable override
`void enblDbgOride(struct debugMessenger* dbgMsger);`
`enblDbgOride()` enables the override command, which means all debug comments after called will run, regardless if an individual group is enabled.

### Enable override
`void dsblDbgOride(struct debugMessenger* dbgMsger);`
`dsblDbgOride()` disables the override command, which means all debug comments will only run if their individual group is enabled.