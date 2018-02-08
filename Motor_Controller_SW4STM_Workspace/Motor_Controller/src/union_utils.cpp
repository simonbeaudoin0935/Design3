#include "../inc/union_utils.h"

float read_float(char *ptr){
	float_t val;
	val.bytes[0] = *ptr; ptr++;
	val.bytes[1] = *ptr; ptr++;
	val.bytes[2] = *ptr; ptr++;
	val.bytes[3] = *ptr;

	return val.floating;
}

int read_int(char* ptr){
	int_t val;
	val.bytes[0] = *ptr; ptr++;
	val.bytes[1] = *ptr; ptr++;
	val.bytes[2] = *ptr; ptr++;
	val.bytes[3] = *ptr;

	return val.integer;
}