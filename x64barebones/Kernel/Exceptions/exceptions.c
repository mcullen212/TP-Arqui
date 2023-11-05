#include <exceptions.h>
#include <keyboardDriver.h>
#include <interruptions.h>

#define ZERO_EXCEPTION_ID  0
#define INVALID_OPCODE_EXCEPTION_ID 6

void (*exceptionsHandlers[MAX_EXCEPTION])(uint64_t exceptionCode, char * errorMessage);

void exceptionDispatcher(uint64_t exception, uint64_t * registers) {
    updateRegs(registers);
    _sti();
    switch(exception) {
        case ZERO_EXCEPTION_ID :
            exceptionsHandlers[ZERO_EXCEPTION_ID]((uint64_t) ZERO_EXCEPTION_ID, "ERROR - Division by Zero\n");
            break;
        case INVALID_OPCODE_EXCEPTION_ID :
            exceptionsHandlers[INVALID_OPCODE_EXCEPTION_ID]((uint64_t) INVALID_OPCODE_EXCEPTION_ID, "ERROR - Ivalid Opcode\n");
            break;
    }
}

void setExceptionHandler(uint64_t number, exceptionHandler exception) {
    exceptionsHandlers[number] = exception;
}
