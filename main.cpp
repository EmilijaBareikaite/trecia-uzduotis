#include "my_lib.h"

int main() {
    
    studentas laikinas;
    vector <studentas> grupe;
    vector <studentas> gudruciai;
    vector <studentas> vargsiukai;
    char suvedimas;
    try {
    cout << "Ar studentų duomenis norite nuskaityti iš failo, ar norite suvedinėti, ar norite generuoti failus? Spauskite 'f', jei iš failo, 's', jei norite suvedinėti, 'g', jei generuoti. ";
    cin >> suvedimas;
    
    if (suvedimas == 's') {
        
        int m;
        cout << "Kiek studentų mokosi? ";
        cin >> m;
    
        mokiniu_sk_patikrinimas(m);
        
        if (m == 0) throw std::runtime_error("Programa baigė darbą, nes nėra studentų.");
        
        char budas;
        cout << "Ar norite suvesti studentų pažymius ir egzamino rezultatą automatiškai ar mechaniškai? Rašykite 'a', jei automatiškai ir 'm', jei mechaniškai.  ";
        cin >> budas;
        budo_patikrinimas(budas);
            
            for (int j = 0; j < m; j++)
            {
                cout<<"Įveskite studento vardą ir pavardę: ";
                cin>>laikinas.vard>>laikinas.pavard;
                
                if (budas == 'm') {
                    int k;
                    cout<<"Įveskite studento pažymį (parašę '-2' baigsite vesti studento pažymius): ";
                    cin>>k;
                    if (k==-2) throw std::runtime_error("Neįvėdete nei vieno pažymio. Programa nutraukta, nes negalima dalyba iš nulio.");
                
                    if ((cin.fail() || k <= 0 || k>10) && k!=-2) throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių tarp 1 ir 10");
                    
                        int n = 0;
                        while ( k != -2)
                        {
                            n++;
                            laikinas.paz.push_back(k);
                            cout<<"Įveskite studento pažymį (parašę '-2' baigsite vesti studento pažymius):  ";
                        
                            cin>>k;
                            if ((cin.fail() || k <= 0 || k>10) && k!=-2) throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių tarp 1 ir 10");
                            
                        }
                    
                    cout<<"Įveskite egzamino rezultatą: ";
                    cin>>laikinas.egz;
                    egzamino_tikrinimas(laikinas.egz, laikinas);
                    
                    laikinas.rez = gal_vid(laikinas.paz, laikinas.egz);
                    laikinas.mediana = count_median(laikinas.paz);
                    
                    grupe.push_back(laikinas);
                    laikinas.paz.clear();
                }
                
                else if (budas == 'a')
                {
                    cout << "Kiek pažymių turės studentas? ";
                    
                    int a_paz_kiekis;
                    cin >> a_paz_kiekis;
                    
                    a_paz_tikrinimas(a_paz_kiekis);
                    
                    for (int u=0; u<a_paz_kiekis; u++) laikinas.paz.push_back(generate_random_mark());
                    
                    sort(laikinas.paz.begin(), laikinas.paz.end());
                    
                    laikinas.egz = generate_random_mark();
                    laikinas.rez = gal_vid(laikinas.paz, laikinas.egz);
                    laikinas.mediana = count_median(laikinas.paz);
                    
                    grupe.push_back(laikinas);
                    laikinas.paz.clear();
                }
                else throw std::invalid_argument("Netinkamai įvesta, prašome įvesti arba 'm' arba 'a': ");
            }
        char spausd;
        cout<<"Ar norite, kad rodytų studentų galutinį vidurkį ar medianą? Rašykite 'v', jeigu norite vidurkio, ir 'm', jeigu norite medianos. ";
        cin>>spausd;
        
        sort(grupe.begin(), grupe.end());
        
        if (spausd == 'v') isvedimas_v(grupe);
        else if (spausd == 'm') isvedimas_m(grupe);
        else throw std::runtime_error("Netinkamas atsakymas suvedimui. Prašome įvesti 'm' arba 'v'.");
        }
    
    else if (suvedimas == 'f') {
        
        string failo_kelias;
        cout<< "Jūsų failo kelias: ";
        cin>> failo_kelias;
        failo_skaitymas(failo_kelias, laikinas, grupe);
        
        for (auto &a: grupe) {if (a.rez<5) vargsiukai.push_back(a);
            else gudruciai.push_back(a);}
        isrusiuotas_spausdinimas(vargsiukai, gudruciai);
        
    }
    
    else if (suvedimas =='g')
    {
        int failo_eilutes;
        cout << "Kiek studentų bus faile?";
        cin >> failo_eilutes;
        
        if (cin.fail() && failo_eilutes<0) throw std::invalid_argument("Netinkamas atsakymas. Prašome įvesti teigiamą sveiką skaičių.");
        Generavimas_failo(failo_eilutes);
    }
        
    else throw std::runtime_error("Netinkamas atsakymas suvedimui. Prašome įvesti 's' arba 'f', arba 'g'.");
    
    }
    catch (const std::exception& e) {std::cerr << "An exception occurred: " << e.what() << endl;
            return 1;}
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}
