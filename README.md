# Team Komodo 2017

This repository contains the code for Team Komodo's 2017 Robot code. Most of this information in also in Discord, but it's getting hard to find everything and there isn't a place for shared common knowledge.

This document is split into four main parts:

1. Getting Started
    - Setting Up Eclipse, WPILib and the ToolChain
    - Installing NI LabView and the FRC Update Suite
2. API Documentation
    - Architecture Overview
    - Summary of Commands
    - Summary of Subsystems
3. Building and Deploying
    - Running on the robot
    - Using the Driver Station
    - Using the Smart Dashboard
4. Troubleshooting
    - Common Problems
    - Contribution Guide

## Getting Started
There are some pretty specific steps you'll need to follow to get the code downloading, building, and running.
Team Komodo uses Eclipse as an IDE, with the WPILib Library and Eclipse plug-in for building and running. You'll also need to setup the FRC Toolchain, install NI LabView software, and its respective FRC Update.

Windows is required.

### Setting Up Eclipse
Eclipse as the complete package is the recommended configuration because it is fairly well integrated with WPILib's building and deployment processes. For deploying to the robot, eclipse and the WPILib is required, but we won't stop you from using your own text editor if you are up to the task of building in a separate environment. 

These instructions will pretain to the recommended configuration, using Eclipse for writing, building, and deploying to the robot.

#### 1. Install the JDK
Eclipse uses the JDK, so install this first.
You can get it [here](http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html)

#### 1. Install Eclipse
Use the Eclipse Installer (available [here](http://https://www.eclipse.org/downloads/))
and install the latest version of **Eclipse Neon** according to their provided instructions. Nothing too special here.

#### 2. The Workspace
Eclipse uses a Workspace system to keep projects isolated from each other. Each workspace can have different settings and none are shared across workspaces.
You'll want to create a new directory to isolate all of the robotics code from other potential projects.

<img src="http://i.imgur.com/Ica8Tlx.png" width="450px"/>

#### 3. Install the FRC Toolchain
WPILib and the Roborio interop using the FRC Toolchain. Install this next from [here](http://first.wpi.edu/FRC/roborio/toolchains/FRC-2017-Windows-Toolchain-4.9.3.msi)

DO NOT CHANGE THE INSTALL DIRECTORY (or remember where you put it...that works too).

#### 4. Install the WPILib Eclipse Plugin
Next, you'll need to install the WPILib eclipse plugin.

1. Open the Help->Install New Software menu
    - <img src="http://i.imgur.com/hT8qfIh.png" width="450px"/>
2. Click "Add" and enter:
    - Name: `FRC Plugins`
    - Location: `http://first.wpi.edu/FRC/roborio/release/eclipse/`
    - <img src="http://i.imgur.com/GkjtDcg.png" width="50%"/>
3. Click OK and select "FRC Plugins" from the "type or select a site" dropdown box
    - <img src="http://i.imgur.com/j0xXUDE.png" width=""/>
4. Expand WPILib Robot Develoment and check the box near 'Robot C++ Development'
    - <img src="http://i.imgur.com/IICh37m.png"/>
5. Click next and accept the license, and accept any warnings about installing unsigned software. 
6. **Reboot Eclipse**

#### 5. Set the Team Number and Environment Variables
1. Open Window -> Preferences, scroll to WPILib Preferences
2. Enter 4293 as the Team Number
    - <img src="http://i.imgur.com/EzD5HRX.png"/>
3. Expand C/C++ -> Build -> Environment in the same preferences window, and select "Add"
4. Fill in the following information:
    - Name: `PATH`
    - Value: `C:\frc\bin`
    - <img src="http://i.imgur.com/pYzA93R.png"/>

#### 6. Clone And Import
1. Using your Git client of choice, (we recommend Github Desktop for beginners), clone the repository into your Eclipse workspace. 
2. Then, import the project into your Eclipse workspace (File->Import Projects from File System)
3. Click directory, and browse to where you cloned your project
    - <img src="http://i.imgur.com/KLslKkB.png"/>
4. Click OK, uncheck "Robot-2017" and check "Robot-2017\Team Komodo 2017"
    - <img src="http://i.imgur.com/PYjjysT.png"/>
5. Click finish, and you're done with setup!

### Installing the NI LabView Software and the FRC Update Suite
#### 1. Download and install the LabView software from [here](http://www.ni.com/download/labview-for-frc-17.0/6489/en/)
(you'll need to ping Discord for the Serial Number)
#### 2. Download and install the FRC Update Suite from [here](http://www.ni.com/download/first-robotics-software-2015/5112/en/)

