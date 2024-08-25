C++ implementation of my python project [https://github.com/JuanPabloZed/IR_Maker](url) (deprecated).

Does the same thing as Voxengo's Deconvolver (https://www.voxengo.com/product/deconvolver/), but for free and with more features (IR visualisation, a nice interface...).

Contact : nathan.zwahlen70@gmail.com

## TO INSTALL A NEWER VERSION
Go to the IR Maker folder, and run the unins0000.exe to uninstall previous version. Then, get the latest release on this github and run it !

## HOW TO MAKE AN IR
This application is based on the use of Angelo Farina's ESS method. To sum up, the ESS method consists in the following : 

1- Generate an exponential sine sweep (ESS) signal through IR Maker
 
2- Play the ESS through a speaker, a guitar cab, a room if you want its reverb, anything you want to characterize/capture
 
3- Record the response of the ESS through the system you want to capture
 
4- Launch IR Maker and let it guide you through the process !

 **Important note** : the software only supports 16, 24 & 32 bit **PCM** WAV files.

## IR MAKER FEATURES
*To get all the features, be sure to run the app as administrator if you're not logged in with an administrator session*
- Automatic output saving for fast workflow **AND** custom saving option
- Custom the IR's length, in ms or samples
- Pre-ringing cut option (can be disabled if you want to experiment and get the full raw output)
- 16, 24, 32 bit PCM output options
- Visual tools for a direct analysis of the IRs (waveform, spectrum, hidable if wanted)
- Hear the IRs directly or through an audio file of your choice (if longer than 10sec, will be truncated at 10sec)
- Multiple IRs rendering at once (batch rendering) : simply select the files you want to process 

**- SWEEP GENERATOR**
  - Customable beginning & ending frequencies (possible to make a decreasing sweep e.g. for a bass drop, but for IR making it *HAS* to be **increasing**)
  - Fade-in/fade-out option
  - Sample rates from 44,1kHz to 192kHz
  - Waveform visualisation

## ADVICE TO MAKE THE CLEANEST IRS
- Use a sweep that goes up to your **Nyquist frequency**, *i.e.* half of the sample rate, instead of stopping at 20kHz (use the **"full frequency range"** boxes to do it for you !)
- Use the **same sample rate** for both the sweep *AND* the response
- Use the **same bit depth** for both the sweep *AND* the response
- For a cab IR, use a **mono file** for the response

## How to get IR Maker
Just get the latest release (Windows only for now) ! For now it might still be buggy so feel free to report any error/problem/bug, but it is proven to do its main job : make accurate IRs.

## Note :
If you want to work on your own version of this code, this works with the QT framework in C++ so you won't be able to run the app without QT libraries.


