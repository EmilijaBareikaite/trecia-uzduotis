#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fixed;
using std::setprecision;
using std::setw;
using std::left;

struct studentas {
    string vard, pavard;
    vector <int> paz;
    int egz;
    float vidurkis, rez, mediana;
};

int generate_random_mark();
float count_median(vector<int> pazymiai);
float gal_vid(vector<int> pazymiai, int egzaminas);
void isvedimas_v(vector<studentas> grupe);
void isvedimas_m(vector<studentas> grupe);
//studentas - tipas; kaip float ar int
