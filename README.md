# The JEEZ - RC Robo Car Project
Project Title: RC Robo Car for Nepathya Intra-College RC Robo Racing Competition</br>
Team Name: The JEEZ</br>
Award: Second Runner-up, Nepathya Intra-College RC Robo Racing Competition</br>

## Project Overview</br>
This project is a remotely controlled (RC) robotic car designed for participation in the Nepathya Intra-College RC Robo Racing Competition.</br> The objective was to design and build a functional, efficient, and responsive robotic car that could compete on various racing tracks, involving obstacles and tight turns, in a race against time.</br>

---
## Features

- Remote control via Web Interface: The car is controlled through a custom web interface hosted on the ESP8266 WiFi module.</br></br>
- Directional control: Supports moving forward, backward, left, and right.</br></br>
- Responsive Speed Control: Adjustable motor speed via a range slider.</br></br>
- Stop Function: Instant stop button for immediate halting of movement.</br></br>
- Custom ESP8266 Web Server: A custom-built web server runs on the ESP8266 microcontroller, allowing for real-time car control.</br></br>
- Optimized Movement: Enhanced movement control where the car responds to button presses for turning (left/right) without holding the buttons. The same logic is applied for forward and backward movement.</br>

---
## Project Components
### Hardware Used:

- ESP8266 WiFi Module: Hosts the web server and handles the car's movement through WiFi.</br>
- L298N Motor Driver: Controls the DC motors based on signals received from the ESP8266.</br>
- DC Motors: four motors to drive the wheels of the robotic car.</br>
- Car Chassis: A simple chassis supporting two DC motors, wheels, and caster.[chassi was made form recycled wodden boards ]</br>
- 12V Battery: Powers the motor and electronic components.</br>
- Wires and connectors: To connect components on the car.</br>
- Breadboard (optional): Used for testing the circuits.</br>

---
## Software Used:</br>
- Arduino IDE: Used for writing and uploading the code to the ESP8266 microcontroller.</br>
- KiCAD: (Optional) For PCB design and schematic representation.</br>
- HTML/CSS/JavaScript: To build the user interface for car control.</br>
- C++: Used in Arduino IDE for controlling motor functions and handling web requests.</br>
- processing 4 : we also included a radar scanning area and provides the visual output of distance, But ew removed this radar thing from car {Because it was un-necessary feture for our project} 

---
## Circuit Diagram
The car's circuit is based on the ESP8266 WiFi module, L298N motor driver, and the DC motors connected to a 12V battery. </br>Below is a high-level view of how components are connected: </br>

---

### ESP8266 Pins: </br>
- GPIO5 (D1) → Motor IN1</br>
- GPIO4 (D2) → Motor IN2</br>
 - GPIO0 (D3) → Motor IN3</br>
- GPIO2 (D4) → Motor IN4</br>
- GPIO12 (D6) → Motor ENA (PWM control for motor speed)</br>
- GPIO14 (D5) → Motor ENB (PWM control for motor speed)</br>

---
## Code Structure</br>
### Main Functionalities</br> </br>
- WiFi Access Point:</br>

The ESP8266 acts as an Access Point, creating a local network to connect the controller device (e.g., phone, laptop).</br></br>
- Web Server:</br>

The web server hosts a simple UI for car control, featuring directional buttons and a speed slider.</br></br>
- Motor Control:</br>

The motors are controlled using digitalWrite for direction and analogWrite for speed control through Pulse Width Modulation (PWM).</br></br>
- Custom Movement Logic:</br>

  Real-time response for left and right turns only while pressing the buttons.</br>
  Similar hold-to-move logic for forward and backward movement.</br></br>

---
Key Code Snippets:</br>
Movement Functions:</br></br>


    
    void moveForward() { /* Control logic for forward movement */ }
    void moveBackward() { /* Control logic for backward movement */ }
    void turnLeft() { /* Control logic for left turn */ }
    void turnRight() { /* Control logic for right turn */ }
    void stopCar() { /* Stops all motor activity */ }
    Speed Control:

    
    void setSpeed() {
      if (server.hasArg("value")) {
        speed = server.arg("value").toInt();
        // Update motor speed based on user input
      }
    }
    
---
    
### HTML/CSS/JavaScript for UI:
The web interface has a simple design with directional buttons and a slider for speed control, as well as real-time feedback for button presses.</br>
# Improvements and Future Work</br>
While the project was a success, a few improvements can be made:</br></br>

## Enhanced UI Design: 
Make the web interface more interactive with better visual feedback.</br>
Mobile Compatibility: Fully optimize the web interface for different screen sizes.</br>
Autonomous Features: Implementing autonomous driving modes using sensors like ultrasonic sensors.</br>
Further Speed Optimization: Fine-tuning the speed control for smoother acceleration.</br>

---
# Conclusion
The JEEZ RC Robo Car Project was a great learning experience for our team. By leveraging the power of ESP8266 and basic robotics principles,</br> we successfully built a robust car that earned us Third place in the Nepathya Intra-College competition. We plan to continue enhancing this project by adding more sophisticated features and improving the control system </br>< We may not update code in this reppo before another race >.

# Acknowledgments
Thanks to Nepathya College for organizing the competition.
---


<!-- Special thanks to ChatGPT for guidance throughout the project. -->

### Fun fact :
  we managed to get second runner-up position with very minimal cost and design 
  - no complexity, less money 😎
  - Cost: Rs.2000 NRP or 14.90 $USD 
  - we used used wooden block from collage for Chassis and designing outer cover <Free of cost 😎 >
  - winning prize 5000 + participation cost 3500
  - Participation cost was given to every teems participating [ to cover up the cost of making, designing car ], but in our case cost was less than 2000, SO IT WAS  WIN WIN SITURATION 😚
  - we removed outer cover of car in last minutes of race for better speed and less weight since we had obstacle like: a dead jump ☠️ , two big plates of water 🤣, narrow wodden block, teen 🥲 and meny more
  - Project engineered by @aakku106 / Adarasha Gaihre
### I will be adding some pic of car and I also wanna share the design behind palcement of motor, material used to attatch motor to Chassis and many more, stay tuned 🦚💙
<a href="https://visitcount.itsvg.in">
  <img src="https://visitcount.itsvg.in/api?id=Jeez&label=Views&icon=3&pretty=true" />
</a>
