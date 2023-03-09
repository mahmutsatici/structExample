

#include <iostream>
#include <sstream>  
#include <algorithm>
using namespace std;
struct ogrenci {
    string isim;
    string id;
    string nott;
};
void karsilastir(ogrenci dizi[], int boyut)
{
    for (int i = 0; i < boyut; i++)
    {
        for (int j = i + 1; j < boyut; j++)
        {
            if (dizi[j].nott > dizi[i].nott)
            {
                ogrenci temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }
        }
    }
}
int main()
{
    int ogrencisayisi;
    cout << "Ogrenci sayisini giriniz: " << endl;
    cin >> ogrencisayisi;
    ogrenci* dizi = new ogrenci[ogrencisayisi];

    for (int i = 0; i < ogrencisayisi; i++) {
        cout << "Ogrenci bilgilerini giriniz " << i + 1 << ":" << endl;
        cout << "Adi: ";
        cin >> dizi[i].isim;
        cout << "Ogrenci Numarasi: ";
        cin >> dizi[i].id;
        cout << "Not: ";
        cin >> dizi[i].nott;

    }

    cout << "Ogrenci Numarasina Gore Arama Yapmak Icin 1 girin" << endl;
    cout << "Ogrencileri Ortalamasina gore siralamak Icin 2 girin" << endl;
    cout << "Tum ogrencilerin ortalamasini hesaplamak Icin 3 girin" << endl;
    cout << "Seciminiz: ";
    string secim;
    cin >> secim;
    string aranan;
    bool kontrol = false;
    int ogrencinotu;
    double toplam = 0;
    switch (secim[0])
    {
    case '1':
        cout << "Aramak istediginiz ogrenci numarasini giriniz: ";
        cin >> aranan;
        for (int i = 0; i < ogrencisayisi; i++)
        {
            if (dizi[i].id == aranan)
            {
                cout << "Aradiginiz kullanici: " << endl;
                cout << "Adi: " << dizi[i].isim << endl;
                cout << "Ogrenci Numarasi: " << dizi[i].id << endl;
                cout << "Not: " << dizi[i].nott << endl;
                kontrol = true;
            }
        }
        if (kontrol) {}
        else
        {
            cout << "Aranan kullanici bulunamadi.";
        }
        break;
    case '2':

        karsilastir(dizi, ogrencisayisi);
        cout << "Ogrencilerin siralamasi:" << endl;

        for (int i = 0; i < ogrencisayisi; i++) {
            cout << "Isim: " << dizi[i].isim << "    Numara: " << dizi[i].id << "    Not: " << dizi[i].nott << endl;
        }
        break;
    case '3':
        for (int i = 0; i < ogrencisayisi; i++)
        {
            ogrencinotu = stoi(dizi[i].nott);
            toplam = toplam + ogrencinotu;
        }
        cout << "Ogrencilerin Ortalamasi: " << toplam / ogrencisayisi << endl;
        break;
    default:
        break;
    }


    return 0;
}

