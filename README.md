Assignments for AEROSP 740 - Visual Navigation for Autonomous Aerial Vehicles, taught by Vasileios Tzoumas in Winter 2021. 
Vasileios also co-taught a similar course in MIT, MIT16.485 - Visual Navigation for Autonomous Vehicles (VNAV) in Fall 2020, https://vnav.mit.edu/

## Lab1 Shell basics, Git , C++
To compile code
```
cd lab1 
g++ -std=c++11 -Wall -pedantic -o random_vector main.cpp random_vector.cpp
```

## Lab2 ROS
Build the project
```
cd {VNA2V_HOME}/vna2v_ws/
catkin build
source devel/setup.bash
```
Bring up the two-drones static scenario. In this environment, we have two aerial vehicles, AV1 [blue] and AV2 [red] that are not moving
```
roslaunch two_drones_pkg two_drones.launch static:=True
```
Hit Ctrl+C to close the visualization

### Visualization of Drone Trajectories
Now, we consider the scenario where two aerial vehicles, AV1 [blue] and AV2 [red] are following different trajectories: a circle and an arc of parabola, respectively. To launch the two-drone scenario in non-static mode, run
```
roslaunch two_drones_pkg two_drones.launch
```
<video src="https://github.com/user-attachments/assets/63db6e2a-693d-4bed-808c-b477956524b5" controls="controls" style="width: 50%;"></video>

## Lab3 Geometric Controller for a Quadrotor
When using each terminal, make sure that you use the current catkin workspace. This can be checked using ```echo $CMAKE_PREFIX_PATH```

Terminal 0: Build the project
```
cd {VNA2V_HOME}/vna2v_ws/
catkin build
source devel/setup.bash
```

Below line will make sure you can run the executable in the command line.
```
cd {VNA2V_HOME}/vna2v-builds/vnav-2021-lab3/
chmod +x vnav-2021-lab3.x86_64
```
Terminal 1: Launch Simulator
```
cd {VNA2V_HOME}/vna2v-builds/vnav-2021-lab3/
./vnav-2021-lab3.x86_64
```
Terminal 2: This launches two ROS nodes: ```tesse_ros_brige``` and ```quadrotor_control_interface```. The former receives state messages from the simulator and publishes them in a few ROS topics, and the latter listens to the controller node and sends the propeller commands to the simulator. 
```
cd {VNA2V_HOME}/vna2v_ws/
roslaunch tesse_ros_bridge tesse_quadrotor_bridge.launch
```
Terminal 3: To visualize the state of the quadrotor, run the following command to load  ```rviz``` preset:
```
cd {VNA2V_HOME}/vna2v_ws/src/controller_pkg/
rviz -d rviz/lab3.rviz
```
Terminal 4: Launch the controller for trajectory tracking
```
cd {VNA2V_HOME}/vna2v_ws/
roslaunch controller_pkg traj_tracking.launch
```
In the simulator, you can press ```W``` to turn on all propellers, and press ```R``` to respawn the quadrotor at the initial location (Reset the simulator).
<video src="https://github.com/user-attachments/assets/8f431e4e-e1ab-4a4b-a711-1d58f8ba0b50" controls="controls" style="width: 50%;"></video>

## Lab4 Trajectory Optimization for Drone Racing
Terminal 0: Build the project, and create an executable to run the simulator
```
cd {VNA2V_HOME}/vna2v_ws/
catkin build
source devel/setup.bash

cd {VNA2V_HOME}/vna2v-builds/vna2v-2021-lab4/
chmod +x vna2v-2021-lab4.x86_64
```
Terminal 1: Launch Simulator
```
cd {VNA2V_HOME}/vna2v-builds/vna2v-2021-lab4/
./vna2v-2021-lab4.x86_64
```
Terminal 2: Launch ```tesse_ros_bridge``` to connect ROS to the simulator
```
cd {VNA2V_HOME}/vna2v_ws/
roslaunch tesse_ros_bridge tesse_quadrotor_bridge.launch
```
Terminal 3: To visualize the state of the quadrotor, run the following command to load  ```rviz``` preset:
```
cd {VNA2V_HOME}/vna2v_ws/src/
rviz -d rviz/lab4.rviz
```
Terminal 4: Launch the trajectory follower
```
cd {VNA2V_HOME}/vna2v_ws/
roslaunch trajectory_generation traj_following.launch
```
Terminal 5: Launch the waypoint publisher
```
cd {VNA2V_HOME}/vna2v_ws/
roslaunch planner_pkg traj_gen.launch
```

