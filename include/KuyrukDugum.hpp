/**
* @file KuyrukDugum.hpp
* @description Üç boyutlu uzaydaki bir noktayı tutan öncelikli kuyruk düğümü uygulaması.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment 2. Ödev
* @date 12.12.2021
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#ifndef KUYRUKDUGUM_HPP
#define KUYRUKDUGUM_HPP

#include "UcBoyutluNokta.hpp"

class KuyrukDugum
{
private:
    UcBoyutluNokta veri;

public:
    KuyrukDugum *sonraki;
    KuyrukDugum(const UcBoyutluNokta &);
    KuyrukDugum(const UcBoyutluNokta &, KuyrukDugum *);
    const UcBoyutluNokta VeriyiAl() const;
};

#endif