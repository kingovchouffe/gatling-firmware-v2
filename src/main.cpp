#include <main.h>

CAN_message_t msg;
CAN_message_t msgTX;

Stepper moteur(STEP_GATLING, DIR_GATLING); //STEP pin =  2, DIR pin = 3
StepControl controller;
Servo drapeauServo;
Servo GatlingServo;
Servo ServoGauche;
Servo ServoDroit;

void setup()
{
  Serial.begin(9600);
  Can0.begin(1000000);
  msgTX.id = 0x600;
  pinMode(RESET_GATLING, OUTPUT); //le reset se fait a l'état bas
  digitalWrite(RESET_GATLING, HIGH);
  pinMode(SLEEP_GATLING, OUTPUT); //le sleep se met a l'état bas poru une carte fonctionelle
  digitalWrite(SLEEP_GATLING, HIGH);
  pinMode(GATLING_PIN, INPUT);

  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, HIGH);

  GatlingServo.attach(GATLING_SERVO_PIN);
  Serial.println("test1");
  moteur
      .setMaxSpeed(V_MOT)        // steps/s
      .setAcceleration(ACC_MOT); // steps/s^2
  moteur.setPosition(0);
  gatlingHeight('h');
}

void loop()
{

  while (Can0.read(msg))
  {
    canHandler();
  }
}

