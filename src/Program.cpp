/**
* @file Program.cpp
* @description Programın giriş noktası. Yeni bir agac oluşturur ve bunu ekrana yazdırır.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment 2. Ödev
* @date 26.12.2021
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#include <iostream>
#include <string>
#include <fstream>
#include "AVLAgac.hpp"

using namespace std;

std::string StringeCevirVeBosalt(DogruKuyrugu &kuyruk)
{
    string s = "";
    while (!kuyruk.BosMu())
    {
        auto nokta = kuyruk.MinimumuGoster();
        kuyruk.MinimumuCikar();

        s += to_string(nokta.UzakligiAl());
        s += " ";
    }

    s += "\n";
    return s;
}

int main()
{
    auto agac = new AVLAgac();
    try
    {
        string yol = "./Noktalar.txt";
        string satir;
        ifstream girdiDosyasi(yol);

        if (!girdiDosyasi)
            throw "Belirtilen dosya bulunamadi! Lutfen Noktalar.txt dosyasini kok dizine yerlestirin.";

        while (getline(girdiDosyasi, satir))
        {
            auto kuyruk = DogruKuyrugu::Ayristir(satir); // Satiri kuyruga cevir. Ya da 'parse' et.
            agac->Ekle(kuyruk); // Olusan kuyrugu agaca ekle.
        }
        girdiDosyasi.close();
        cout << agac->PostorderOlarakStringeCevir(); // Agaci postorder olacak sekilde ekrana yazdir.
    }

    catch (const char *err)
    {
        cout << err << endl;
        return EXIT_FAILURE;
    }

    if (agac != NULL)
        delete agac;

    return EXIT_SUCCESS;
}