#include <commands.h>

void div0() {
    int a, b, c;
    a = 0;
    b = 1;
    c = b / a;
    a = c;
}
