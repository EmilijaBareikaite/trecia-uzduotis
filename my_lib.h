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



class Studentas {
    private:
      string vardas_, pavarde_;
      int egz_;
      vector<int> paz;
        float rez_, mediana_;
    
    public:
      Studentas() : egz_(0) { }  // default konstruktorius
      Studentas(std::istream& is);
      std::string getName() const { return vardas_; }
      std::string getSurname() const { return pavarde_; }
    vector<int> getPaz() const { return paz; }
      int GautiEgzamina() const { return egz_; }
        float getRez() const { return rez_; }
    float getMediana() const { return mediana_; }
      int GautiDydi() const { return paz.size(); }
      double GP(int, double);
      double GP(int, const std::vector<int>);
      double GP(double (*) (std::vector<int>));
      void setStudentas(std::string, std::string);
     void setEgzaminas(int);
    void setRez(float);
    void setMediana(float);
      void SetPAZ(int);
      void EmptyPAZ();
    void SortPAZ();
};

bool Lyginimas(const Studentas&, const Studentas&);





template <class T> void isvedimas_v(T grupe)
 {
    printf("%-25s%-20s%-15s\n", "Pavardė","Vardas","Galutinis (Vid.)" );
    cout<<"----------------------------------------------------------------"<<endl;
    for (auto &a: grupe)
    {
        cout<<left<<setw(24)<<a.getSurname()<<left<<setw(20)<<a.getName()<<left<<setw(15)<<fixed<<setprecision(2)<<a.getRez()<<endl;
    }
}

template <class T> void isvedimas_m(T grupe) {

    printf("%-25s%-20s%-15s\n", "Pavardė","Vardas","Galutinis (Med.)" );
    cout<<"----------------------------------------------------------------"<<endl;
    for (auto &a: grupe)
    {
        cout<<left<<setw(24)<<a.getSurname()<<left<<setw(20)<<a.getName()<<left<<setw(15)<<fixed<<setprecision(2)<<a.getMediana()<<endl;
    }
}





void a_paz_tikrinimas(int& a_paz_kiekis);
void Generavimas_failo(int skaic);
int generate_random_mark();
void mokiniu_sk_patikrinimas(int& m);
void budo_patikrinimas(char& budas);
void egzamino_tikrinimas(int& egz, Studentas laikinas);
double Vidurkis(vector<int> paz);
float mediana(vector<int> pazymiai);







