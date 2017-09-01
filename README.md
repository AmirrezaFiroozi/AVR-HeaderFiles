# AVR-HeaderFiles
Custom made HeaderFiles for programming AVR using C and CodeVisionAVR

#Why is this repository created ?
Since I'm going to AVR class I found myself interested in making HeaderFiles in order to easier the tasks 
And I'd like to share them with anyone.

#What program do I need to use HeaderFiles in ?
I use CodeVisionAVR myself But I think they should work in other C Compilers too, However I've not tested.
If you test files with other compilers let me know the result

#Under which license are the header files ?
Obviously they are under GPLv3 or any later version of GPL .

#How can I use header files?
Simply put both .h and .c file of the header on the directory of your project 
then in your program include .h files like below
\#include "HeaderFile.h"
After that you will need to link the .c file or in my case you need to add the file 
at: Project --> Configure --> Input Files
