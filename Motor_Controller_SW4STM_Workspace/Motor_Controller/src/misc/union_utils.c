#include "misc/union_utils.h"

float readFloatUnion(char* ptr){

	floatUnion_t v_floatUnion;

	v_floatUnion.bytes[0] = *ptr; ptr++;
	v_floatUnion.bytes[1] = *ptr; ptr++;
	v_floatUnion.bytes[2] = *ptr; ptr++;
	v_floatUnion.bytes[3] = *ptr;

	return v_floatUnion.floating;
}

int readIntUnion(char* ptr){

	intUnion_t v_intUnion;

	v_intUnion.bytes[0] = *ptr; ptr++;
	v_intUnion.bytes[1] = *ptr; ptr++;
	v_intUnion.bytes[2] = *ptr; ptr++;
	v_intUnion.bytes[3] = *ptr;

	return v_intUnion.integer;
}
