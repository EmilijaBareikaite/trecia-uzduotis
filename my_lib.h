#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <chrono>
#include <random>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::setprecision;
using std::setw;
using std::left;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::to_string;
using std::list;
using namespace std::chrono;

struct studentas {
    string vard, pavard;
    vector <int> paz;
    int egz;
    float vidurkis, rez, mediana;
    int rusiavimas;
    
    bool operator<(const studentas& other) const{
        
        if(rusiavimas==1) {
            if (vard != other.vard) {
                return vard < other.vard;
            }
            return pavard < other.pavard;
        }
        else if (rusiavimas==2) {
            if (pavard != other.pavard) {
                return pavard < other.pavard;
            }
            return vard < other.vard;
        }
        else {return rez <other.rez;}
    }
};

struct l_studentas {
    string vard, pavard;
    list <int> paz;
    int egz;
    float vidurkis, rez, mediana;
    int rusiavimas;
    
    bool operator<(const l_studentas& other) const{
        
        if(rusiavimas==1) {
            if (vard != other.vard) {
                return vard < other.vard;
            }
            return pavard < other.pavard;
        }
        else if (rusiavimas==2) {
            if (pavard != other.pavard) {
                return pavard < other.pavard;
            }
            return vard < other.vard;
        }
        else {return rez <other.rez;}
    }
};

template <class T1, class T2> float gal_vid(const T1 &pazymiai, T2 &egzaminas) {
    float vidurkis, suma = 0;
    float rez;
    for (const auto &pazymys : pazymiai) {
        suma += pazymys;
    }
    vidurkis = suma / pazymiai.size();
    rez = 0.4 * vidurkis + 0.6 * egzaminas;
    return rez;
}

template <class T> void isvedimas_v(T grupe)
 {
    printf("%-25s%-20s%-15s\n", "Pavardė","Vardas","Galutinis (Vid.)" );
    cout<<"----------------------------------------------------------------"<<endl;
    for (auto &a: grupe)
    {
        cout<<left<<setw(24)<<a.pavard<<left<<setw(20)<<a.vard<<left<<setw(15)<<fixed<<setprecision(2)<<a.rez<<endl;
    }
}

template <class T> void isvedimas_m(T grupe) {

    printf("%-25s%-20s%-15s\n", "Pavardė","Vardas","Galutinis (Med.)" );
    cout<<"----------------------------------------------------------------"<<endl;
    for (auto &a: grupe)
    {
        cout<<left<<setw(24)<<a.pavard<<left<<setw(20)<<a.vard<<left<<setw(15)<<fixed<<setprecision(2)<<a.mediana<<endl;
    }
}

template <class T1> void rusiavimas_dv_gr(T1 grupe, T1 &vargsiukai, T1 &gudruciai) {
    auto start_2 = high_resolution_clock::now();
    
    for (auto &a: grupe) {if (a.rez<5) vargsiukai.push_back(a);
        else gudruciai.push_back(a);}
    
    auto end_2 = high_resolution_clock::now();
    
    duration<double> diff_2 = end_2-start_2;
    cout << to_string(grupe.size()) + " įrašų dalijimo i dvi grupes laikas: "<< diff_2.count() << " s\n";
}

void failo_skaitymas(string failo_kelias, struct studentas laikinas, vector<studentas> &grupe);
void isrusiuotas_spausdinimas(vector<studentas> vargsiukai, vector<studentas> gudruciai);
void egzamino_tikrinimas(int& egz, struct studentas laikinas);

float count_median_l(list<int>& pazymiai) ;
int generate_random_mark();
float count_median(vector<int> pazymiai);
void Generavimas_failo(int skaic);
void a_paz_tikrinimas(int& a_paz_kiekis);
void mokiniu_sk_patikrinimas(int& m);
void budo_patikrinimas(char& budas);
