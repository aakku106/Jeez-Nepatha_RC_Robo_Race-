#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Network credentials
const char* ssid = "aakku";
const char* password = "@ccn1069"; // you can change SSID and Password...

ESP8266WebServer server(80);

// Define motor control pins
#define IN1 5  // GPIO5 (D1)
#define IN2 4  // GPIO4 (D2)
#define IN3 0  // GPIO0 (D3)
#define IN4 2  // GPIO2 (D4)

// Define speed control pins (PWM)
#define ENA 12 // GPIO12 (D6)
#define ENB 14 // GPIO14 (D5)

// Define initial speed (PWM duty cycle)
int speed = 1023; // Max speed

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Set up the ESP8266 as an Access Point
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/", handleRoot);
  server.on("/forward", moveForward);
  server.on("/backward", moveBackward);
  server.on("/left", turnLeft);
  server.on("/right", turnRight);
  server.on("/stop", stopCar);
  server.on("/speed", setSpeed);
  server.begin();
  Serial.println("HTTP server started");
}

void handleRoot() {
  String html = "<!DOCTYPE html>";
  html += "<html>";
  html += "<head>";
  html += "<title>Car Control</title>";
  html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no\">";
  html += "<style>";
  html += "body { user-select: none; margin: 0; font-family: Arial, sans-serif; text-align: center; background-color: #f0f0f0; }";
  html += "button { width: 100px; height: 100px; font-size: 20px; margin: 10px; border: none; border-radius: 10px; color: white; }";
  html += "button:active { transform: scale(0.95); }";
  html += "#forward { background-color: #4CAF50; }";
  html += "#backward { background-color: #f44336; }";
  html += "#left { background-color: #03A9F4; }"; // Swapped color
  html += "#right { background-color: #ff9800; }"; // Swapped color
  html += "#stop { background-color: #9E9E9E; }";
  html += "input[type=range] { width: 80%; }";
  html += "</style>";
  html += "</head>";
  html += "<body>";
  html += "<h1>Car Control</h1>";
  html += "<div>";
  html += "<button id=\"forward\" onclick=\"sendCommand('/forward')\">Forward</button><br>";
  html += "<button id=\"right\" onmousedown=\"startMoving('/right')\" onmouseup=\"stopMoving()\" ontouchstart=\"startMoving('/right')\" ontouchend=\"stopMoving()\">Right</button>"; // Swapped button
  html += "<button id=\"stop\" onclick=\"sendCommand('/stop')\">Stop</button>";
  html += "<button id=\"left\" onmousedown=\"startMoving('/left')\" onmouseup=\"stopMoving()\" ontouchstart=\"startMoving('/left')\" ontouchend=\"stopMoving()\">Left</button><br>"; // Swapped button
  html += "<button id=\"backward\" onclick=\"sendCommand('/backward')\">Backward</button><br>";
  html += "<input type=\"range\" min=\"0\" max=\"1023\" value=\"1023\" onchange=\"setSpeed(this.value)\"><br>";
  html += "</div>";

  html += "<script>";
  html += "var moveInterval;";
  html += "function sendCommand(command) {";
  html += "  var xhr = new XMLHttpRequest();";
  html += "  xhr.open('GET', command, true);";
  html += "  xhr.send();";
  html += "  updateButtonColors(command);";
  html += "}";
  html += "function setSpeed(value) {";
  html += "  var xhr = new XMLHttpRequest();";
  html += "  xhr.open('GET', '/speed?value=' + value, true);";
  html += "  xhr.send();";
  html += "}";
  html += "function updateButtonColors(command) {";
  html += "  document.querySelectorAll('button').forEach(button => button.style.backgroundColor = '');";
  html += "  if (command === '/forward') { document.getElementById('forward').style.backgroundColor = '#388E3C'; }";
  html += "  else if (command === '/backward') { document.getElementById('backward').style.backgroundColor = '#D32F2F'; }";
  html += "  else if (command === '/left') { document.getElementById('left').style.backgroundColor = '#0288D1'; }"; // Swapped color
  html += "  else if (command === '/right') { document.getElementById('right').style.backgroundColor = '#F57C00'; }"; // Swapped color
  html += "  else if (command === '/stop') { document.getElementById('stop').style.backgroundColor = '#616161'; }";
  html += "}";
  html += "function startMoving(command) {";
  html += "  sendCommand(command);";
  html += "  moveInterval = setInterval(function() { sendCommand(command); }, 200);";
  html += "}";
  html += "function stopMoving() {";
  html += "  clearInterval(moveInterval);";
  html += "  sendCommand('/stop');";
  html += "}";
  html += "</script>";

  html += "</body>";
  html += "</html>";

  server.send(200, "text/html", html);
}

void moveForward() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  server.send(200, "text/plain", "Moving Forward");
}

void moveBackward() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  server.send(200, "text/plain", "Moving Backward");
}

void turnLeft() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  server.send(200, "text/plain", "Turning Left");
}

void turnRight() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  server.send(200, "text/plain", "Turning Right");
}

void stopCar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  server.send(200, "text/plain", "Stopping");
}

void setSpeed() {
  if (server.hasArg("value")) {
    speed = server.arg("value").toInt();
    server.send(200, "text/plain", "Speed set to " + String(speed));
  } else {
    server.send(200, "text/plain", "No speed value provided");
  }
}

void loop() {
  server.handleClient();
}
