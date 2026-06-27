# ip-template

This repo is an archived template, used to build further IPs. This repo does not store any usefull code.

## IP structure

To ensure a coherency all along the project, the IP must follow a standardized structure. Here the different folders :

- doc/ The documentation folder
  - assets/ The images and other ressources
- rtl/ The hardware sources.
  - ip/ All IP that are used within the project.
  - buses/ All standard interfaces used to interract with other IP.
  - modules/ All sources files that does not interract outside this IP.
- scripts/ All software scripts to run the different steps. Essentially targetted to the physical P&R steps.
- tb/ All the testbench sources to run.
  - framework/ All the different frameworks to make the testing easier. Fully optionnal.
