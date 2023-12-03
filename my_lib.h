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
    double *elem;
    
    public:
    Studentas(); //konstruktorius
      Studentas(std::istream& is);
    ~Studentas(); //destruktorius
    Studentas(const Studentas& other); //copy kontruktorius
    Studentas& operator=(const Studentas& other); //priskyrimo operatorius
    // išvesties operatorius
    friend std::ostream& operator<<(std::ostream& out, const Studentas &a) {
        out <<"Studento vardas, pavardė ir galutinis rezultatas: "<<a.getName()<<" "<<a.getSurname()<<" "<<a.getRez()<<endl;
            return out;
        }
    //Įvesties operatorius
    friend std::istream& operator>>(std::istream& in, Studentas &a) {
        string vardas, pavarde;
        float rez;
            in >> vardas >> pavarde;
            a.setStudentas(vardas, pavarde);
            return in;
        }
      std::string getName() const { return vardas_; }
      std::string getSurname() const { return pavarde_; }
    vector<int> getPaz() const { return paz; }
      int GautiEgzamina() const { return egz_; }
        float getRez() const { return rez_; }
    float getMediana() const { return mediana_; }
      int GautiDydi() const { return paz.size(); }
      double GP(int, double);
    
      void setStudentas(std::string, std::string);
     void setEgzaminas(int);
    void setRez(float);
    void setMediana(float);
      void SetPAZ(int);
      void EmptyPAZ();
    void SortPAZ();
};

bool LyginimasPagalPavarde(const Studentas&, const Studentas&);
bool LyginimasPagalVarda(const Studentas&, const Studentas&);
bool LyginimasPagalRezultata(const Studentas&, const Studentas&);



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


template <class T1> void isrusiuotas_spausdinimas(T1 vargsiukai, T1 gudruciai) {auto start = high_resolution_clock::now();
    ofstream failas("vargsiukai.txt");
    if(!failas) {std::cerr<<"Failo klaida"<<endl;}

    failas <<left<<setw(20)<< "Vardas" <<left<<setw(20)<<"Pavarde"<<left<<setw(10)<<"Galutinis (Vid.)"<<endl;
    failas<<"-----------------------------------------------------"<<endl;
    for (auto &a: vargsiukai) {
        failas<<left<<setw(20)<<a.getName()<<left<<setw(20)<<a.getSurname()<<left<<setw(10)<<fixed<<setprecision(2)<<a.getRez()<<endl;
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
        g_failas<<left<<setw(20)<<a.getName()<<left<<setw(20)<<a.getSurname()<<left<<setw(10)<<fixed<<setprecision(2)<<a.getRez()<<endl;
    }
    g_failas.close();
    auto end_2 = high_resolution_clock::now();
    duration<double> diff_2 = end_2-start_2;
    std::cout << "Gudručių įrašymo į failą laikas: "<< diff_2.count() << " s\n";
    }





template <class P>
void padalinimas_v_3(P& grupe, P& vargsiukai) {
    int skaic = grupe.size();
    auto start_2 = high_resolution_clock::now();

    auto partitionPoint = std::stable_partition(grupe.begin(), grupe.end(), [](const Studentas& a) {
                return a.getRez() < 5;
                });

            // Visus studentus, kuriu galutinis < 5 dedame i vargsiukus
            vargsiukai.insert(vargsiukai.end(), grupe.begin(), partitionPoint);

            // Is grupes istriname studentus, kurie buvo ideti i vargsiukus
            grupe.erase(grupe.begin(), partitionPoint);

    auto end_2 = high_resolution_clock::now();
    duration<double> diff_2 = end_2 - start_2;
        cout << to_string(skaic) + " įrašų dalijimo i dvi grupes laikas: " << diff_2.count() << " s\n";
}




void a_paz_tikrinimas(int& a_paz_kiekis);
void Generavimas_failo(int skaic);
int generate_random_mark();
void mokiniu_sk_patikrinimas(int& m);
void budo_patikrinimas(char& budas);
void egzamino_tikrinimas(int& egz, Studentas laikinas);
double Vidurkis(vector<int> paz);
float mediana(vector<int> pazymiai);
void failo_skaitymas(string failo_kelias, Studentas laikinas, vector<Studentas> &grupe);
