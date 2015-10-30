# Tampere Hacklab doorbell
Arduino firmware for doorbell located in Tampere Hacklab.
Doorbell is integrated in door access system.

# Hardware
Custom board with build in Funduino Mini Pro arduino clone.
L293D H-Bridge controller IC is connected to arduino by three control lines (Enable, High Bell, Low Bell).
Button is connected trough 24V relay, and should be connected between +24V and SW input terminals.
Two tone bell ringer from old telephone is connected to L293D with screw terminals. 
Hammer will strike corresponding bell when enable and bell control lines are pulled high.

# Software
Arduino scetch to control bell ringing supplied in this repository

# Installing
Connect Funduino Mini Pro with micro usb cable to computer. Open source in Arduino software,
select Arduino Leonardo from board menu and corresponding port for it. Use Arduino software
to compile and upload software in doorbell.

# Runing
Plug doorbell in electricity outlet, press button located outside of Tampere Hacklab door.
