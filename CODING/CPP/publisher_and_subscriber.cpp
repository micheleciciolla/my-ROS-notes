/*

THIS IS A SIMPLE NODE PUBLISHING AND SUBSCRIBING TO THE SAME
TOPIC

THIS IS USEFUL TO UNDERSTAND HOW TO USE SUBSCRIBERS,PUBLISHERS, CLASSES, DEBUG MSGS

*/


#include <ros/ros.h>
#include <std_msgs/Int8.h>

#include <string>

using namespace std;
class SimpleTest {

protected:
  // attributes of the SimpleTest object
  // node handler
  ros::NodeHandle nh;
  // the name of the topic you want to publish and suscriber to
  string topic_name = "my_topic";

public:
  // my_subscriber is an attribute of the object
  ros::Subscriber my_subscriber = nh.subscribe(topic_name, 10, myCallBack);
  // my_publisher is an attribute of the object
  ros::Publisher my_publisher = nh.advertise<std_msgs::Int8>(topic_name, 10);

  // constructor and desctructor
  SimpleTest(){};
  ~SimpleTest(){};

  // your reading callback when a new message on the topic is published
  void static myCallBack(const std_msgs::Int8::ConstPtr &msg) {
    // print on the screen as a info msg)
    ROS_INFO("I heard: [%i]", msg->data);
    // ros::shutdown();
  }
};

int main(int argc, char **argv) {

  // this allow you to see debug messages in green
  if (ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME,
                                     ros::console::levels::Debug)) {
    ros::console::notifyLoggerLevelsChanged();
  }

  string node_name = "SimpleTest";
  // create your node with a custom name
  ros::init(argc, argv, node_name);

  // build the object
  SimpleTest test1;

  // initialize the loop rate in Hz
  // Every second
  ros::Rate loop_rate(1);
  // your content to publish is not just
  // an int, but it has to respect
  // topic data
  std_msgs::Int8 content;
  content.data = 0;

  // the main process loop
  while (ros::ok()) {
    ROS_DEBUG("-----------");
    // until somebody press Ctrl+c or you call shutdown
    // publish on the topic
    test1.my_publisher.publish(content);
    ROS_INFO("I publish: [%i]", content.data);

    // update the system
    ros::spinOnce();
    loop_rate.sleep();
    // update the content to publish
    content.data++;
  }

  // end on the main
  return 0;
}