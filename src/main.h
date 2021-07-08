#include <Arduino.h>
#include <FlexCAN.h>
#include <TeensyStep.h>
#include <Servo.h>
#include "kinetis_flexcan.h"

#define CAN_TX           3
#define CAN_RX           4

#define DIR_GATLING      5
#define STEP_GATLING     6
#define SLEEP_GATLING    7
#define RESET_GATLING    8
#define GATLING_HAUT     0
#define GATLING_BAS     60
#define GATLING_MILIEU  25
#define GATLINE_PAS     1700
#define GATLING_POS_1    0
#define GATLING_POS_2   GATLINE_PAS
#define GATLING_POS_3   GATLINE_PAS*2
#define GATLING_POS_4   GATLINE_PAS*3
#define GATLING_POS_5   GATLINE_PAS*4
#define GATLING_POS_6   GATLINE_PAS*5

#define GATLING_PIN       10
#define GATLING_SERVO_PIN 20

#define DRAPEAU_HAUT     255
#define DRAPEAU_BAS       0
#define DRAPEAU_PIN_SERVO 23
#define DRAPEAU_PIN       10

#define SERVO_COT_GAUCHE    20
#define SERVO_COT_DROIT     21
#define ANGLE_DEFAUT_DROIT  90
#define ANGLE_DEFAUT_GAUCHE 90

#define PIN_LED    13


#define V_MOT 5000
#define ACC_MOT 2000

uint8_t posprec=1;

void canHandler();
void gatlingGo(uint8_t pos);
void gatlingHeight(uint8_t height);
void gatlingInit();
void drapeau();
void drapeauInit();
void servoMove(uint8_t servo,uint8_t angle);
void servoInit(uint8_t servo);