#include "my_lib.h"

int generate_random_mark() //sugeneruojamas random skaic nuo 1 iki 10
{
    srand(time(NULL));
    return (rand() % 10) + 1;
}

float count_median(vector<int> pazymiai) //funkcija skaiciuoja mediana
{
    sort(pazymiai.begin(), pazymiai.end());
    float mediana;
    if (pazymiai.size() % 2 == 0)
    {
        mediana = (pazymiai.at(pazymiai.size()/2) + pazymiai.at((pazymiai.size()/2)-1))/2.0;
    }
    else
    {
        mediana = pazymiai.at(pazymiai.size()/2);
    }
    return mediana;
}

float gal_vid(vector<int> pazymiai, int egzaminas) {
    float vidurkis, suma = 0;
    float rez;
    for (int i = 0; i < pazymiai.size(); i++) {
        suma = suma + pazymiai.at(i);
    }
    vidurkis = suma / pazymiai.size();
    rez = 0.4 * vidurkis + 0.6 * egzaminas;
    return rez;
}

void isvedimas_v(vector<studentas> grupe) {
    printf("%-25s%-20s%-15s\n", "Pavardė","Vardas","Galutinis (Vid.)" );
    cout<<"----------------------------------------------------------------"<<endl;
    for (auto &a: grupe)
    {
        cout<<left<<setw(24)<<a.pavard<<left<<setw(20)<<a.vard<<left<<setw(15)<<fixed<<setprecision(2)<<a.rez<<endl;
    }
}

void isvedimas_m(vector<studentas> grupe) {
    printf("%-25s%-20s%-15s\n", "Pavardė","Vardas","Galutinis (Med.)" );
    cout<<"----------------------------------------------------------------"<<endl;
    for (auto &a: grupe)
    {
        cout<<left<<setw(24)<<a.pavard<<left<<setw(20)<<a.vard<<left<<setw(15)<<fixed<<setprecision(2)<<a.mediana<<endl;
    }

}

void isvedimas_f(vector<studentas> grupe) {
    printf("%-25s%-18s%-20s%-15s\n", "Pavardė","Vardas","Galutinis (Vid.)","Galutinis (Med.)");
    cout<<"------------------------------------------------------------------------------"<<endl;
    for (auto &a: grupe)
    {
        cout<<left<<setw(24)<<a.pavard<<left<<setw(18)<<a.vard<<left<<setw(20)<<fixed<<setprecision(2)<<a.rez<<left<<setw(15)<<fixed<<setprecision(2)<<a.mediana<<endl;
    }

}

void mokiniu_sk_patikrinimas(int& m) {
    
    try {if (cin.fail() || m < 0)
    {
        throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių");}
    }
    catch (const std::invalid_argument& e) {
        std::cerr<< e.what()<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Įveskite iš naujo: ";
        cin>>m;
        mokiniu_sk_patikrinimas(m);
    
    }
}

void budo_patikrinimas(char& budas) {
    
    try { if ((budas!='m' && budas!='a') || cin.fail()==true)
    throw std::invalid_argument("Netinkamas atsakymas suvedimui. Prašome įvesti 'm' arba 'a'."); }
        
    catch (const std::invalid_argument& e) {
        std::cerr<< e.what()<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Įveskite iš naujo: ";
        cin>>budas;
        budo_patikrinimas(budas);
    }
}
void egzamino_tikrinimas(int& egz, struct studentas laikinas) {
    try {if (cin.fail() || egz <= 0 || egz>10) throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių tarp 1 ir 10");
    }
    catch (const std::invalid_argument& e) {
        std::cerr<< e.what()<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Įveskite iš naujo: ";
        cin>>egz;
        laikinas.egz = egz;
        egzamino_tikrinimas(egz, laikinas);
    }
}

void a_paz_tikrinimas(int& a_paz_kiekis) {
    try {if (cin.fail() || (a_paz_kiekis < 0)) {
        throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių");
    }
        else if (a_paz_kiekis == 0) { throw std::invalid_argument("Netinkamai įvesta, negalima dalyba iš 0. Prašome įvesti didesnį už nulį teigiamą sveiką skaičių");}}
    catch (const std::invalid_argument& e) {
        std::cerr<< e.what()<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Įveskite iš naujo: ";
        cin>>a_paz_kiekis;
        a_paz_tikrinimas(a_paz_kiekis);
    }
}