void canHandler()
{
  byte data[8];
  for (int i = 0; i < 8; i++)
  {
    data[i] = msg.buf[i];
  }
  if (msg.id == 0x700)
  {
    switch (data[0])
    {
    case 'O': //orientation
      Serial.print("test\n");
      switch (data[2])
      {
      case '1':
        gatlingGo(1);
        msgTX.buf[0] = 'R';
        msgTX.buf[1] = 'g';
        msgTX.buf[2] = 'a';
        msgTX.len = 3;
        Can0.write(msgTX);
        break;
      case '2':
        gatlingGo(2);
        msgTX.buf[0] = 'R';
        msgTX.buf[1] = 'g';
        msgTX.buf[2] = 'a';
        msgTX.len = 3;
        Can0.write(msgTX);
        break;
      case '3':
        gatlingGo(3);
        msgTX.buf[0] = 'R';
        msgTX.buf[1] = 'g';
        msgTX.buf[2] = 'a';
        msgTX.len = 3;
        Can0.write(msgTX);
        break;
      case '4':
        gatlingGo(4);
        msgTX.buf[0] = 'R';
        msgTX.buf[1] = 'g';
        msgTX.buf[2] = 'a';
        msgTX.len = 3;
        Can0.write(msgTX);
        break;
      case '5':
        gatlingGo(5);
        msgTX.buf[0] = 'R';
        msgTX.buf[1] = 'g';
        msgTX.buf[2] = 'a';
        msgTX.len = 3;
        Can0.write(msgTX);
        break;
      case '6':
        gatlingGo(6);
        msgTX.buf[0] = 'R';
        msgTX.buf[1] = 'g';
        msgTX.buf[2] = 'a';
        msgTX.len = 3;
        Can0.write(msgTX);
        break;
      }
      break;
    case 'A': //hauteur
      switch (data[2])
      {

      case 'h':
        gatlingHeight('h');
        msgTX.buf[0] = 'R';
        msgTX.buf[1] = 'g';
        msgTX.buf[2] = 'h';
        msgTX.len = 3;
        Can0.write(msgTX);
        break;
      case 'b':
        gatlingHeight('b');
        msgTX.buf[0] = 'R';
        msgTX.buf[1] = 'g';
        msgTX.buf[2] = 'h';
        msgTX.len = 3;
        Can0.write(msgTX);
        break;
      case 'm':
        gatlingHeight('m');
        msgTX.buf[0] = 'R';
        msgTX.buf[1] = 'g';
        msgTX.buf[2] = 'h';
        msgTX.len = 3;
        Can0.write(msgTX);
        break;
      }
    }
  }
}
//Make the gatling turn to the position
void gatlingGo(uint8_t pos)
{
  Serial.printf("posprec=%i\n\r", posprec);
  Serial.printf("pos=%i\n\r", pos);

  if (pos == posprec)
    return;
  if (pos > posprec)
  {
    //digitalWrite(DIR_GATLING,HIGH);
    switch (pos)
    {
    case 1:
      moteur.setTargetAbs(GATLING_POS_1);
      controller.move(moteur);
      //delay(500);
      moteur.setPosition(GATLING_POS_1);
      break;
    case 2:
      moteur.setTargetAbs(GATLING_POS_2);
      controller.move(moteur);
      //delay(500);
      moteur.setPosition(GATLING_POS_2);
      break;
    case 3:
      moteur.setTargetAbs(GATLING_POS_3);
      controller.move(moteur);
      //delay(500);
      moteur.setPosition(GATLING_POS_3);
      break;
    case 4:
      moteur.setTargetAbs(GATLING_POS_4);
      controller.move(moteur);
      //delay(500);
      moteur.setPosition(GATLING_POS_4);
      break;
    case 5:
      moteur.setTargetAbs(GATLING_POS_5);
      controller.move(moteur);
      //delay(500);
      moteur.setPosition(GATLING_POS_5);
      break;
    case 6:
      moteur.setTargetAbs(GATLING_POS_6);
      controller.move(moteur);
      //delay(500);
      moteur.setPosition(GATLING_POS_6);
      break;
    }
    posprec = pos;
  }
  else
  {
    //digitalWrite(DIR_GATLING,LOW);
    //moteur.dir=0;
    Serial.print("Else");
    switch (pos)
    {
    case 1:

      moteur.setTargetAbs(-GATLING_POS_1);
      controller.move(moteur);
      //delay(500);
      moteur.setPosition(GATLING_POS_1);
      break;
    case 2:

      moteur.setTargetAbs(-GATLING_POS_2);
      controller.move(moteur);
      //delay(500);
      moteur.setPosition(GATLING_POS_2);

      break;
    case 3:

      moteur.setTargetAbs(-GATLING_POS_3);
      controller.move(moteur);
      //delay(500);
      moteur.setPosition(GATLING_POS_3);

      break;
    case 4:
      moteur.setTargetAbs(GATLING_POS_4);
      controller.move(moteur);
      //delay(500);
      moteur.setPosition(GATLING_POS_4);

      break;
    case 5:
      moteur.setTargetAbs(GATLING_POS_5);
      controller.move(moteur);
      //delay(500);
      moteur.setPosition(GATLING_POS_5);

      break;
    case 6:
      moteur.setTargetAbs(GATLING_POS_6);
      controller.move(moteur);
      //delay(500);
      moteur.setPosition(GATLING_POS_6);
      break;
    }
    posprec = pos;
  }
}
void gatlingHeight(uint8_t height)
{
  switch (height)
  {
  case 'h':
    GatlingServo.write(GATLING_HAUT);
    //delay(25);
    break;
  case 'b':
    GatlingServo.write(GATLING_BAS);
    //delay(25);
    break;
  case 'm':
    GatlingServo.write(GATLING_MILIEU);
    //delay(25);
    break;
  }
}
/* void gatlingInit(){

while (digitalRead(GATLING_PIN))
{
  moteur.setTargetRel(10000);
  controller.move(moteur);
}
controller.stop();
moteur.setPosition(0);
} */

void drapeau()
{
  while (digitalRead(DRAPEAU_PIN))
  {
    drapeauServo.writeMicroseconds(140); //157->130 = clockwise; 157 ->  170 counterclockwise
  }
  drapeauServo.writeMicroseconds(152); //stop the servo
}

void drapeauInit()
{
  while (digitalRead(DRAPEAU_PIN))
  {
    drapeauServo.writeMicroseconds(165); //157->130 = clockwise; 157 ->  170 counterclockwise
  }
  drapeauServo.writeMicroseconds(152); //stop the servo
}

void servoMove(uint8_t servo, uint8_t angle)
{
  switch (servo)
  {
  case SERVO_COT_DROIT:
    ServoDroit.write(angle);
    break;
  case SERVO_COT_GAUCHE:
    ServoGauche.write(angle);
    break;
  }
}

void servoInit(uint8_t servo)
{
  ServoDroit.write(ANGLE_DEFAUT_DROIT);
  delay(20);
  ServoGauche.write(ANGLE_DEFAUT_GAUCHE);
}
