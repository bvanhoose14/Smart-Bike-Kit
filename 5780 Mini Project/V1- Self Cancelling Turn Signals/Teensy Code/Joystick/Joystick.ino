#define A_BTN 5
#define B_BTN 3
#define X_BTN 4
#define Y_BTN 2
#define UP_BTN 6
#define DOWN_BTN 7
#define LEFT_BTN 8
#define RIGHT_BTN 9
#define START_BTN 10
#define SEL_BTN 11
#define LB_BTN 12
#define RB_BTN 14

#define JOYSTICK_Y A9
#define JOYSTICK_X A8

void setup() {
  pinMode(A_BTN, INPUT_PULLUP);
  pinMode(B_BTN, INPUT_PULLUP);
  pinMode(X_BTN, INPUT_PULLUP);
  pinMode(Y_BTN, INPUT_PULLUP);
  pinMode(UP_BTN, INPUT_PULLUP);
  pinMode(DOWN_BTN, INPUT_PULLUP);
  pinMode(LEFT_BTN, INPUT_PULLUP);
  pinMode(RIGHT_BTN, INPUT_PULLUP);
  pinMode(START_BTN, INPUT_PULLUP);
  pinMode(SEL_BTN, INPUT_PULLUP);
  //pinMode(LB_BTN, INPUT_PULLUP);
  //pinMode(RB_BTN, INPUT_PULLUP);
}

void loop() {
  // read analog inputs and set X-Y position
  Joystick.X(analogRead(JOYSTICK_X));
  Joystick.Y(analogRead(JOYSTICK_Y));

  // read the digital inputs and set the buttons
  Joystick.button(1, digitalRead(X_BTN));
  Joystick.button(2, digitalRead(A_BTN));
  Joystick.button(3, digitalRead(B_BTN));
  Joystick.button(4, digitalRead(Y_BTN));
  //Joystick.button(5, digitalRead(LB_BTN));
  //Joystick.button(6, digitalRead(RB_BTN));
  Joystick.button(9, digitalRead(SEL_BTN));
  Joystick.button(10, digitalRead(START_BTN));
  Joystick.button(11, digitalRead(UP_BTN));
  Joystick.button(12, digitalRead(DOWN_BTN));
  Joystick.button(13, digitalRead(LEFT_BTN));
  Joystick.button(14, digitalRead(RIGHT_BTN));
  // a brief delay, so this runs 20 times per second
  delay(50);
}
