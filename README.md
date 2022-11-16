# gazebo_simulator_OGM
occupancy grid mapping in gazebo 

##### for package sim_demo_1 ########

# build a robot that include camera and lidar , which can show in rviz

roslaunch sim_demo_1 sim_2plus.launch

##### for package sim_demo_2 #####

#  compare with package sim_demo_1, add the arbotix control. we can test this with follow command

roslaunch sim_demo_2 demo_2.launch

rostopic pub -r 10 /cmd_vel geometry_msgs/Twist '{linear: {x: 0.2, y: 0, z: 0}, angular: {x: 0, y: 0, z: 0.5}}'
or
rosrun teleop_twist_keyboard teleop_twist_keyboard.py


#### for package  sim_urdf_gazebo #####

# realization of sensor-equipped robot movement in the gazebo. sensor: camera laser kinect

roslaunch sim_urdf_gazebo sim_gazebo.launch


#### for package occ_grid_mapping ####

roslaunch occ_grid_mapping ogm.launch
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
