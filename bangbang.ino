#include <Servo.h>

#define PIN_SERVO 10
#define PIN_IR A0

float ir_distance();

Servo ser;


void setup()
{
	ser.attach(PIN_SERVO);
	ser.writeMicroseconds(1610);
	Serial.begin(57600);
}


void loop()
{
	float dist = ir_distance();
	Serial.print("min:200,max:600,volt:");
	Serial.println(dist);
	if (dist < 255)
		ser.writeMicroseconds(1610+50);
	if (dist >= 255)
		ser.writeMicroseconds(1610-50);
	delay(100);
}


float ir_distance()
{
	static float val;
	float volt = float(analogRead(PIN_IR));
	val = 63158.4/(volt-58.2)-8;
	return val;
	return val = 0.1 * volt + 0.9 * val;
	val = ((6762.0/(volt-9.0))-4.0) * 10.0;
	return val;
}
// vim: ft=cpp ts=4 sw=4 noet
