
// sonar
const int vccPin = 11;
const int trigPin = 12;
const int echoPin = 13;

// Motor A

int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B

int enB = 3;
int in3 = 5;
int in4 = 4;



float duration, distance;
int car_speed = 100;

// float old = 20;
float ultrsonic_distance = 20.0;

void setup() {

  // Set all the pins

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(vccPin, OUTPUT);
  digitalWrite(vccPin, HIGH);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  delay(5000);

  start_car();
  forward(car_speed);
}

void loop() {
  distance = UltraSonic_Ping();
  if(distance < 40.0)
  {
     backward(car_speed, 1500);
     backward_left(car_speed, 1000);
  }
  else
  {
    forward(car_speed);
  }
  Serial.print("Distance: ");
  Serial.println(distance);
  //Serial.print("Speed: ");
  //Serial.println(car_speed);
  delay(200);
}
void start_car()
{
  // Turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(2000);
}
void stop_car()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void forward(int car_speed)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 

  analogWrite(enA, car_speed);
  analogWrite(enB, car_speed);
}
void backward(int car_speed, int len_time)
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 

  analogWrite(enA, car_speed);
  analogWrite(enB, car_speed);

  delay(len_time);
  stop_car();
}
void forward_right(int car_speed, int len_time)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 

  analogWrite(enA, car_speed);
  analogWrite(enB, 10);

  delay(len_time);
  stop_car();
}
void backward_right(int car_speed, int len_time)
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 

  analogWrite(enA, 10);
  analogWrite(enB, car_speed);

  delay(len_time);
  stop_car();
}
void forward_left(int car_speed, int len_time)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 

  analogWrite(enA, 10);
  analogWrite(enB, car_speed);

  delay(len_time);
  stop_car();
}
void backward_left(int car_speed, int len_time)
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 

  analogWrite(enA, car_speed);
  analogWrite(enB, 10);

  delay(len_time);
  stop_car();
}


float UltraSonic_Ping()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  return float (((pulseIn(echoPin, HIGH))*.0343)/2);
}
void Go_to_Position()
{
  car_speed = 20;
    
  do {
    // forward
  } while (UltraSonic_Ping() > (ultrsonic_distance+1));
  if(distance < (ultrsonic_distance-1))
  {
    do {
      // backward
    } while (UltraSonic_Ping() < (ultrsonic_distance-1));
  }
}
