## **Current Sensor**

### **What is the Current Sensor for?**

The current sensor is designed to provide feedback via mqtt status messages for devices that have
no such ability.
For example, if the television is controlled by an mqtt relay, there is no status message telling the 
controller if the TV is on or off in the first place.

### **How to use it**
There is a sense wire on the PCB. This sense wire is to be placed around or adjacent to the "live" side
of the power cable to the device.  When properly placed, the LED on the board will turn on or off as the
power to the device is turned on or off.

##**The remainder is for appearance experiments only**

```Arduino
#include <EEPROM.h>

void setup(){

}

void loop(){

}

```

The library provides a global variable named `EEPROM`, you use this variable to access the library functions. The methods provided in the EEPROM class are listed below.

You can view all the examples [here](examples/).

### **Library functions**

#### **`EEPROM.read( address )`** [[_example_]](examples/eeprom_read/eeprom_read.ino)

This function allows you to read a single byte of data from the eeprom.
Its only parameter is an `int` which should be set to the address you wish to read.

The function returns an `unsigned char` containing the value read.

#### **`EEPROM.write( address, value )`** [[_example_]](examples/eeprom_write/eeprom_write.ino)

The `write()` method allows you to write a single byte of data to the EEPROM.
Two parameters are needed. The first is an `int` containing the address that is to be written, and the second is a the data to be written (`unsigned char`).

This function does not return any value.

#### **`EEPROM.update( address, value )`** [[_example_]](examples/eeprom_update/eeprom_update.ino)

This function is similar to `EEPROM.write()` however this method will only write data if the cell contents pointed to by `address` is different to `value`. This method can help prevent unnecessary wear on the EEPROM cells.

This function does not return any value.

#### **`EEPROM.get( address, object )`** [[_example_]](examples/eeprom_get/eeprom_get.ino)

This function will retrieve any object from the EEPROM.
Two parameters are needed to call this function. The first is an `int` containing the address that is to be written, and the second is the object you would like to read.

This function returns a reference to the `object` passed in. It does not need to be used and is only returned for conveience.

#### **`EEPROM.put( address, object )`** [[_example_]](examples/eeprom_put/eeprom_put.ino)

This function will write any object to the EEPROM.
Two parameters are needed to call this function. The first is an `int` containing the address that is to be written, and the second is the object you would like to write.

This function uses the _update_ method to write its data, and therefore only rewrites changed cells.

This function returns a reference to the `object` passed in. It does not need to be used and is only returned for conveience.

#### **Subscript operator: `EEPROM[address]`** [[_example_]](examples/eeprom_crc/eeprom_crc.ino)

This operator allows using the identifier `EEPROM` like an array.  
EEPROM cells can be read _and_ **_written_** directly using this method.

This operator returns a reference to the EEPROM cell.

```c++
unsigned char val;

//Read first EEPROM cell.
val = EEPROM[ 0 ];

//Write first EEPROM cell.
EEPROM[ 0 ] = val;

//Compare contents
if( val == EEPROM[ 0 ] ){
  //Do something...
}
```

#### **`EEPROM.length()`**

This function returns an `unsigned int` containing the number of cells in the EEPROM.

---

### **Advanced features**

This library uses a component based approach to provide its functionality. This means you can also use these components to design a customized approach. Two background classes are available for use: `EERef` & `EEPtr`.

#### **`EERef` class**

This object references an EEPROM cell.
Its purpose is to mimic a typical byte of RAM, however its storage is the EEPROM.
This class has an overhead of two bytes, similar to storing a pointer to an EEPROM cell.

```C++
EERef ref = EEPROM[ 10 ]; //Create a reference to 11th cell.

ref = 4; //write to EEPROM cell.

unsigned char val = ref; //Read referenced cell.
```

#### **`EEPtr` class**

This object is a bidirectional pointer to EEPROM cells represented by `EERef` objects.
Just like a normal pointer type, this type can be dereferenced and repositioned using 
increment/decrement operators.

```C++
EEPtr ptr = 10; //Create a pointer to 11th cell.

*ptr = 4; //dereference and write to EEPROM cell.

unsigned char val = *ptr; //dereference and read.

ptr++; //Move to next EEPROM cell.
```

#### **`EEPROM.begin()`**

This function returns an `EEPtr` pointing to the first cell in the EEPROM.  
This is useful for STL objects, custom iteration and C++11 style ranged for loops.

#### **`EEPROM.end()`**

This function returns an `EEPtr` pointing at the location after the last EEPROM cell.  
Used with `begin()` to provide custom iteration.

**Note:** The `EEPtr` returned is invalid as it is out of range. Infact the hardware causes wrapping of the address (overflow) and `EEPROM.end()` actually references the first EEPROM cell.
