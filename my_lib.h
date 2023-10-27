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

template <class T1, class T2, class T3> void failo_skaitymas(T1 failo_kelias, T2 laikinas, T3 &grupe){
    auto start_1 = high_resolution_clock::now();
    ifstream myfile(failo_kelias);
    int count_nd_words = 0;
    
    if(myfile.fail() == true) {cout<<"nepavyko atidaryti failo"<<endl;
    }
    
    string eilute;
    
    for (int i = 0; i<1; i++) getline(myfile,eilute);
    
    istringstream iss(eilute);
    string zodis;
    
    while (iss >> zodis) {
        if (zodis.substr(0, 2) == "ND") count_nd_words++;
    }
    
    while(myfile >> laikinas.vard >> laikinas.pavard) {
        
        for(int i=0; i<count_nd_words; i++)
        {
            int nd_skaicius;
            
            if (!(myfile >> nd_skaicius)) throw std::invalid_argument("Pažymys nėra sveikas skaičius. Pataisykite failą");
            
            if (nd_skaicius>10 || nd_skaicius <=0) throw std::invalid_argument("Pažymys nėra sveikas teigiamas skaičius tarp 1 ir 10. Pataisykite failą.");
            
            laikinas.paz.push_back(nd_skaicius);
        }
        
        myfile>> laikinas.egz;
        if (!myfile >> laikinas.egz) throw std::invalid_argument("Egzaminas nėra sveikas skaičius. Pataisykite failą");
        
        else if (laikinas.egz>10 || laikinas.egz <=0) throw std::invalid_argument("Egzaminas nėra sveikas teigiamas skaičius tarp 1 ir 10. Pataisykite failą.");
        
        laikinas.rez = gal_vid(laikinas.paz, laikinas.egz);
        grupe.push_back(laikinas);
        laikinas.paz.clear();
    }
    
    myfile.close();
    auto end_1 = high_resolution_clock::now();
    duration<double> diff_1 = end_1-start_1;
    std::cout << "Failo iš " + to_string(grupe.size()) + " įrašų nuskaitinėjimo laikas: "<< diff_1.count() << " s\n";
};
template <class T1> void isrusiuotas_spausdinimas(T1 vargsiukai, T1 gudruciai) {auto start = high_resolution_clock::now();
    ofstream failas("vargsiukai.txt");
    if(!failas) {std::cerr<<"Failo klaida"<<endl;}
    
    failas <<left<<setw(20)<< "Vardas" <<left<<setw(20)<<"Pavarde"<<left<<setw(10)<<"Galutinis (Vid.)"<<endl;
    failas<<"-----------------------------------------------------"<<endl;
    for (auto &a: vargsiukai) {
        failas<<left<<setw(20)<<a.vard<<left<<setw(20)<<a.pavard<<left<<setw(10)<<fixed<<setprecision(2)<<a.rez<<endl;
    }
    failas.close();
    auto end = high_resolution_clock::now();
    duration<double> diff = end-start;
    std::cout << "Vargšiukų įrašymo į failą laikas: "<< diff.count() << " s\n";
    
    auto start_2 = high_resolution_clock::now();
    ofstream g_failas("gudruciai.txt");
    if(!g_failas) {std::cerr<<"Failo klaida"<<endl;}
    
    g_failas <<left<<setw(20)<< "Vardas" <<left<<setw(20)<<"Pavarde"<<left<<setw(10)<<"Galutinis (Vid.)"<<endl;
    g_failas<<"-----------------------------------------------------"<<endl;
    for (auto &a: gudruciai) {
        g_failas<<left<<setw(20)<<a.vard<<left<<setw(20)<<a.pavard<<left<<setw(10)<<fixed<<setprecision(2)<<a.rez<<endl;
    }
    g_failas.close();
    auto end_2 = high_resolution_clock::now();
    duration<double> diff_2 = end_2-start_2;
    std::cout << "Gudručių įrašymo į failą laikas: "<< diff_2.count() << " s\n";
    }

template <class T> void egzamino_tikrinimas(int& egz, T laikinas) {
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

float count_median_l(list<int>& pazymiai) ;
int generate_random_mark();
float count_median(vector<int> pazymiai);
void Generavimas_failo(int skaic);
void a_paz_tikrinimas(int& a_paz_kiekis);
void mokiniu_sk_patikrinimas(int& m);
void budo_patikrinimas(char& budas);
