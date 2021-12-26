/**
* @file AgacDugum.hpp
* @description Doğru kuyruğunu tutan bir AVL ağacı düğümü uygulaması.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment 2. Ödev
* @date 12.12.2021
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#ifndef AGACDUGUM_HPP
#define AGACDUGUM_HPP

#include "DogruKuyrugu.hpp"

class AgacDugum
{
private:
    DogruKuyrugu veri;

public:
    int yukseklik;
    AgacDugum *sol;
    AgacDugum *sag;

    AgacDugum(const DogruKuyrugu &);
    AgacDugum(const DogruKuyrugu &, AgacDugum *, AgacDugum *);

    const DogruKuyrugu VeriyiAl() const;
    void VeriyiDegistir(const DogruKuyrugu &);

    ~AgacDugum();
};

#endif