# Useful links  
MegaCore:  
https://github.com/MCUdude/MegaCore  
pin mapping for ATmega2560:  
https://docs.arduino.cc/retired/hacking/hardware/PinMapping2560/  
call back of interrupt:  
https://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html  
# Description of the register logic  
<pre><code>struct Reg  
{
    object - The object that the register interacts with  
    addr - Register address  
    value - The value of the register  
}  

get(Reg* ) - The function of getting the register value  
set(Reg* ) - The function of setting a value to a register  
run(Reg* ) - A function that implements register logic
</code></pre>