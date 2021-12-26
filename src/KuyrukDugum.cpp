/**
* @file KuyrukDugum.cpp
* @description Çift yönlü bağlı liste için bir düğüm uygulaması.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment 2. Ödev
* @date 13.11.2021
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#include "AgacDugum.hpp"
#include "DogruKuyrugu.hpp"

#pragma region Kurucu

KuyrukDugum::KuyrukDugum(const UcBoyutluNokta &veri)
{
    this->veri = veri;
    this->sonraki = NULL;
}

KuyrukDugum::KuyrukDugum(const UcBoyutluNokta &veri, KuyrukDugum *sonraki)
{
    this->veri = veri;
    this->sonraki = sonraki;
}

#pragma endregion

#pragma region Metotlar

const UcBoyutluNokta KuyrukDugum::VeriyiAl() const
{
    return veri;
}

#pragma endregion