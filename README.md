## My Notes taken during the ROS course of theconstruct.sim website

## How to build libraries using make
[link](https://github.com/ethz-asl/libpointmatcher/blob/master/doc/CompilationUbuntu.md)

## Setting up Visual Studio Code to work with ROS
[link](https://answers.ros.org/question/256565/how-to-add-ros-to-path-in-vs-code/)
and follow the Diogo42 answer

## Solutions to Quizzes
Solution to 6.5 Services Quiz 

https://i-08fcd4fa18fff8e5a.robotigniteacademy.com/e56f00b7-7579-4c9f-b944-cded3d110728/jupyter/notebooks/basic_ROS_Cpp/extra_files/services_quiz_solutions_cpp_v2.ipynb

Solution to 8.6 Action clients

https://i-0248b2c151986e466.robotigniteacademy.com/b49a3b5a-1b70-433c-ba13-7f607c40a39c/jupyter/notebooks/basic_ROS_Cpp/extra_files/unit4_basicROS_part1_solutions_cpp.ipynb

Solution to 9 using custom action messages

https://i-02277c3e9e05accdf.robotigniteacademy.com/5e32a7e5-998a-4d2f-81ed-244d34603f37/jupyter/notebooks/basic_ROS_Cpp/extra_files/actions_quiz_solutions_cpp.ipynb

## Remove links of git folders that are in your git repo
For each of the folders:
```
git rm --cached submodule_path # delete reference to submodule HEAD (no trailing slash)
git rm .gitmodules             # if any (dont worry if there's no files)
rm -rf submodule_path/.git     
```
Do the above commands for each git repo you want to delink and finally:
```
git add *                      # will add files 
git commit -m "your message"
```
## Remapping 
The topic 2 in the system is remapped into topic 1 since publisher.py needs it.
```
<launch>
    <remap from="topic1" to="topic2" />
    <node name="publisher_node" pkg="my_robot_tutorials" type="publisher" />
</launch>
```
<remap from="EXPRECTED TOPIC FROM BELOW" to="THE TOPIC YOU HAVE" />

