# AVR-HeaderFiles
Custom made HeaderFiles for programming AVR using C and CodeVisionAVR

#### Why is this repository created ?

Since I'm going to AVR class I found myself interested in making HeaderFiles in order to easier the tasks 
And I'd like to share them with other people.

#### What program do I need to use HeaderFiles in ?

I use CodeVisionAVR myself But I think they should work in other C Compilers too, However I've not tested that.

If you tested files with other compilers let me know the result

#### Under which license are the header files ?

Obviously they are under GPLv3 or any later version of GPL .

#### How can I use header files?

Simply put both .h and .c file(s) of the header(s) on the directory of your project 
then in your program include .h file(s) like below

\#include "HeaderFile.h"

After that you will need to link the .c file(s) or in my case you need to add the file(s) 
at:

Project --> Configure --> Input Files
