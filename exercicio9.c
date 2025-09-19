#include <avr/io.h>

int main(void) {
    DDRD |= 0b01110000;

    while (1) {
        PORTD |= 0b01110000;
    }

    return 0;
}
