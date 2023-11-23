#include "my_lib.h"


void Studentas::setStudentas(std::string vardas, std::string pavarde)
{
    vardas_ = vardas;
    pavarde_ = pavarde;
}
void Studentas::setEgzaminas(int egzaminas) {
    egz_ = egzaminas;
}
void Studentas::setRez(float rez) {
    rez_ = rez;
}
void Studentas::setMediana(float mediana){
    mediana_ = mediana;
}
void Studentas::SetPAZ(int Score)
{
    paz.push_back(Score);
}

void Studentas::EmptyPAZ()
{
    paz.clear();
}
void Studentas::SortPAZ() {
    sort(paz.begin(), paz.end());
}

double Studentas::GP(int egzaminas, double nd)
{
    return 0.4 * nd + 0.6 * egzaminas;
}

double Vidurkis(vector<int> paz)
{
    float vidurkis = std::accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
    return vidurkis;
}



float mediana(vector<int> pazymiai) {
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

int generate_random_mark() //sugeneruojamas random skaic nuo 1 iki 10
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 mt_engine(seed);

        std::uniform_int_distribution<int> distribution(1, 10);
        int random_number = distribution(mt_engine);
        return random_number;
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






void egzamino_tikrinimas(int& egz, Studentas laikinas) {
    try {if (cin.fail() || egz <= 0 || egz>10) throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių tarp 1 ir 10");
    }
    catch (const std::invalid_argument& e) {
        std::cerr<< e.what()<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"Įveskite iš naujo: ";
        cin>>egz;
        laikinas.setEgzaminas(egz);
        egzamino_tikrinimas(egz, laikinas);
    }
}
bool Lyginimas(const Studentas& x, const Studentas& y)
{
    return x.getSurname() < y.getSurname();
}
