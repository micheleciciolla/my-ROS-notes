# Linux tips and tricks

## Looking for some file in the folders
```
find / -name <YourFileName>
```
## Include notes
When you want to include something, the header should be inside the /opt/ros/noetic/include/ folder
```
#include <actionlib/TestAction.h>
#include <actionlib/server/simple_action_server.h>
#include <actionlib_tutorials/FibonacciAction.h>
#include <ros/ros.h>
```
