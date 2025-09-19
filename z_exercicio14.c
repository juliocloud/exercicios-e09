#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB &= ~0b00011110; 
    PORTB |= 0b00011110; // ativa pull-up,  liga o resistor interno
    DDRD |= 0b00001000;  

    uint8_t estado = 0;
    uint8_t botoes;

    while (1) {
        botoes = ~PINB & 0b00011110; // le botoes, inverte a logica

        switch (estado) {
            case 0:
                if (botoes == 0b00000100) {
                    estado = 1; 
                } else if (botoes != 0) {
                    estado = 0; // errou, reinicia
                }
                break;

            case 1:
                if (botoes == 0b00001100) {
                    estado = 2; 
                } else if (botoes != 0b00000100) {
                    estado = 0;
                }
                break;

            case 2:
                if (botoes == 0b00011100) {
                    estado = 3;
                } else if (botoes != 0b00001100) {
                    estado = 0;
                }
                break;

            case 3:
                if (botoes == 0b00011110) {
                    PORTD |= 0b00001000; 
                } else if (botoes != 0b00011100) {
                    estado = 0;
                }
                break;
        }

        if (botoes == 0) { 
            estado = 0;               
            PORTD &= ~0b00001000; // trava desligada
        }

        _delay_ms(10);
    }
}
