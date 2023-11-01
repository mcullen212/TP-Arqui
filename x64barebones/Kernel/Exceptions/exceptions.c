#include <exceptions.h>

#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_EXCEPTION_ID 6

void (*exceptionsHandlers[MAX_EXCEPTION])(char * exception, uint64_t * registers);

void exceptionDispatcher(uint64_t exception) {
    switch(exception) {
        case ZERO_EXCEPTION_ID :
            //exceptionsHandlers[ZERO_EXCEPTION_ID]("ERROR - Division by Zero", );
            break;
        case INVALID_OPCODE_EXCEPTION_ID :
            //exceptionsHandlers[INVALID_OPCODE_EXCEPTION_ID]("ERROR - Ivalid Opcode", );
            break;
    }
}

void setExceptionHandler(uint64_t number, exceptionHandler exception) {
    exceptionsHandlers[number] = exception;
}
