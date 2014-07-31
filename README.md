STM32F3Discovery_SysTickPractice
================================

This is a repository for my SysTick practice on stm32f3 discovery.

The development environment was created by following this instruction.

(http://zaidpirwani.com/1160/stm32f3discovery-arm-gcc-environment-on-windows-part-1/)
* Download and install the STM32 ST-Link Utility
* Installing the GCC ARM Toolchain and GNU make
* Test to see if GCC ARM Toolchain is installed

arm-none-eabi-gcc  [ENTER]
RESULT
arm-none-eabi-gcc: fatal error: no input files
 compilation terminated.

make  [ENTER]
RESULT
make: *** No targets specified and no makefile found. Stop.


We will need gnu make to be able to run makefiles. Makefiles are scripts that allow us to invoke the gcc compiler efficiently. It is very handy for building multiple source projects.

Download the “GNU make for windows”  binaries and the dependencies zip files from http://gnuwin32.sourceforge.net/packages/make.htm.

We unzip them and locate the “make.exe” file from the binaries zip file; which should be in the bin directory of that zip file, and the “libiconv2.dll” and “libintl3.dll” files from the dependencies zip file which you will also find under the bin directory in that zipped file. Once you locate “make.exe”, “libiconv2.dll” and “libintl3.dll”, copy them into the same directory containing the compiler binaries.

Which should be look something like: “C:\Program Files (x86)\GNU Tools ARM Embedded\4.6 2012q2\bin”  This way the make command can also be invoked from anywhere on your C drive.

—– steps directly copied from http://hertaville.com/2012/05/28/gcc-arm-toolchain-stm32f0discovery/


The project template can be found at this repository.
https://github.com/mblythe86/stm32f3-discovery-basic-template.git

Make sure that makefile in the above template is for unix only, 
so you need to modify it for windows.

This repository has makefile for windows.
