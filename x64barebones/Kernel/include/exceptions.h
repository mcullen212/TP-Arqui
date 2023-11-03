#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdint.h>

#define MAX_EXCEPTION 20

#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_EXCEPTION_ID 6


typedef void (*exceptionHandler)(char * exception);

void setExceptionHandler(uint64_t number, exceptionHandler exception);

#endif
