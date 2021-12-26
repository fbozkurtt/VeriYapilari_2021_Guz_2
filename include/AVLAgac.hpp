/**
* @file AVLAgac.cpp
* @description Doğru kuyruklarını tutan bir öncelikli AVL ağacı uygulaması.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment 2. Ödev
* @date 12.12.2021
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#ifndef AVLAGAC_HPP
#define AVLAGAC_HPP

#include <string>
#include "AgacDugum.hpp"

class AVLAgac
{
private:
	AgacDugum *kok;
	AgacDugum *AraVeEkle(AgacDugum *, const DogruKuyrugu &);
	AgacDugum *SolCocukIleDegistir(AgacDugum *);
	AgacDugum *SagCocukIleDegistir(AgacDugum *);
	std::string Postorder(AgacDugum *alt_Dugum) const;
	int Yukseklik(AgacDugum *alt_Dugum) const;
	bool DugumSil(AgacDugum *&alt_Dugum);
	bool Ara(AgacDugum *alt_Dugum, const DogruKuyrugu &aranan);

public:
	AVLAgac();
	bool BosMu() const;
	void Ekle(const DogruKuyrugu &yeni);
	void Temizle();
	std::string PostorderOlarakStringeCevirVeTemizle();
	int Yukseklik() const;
	~AVLAgac();
};

#endif