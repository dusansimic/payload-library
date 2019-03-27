#ifndef _PAYLOAD_H_
#define _PAYLOAD_H_

#include <stdint.h>

union int32union;
union int16union;
typedef uint8_t byte;

class Payload {
	private:
		byte *data;
		byte payloadSize;
	public:
		Payload();
		Payload(byte *data);
		void addInteger(int32_t data);
		void addShort(int16_t data);
		void addByte(byte data);
		void clear();
		byte* getPayload();
    operator byte*();
};

#endif
