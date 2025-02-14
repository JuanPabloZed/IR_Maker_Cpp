C++ implementation of my python project [https://github.com/JuanPabloZed/IR_Maker](url) (deprecated).

Does the same thing as Voxengo's Deconvolver (https://www.voxengo.com/product/deconvolver/), but for free and with more features (IR visualisation, a nice interface...).

## TO INSTALL A NEWER VERSION
Go to your IR Maker installation folder (where you chose to install it with the setup executable, mostly in Program Files or Program Files (x86)), and run the unins0000.exe to uninstall previous version. Then, get the latest release on this github and run it !

## HOW TO MAKE AN IR
This application is based on the use of Angelo Farina's ESS method. To sum up, the ESS method consists in the following : 

1- Generate an exponential sine sweep (ESS) signal through IR Maker
 
2- Play the ESS through a speaker, a guitar cab, a room if you want its reverb, anything you want to characterize/capture
 
3- Record the response of the ESS through the system you want to capture
 
4- Launch IR Maker and let it guide you through the process !

 **Important note** : the software only supports 16, 24 & 32 bit **PCM** WAV files.

## IR MAKER FEATURES
*To get all the features, be sure to run the app with administrator rights (if you installed the application in Program Files)*
- Automatic output saving for fast workflow **AND** custom saving option
- Selectable IR length, in ms or samples
- Pre-ringing and tail cut option (can be disabled if you want to experiment and get the full raw output)
- 16, 24, 32 bit **PCM** output options
- Multiple IRs rendering at once (batch rendering) : simply select the files you want to process and generate all IRs at once
- Visual tools for a direct analysis of the IRs (waveform & spectrum, hidable if wanted, not available with batch rendering)
- Listen to the raw IRs or test them through an audio file of your choice (if longer than 10sec, will be truncated at 10sec)

**- SWEEP GENERATOR**
  - Custom beginning & ending frequencies (possible to make a decreasing sweep e.g. for a bass drop, but for IR making it *HAS* to be **increasing**)
  - Fade-in/fade-out option
  - Sample rates from 44,1kHz to 192kHz
  - Waveform visualisation

## ADVICE TO MAKE THE CLEANEST IRS
- Use the **same sample rate** for both the sweep *AND* the response
- Use a sweep that goes up to your **Nyquist frequency** (half of the sample rate) or your recorded file instead of stopping at 20kHz (use the **"full frequency range"** boxes to do it for you !)
- Use the **same bit depth** for both the sweep *AND* the response
- For a guitar/bass cabinet/speaker IR, use a **mono file** for the recorded file

## How to get IR Maker
Just get the latest release (Windows only for now) ! For now it might still be buggy so feel free to report any error/problem/bug, but it is proven to do its main job : make accurate IRs.

## Note :
If you want to work on your own version of this code, this works with the QT framework (6.6.3) in C++.


