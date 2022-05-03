/* vaibhav vijay devkate */


const int echoPin = 10; // Echo Pin of Ultrasonic Sensor
const int trigpin = 9;// Trigger Pin of Ultrasonic Sensor
const int LED =12; //led blink when 50% garbage level is cross
const int LED1 =13;//led blink when 100% garbage level is cross i.e. dustbin is full 

                    
void setup() 
{
  Serial.begin(9600); // Starting Serial Communication
  pinMode(trigpin, OUTPUT); // initialising pin 3 as output
  pinMode(echoPin, INPUT); 
  pinMode(LED, OUTPUT);
  pinMode(LED1, OUTPUT);// initialising pin 2 as input
}

void loop()
{
  long duration, inches;
  
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echoPin, HIGH); // using pulsin function to determine total time
  inches = microsecondsToInches(duration); // calling method
 
  
    Serial.print(inches);

    Serial.print("in, ");
    if(inches==0||inches>460){
    Serial.print("dustbin level :100%");
    Serial.print("dustbin is Full");
     digitalWrite(LED1, HIGH);
     digitalWrite(LED, HIGH);
  
 
    }
      Serial.println();
    if(inches<=1  &&  inches>=0.5){
    Serial.print("dustbin level :100%");
    digitalWrite(LED, HIGH);
     Serial.print("dustbin is Full");
    digitalWrite(LED1, HIGH);
    }
      Serial.println();
    if(inches<=2 && inches>1){
    Serial.print("dustbin level :75%");
     digitalWrite(LED, HIGH);
     //digitalWrite(LED1, HIGH);
      digitalWrite(LED1, LOW);
    }
    
    Serial.println();
    if(inches<=3 && inches>2){
    Serial.print("dustbin level :50%");
    digitalWrite(LED, HIGH);
     digitalWrite(LED1, LOW);
    }
    
    Serial.println();
    if(inches<=4 && inches>3){
    Serial.print("dustbin level :25%");
     digitalWrite(LED1, LOW);
    digitalWrite(LED, LOW);
   
    }
    
    Serial.println();
    if(inches>=5){
    Serial.print("dustbin level :0%");
    Serial.println("Dustbin is empty");
    digitalWrite(LED1, LOW);
    digitalWrite(LED, LOW);
       } 
  
   
 delay(2000);
    }
    
   
 


long microsecondsToInches(long microseconds) // method to covert microsec to inches 
{
 return microseconds / 74 / 2;
}
