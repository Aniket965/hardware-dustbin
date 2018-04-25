# hardware-dustbin
> **Tested** on ardiuno uno and mega

----

This repo contains the code for smart dustbins
 > this require following sensors and hardware
 - 2 ultra sonic sensors
 - 2 servo motor
 - ardiuno Uno
 - switch
 
 ----
 
## 🏃 Start
> Tested on Ardiuno uno
- connect trigger pin and echo pin of first ultra sound sensor to 2 and 4 respectively and vcc to 5v, gnd to gnd
- connect trigger pin and echo pin of second ultra sound sensor to 5 and 6 respectively and vcc to 5v, gnd to gnd
- connect servo for first dustbin servo Signal wire to pin number 9,second dustbins to pin number 8 and vcc to 5v and gnd to gnd.
- connect switch to pin number 12 , one end to vcc with 10k ohm resistor in between
- upload the code to ardiuno
- run ``` python dustbin.py ```

----

## 🙌🏻 Next Step
- run [App](https://github.com/Aniket965/rn-dustbin)
