#include "my_lib.h"

int main() {
    
    studentas laikinas;
    vector <studentas> grupe;
    try{ char suvedimas;
        
        
        cout << "Ar studentų duomenis norite nuskaityti iš failo, ar norite suvedinėti? Spauskite 'f', jei iš failo, ir 's', jei norite suvedinėti. ";
        cin >> suvedimas;
        
        if (suvedimas == 's') {
            int m;
                cout << "Kiek studentų mokosi? ";
                cin >> m;
                
                if (cin.fail() || m < 0) {
                    throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių");
                }
                else if (m == 0) { throw std::invalid_argument("Progama baigė darbą, nes nėra studentų.");}

            char budas;
            cout << "Ar norite suvesti studentų pažymius ir egzamino rezultatą automatiškai ar mechaniškai? Rašykite 'a', jei automatiškai ir 'm', jei mechaniškai.  ";
            
            cin >> budas;
            if (budas!='m' & budas!='a') { throw std::runtime_error("Netinkamas atsakymas suvedimui. Prašome įvesti 'm' arba 'a'."); }
            
            for (int j=0; j<m; j++) {
                cout<<"Įveskite studento vardą ir pavardę: ";
                cin>>laikinas.vard>>laikinas.pavard;
                
                                if (budas == 'm') {
                                    int k;
                                    cout<<"Įveskite studento pažymį (parašę '-2' baigsite vesti studento pažymius): ";
                                    cin>>k;
                                    if (cin.fail() || k <= 0 || k>10) {
                                        throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių tarp 1 ir 10");
                                    }
                
                                    int n=0;
                                    while ( k != -2)
                                    {
                                        n++;
                                        laikinas.paz.push_back(k);
                                        cout<<"Įveskite studento pažymį (parašę '-2' baigsite vesti studento pažymius):  ";
                
                                        cin>>k;
                                        if (cin.fail() || k <= 0 || k>10) {
                                            throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių tarp 1 ir 10");
                                        }
                
                                    }
                
            
                    
                    cout<<"Įveskite egzamino rezultatą: ";
                    cin>>laikinas.egz;
                    if (cin.fail() || laikinas.egz <= 0 || laikinas.egz>10)
                    {
                        throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių tarp 1 ir 10");
                    }
                    
                    
                    laikinas.rez = gal_vid(laikinas.paz, laikinas.egz);
                    
                    laikinas.mediana = count_median(laikinas.paz);
                    
                    grupe.push_back(laikinas);
                    laikinas.paz.clear();
                }
                
                else
                {
                    
                    cout << "Kiek pažymių turės studentas? ";
                    
                    int a_paz_kiekis;
                    cin >> a_paz_kiekis;
                    if (cin.fail() || (a_paz_kiekis < 0)) {
                        throw std::invalid_argument("Netinkamai įvesta. Prašome įvesti teigiamą sveiką skaičių");
                    }
                    else if (a_paz_kiekis == 0) { throw std::invalid_argument("Netinkamai įvesta, negalima dalyba iš 0. Prašome įvesti didesnį už nulį teigiamą sveiką skaičių");}
                    
                    
                    for (int u=0; u<a_paz_kiekis; u++) {
                        laikinas.paz.push_back(generate_random_mark());}
                    
                    sort(laikinas.paz.begin(), laikinas.paz.end());
                    
                    laikinas.egz = generate_random_mark();
                    
                    laikinas.rez = gal_vid(laikinas.paz, laikinas.egz);
                    
                    laikinas.mediana = count_median(laikinas.paz);
                    
                    grupe.push_back(laikinas);
                    
                    laikinas.paz.clear();
                    
                }
                
                
            }
        }
        else if (suvedimas == 'f') {
            
            string failo_kelias;
            cout<< "Jūsų failo kelias: ";
            cin>> failo_kelias;
            
            ifstream myfile(failo_kelias);
            if(myfile.fail()) {
                cout<<"nepavyko atidaryti failo"<<endl;
                return 1;
            }
            
            string eilute; //eilute storins antraste
            for (int i = 0; i<1; i++) {
                getline(myfile,eilute);
            }
            
            istringstream iss(eilute);
            string zodis;
            
            int count_nd_words = 0;
            
            while (iss >> zodis) {
                if (zodis.substr(0, 2) == "ND") {
                    count_nd_words++;
                }
            }
            
            while(myfile >> laikinas.vard >> laikinas.pavard) {
                
                for(int i=0; i<count_nd_words; i++) {
                    int nd_skaicius;
                    
                    
                    if (!(myfile >> nd_skaicius)){
                        throw std::invalid_argument("Pažymys nėra sveikas skaičius. Pataisykite failą");
                                    }
                    
                    if (nd_skaicius>10 || nd_skaicius <=0) {
                        throw std::invalid_argument("Pažymys nėra sveikas teigiamas skaičius tarp 1 ir 10. Pataisykite failą.");
                    }
                    laikinas.paz.push_back(nd_skaicius);
                }
                
                myfile>> laikinas.egz;
                if (!myfile >> laikinas.egz) {
                    throw std::invalid_argument("Egzaminas nėra sveikas skaičius. Pataisykite failą");
                
                }
                
                else if (laikinas.egz>10 || laikinas.egz <=0) {
                    throw std::invalid_argument("Egzaminas nėra sveikas teigiamas skaičius tarp 1 ir 10. Pataisykite failą.");
                }
                
                laikinas.rez = gal_vid(laikinas.paz, laikinas.egz);
                laikinas.mediana = count_median(laikinas.paz);
                grupe.push_back(laikinas);
                laikinas.paz.clear();
            }
            
            myfile.close();
        }
        else  {
            throw std::runtime_error("Netinkamas atsakymas suvedimui. Prašome įvesti 's' arba 'f'.");
        }
        
        //isvedimas
        char spausd;
        cout<<"Ar norite, kad rodytų studentų galutinį vidurkį ar medianą? Rašykite 'v', jeigu norite vidurkio, ir 'm', jeigu norite medianos. ";
        cin>>spausd;
        sort(grupe.begin(), grupe.end());
        if (spausd == 'v') {
            isvedimas_v(grupe);
        }
        else if (spausd == 'm')
        {
            isvedimas_m(grupe);
        }
        else {
            throw std::runtime_error("Netinkamas atsakymas suvedimui. Prašome įvesti 'm' arba 'v'.");
        }
    }
    catch (const std::exception& e) {
            std::cerr << "An exception occurred: " << e.what() << endl;
            return 1;
        }
    return 0;
}
        

