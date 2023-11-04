//Keyboard driver
#include <keyboardDriver.h>
#include <videoDriver.h>

static char shiftPressed = 0;
static char capsLockPressed = 0;
static char altPressed = 0;
static char buffer[BUFFER_SIZE];
static unsigned long index = 0;
static unsigned long currentKey = 0;

static char flag = 0;

static char * registersName[REGISTERS_AMOUNT] = {"R15 = ", "R14 = ", "R13 = ", "R12 = ", "R11 = ", "R10 = ", "R9 = ", "R8 = ", "RSI = ", "RDI = ", "RBP = ", "RDX = ", "RCX = ", "RBX = ", "RAX = ", "RIP  = ", "CS = ", "RFLAGS = ", "RSP = ", "SS = "};
static uint64_t currentRegisters[REGISTERS_AMOUNT];

static uint64_t binaryToHex(uint64_t binaryNum);
static void uint64HexaToString(uint64_t valorHexa, char *hexaString);

char keyMap[][2] = { // [cantidad de teclas][2] => teclado estandar en ingles
                     // primer elemento es la tecla que presionas
                     // y el segundo es la tecla sumada con shift
        {0, 0},
        {27, 27}, // esc key
        {'1', '!'},
        {'2', '@'},
        {'3', '#'},
        {'4', '$'},
        {'5', '%'},
        {'6', '^'},
        {'7', '&'},
        {'8', '*'},
        {'9', '('},
        {'0', ')'},
        {'-', '_'},
        {'-', '+'},
        {'\b', '\b'}, // delete
        {'\t', '\t'}, //tab
        {'q', 'Q'},
        {'w', 'W'},
        {'e', 'E'},
        {'r', 'R'},
        {'t', 'T'},
        {'y', 'Y'},
        {'u', 'U'},
        {'i', 'I'},
        {'o', 'O'},
        {'p', 'P'},
        {'[', '{'},
        {']', '}'},
        {'\n', '\n'}, //enter
        {0, 0}, //ctrl
        {'a', 'A'},
        {'s', 'S'},
        {'d', 'D'},
        {'f', 'F'},
        {'g', 'G'},
        {'h', 'H'},
        {'j', 'J'},
        {'k', 'K'},
        {'l', 'L'},
        {';', ':'},
        {'\'', '\"'},
        {167, '~'},
        {0, 0}, // left shift
        {'\\', '|'},
        {'z', 'Z'},
        {'x', 'X'},
        {'c', 'C'},
        {'v', 'V'},
        {'b', 'B'},
        {'n', 'N'},
        {'m', 'M'},
        {',', '<'},
        {'.', '>'},
        {'/', '?'},
        {0, 0}, // right shift
        {0, 0}, //(keypad) * pressed
        {0, 0}, //left alt pressed
        {' ', ' '} // space
    };

void keyHandler(uint64_t * registers) {
    uint64_t number = getKeyNumber();

    if( shiftPressed && number == LEFT_ALT_PRESSED){
        updateRegs(registers);
    }

    if( number == ESC_PRESSED || number == CTRL_PRESSED ){ // if esc or ctrl is pressed, do nothing
        return;
    }

    if(number == LEFT_SHIFT_PRESSED  || number == RIGHT_SHIFT_PRESSED){
        shiftPressed = 1;   // if shift is pressed, turn it on
        return;
    }

    if(number == LEFT_SHIFT_RELEASED || number == RIGHT_SHIFT_RELEASED){
        shiftPressed = 0;   // if shift is released, turn it off
        return;
    }
    if(number == CAPS_LOCK_PRESSED){
        capsLockPressed = 1 - capsLockPressed; // if caps lock is pressed, turn it off
        return;
    }

    if(number == LEFT_ALT_PRESSED){
        altPressed = 1;
        return;
    }
    if(number == LEFT_ALT_RELEASED){
        altPressed = 0;
        return;
    }

    if(number >= RELEASED){
        return; // if key is released, do nothing
    }

    if (shiftPressed) {
        buffer[index % BUFFER_SIZE] = keyMap[number][1];
        index++;
        return;
    }

    if (capsLockPressed /* Agregar Condicion*/) {
        buffer[index % BUFFER_SIZE] = keyMap[number][1]; // add the key to the buffer
        index++;
        return;
    }

    buffer[index % BUFFER_SIZE] = keyMap[number][0];
    index++;
}

void readFromKeyboard(uint8_t * toRetbuffer, uint32_t amount, uint32_t * size) {
    int j;
    int toConsume = index - currentKey;
    for (j = 0; j < toConsume && j < amount; j++) {
        toRetbuffer[j] = buffer[currentKey % BUFFER_SIZE];
        currentKey++;
    }
    *size = j;
}

char savedRegs() {
    return flag;
}

void updateRegs(uint64_t * registers) {
    flag = 1;
    for(int i = 0; i < REGISTERS_AMOUNT; i++){
        currentRegisters[i] = registers[i];
    }
}

void valueToHexString(unsigned long long value, uint8_t * hexStr) {
    static const uint8_t hexDigits[] = "0123456789ABCDEF";
    int i;

    hexStr[0] = '0';
    hexStr[1] = 'x';

    for (i = 0; i < 16; i++) {
        hexStr[18 - i] = hexDigits[(value >> (i * 4)) & 0xF];
        if(hexStr[18-i]== 0){
            hexStr[18-i]='1';
        }
    }
    hexStr[19] = '\0';
}

void copyRegisters(uint64_t num, char*buffer){
    num = binaryToHex(num);
    uint64HexaToString(num, buffer);
}

static uint64_t binaryToHex(uint64_t binaryNum){
    return binaryNum;
}

static void uint64HexaToString(uint64_t valorHexa, char *hexaString) {
    int i;
    for (i = 15; i >= 0; i--) {
        uint64_t nibble = (valorHexa >> (i * 4)) & 0xF;
        hexaString[15 - i] = (nibble < 10) ? (char)('0' + nibble) : (char)('A' + (nibble - 10));
    }
    hexaString[16] = 'h';
    hexaString[17] = '\0'; // Terminar la cadena con el carácter nulo
}

uint8_t * getRegisterName(int index){
    return (uint8_t *)registersName[index];
}

uint64_t getRegisterValue(int index){
    return currentRegisters[index];
}


