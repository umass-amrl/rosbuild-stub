# rosbuild-stub
Boilerplate for C++ ROSNode to streamline the build system. Just type make.

## Getting started

0. Install ROS.
1. Do only once: Clone this repo.
2. Do only once: Run `./add-to-rospath.sh` to add the repo to the ROS packages path.
3. Run `make`. 
4. Work on your code rather than the build system.
4. No, *DO NOT* run cmake, rosmake rosbuild, catkin_build or anything.

## Customization
You might want to change the ROS package name, disable msg / srv creation, and/or add your own executables.
For this, look at `manifest.xml`, and `CMakeLists.txt`.
