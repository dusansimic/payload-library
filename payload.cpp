#include <stdlib.h>
#include <stdint.h>
#include "payload.hpp"

union int32_union {
	int32_t intData;
	byte byteData[4];
} int32_union;
union int16_union {
	int16_t shortData;
	byte byteData[2];
} int16_union;

Payload::Payload() {
	data = new byte[0];
	payloadSize = 0;
}

void Payload::addInteger(int32_t data) {
	// Increace payload size and realloc data array
	this->payloadSize+=4;
	this->data = (byte*) realloc(this->data, this->payloadSize * sizeof(byte));
	// Load new data into union for converting
	int32_union.intData = data;
	// Create a pointer to insert new data
	byte* dataWalk = this->data;
	dataWalk+=this->payloadSize-4;

	// Insert new data
	for (byte i = 0; i < 4; i++) {
		*dataWalk++ = int32_union.byteData[i];
	}
}

void Payload::addShort(int16_t data) {
	// Increace payload size and realloc data array
	this->payloadSize+=2;
	this->data = (byte*) realloc(this->data, this->payloadSize * sizeof(byte));
	// Load new data into union for converting
	int16_union.shortData = data;
	// Create a pointer to insert new data
	byte* dataWalk = this->data;
	dataWalk += this->payloadSize-4;

	// Insert new data
	for (byte i = 0; i < 2; i++)
		*dataWalk++ = int32_union.byteData[i];
}

void Payload::addByte(byte data) {
	// Increace payload size and realloc data array
	this->payloadSize++;
	this->data = (byte*) realloc(this->data, this->payloadSize * sizeof(byte));
	// Insert new data
	this->data[this->payloadSize - 1] = data;
}

void Payload::clear() {
	// Clear data array
	this->payloadSize = 0;
	delete this->data;
	this->data = new byte[0];
}

byte* Payload::getPayload() {
	return this->data;
}

Payload::operator byte*() {
	return this->data;
}
