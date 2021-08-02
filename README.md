## Lesson 1 : Editing the CMAKELIST file for C++ executable (example using simple.cpp)
Here i am using a variable name to which i give the name of the .cpp executable simple_service_server file. 
```
set(name "simple_service_server")
add_executable(${name} src/${name}.cpp)
add_dependencies(${name} ${${name}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${name}
   ${catkin_LIBRARIES}
 )

```
Add such lines for each .cpp files in the /src folder. It will generate a binary simple inside devel/lib.


## Lesson 2 : Using custom message type Age.msg example

### Prepare CMakeLists.txt and package.xml for custom message compilation 

1) Create a directory inside your package named msg
```
roscd <package_name>
mkdir msg
```

2) create a file named <your-message-name>.msg inside this msg folder indicating type and name of the fields:
```
float32 years
float32 months
float32 days
```

3) Edit the CMAKELIST.txt file
```
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

add_message_files(
  FILES
  Age.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp std_msgs message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
```
4) Modify package.xml adding three lines
```
<build_depend>message_generation</build_depend>

<build_export_depend>message_runtime</build_export_depend>
<exec_depend>message_runtime</exec_depend>
```
### Test and use it inside a .cpp script

5) Compile the package

6) Check if everything went fine 
```
rosmsg show Age
```
7) Edit again CMAKELIST.txt to include your .cpp file using such custom message type (example using publish_age.cpp inside topic_subscriber_pkg package)
```
add_executable(publish_age src/publish_age.cpp)
add_dependencies(publish_age ${publish_age_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(publish_age
   ${catkin_LIBRARIES}
 )
add_dependencies(publish_age topic_subscriber_pkg_generate_messages_cpp)
```
8) Include in publish_age.cpp
```
#include <topic_subscriber_pkg/Age.h> 
``` 

9) Usage

```
// declare object
topic_subscriber_pkg::Age age;

// add fields value 
age.years = 45;
  age.months = 30;
  age.days = 28322;

// publish 
ros::Publisher pub =
      nh.advertise<topic_subscriber_pkg::Age>(topic_name, 1000);
  ros::Rate loop_rate(2);

  while (ros::ok()) {
    pub.publish(age);
    ros::spinOnce();
    loop_rate.sleep();
  }
```

10) Add to the launcher
```
<launch>
    <!-- Package launch file -->
    <node pkg="topic_subscriber_pkg" type="age_publisher" name="age_publisher"  output="screen">
    </node>
</launch>
```
11) Build the package using catkin build topic_subscriber_pkg






