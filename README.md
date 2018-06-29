# EDD-Wall-Project

  This was the code I created for my Engineering Design and Development class during my senior year of high school. My groups project was a sheet of fiberglass that would unroll over the side of a house to protect the siding and windows from hail damage. The unrolling process was automated and controlled by a motor connected to a raspberry pi 2. This was the code that was used to control the deployment of the sheet. 
  It half works; I gave up on trying to get the button to work and just activated the sheet from the terminal. The code to control the encoder does not work when powered by the motor. The code is a complete mess overall. My group did get a good prototype grade anyways, and that's all I care about.
  If you really want to use all or part of this mess, then it depends on the PiGPIO library. The pin numbers to which everything connects to can be found in pin.h and uses Broadcom's numbering system.
