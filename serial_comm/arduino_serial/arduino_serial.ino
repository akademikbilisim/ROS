#define PIN_A 7
#define PIN_B 8
#define PIN_C 9

int counter_a = 0;
int counter_b = 0;
int counter_c = 0;

boolean state_a = HIGH;
boolean state_b = HIGH;
boolean state_c = HIGH;
boolean last_state_a = HIGH;
boolean last_state_b = HIGH;
boolean last_state_c = HIGH;


void setup(){
  Serial.begin(9600);
  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);
  pinMode(PIN_C, INPUT);
}

void loop(){
  state_a = digitalRead(PIN_A);
  if(state_a != last_state_a){
    if ( state_a == HIGH ){
      counter_a++;
    }
  }
  last_state_a = state_a;

  state_b = digitalRead(PIN_B);
  if(state_b != last_state_b){
    if ( state_b == HIGH ){
      counter_b++;
    }
  }
  last_state_b = state_b;

  state_c = digitalRead(PIN_C);
  if(state_c != last_state_c){
    if ( state_c == HIGH ){
      counter_c++;
    }
  }
  last_state_c = state_c;

  delay(100);
  Serial.println((String) state_a+';'+state_b+';'+state_c+';'+counter_a+';'+counter_b+';'+counter_c+';');

}
