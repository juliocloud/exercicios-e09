#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRD &= ~0b00100000;

    while (1) {
        PORTD ^= 0b00100000;
        _delay_ms(1000);
    }

    return 0;
}
