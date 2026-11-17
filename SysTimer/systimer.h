/** @file systimer.h */

/**
  *
  * @author B.W.
  * @date 2024/11/01
  *
  * Inicjalizacja licznika Timer1 (16 bitowy) w trybie CTC, tak by umozliwial
  * generowanie przerwania co scisle okreslony czas. 
  *
  * @note wersja testowa
  *
  */

#ifndef SYSTIMER_H_
#define SYSTIMER_H_

#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#ifndef F_CPU
#define F_CPU 14745600UL
#warning F_CPU is defined as 14745600UL in systimer.h
#endif

/**
  * Stale wykorzystane jako wartosc zwracana przez dunkcje systimer_init
  */
#define SYSTIMER_NO_ERROR 0   /**< Licznik skonfigurowany poprawnie */
#define SYSTIMER_ERROR_1  1   /**< Licznik nie bedzie dokladnie odmierzac czasu */
#define SYSTIMER_ERROR_2  2   /**< Nie udalo sie skonfigurowac licznika */

/**
  * Funkcja pozwalajaca skonfigurowac licznik Timer1 tak by pozwalal na genetacje
  * przerwania o okreslony czas.
  *
  * @param  systick watrosc czasu podana w [ms]
  * @return zwraca kod okreslajacy, czy licznik udalo sie poprawnie skonfigurowac
  *         i z jaka dokladnoscia bedzie odmierzany czas
  *
  */
uint8_t systimer_init(uint16_t systick);

/**
  * Funkcja obslugi przerwania od porownania licznika Timer1. Zawiera wywolanie
  * tzw. funkcji zwrotnej, ktora zdefiniowana w aplikacji bedzie wywolywana
  * cyklicznie co czas @c systick.
  *
  * @param  brak
  * @return brak
  *
  */


#endif /* SYSTIMER_H_ */
