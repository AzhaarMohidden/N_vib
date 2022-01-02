
int Pot_val; //Potentiometer value str integer

int Sol_1 = 4; //pinout set to digital I/O 4
int Sol_1_delay = 0; 

bool Sol_1_state = false;


unsigned long C_time;
unsigned long Sol_1_time = 0; 

void setup() {
  pinMode(Sol_1, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  C_time = millis();
  Pot_val = analogRead(0)/10; // Potentiometer read pin connected to A0
  Solenoid_1();  
//  printer(); // Enable only for DEBUG
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
