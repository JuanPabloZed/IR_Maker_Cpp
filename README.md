C++ implementation of my python project [https://github.com/JuanPabloZed/IR_Maker](url).

Voxengo's Deconvolver utility, but free and with more features (IR visualisation, a decent UI...).




## HOW TO MAKE AN IR
This application is based on the use of Angelo Farina's ESS method. To sum up, the ESS method consists in the following : 

1- Generate an  exponential sine sweep (ESS) signal (can be done with IR Maker)
 
2- Play the ESS through a speaker, a guitar cab, anything you want to characterize/capture
 
3- Record the response of the ESS through the system you want to capture
 
4- Turn on IR Maker and let it guide you through the process !

 **Important note** : the application only supports 16, 24 & 32 bit *PCM* WAV files.

Multichannel compatibility is in the works too, stay tuned !

## How to get IR Maker
Just get the latest release (Windows only for now) ! For now it might still be buggy so feel free to report any error/problem/bug, but it is proven to do it's main job : make accurate IRs.

If you want to work on your own version of this code, this works with the QT framework in C++ so you won't be able to run the app without QT libraries.


