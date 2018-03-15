// pins
#define LATCH_IN_RST_PIN 7
#define LATCH_IN_SET_PIN 6
#define LATCH_OUT_PIN 5

#define CLK_OUT_PIN 4
#define CLK_CTRL_IN_PIN A0

#define ADDER_INA_PIN 9
#define ADDER_INB_PIN 10
#define ADDER_OUT1_PIN 2
#define ADDER_OUT2_PIN 3

// global state
bool latch = 0;
bool clk = 0;
unsigned long ts;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LATCH_IN_SET_PIN, INPUT);
  pinMode(LATCH_IN_RST_PIN, INPUT);
  pinMode(LATCH_OUT_PIN, OUTPUT);
  
  pinMode(ADDER_INA_PIN, INPUT);
  pinMode(ADDER_INB_PIN, INPUT);
  pinMode(ADDER_OUT1_PIN, OUTPUT);
  pinMode(ADDER_OUT2_PIN, OUTPUT);
  
  pinMode(CLK_OUT_PIN, OUTPUT);
  pinMode(CLK_CTRL_IN_PIN, INPUT);
  Serial.begin(9600);
  ts = millis() + analogRead(CLK_CTRL_IN_PIN);
}

// the loop function runs over and over again forever
void loop() {
  // latch
  if (digitalRead(LATCH_IN_RST_PIN)) {
    latch = false;  
  } else if (digitalRead(LATCH_IN_SET_PIN)) {
    latch = true;
  }

  digitalWrite(LATCH_OUT_PIN, latch);
  
  // adder
  if (digitalRead(ADDER_INA_PIN) && digitalRead(ADDER_INB_PIN)) {
    digitalWrite(ADDER_OUT1_PIN, LOW);
    digitalWrite(ADDER_OUT2_PIN, HIGH);    
  } else if (digitalRead(ADDER_INA_PIN) || digitalRead(ADDER_INB_PIN)) {
    digitalWrite(ADDER_OUT1_PIN, HIGH);
    digitalWrite(ADDER_OUT2_PIN, LOW);    
  } else {
    digitalWrite(ADDER_OUT1_PIN, LOW);
    digitalWrite(ADDER_OUT2_PIN, LOW);
  }
  
  // clock
  if (millis() > ts) {
    clk = !clk;
    digitalWrite(CLK_OUT_PIN, clk);
    ts += analogRead(CLK_CTRL_IN_PIN);
  }
 
}
