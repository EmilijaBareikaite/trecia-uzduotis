#include "my_lib.h"

int generate_random_mark() //sugeneruojamas random skaic nuo 1 iki 10
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 mt_engine(seed);

        std::uniform_int_distribution<int> distribution(1, 10);
        int random_number = distribution(mt_engine);
        return random_number;
}

float count_median(vector<int> pazymiai) //funkcija skaiciuoja mediana
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

float gal_vid(vector<int> pazymiai, int egzaminas) {
    float vidurkis, suma = 0;
    float rez;
    for (int i = 0; i < pazymiai.size(); i++) {
        suma = suma + pazymiai.at(i);
    }
    vidurkis = suma / pazymiai.size();
    rez = 0.4 * vidurkis + 0.6 * egzaminas;
    return rez;
}

void isvedimas_v(vector<studentas> grupe) {
    printf("%-25s%-20s%-15s\n", "Pavardė","Vardas","Galutinis (Vid.)" );
    cout<<"----------------------------------------------------------------"<<endl;
    for (auto &a: grupe)
    {
        cout<<left<<setw(24)<<a.pavard<<left<<setw(20)<<a.vard<<left<<setw(15)<<fixed<<setprecision(2)<<a.rez<<endl;
    }
}

void isvedimas_m(vector<studentas> grupe) {
    printf("%-25s%-20s%-15s\n", "Pavardė","Vardas","Galutinis (Med.)" );
    cout<<"----------------------------------------------------------------"<<endl;
    for (auto &a: grupe)
    {
        cout<<left<<setw(24)<<a.pavard<<left<<setw(20)<<a.vard<<left<<setw(15)<<fixed<<setprecision(2)<<a.mediana<<endl;
    }

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
void egzamino_tikrinimas(int& egz, struct studentas laikinas) {
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


void failo_skaitymas(string failo_kelias, struct studentas laikinas, vector<studentas> &grupe)
{
    
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
        laikinas.mediana = count_median(laikinas.paz);
        grupe.push_back(laikinas);
        laikinas.paz.clear();
    }
    
    myfile.close();
    auto end_1 = high_resolution_clock::now();
    duration<double> diff_1 = end_1-start_1;
    std::cout << "Failo iš " + to_string(grupe.size()) + " įrašų nuskaitinėjimo laikas: "<< diff_1.count() << " s\n";
    
}

void isrusiuotas_spausdinimas(vector<studentas> vargsiukai, vector<studentas> gudruciai) {
    
    auto start = high_resolution_clock::now();
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


