#define Skanan 13
#define Skiri 12
#define gigi1 50
#define gigi2 100
#define gigi3 150
#define gigi4 255

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

//sensor jarak
#define trigPin 4
#define echoPin 2
int distance;


void setup() {
  // put your setup code here, to run once:
  
  //Serial.begin(9600);
  
  //line folowing sensors
  pinMode(Skanan,INPUT);
  pinMode(Skiri,INPUT);
  
  //motor pins
  pinMode(EN_A, OUTPUT);
  pinMode(IN1, OUTPUT);  
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);  
  pinMode(IN4, OUTPUT);
  pinMode(EN_B, OUTPUT);
  
  //ultrasonic pins
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
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


int cekjarak()
{
    long durasi;
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    durasi = pulseIn(echoPin,HIGH);
    return durasi*0.034/2;  
}

void loop() {
  // put your main code here, to run repeatedly:
    int Vkananhitam=digitalRead(Skanan);
    int Vkirihitam=digitalRead(Skiri);
    //Serial.print(Vkirihitam);Serial.print("|");Serial.println(Vkananhitam);
    //if (Vkirihitam==1){Serial.print("(Putih ");} else {Serial.println("(Hitam ");}
    //if (Vkananhitam==1){Serial.println("||| Hitam)");} else {Serial.println("||| Putih)");}

    if (cekjarak() >= 20)
    {
      if (Vkirihitam&&Vkananhitam)
      {
        kananstop();
        kiristop();
      }
  
      if (!Vkirihitam&&Vkananhitam)
      {
        kirimaju(gigi3);
        kananstop();
        //kananmundur(gigi4);
      }
  
      if (Vkirihitam&&!Vkananhitam)
      {
        kananmaju(gigi3);
        kiristop();
        //kirimundur(gigi4);
      }
      
      if (!Vkirihitam&&!Vkananhitam)
      {
        kananmaju(gigi4);
        kirimaju(gigi4);
      }
    }else{
      kananstop();
      kiristop();
    }
    //delay(50);
}
