#define Skanan 13
#define Skiri 12

//Motor Pins
#define EN_A  11      //Enable pin for first motor
#define IN1  9       //control pin for first motor
#define IN2  8       //control pin for first motor
#define IN3  7        //control pin for second motor
#define IN4  6        //control pin for second motor
#define EN_B  10      //Enable pin for second motor
//Initializing variables to store data
int motor_speed;
int motor_speed1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Skanan,INPUT);
  pinMode(Skiri,INPUT);
  pinMode(EN_A, OUTPUT);
  pinMode(IN1, OUTPUT);  
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);  
  pinMode(IN4, OUTPUT);
  pinMode(EN_B, OUTPUT);
}

void kananmaju(int kecepatan)
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(EN_A, kecepatan);
}

void kirimaju(int kecepatan)
{
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(EN_B, kecepatan);
}


void kananmundur(int kecepatan)
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(EN_A, kecepatan);
}

void kirimundur(int kecepatan)
{
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(EN_B, kecepatan);
}

void kananstop()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(EN_A, 0);
}

void kiristop()
{
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(EN_B, 0);
}


void loop() {
  // put your main code here, to run repeatedly:
    int Vkananhitam=digitalRead(Skanan);
    int Vkirihitam=digitalRead(Skiri);
    Serial.print("KANAN:");Serial.println(Vkanan);
    Serial.print("KIRI :");Serial.println(Vkiri);

    if 


    
    delay(200);
}
