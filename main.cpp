#include "my_lib.h"

int main() {
    
    Studentas laikinas;
    vector<Studentas> grupe, vargsiukai, gudruciai;
    
    char suvedimas;
    int egzaminas;
    string vardas, pavarde;
    
    try {
        
        cout << "Ar studentų duomenis norite nuskaityti iš failo, ar norite suvedinėti, ar norite generuoti failus? Spauskite 'f', jei iš failo, 's', jei norite suvedinėti, 'g', jei generuoti. ";
        cin >> suvedimas;
        
        if (suvedimas == 's')
        {
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
                cout<<"Įveskite studento vardą ir pavardę ";
                cin>>vardas>>pavarde;
                laikinas.setStudentas(vardas, pavarde);
                
                if (budas == 'm')
                {
                    int k;
                    cout<<"Įveskite studento pažymį (parašę '-2' baigsite vesti studento pažymius): ";
                    cin>>k;
                    if (k==-2) throw std::runtime_error("Neįvėdete nei vieno pažymio. Programa nutraukta, nes negalima dalyba iš nulio.");
                    
                    if ((cin.fail() || k <= 0 || k>10) && k!=-2) throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių tarp 1 ir 10");
                    
                    int n = 0;
                    while ( k != -2)
                    {
                        n++;
                        laikinas.SetPAZ(k);
                        cout<<"Įveskite studento pažymį (parašę '-2' baigsite vesti studento pažymius):  ";
                        
                        cin>>k;
                        if ((cin.fail() || k <= 0 || k>10) && k!=-2) throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių tarp 1 ir 10");
                        
                    }
                    cout<<"Iveskite egzamina: ";
                    cin>>egzaminas;
                    laikinas.setEgzaminas(egzaminas);
                    egzamino_tikrinimas(egzaminas, laikinas);
                    
                    double vidurkis = Vidurkis(laikinas.getPaz());
                    float medianaa = mediana(laikinas.getPaz());
                    laikinas.setRez(laikinas.GP(laikinas.GautiEgzamina(), vidurkis));
                    laikinas.setMediana(medianaa);
                    
                    grupe.push_back(laikinas);
                    laikinas.EmptyPAZ();
                }
                else if (budas == 'a')
                {
                    cout << "Kiek pažymių turės studentas? ";
                    int a_paz_kiekis;
                    cin >> a_paz_kiekis;
                    a_paz_tikrinimas(a_paz_kiekis);
                    
                    
                    for (int u=0; u<a_paz_kiekis; u++) laikinas.SetPAZ(generate_random_mark());
                    
                    laikinas.SortPAZ();
                    
                    laikinas.setEgzaminas(generate_random_mark());
                    
                    double vidurkis = Vidurkis(laikinas.getPaz());
                    float medianaa = mediana(laikinas.getPaz());
                    laikinas.setRez(laikinas.GP(laikinas.GautiEgzamina(), vidurkis));
                    laikinas.setMediana(medianaa);
                    
                    grupe.push_back(laikinas);
                    laikinas.EmptyPAZ();
                }
                
                
                
                
                else throw std::invalid_argument("Netinkamai įvesta, prašome įvesti arba 'm' arba 'a': ");
            }
            
            char spausd;
            cout<<"Ar norite, kad rodytų studentų galutinį vidurkį ar medianą? Rašykite 'v', jeigu norite vidurkio, ir 'm', jeigu norite medianos. ";
            cin>>spausd;
            
            sort(grupe.begin(), grupe.end(), LyginimasPagalPavarde);
            
            if (spausd == 'v') isvedimas_v(grupe);
            else if (spausd == 'm') isvedimas_m(grupe);
            else throw std::runtime_error("Netinkamas atsakymas suvedimui. Prašome įvesti 'm' arba 'v'.");
            
        }
                else if (suvedimas == 'f')
                        {
                                string failo_kelias;
                                cout<< "Jūsų failo kelias: ";
                                cin>> failo_kelias;
                                
                                failo_skaitymas(failo_kelias, laikinas, grupe);

                                int atsakymas;
                                cout<<"Pagal ką rūšiuoti vargšiukų ir gudručių failus? 1 - pagal vardą, 2 - pagal pavardę, 3 -  pagal rezultatą. ";
                                cin>>atsakymas;
                            
                            if (atsakymas==1) {sort(grupe.begin(), grupe.end(), LyginimasPagalVarda);}
                            else if (atsakymas==2) {sort(grupe.begin(), grupe.end(), LyginimasPagalPavarde);}
                            else {sort(grupe.begin(), grupe.end(), LyginimasPagalRezultata);}
                            
                           
                                    padalinimas_v_3(grupe, vargsiukai);
                          
                                    isrusiuotas_spausdinimas(vargsiukai, grupe);
                                        
                            }
                    
            else if (suvedimas =='g')
                    {
                            int failo_eilutes;
                            cout << "Kiek studentų bus faile? ";
                            cin >> failo_eilutes;
                   
                            if (cin.fail() && failo_eilutes<0) throw std::invalid_argument("Netinkamas atsakymas. Prašome įvesti teigiamą sveiką skaičių.");
                   
                                Generavimas_failo(failo_eilutes);
                   
                    }
                   
            else throw std::runtime_error("Netinkamas atsakymas suvedimui. Prašome įvesti 's' arba 'f', arba 'g'.");}
    

           
         catch (const std::exception& e) {std::cerr << "An exception occurred: " << e.what() << endl;
                return 1;}
        
            system( "read -n 1 -s -p \"Press any key to continue...\"" );
            return 0;
        }
        
        
    
