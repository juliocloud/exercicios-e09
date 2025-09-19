#include <avr/io.h>

int main(void) {
    DDRD &= ~0b00100000;
    PORTD |= 0b00100000;

    while (1) {
        if (PIND & 0b00100000) {
            // botão solto
        } else {
            // botão pressionado
        }
    }

    return 0;
}
