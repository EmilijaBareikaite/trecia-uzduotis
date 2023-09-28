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
    printf("%-25s%-25s%-15s\n", "Pavardė","Vardas","Galutinis (Vid.)" );
    cout<<"----------------------------------------------------------------"<<endl;
    for (auto &a: grupe)
    {
        cout<<left<<setw(24)<<a.pavard<<left<<setw(25)<<a.vard<<left<<setw(15)<<fixed<<setprecision(2)<<a.rez<<endl;
    }
}

void isvedimas_m(vector<studentas> grupe) {
    printf("%-25s%-25s%-15s\n", "Pavardė","Vardas","Galutinis (Med.)" );
    cout<<"----------------------------------------------------------------"<<endl;
    for (auto &a: grupe)
    {
        cout<<left<<setw(24)<<a.pavard<<left<<setw(25)<<a.vard<<left<<setw(15)<<fixed<<setprecision(2)<<a.mediana<<endl;
    }

}



