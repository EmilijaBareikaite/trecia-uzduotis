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
using std::istringstream;

struct studentas {
    string vard, pavard;
    vector <int> paz;
    int egz;
    float vidurkis, rez, mediana;
    
    
    bool operator<(const studentas& other) const {
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

//studentas - tipas; kaip float ar int
