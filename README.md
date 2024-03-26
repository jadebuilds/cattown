# cattown
Code for Cat Town Kickstarter project

## Architecture

Cat Town uses two processors:

* The microcontroller, "Jerry", handles fast real-time motion platform controls, allowing the platform to run fast, smooth, and continuous. Cat Town uses an ESP32 Arduino Nano.
* The embedded Linux controller, "Tom", does real-time data processing to make the mice responsive and clever. Cat Town uses a Raspberry Pi Zero 2 W.

Each processor has its own directory containing a README that discusses how the processor is architected.


## Glossary

"kahu": A Hawaiian name for a human who cares for a pet, with connotations of "guardian, protector, steward, beloved attendant", and others. 
        "User" is too stale, and I don't want to call us "owners". See also: https://www.instagram.com/reel/C2NlrKoi5-h/