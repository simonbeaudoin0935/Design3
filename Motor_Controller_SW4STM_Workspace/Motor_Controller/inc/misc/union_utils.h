#ifndef FLOAT_CONVERSION_H
#define FLOAT_CONVERSION_H

typedef union{
	float floating;
	char  bytes[sizeof(float)];
}floatUnion_t;

typedef union{
	int integer;
	char bytes[sizeof(int)];
}intUnion_t;


float readFloatUnion(char* ptr);
int   readIntUnion(char* ptr);

#endif //FLOAT_CONVERSION_H
