# Scripts

The script folder hold differents scripts, such as : 

- **ip.py** : The LiteX IP instance python file. The instance function must be under the the instantiate function. If non applicable, return 0 and print in console.
- **sources.tcl** : The script to list all the sources for the IP. This must include all secondary IPs and others buses.
- **synth.tcl** : A basic synthesis flow to try the IP for real.
- **constraints.tcl** : The constraint file, to add the correct constraints to the project.

> [!NOTE]
> The TCL scripts MUST handle arguments such as --quartus --vivado --genus ... And run the RIGHT commands with the right tools.
> If ommited, the script MUST NOT run anything excepted an error and a message.