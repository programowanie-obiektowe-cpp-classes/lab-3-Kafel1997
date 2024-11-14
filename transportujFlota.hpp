#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    // Twoja implementacja tutaj
    if (towar == 0)
        return 0; 

    unsigned int przetransportowano = 0;
    unsigned int liczbaZaglowcow    = 0;
    Stocznia     stocznia;

    while (przetransportowano < towar) {
        Statek*      statek              = stocznia();
        unsigned int transportowanaIlosc = statek->transportuj();
        przetransportowano += transportowanaIlosc;

        
        if (dynamic_cast< Zaglowiec* >(statek) != nullptr) {
            liczbaZaglowcow++;
        }

        delete statek; 
    }

    return liczbaZaglowcow;
}