/**
* @file DogruKuyrugu.hpp
* @description Üç boyutlu uzaydaki noktaları tutan bir öncelikli kuyruk uygulaması.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment 2. Ödev
* @date 12.12.2021
* @author Gruptakilerin yazar adları ve mail adresleri
*/

#ifndef DOGRUKUYRUGU_HPP
#define DOGRUKUYRUGU_HPP

#include <string>
#include "KuyrukDugum.hpp"

class DogruKuyrugu
{
private:
    std::string metin;
    KuyrukDugum *on;
    KuyrukDugum *arka;
    long ToplamUzunluk;
    int OnceligiAl(const KuyrukDugum *) const;
    KuyrukDugum *MinimumDugumunOncesi() const;

public:
    DogruKuyrugu();

    bool BosMu() const;
    void Ekle(const UcBoyutluNokta &);
    void MinimumuCikar();
    const UcBoyutluNokta MinimumuGoster() const;
    long ToplamUzunluguAl() const;
    std::string MetniAl() const;
    void MetniDegistir(std::string);
    void Temizle();

    static DogruKuyrugu Ayristir(std::string); // Parse
    static std::string StringeCevir(DogruKuyrugu);

    friend std::ostream &operator<<(std::ostream &, DogruKuyrugu &);
    bool operator<(DogruKuyrugu const &sag) const;
    bool operator>(DogruKuyrugu const &sag) const;
    bool operator==(DogruKuyrugu const &sag) const;
    ~DogruKuyrugu();
};

#endif