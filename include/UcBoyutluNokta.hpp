/**
* @file UcBoyutluNokta.hpp
* @description Üç boyutlu uzaydaki nokta uygulaması.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment 2. Ödev
* @date 12.12.2021
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#ifndef UCBOYUTLUNOKTA_HPP
#define UCBOYUTLUNOKTA_HPP

class UcBoyutluNokta
{
public:
    int X;
    int Y;
    int Z;
    UcBoyutluNokta();
    UcBoyutluNokta(int, int, int);
    int UzakligiAl(int, int, int) const;
    int UzakligiAl() const;
    int UzakligiAl(const UcBoyutluNokta &) const;
};

#endif