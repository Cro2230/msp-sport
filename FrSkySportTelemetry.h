/*
  FrSky telemetry class for Teensy 3.x and 328P based boards (e.g. Pro Mini, Nano, Uno)
  (c) Pawelsky 20141120
  Not for commercial use
*/

#ifndef _FRSKY_SPORT_TELEMETRY_H_
#define _FRSKY_SPORT_TELEMETRY_H_

#include "Arduino.h"
#include "FrSkySportSensor.h"
#include "FrSkySportSingleWireSerial.h"

#define FRSKY_TELEMETRY_MAX_SENSORS 10

#define FRSKY_TELEMETRY_START_FRAME 0x7E

class FrSkySportTelemetry
{
  public:
    void begin(FrSkySportSingleWireSerial::SerialId id,
                FrSkySportSensor* sensor1, FrSkySportSensor* sensor2 = NULL,
                FrSkySportSensor* sensor3 = NULL, FrSkySportSensor* sensor4 = NULL,
                FrSkySportSensor* sensor5 = NULL, FrSkySportSensor* sensor6 = NULL,
                FrSkySportSensor* sensor7 = NULL, FrSkySportSensor* sensor8 = NULL,
                FrSkySportSensor* sensor9 = NULL, FrSkySportSensor* sensor10 = NULL);
    void send();

	void reset();

  private:
    FrSkySportSensor* sensors[FRSKY_TELEMETRY_MAX_SENSORS];
    FrSkySportSingleWireSerial serial;
    uint8_t  sensorCount;
    uint8_t  prevData;

};

#endif // _FRSKY_SPORT_TELEMETRY_H_
