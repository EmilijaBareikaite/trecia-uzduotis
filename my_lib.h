#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>

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

struct studentas {
    string vard, pavard;
    vector <int> paz;
    int egz;
    float vidurkis, rez, mediana;
    
    
    bool operator<(const studentas& other) const{
        if (pavard != other.pavard) {
                    return pavard < other.pavard;
                }
                return vard < other.vard;
            }
};

int generate_random_mark();
float count_median(vector<int> pazymiai);
float gal_vid(vector<int> pazymiai, int egzaminas);
void isvedimas_v(vector<studentas> grupe);
void isvedimas_m(vector<studentas> grupe);
void isvedimas_f(vector<studentas> grupe);
void mokiniu_sk_patikrinimas(int& m);
void budo_patikrinimas(char& budas);
void egzamino_tikrinimas(int& egz, struct studentas laikinas);
void a_paz_tikrinimas(int& a_paz_kiekis);
void Generavimas_failo(int skaic);

