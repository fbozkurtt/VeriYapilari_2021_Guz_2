/**
* @file DogruKuyrugu.cpp
* @description Üç boyutlu uzaydaki noktaları tutan bir öncelikli kuyruk uygulaması.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment 2. Ödev
* @date 12.12.2021
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#include <iostream>
#include <string>
#include <sstream>
#include "DogruKuyrugu.hpp"

#pragma region Kurucu

DogruKuyrugu::DogruKuyrugu()
{
    ToplamUzunluk = 0;
    on = NULL;
    arka = NULL;
}

#pragma endregion

#pragma region Bilesenler

int DogruKuyrugu::OnceligiAl(const KuyrukDugum *dugum) const
{
    return dugum->VeriyiAl().UzakligiAl();
}

KuyrukDugum *DogruKuyrugu::MinimumDugumunOncesi() const
{
    if (on == NULL)
        throw "Kuyruk bos!";

    auto minOncelik = OnceligiAl(on);
    auto gecici = on;
    KuyrukDugum *minDugumunOncesi = NULL;

    while (gecici->sonraki != NULL)
    {
        auto suankiOncelik = OnceligiAl(gecici->sonraki);
        if (suankiOncelik < minOncelik)
        {
            minOncelik = suankiOncelik;
            minDugumunOncesi = gecici;
        }
        gecici = gecici->sonraki;
    }

    return minDugumunOncesi;
}

#pragma endregion

#pragma region Metotlar

bool DogruKuyrugu::BosMu() const
{
    return on == NULL;
}

void DogruKuyrugu::Ekle(const UcBoyutluNokta &nokta)
{
    auto yeniDugum = new KuyrukDugum(nokta);

    if (arka != NULL)
    {
        ToplamUzunluk += arka->VeriyiAl().UzakligiAl(yeniDugum->VeriyiAl());
    }

    if (on == NULL)
        on = arka = yeniDugum;

    else
    {
        arka->sonraki = yeniDugum;
        arka = yeniDugum;
    }

    //metin = StringeCevir(*this);
}

void DogruKuyrugu::MinimumuCikar()
{
    if (on == NULL)
        throw "Kuyruk bos!";

    KuyrukDugum *gecici;
    auto minDugumOncesi = MinimumDugumunOncesi();

    if (minDugumOncesi == NULL)
    {
        gecici = on;
        on = on->sonraki;
    }
    else
    {
        if (minDugumOncesi->sonraki == arka)
            arka = minDugumOncesi;

        gecici = minDugumOncesi->sonraki;
        minDugumOncesi->sonraki = minDugumOncesi->sonraki->sonraki;
    }

    delete gecici;
}

const UcBoyutluNokta DogruKuyrugu::MinimumuGoster() const
{
    auto minDugumOncesi = MinimumDugumunOncesi();

    if (minDugumOncesi == NULL)
        return on->VeriyiAl();
    else
        return minDugumOncesi->sonraki->VeriyiAl();
}

long DogruKuyrugu::ToplamUzunluguAl() const
{
    return ToplamUzunluk;
}

std::string DogruKuyrugu::MetniAl() const
{
    return metin;
}

void DogruKuyrugu::MetniDegistir(std::string metin)
{
    this->metin = metin;
}

std::string DogruKuyrugu::StringeCevir(DogruKuyrugu kuyruk)
{
    std::string s = "";
    while (!kuyruk.BosMu())
    {
        auto nokta = kuyruk.MinimumuGoster();
        kuyruk.MinimumuCikar();

        s += std::to_string(nokta.UzakligiAl());
        s += " ";
    }

    return s;
}

void DogruKuyrugu::Temizle()
{
    while (on != NULL)
        MinimumuCikar();
}

DogruKuyrugu DogruKuyrugu::Ayristir(std::string s)
{
    DogruKuyrugu kuyruk;

    std::string simge;
    std::stringstream sstream(s);

    auto sayac = 1;
    int x, y, z;

    while (getline(sstream, simge, ' '))
    {
        if (sayac == 1)
            x = stoi(simge);

        if (sayac == 2)
            y = stoi(simge);

        if (sayac == 3)
        {
            z = stoi(simge);

            auto nokta = new UcBoyutluNokta(x, y, z);
            kuyruk.Ekle(*nokta);
            sayac = 1;
            continue;
        }
        sayac++;
    }

    if (sayac != 1)
        throw "Sayi adedi ucun katlari olmali!";

    kuyruk.MetniDegistir(DogruKuyrugu::StringeCevir(kuyruk));
    return kuyruk;
}

std::ostream &operator<<(std::ostream &sol, DogruKuyrugu &sag)
{
    auto suanki = sag.on;

    while (suanki != NULL)
    {
        auto nokta = suanki->VeriyiAl();

        sol << nokta.UzakligiAl() << " ";
        suanki = suanki->sonraki;
    }

    return sol;
}

bool DogruKuyrugu::operator<(DogruKuyrugu const &sag) const
{
    return this->ToplamUzunluk < sag.ToplamUzunluk;
}
bool DogruKuyrugu::operator>(DogruKuyrugu const &sag) const
{

    return this->ToplamUzunluk > sag.ToplamUzunluk;
}
bool DogruKuyrugu::operator==(DogruKuyrugu const &sag) const
{

    return this->ToplamUzunluk == sag.ToplamUzunluk;
}

#pragma endregion

#pragma region Yikici

DogruKuyrugu::~DogruKuyrugu()
{
    Temizle();

    if (on != NULL)
        delete on;

    if (arka != NULL)
        delete arka;
}

#pragma endregion