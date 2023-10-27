#include "my_lib.h"

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
//void egzamino_tikrinimas(int& egz, struct studentas laikinas) {
//    try {if (cin.fail() || egz <= 0 || egz>10) throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių tarp 1 ir 10");
//    }
//    catch (const std::invalid_argument& e) {
//        std::cerr<< e.what()<<endl;
//        cin.clear();
//        cin.ignore(256, '\n');
//        cout<<"Įveskite iš naujo: ";
//        cin>>egz;
//        laikinas.egz = egz;
//        egzamino_tikrinimas(egz, laikinas);
//    }
//}

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

void Generavimas_failo(int skaic)
{
    int n;
    cout<<"Kiek namų darbų rezultatų turės studentai? ";
    cin>>n;
    
    if (n<0 || cin.fail()) throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių.");
    
    auto start = high_resolution_clock::now();
    ofstream failas("studentai"+to_string(skaic)+".txt");
    
    if(!failas) {std::cerr<<"Failo klaida"<<endl;}

    failas <<left<<setw(20)<< "Vardas" <<left<<setw(20)<<"Pavarde";
    
    for(int i=1; i<=n; i++) failas <<left<<setw(5)<< "ND"+to_string(i);
    failas <<left<<setw(5)<<"Egz"<< endl;
    
    for (int j=1; j<=skaic; j++)
    {
        failas <<left<<setw(20)<< "Vardas" + to_string(j) <<left<<setw(20)<< "Pavarde" + to_string(j);
        for (int k=0; k<n; k++)
        {
            int nd = generate_random_mark();
            failas <<left<<setw(5)<< nd;
        }
            int egz = generate_random_mark();
            failas <<left<<setw(5)<< egz <<endl;
    }
    
    failas.close();
    auto end = high_resolution_clock::now();
    duration<double> diff = end-start;
    std::cout << to_string(skaic) + " elementų užpildymas užtruko: "<< diff.count() << " s\n";
}

float count_median(vector<int> pazymiai)
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

float count_median_l(list<int>& pazymiai) {

    int size = pazymiai.size();
    auto it = pazymiai.begin();
    advance(it, size/2); // Move the iterator to the middle element

    if (size % 2 == 0) {
        int med1 = *it;
        --it;
        int med2 = *it;
        return static_cast<float>(med1 + med2) / 2.0;
    } else {
        return static_cast<float>(*it);
    }
}
