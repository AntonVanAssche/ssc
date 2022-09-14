//Define which pins are used.
#define buttonLeft 2
#define buttonRight 3
#define buzzer 4
#define ledLeft 5
#define ledRight 6

// Initialize the variables that keeps track of the score.
int scoreLeft = 0;
int scoreRight = 0;

void setup() {
   // Initialize serial communication at 9600 bps.
   Serial.begin(9600);

   // Initialize buttons as inputs.
   pinMode(buttonLeft, INPUT);
   pinMode(buttonRight, INPUT);

   // Initialize buzzer and LEDs as outputs.
   pinMode(buzzer, OUTPUT);
   pinMode(ledLeft, OUTPUT);
   pinMode(ledRight, OUTPUT);
}

void playSound() {
   digitalWrite(buzzer, HIGH);
   delay(1000);
   digitalWrite(buzzer, LOW);
}

void blinkLed(int led) {
   digitalWrite(led, HIGH);
   playSound();
   digitalWrite(led, LOW);
}

void printScore() {
   Serial.print("Score: ");
   Serial.print(scoreLeft);
   Serial.print(" - ");
   Serial.println(scoreRight);
}

void loop() {
   // Read the state of the buttons.
   int buttonLeftState = digitalRead(buttonLeft);
   int buttonRightState = digitalRead(buttonRight);

   // Check if the left button is pressed.
   if (buttonLeftState == HIGH) {
      blinkLed(ledLeft);
      scoreLeft++;
      printScore();
   }

   // Check if the right button is pressed.
   if (buttonRightState == HIGH) {
      blinkLed(ledRight);
      scoreRight++;
      printScore();
   }
}

