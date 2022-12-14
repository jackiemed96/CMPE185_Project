# CMPE 185 Final Project
**Steps to run camera and object detection node:**
1. Source ROS (this project uses galactic) in each terminal that is being used with ```source /opt/ros/galactic/setup.bash```
2. Navigate to 'CMPE185_ws' directory and source the install folder with ```source install/setup.bash```
3. To start camera node : ```ros2 launch camera_node ros2bag_file.launch```
    - This will open up RVIZ2 to see the data
4. To start object detection node: ```ros2 launch objdetect_node objdetect.launch```
    - It will take a second to show up on RVIZ2 screen but video will loop once it is playing
