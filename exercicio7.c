#include <avr/io.h>

int main(void) {
    DDRD &= ~0b00000100;
    DDRD |= 0b00001000;

    while (1) {
        if (PIND & 0b00000100) {
            PORTD |= 0b00001000;
        } else {
            PORTD &= ~0b00001000;
        }
    }

    return 0;
}
