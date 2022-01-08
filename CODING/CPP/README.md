# Cpp tips and tricks

## Running through the list of nodes via code

To get the list of available nodes this is the function to call
```
ros::master::getNodes(nodes)
```
which saves the list of nodes into a particular propetary data structure `ros::V_string nodes`, which is a **std::vector<<std::string>>** at the end, you need to define before.

In order to `find` if a node `is not inside` this list i use the `find` function like this:

```
if (std::find(nodes.begin(), nodes.end(), desired_node) == nodes.end())
```
where desired_node is string variable.

____
## Running through the list of available topics

Same way as done before, the function to call is from the roscpp API `getTopics`
```
ros::master::V_TopicInfo master_topics;
ros::master::getTopics(master_topics);
```

In order to run in this list of topics this might be an approach:

```
for (ros::master::V_TopicInfo::iterator it = master_topics.begin(); it != master_topics.end(); it++)
{
    std::cout << std::endl;
    const ros::master::TopicInfo &info = *it;
    std::cout << "topic_" << it - master_topics.begin() << ": " << info.name << std::endl;
    std::cout << "topic_" << it - master_topics.begin() << ": " << info.datatype << std::endl;
}
```
The way it's done is using an iterator which as to be the same type of the data structure (ros::master::V_TopicInfo) with ::iterator appended. **They allow you to iterate over the container, access and assign the values**.

 You initialize at the beginning of the vector and run until it reaches the end of it (it != master_topics.end()).
`In order to access the data of the iterator` you need to use 
```
const ros::master::TopicInfo &info = *it;
```

because with the deferencing operator (*) `*<it>` you get the value of the pointer and you save it inside a variable name info which has several field like name and datatype.

Also with `(*it).name` of course you get the value.
____
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
____
## Remove elements from a std::vector according to unary function

Here you have a vector of strings containing topic names and i want to `remove` from this vector all the strings that `do not` contain a certain string. So basically this is a substring finding and removing task. This is how i've done in the past. For the vector reduction two functions are used `erase` and `remove_if` while for the substring finding i used `find`.

```
std::vector<std::string> topics;

topics.erase(
    std::remove_if(
        topics.begin(), topics.end(), containsNameSpace),
    topics.end());
```

The unary function containsNameSpace is this way defined. It has to return a bool outcome and its input is the same type of the vector calling it.

```
bool static containsNameSpace(std::string &n)
    {

        if (n.find("/topic_checker") != std::string::npos)
        {
            // if it's found dont remove it
            return false;
        }

        return true;
    }
```