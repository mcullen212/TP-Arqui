//Keyboard driver
#include <keyboardDriver.h>


static char shiftPressed = 0;
static char capsLockPressed = 0;

char keyMap[][2] = { // [cantidad de teclas][2]
                      // primer elemento es la tecla que presionas y el segundo es la tecla sumada con shift
        {0, 0},
        {0, 0}, // esc key 
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
        {'\b', 128},
        {'\t', '\t'},
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
        {'\n', '\n'},
        {0, 0},
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

uint8_t getKeyMapping(uint64_t number) {
    if(number == LEFT_SHIFT_NBR  || number == RIGHT_SHIFT_NBR){
        shiftPressed = 1;
    }

    if(number == LEFT_SHIFT_RELEASED || number == RIGHT_SHIFT_RELEASED){
        shiftPressed = 0;
    }

    if(number >= RELEASED){
        return 0;
    }

    if(shiftPressed){
        return keyMap[number][1];
    }
    return keyMap[number][0];
}

uint8_t getKeyPressed() {
    return getKeyMapping(getKeyNumber());
}