<video src="https://github.com/user-attachments/assets/2ed1bb5f-f777-4704-a1f2-469930c17439" controls="controls" style="width: 50%;"></video>

 ## Lab5 Feature Detection, Tracking & Matching 
 Build the project.
 To extract keypoints based on a specific Feature descriptor, and match features/keypoints (using Fast Approximate Nearest Neighbor Search Library) between 2 images along with Outlier detection, run
 ```
 cd {VNA2V_HOME}/vna2v_ws/
 roslaunch lab_5 two_frames_tracking.launch descriptor:=<descriptor_name>
 ```
 Various Feature Tracking algorithms (<descriptor_name>) were used and key statistics were recorded to compare different Feature Descriptors.
 These include 
 1. 'SIFT' (Scale Invariant Feature Transform), 
 2. ['SURF'](https://docs.opencv.org/3.4.2/df/dd2/tutorial_py_surf_intro.html), 
 3. ['ORB'](https://docs.opencv.org/3.4.2/d1/d89/tutorial_py_orb.html), 
 4. 'FAST' ([FAST](https://docs.opencv.org/3.4.2/df/d0c/tutorial_py_fast.html) (detector) +[BRIEF](https://docs.opencv.org/3.4.2/dc/d7d/tutorial_py_brief.html) (descriptor)), 
 5. 'LK' ([Lucas Kanade](https://docs.opencv.org/3.3.1/dc/d6b/group__video__track.html#ga473e4b886d0bcc6b65831eb88ed93323) (Tracker) + [Harris corner](https://docs.opencv.org/3.4.2/dc/d0d/tutorial_py_features_harris.html) (detector))

 To perform Feature Tracking for actual videos ([rosbag datasets](https://drive.google.com/drive/folders/1y-fPmAfEsDebJ_1_xTewwTYf2i8GfqFs?usp=sharing)), run
 ```
 roslaunch lab_5 video_tracking.launch path_to_dataset:=/home/$USER/Downloads/<NAME_OF_DOWNLOADED_FILE>.bag descriptor:=<descriptor_name>
 ```
#### Feature Tracking for videos using different algorithms
<video src="https://github.com/user-attachments/assets/39393b50-0f25-4998-9fa2-18f70d43eee0" controls="controls" style="width: 50%;"></video>
<video src="https://github.com/user-attachments/assets/2370f7b0-0cea-4723-b73f-d4fa869dd167" controls="controls" style="width: 50%;"></video>
<video src="https://github.com/user-attachments/assets/d79658c8-f1ae-4c49-b979-79dd78e0433b" controls="controls" style="width: 50%;"></video>

 ## Lab6 Vision-based Motion Estimation


 ## Lab7 Visual Odometry, Optimization and using GTSAM (Georgia Tech Smoothing And Mapping) to solve Computer Vision problems
 Add new packages to your catkin workspace using wstool
 ```
 cd {VNA2V_HOME}/vna2v_ws/src/
 cp -r {VNA2V_HOME}/Labs/lab7 ./
 wstool merge --merge-replace {VNA2V_HOME}/vna2v_ws/src/lab7/install/lab_7.rosinstall -y
 wstool update
 ```
 Note: Earlier labs may have already installed some packages in ```src```, and the last step ```wstool update``` would install packages in ```dependencies```. Whilie building lab_7, it might complain about duplicated packages, in which case you should manually remove the duplicate packages from ```src```.

 Build gtsam and then build lab_7, and finally source your workspace
 ```
 catkin build gtsam_catkin
 catkin build lab_7
 source {VNA2V_HOME}/vna2v_ws/devel/setup.bash
 ```

 ### GTSAM for 3D Pose Estimation (with and without Motion Capture), and for solving Computer Vision problem 
 x can take values '1', '2_3', '4', '5' in ```deliverable_x``` for running deliverables 1-5.
 Terminal 1
 ```
 roscore
 ```
 Terminal 2
 ```
 rosrun lab_7 {deliverable_x}
 ```
 To visualize pose and/or positions in ```rviz```, run ```rviz -d /path/to/lab_7.rviz``` (for deliverables 2, 3) or ```rviz -d /path/to/deliverable_4.rviz``` (for deliverables 4) in a separate terminal after running ```roscore```

 While making following updates to run different scenarios, make sure to rebuild ```lab_7``` workspace and source it after making updates in code.
 1. Set ```static constexpr bool use_mocap = false``` for deliverable 2, and ```static constexpr bool use_mocap = true``` for deliverable 3 in ```deliberable_2_3.cpp```
 2. Similarly, ```setMaxIterations``` can be used to set maximum iterations (to 1,3,6) for the optimized trajectory using ```GaussNewtonOptimizer```
 #### GTSAM for 3D Pose Estimation (with and without Motion Capture)
 <img src="media/lab7_del2_3_summary.png"> <img src="media/HW1_1b.png">
 #### GTSAM for solving Computer Vision problem
 <img src="media/lab7_del4_summary.png"> <img src="media/HW1_1b.png">
 


 ## Lab8 Object Tracking/Detection, Object Localization and Place Recognition 
