
#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdint.h>
#include <vector>
#include <plutodrone/Common.h>
//#include <plutodrone/Communication.h>
//#include "Communication.h"







//extern int8_t inputBuffer[1024];
//extern uint8_t bufferIndex;
//extern NSMutableArray* requests;

/*static const int MSP_FC_VERSION=3;
static const int MSP_RAW_IMU=102;
static const int MSP_RC = 105;
static const int MSP_ATTITUDE=108;
static const int MSP_ALTITUDE=109;
static const int MSP_ANALOG=110;
static const int MSP_SET_RAW_RC=200;
static const int MSP_ACC_CALIBRATION=205;
static const int MSP_MAG_CALIBRATION=206;
static const int MSP_SET_MOTOR=214;
static const int MSP_SET_ACC_TRIM=239;
static const int MSP_ACC_TRIM=240;
static const int MSP_EEPROM_WRITE = 250;
static const int MSP_SET_POS= 216;

static const int IDLE = 0, HEADER_START = 1, HEADER_M = 2, HEADER_ARROW = 3, HEADER_SIZE = 4, HEADER_CMD = 5, HEADER_ERR = 6;

*/


/*
extern int roll;
extern int pitch;
extern int yaw;
extern float battery;
extern int rssi;

extern float accX;
extern float accY;
extern float accZ;

extern float gyroX;
extern float gyroY;
extern float gyroZ;

extern float magX;
extern float magY;
extern float magZ;

extern float alt;

extern int FC_versionMajor;
extern int FC_versionMinor;
extern int FC_versionPatchLevel;

extern int trim_roll;
extern int trim_pitch;


extern float rcThrottle, rcRoll, rcPitch, rcYaw, rcAUX1 , rcAUX2, rcAUX3, rcAUX4 ;
*/



class Protocol{

public:

int8_t inputBuffer[1024];
uint8_t bufferIndex=0;


int roll;
int pitch;
int yaw;
float battery;
int rssi;

float accX;
float accY;
float accZ;

float gyroX;
float gyroY;
float gyroZ;

float magX;
float magY;
float magZ;

float alt;

int FC_versionMajor;
int FC_versionMinor;
int FC_versionPatchLevel;

int trim_roll;
int trim_pitch;


float rcThrottle, rcRoll, rcPitch, rcYaw, rcAUX1 , rcAUX2, rcAUX3, rcAUX4 ;

int read8();
int read16();
int read32();

void evaluateCommand(int command);


void sendRequestMSP(std::vector<int8_t> data, Communication);

void sendRequestMSP_SET_RAW_RC(int channels[], Communication com);

void sendRequestMSP_SET_POS(int posArray[], Communication com);


void sendRequestMSP_GET_DEBUG(std::vector<int> requests,Communication com);

std::vector<int8_t> createPacketMSP(int msp, std::vector<int8_t>payload,Communication com);






private:



























};


#endif
