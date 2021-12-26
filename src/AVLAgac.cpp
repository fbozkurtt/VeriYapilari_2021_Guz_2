/**
* @file AVLAgac.cpp
* @description Doğru kuyruklarını tutan bir öncelikli AVL ağacı uygulaması.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment 2. Ödev
* @date 12.12.2021
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#include <iostream>
#include <cmath>
#include "AVLAgac.hpp"

#pragma region Kurucu

AVLAgac::AVLAgac()
{
	kok = NULL;
}

#pragma endregion

#pragma region Bilesenler

AgacDugum *AVLAgac::AraVeEkle(AgacDugum *alt_Dugum, const DogruKuyrugu &yeni)
{
	if (alt_Dugum == NULL)
	{
		alt_Dugum = new AgacDugum(yeni);
		//std::cout<<DogruKuyrugu::StringeCevir(alt_Dugum->VeriyiAl()) + "\n";
	}
	else if (yeni < alt_Dugum->VeriyiAl() || yeni == alt_Dugum->VeriyiAl())
	{
		alt_Dugum->sol = AraVeEkle(alt_Dugum->sol, yeni);

		if (Yukseklik(alt_Dugum->sol) - Yukseklik(alt_Dugum->sag) == 2)
		{
			if (yeni < alt_Dugum->sol->VeriyiAl())
				alt_Dugum = SolCocukIleDegistir(alt_Dugum);
			else
			{
				alt_Dugum->sol = SagCocukIleDegistir(alt_Dugum->sol);
				alt_Dugum = SolCocukIleDegistir(alt_Dugum);
			}
		}
	}
	else if (yeni > alt_Dugum->VeriyiAl())
	{
		alt_Dugum->sag = AraVeEkle(alt_Dugum->sag, yeni);

		if (Yukseklik(alt_Dugum->sag) - Yukseklik(alt_Dugum->sol) == 2)
		{
			if (yeni > alt_Dugum->sag->VeriyiAl())
				alt_Dugum = SagCocukIleDegistir(alt_Dugum);
			else
			{
				alt_Dugum->sag = SolCocukIleDegistir(alt_Dugum->sag);
				alt_Dugum = SagCocukIleDegistir(alt_Dugum);
			}
		}
	}

	alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
	return alt_Dugum;
}

AgacDugum *AVLAgac::SolCocukIleDegistir(AgacDugum *alt_Dugum)
{
	AgacDugum *gecici = alt_Dugum->sol;
	alt_Dugum->sol = gecici->sag;
	gecici->sag = alt_Dugum;

	alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
	gecici->yukseklik = std::max(Yukseklik(gecici->sol), alt_Dugum->yukseklik) + 1;

	return gecici;
}

AgacDugum *AVLAgac::SagCocukIleDegistir(AgacDugum *alt_Dugum)
{
	AgacDugum *gecici = alt_Dugum->sag;
	alt_Dugum->sag = gecici->sol;
	gecici->sol = alt_Dugum;

	alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
	gecici->yukseklik = std::max(Yukseklik(gecici->sag), alt_Dugum->yukseklik) + 1;

	return gecici;
}

std::string AVLAgac::Postorder(AgacDugum *alt_Dugum) const
{
	std::string s = "";
	if (alt_Dugum != NULL)
	{
		Postorder(alt_Dugum->sol);
		Postorder(alt_Dugum->sag);
		std::cout<<DogruKuyrugu::StringeCevir(alt_Dugum->VeriyiAl()) + "\n";
		// s += "\n";
		// std::cout << s;
	}
	return s;
}

int AVLAgac::Yukseklik(AgacDugum *alt_Dugum) const
{
	if (alt_Dugum == NULL)
		return -1;
	return 1 + std::max(Yukseklik(alt_Dugum->sol), Yukseklik(alt_Dugum->sag));
}

bool AVLAgac::DugumSil(AgacDugum *&alt_Dugum)
{
	AgacDugum *silinecekDugum = alt_Dugum;

	if (alt_Dugum->sag == NULL)
		alt_Dugum = alt_Dugum->sol;
	else if (alt_Dugum->sol == NULL)
		alt_Dugum = alt_Dugum->sag;
	else
	{
		silinecekDugum = alt_Dugum->sol;
		AgacDugum *ebeveynDugum = alt_Dugum;
		while (silinecekDugum->sag != NULL)
		{
			ebeveynDugum = silinecekDugum;
			silinecekDugum = silinecekDugum->sag;
		}
		alt_Dugum->VeriyiDegistir(silinecekDugum->VeriyiAl());
		if (ebeveynDugum == alt_Dugum)
			alt_Dugum->sol = silinecekDugum->sol;
		else
			ebeveynDugum->sag = silinecekDugum->sol;
	}
	delete silinecekDugum;
	return true;
}

bool AVLAgac::Ara(AgacDugum *alt_Dugum, const DogruKuyrugu &aranan)
{
	if (alt_Dugum == NULL)
		return false;
	if (alt_Dugum->VeriyiAl() == aranan)
		return true;
	if (aranan < alt_Dugum->VeriyiAl())
		return Ara(alt_Dugum->sol, aranan);
	if (aranan > alt_Dugum->VeriyiAl())
		return Ara(alt_Dugum->sag, aranan);

	return false; //Erisilemez kod
}

#pragma endregion

#pragma region Metotlar

bool AVLAgac::BosMu() const
{
	return kok == NULL;
}

void AVLAgac::Ekle(const DogruKuyrugu &yeni)
{
	kok = AraVeEkle(kok, yeni);
}

void AVLAgac::Temizle()
{
	while (!BosMu())
		DugumSil(kok);
}

int AVLAgac::Yukseklik() const
{
	return Yukseklik(kok);
}

std::string AVLAgac::PostorderOlarakStringeCevirVeTemizle()
{
	return Postorder(kok);
}

#pragma endregion

#pragma region Yikici

AVLAgac::~AVLAgac()
{
	Temizle();
}

#pragma endregion