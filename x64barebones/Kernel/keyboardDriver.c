//Keyboard driver
#include <keyboardDriver.h>

uint8_t keyValues[] = {'\0', '\0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '+', 8, '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 10, 17, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 15, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 15, '\0', '\0', ' ', '\0'};
    //Key Number      0   1    2    3    4    5    6    7    8    9   10    11   12   13  14  15   16   17   18   19   20   21   22   23   24   25   26   27   28  29  30   31   32   33   34   35   36   37   38   39   40    41   42   43   44   45   46   47   48   49   50   51   52   53   54   55   56    57   58

uint8_t getKeyMapping(uint64_t number) {
    return keyValues[number];
}

uint8_t getKeyPressed() {
    return getKeyMapping(getKeyNumber());
}
