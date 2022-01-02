
int Pot_val;

int Sol_1 = 4;
int Sol_1_delay = 0;

bool Sol_1_state = false;


unsigned long C_time;
unsigned long Sol_1_time = 0; 

void setup() {
  pinMode(Sol_1, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  C_time = millis();
  Pot_val = analogRead(0)/10;
//  printer();
  Solenoid_1();  
}

void Solenoid_1(){
  if(C_time - Sol_1_time >= Pot_val){
    Sol_1_time = millis();
    if(Sol_1_state == true){
      Sol_1_state = false;
      digitalWrite(Sol_1, LOW);
      }
    else if(Sol_1_state == false){
      Sol_1_state = true;
      digitalWrite(Sol_1, HIGH);
      }
    }
  }

void printer(){
    Serial.print(C_time);
    Serial.print(": ");
    Serial.print(Pot_val);
    Serial.print(": ");
    Serial.println(Sol_1_state);
  }
