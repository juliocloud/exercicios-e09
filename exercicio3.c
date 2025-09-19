#include <avr/io.h>
#include <util/delay.h> 

int main(void) {
    DDRD |= 0b00001000; 
    DDRB |= 0b00010000; 

    while (1) {
        PORTD ^= 0b00001000;
        PORTB ^= 0b00010000;
        _delay_ms(42); 
    }

    return 0;
}
