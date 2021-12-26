/**
* @file AgacDugum.cpp
* @description Çift yönlü bağlı liste için bir düğüm uygulaması.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment 2. Ödev
* @date 13.11.2021
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#include "AgacDugum.hpp"
#include "DogruKuyrugu.hpp"

AgacDugum::AgacDugum(const DogruKuyrugu &veri)
{
    this->sol = NULL;
    this->sag = NULL;
    this->veri = veri;
}

AgacDugum::AgacDugum(const DogruKuyrugu &veri, AgacDugum *sol, AgacDugum *sag)
{
    this->sol = sol;
    this->sag = sag;
    this->veri = veri;
}

const DogruKuyrugu AgacDugum::VeriyiAl() const
{
    return veri;
}

void AgacDugum::VeriyiDegistir(const DogruKuyrugu &veri)
{
    this->veri = veri;
}

AgacDugum::~AgacDugum()
{
    veri.Temizle();
}