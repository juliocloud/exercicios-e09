#include <avr/io.h>

int main(void) {
    DDRB &= ~0b00011111;
    PORTB |= 0b00011111;
    DDRD |= 0b00000001;
    DDRC |= 0b00000001;

    int entradas;
    while (1) {
        entradas = PINB & 0b00011111;

        if (entradas == 0b00010101 || entradas == 0b00001010) {
            PORTD |= 0b00000001;
            PORTC &= ~0b00000001;
        } else if (entradas == 0b00011111 || entradas == 0b00000000) {
            PORTD &= ~0b00000001;
            PORTC |= 0b00000001;
        } else {
            PORTD &= ~0b00000001;
            PORTC &= ~0b00000001;
        }
    }
    return 0;
}
