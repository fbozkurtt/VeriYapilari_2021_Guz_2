/**
* @file UcBoyutluNokta.cpp
* @description Üç boyutlu uzaydaki nokta uygulaması.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment 1. Ödev
* @date 12.12.2021
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#include <cmath>
#include <iostream>
#include "UcBoyutluNokta.hpp"

UcBoyutluNokta::UcBoyutluNokta()
{
    X = 0;
    Y = 0;
    Z = 0;
}

UcBoyutluNokta::UcBoyutluNokta(int x, int y, int z)
{
    X = x;
    Y = y;
    Z = z;
}

int UcBoyutluNokta::UzakligiAl(int x, int y, int z) const
{
    int uzaklik = sqrt(pow(X - x, 2) + pow(Y - y, 2) + pow(Z - z, 2));
    return uzaklik;
}

int UcBoyutluNokta::UzakligiAl() const
{
    return UzakligiAl(0, 0, 0);
}

int UcBoyutluNokta::UzakligiAl(const UcBoyutluNokta &nokta) const
{
    return UzakligiAl(nokta.X, nokta.Y, nokta.Z);
}