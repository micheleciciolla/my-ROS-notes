## Waitig time before doing a operation
Here i am using unistd
```
#include <unistd.h>
```
usage:
```
  int i = 0;
  while (i < req.duration)
    {
        vel_pub.publish(vel_msg);
        usleep(1000000); // We set 1000000 because the time is set in microseconds
        i++;
    }

```

## Looking for some file in the folders
```
find / -name <YourFileName>

## Include notes
When you want to include something, the header should be inside the /opt/ros/noetic/include/ folder
```
#include <actionlib/TestAction.h>

#include <actionlib/server/simple_action_server.h>

#include <actionlib_tutorials/FibonacciAction.h>

#include <ros/ros.h>
```
