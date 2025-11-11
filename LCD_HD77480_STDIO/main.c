
#include <avr/io.h>

// ToDo: sterownik wyswietlacza zrealizowac jako modul niezalezny od mikrokontrolera 
#include "HD44780.h"

#include <stdio.h>
#include <avr/pgmspace.h>

int main(void)
{
    LCD_Initialize();
    
    LCD_WriteText("Test...");
    
    while (1) 
    {
    }
}

