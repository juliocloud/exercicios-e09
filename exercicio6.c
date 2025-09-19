#include <avr/io.h>

int main(void) {
    DDRD |= 0b11000000;
    DDRD &= ~0b01000000;

    while (1) {
        PORTD |= 0b10000000; 
    }

    return 0;
}
