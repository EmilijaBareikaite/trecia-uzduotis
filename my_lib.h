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


int generate_random_mark();
float count_median(vector<int> pazymiai);
float gal_vid(vector<int> pazymiai, int egzaminas);
void isvedimas_v(vector<studentas> grupe);
void isvedimas_m(vector<studentas> grupe);
void mokiniu_sk_patikrinimas(int& m);
void budo_patikrinimas(char& budas);
void egzamino_tikrinimas(int& egz, struct studentas laikinas);
void a_paz_tikrinimas(int& a_paz_kiekis);
void Generavimas_failo(int skaic);
void failo_skaitymas(string failo_kelias, struct studentas laikinas, vector<studentas> &grupe);
void isrusiuotas_spausdinimas(vector<studentas> vargsiukai, vector<studentas> gudruciai);
float count_median_l(list<int>& pazymiai) ;
