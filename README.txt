NZDIS Camera View demo

Copyright (C) 2011 NZDIS Team.
Copyright (C) 2011 Authors and contributors (SEE AUTORS.txt file)



 Intro
=======

This is an example of Android application using OpenCV for
feature tracking and face recognition.  This example has
been adopted from the OpenCV example application CVCamera.


 Prerequisites 
===============

* Android NDK (r5b or newer)
* Android SDK
* ant
* CMake
* android-cmake
* swig (and swig-java)
* OpenCV (and opencv-android) 




 Installing android-cmake
==============================

Follow the instructions:
http://code.google.com/p/android-cmake/




 Installing OpenCV
========================

Follow the instructions:
http://opencv.willowgarage.com/wiki/AndroidTrunk




 Environmental constants 
=========================

Best, place these into your .bash_profile or .bashrc


# Android SDK and NDK
ANDROID_NDK=path/to/android-ndk
ANDROID_SDK=path/to/android-sdk
export ANDROID_NDK ANDROID_SDK

PATH=$ANDROID_NDK:$ANDROID_SDK/platform-tools:$PATH
export PATH

ANDROID_CMAKE=path/to/android-cmake
export ANDROID_CMAKE
export ANDTOOLCHAIN=$ANDROID_CMAKE/toolchain/android.toolchain.cmake

alias android-cmake='cmake -DOpenCV_Dir=$OPENCV_ROOT/android/build -DCMAKE_TOOLCHAIN_FILE=$ANDTOOLCHAIN '

OPENCV_ROOT=path/to/opencv
OpenCV_DIR=$OPENCV_ROOT/android/build
AndroidOpenCV_DIR=$OPENCV_ROOT/android/android-opencv/build
export OPENCV_ROOT OpenCV_DIR AndroidOpenCV_DIR



 Building the demo
===================

from the main src directory, execute:

mkdir build
cd build
cmake ..
<if troubleshooting needed, see below>
make
cd ..
<plug your device into your PC/Mac via USB>
ant install 
<enjoy>



 CMake troubleshooting 
=======================

Not on all platform the android-cmake works. If it stops with 
an error saying install_name_tool not found, open the file CMakeCache.txt 
and set the value of variable:

CMAKE_INSTALL_NAME_TOOL:FILEPATH
as:
CMAKE_INSTALL_NAME_TOOL:FILEPATH=/usr/bin/install_name_tool

You will need to re-run 
   android-cmake .. 
again to get the Makefile generated properly.





 License
=========

Copyright 2011 NZDIS Team.
Copyright 2011 [see AUTHORS.txt]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
