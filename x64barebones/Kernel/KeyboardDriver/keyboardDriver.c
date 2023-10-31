//Keyboard driver
#include <keyboardDriver.h>


static char shiftPressed = 0;
static char capsLockPressed = 0;
static char buffer[BUFFER_SIZE];
static unsigned long index = 0;
static unsigned long currentKey = 0;

char keyMap[][2] = { // [cantidad de teclas][2] => teclado estandar en ingles
                     // primer elemento es la tecla que presionas
                     // y el segundo es la tecla sumada con shift
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

void keyHandler() {
    uint64_t number = getKeyNumber();
    if(number == LEFT_SHIFT_PRESSED  || number == RIGHT_SHIFT_PRESSED){
        shiftPressed = 1;   // Si se presiona el Shift, prende el flag
        return;
    }

    if(number == LEFT_SHIFT_RELEASED || number == RIGHT_SHIFT_RELEASED){
        shiftPressed = 0;   // Si se suelta el Shift, lo apagar
        return;
    }
    if(number == CAPS_LOCK_PRESSED){
        capsLockPressed = 1 - capsLockPressed; // Toggle de la tecla CapsLock
        return;
    }

    if(number >= RELEASED){
        return; // Si la teclsa es mayor a RELEASED y no es ninguna especial, no nos interesa que se suelte.
    }

    if (shiftPressed) {
        buffer[index % BUFFER_SIZE] = keyMap[number][1];
        index++;
        return;
    }

    if (capsLockPressed /* Agregar Condicion*/) {
        buffer[index % BUFFER_SIZE] = keyMap[number][1];    // Agrego al buffer la tecla, y me guardo cual fue la ultima.
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


