#include <avr/io.h>

int main(void) {
    DDRD &= ~0b00000111; 
    DDRD |= 0b10000000;
    if ((DDRD & 0b00000111) == 0b00000000) {
        PORTD |= 0b10000000;
    }

    while (1) {
      
    }

    return 0;
}
