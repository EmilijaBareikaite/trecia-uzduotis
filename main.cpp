#include "my_lib.h"

int main() {
    
    studentas laikinas;
    vector <studentas> grupe;
    
    int m;
    cout << "Kiek studentų mokosi? ";
    cin >> m;
    
    char budas;
    cout << "Ar norite suvesti studentų pažymius ir egzamino rezultatą automatiškai ar mechaniškai? Rašykite 'a', jei automatiškai ir 'm', jei mechaniškai.  ";
    
    cin >> budas;
    
    for (int j=0; j<m; j++) {
        cout<<"Įveskite studento vardą ir pavardę: ";
        cin>>laikinas.vard>>laikinas.pavard;
        
        if (budas == 'm') {
            int k;
            cout<<"Įveskite studento pažymį (parašę '-2' baigsite vesti studento pažymius): ";
            cin>>k;
            
            int n=0;
            while ( k != -2)
            {
                n++;
                laikinas.paz.push_back(k);
                cout<<"Įveskite studento pažymį (parašę '-2' baigsite vesti studento pažymius):  ";
                cin>>k;
            }
            
            cout<<"Įveskite egzamino rezultatą: ";
            cin>>laikinas.egz;
            
            laikinas.rez = gal_vid(laikinas.paz, laikinas.egz);
            
            laikinas.mediana = count_median(laikinas.paz);
            
            grupe.push_back(laikinas);
            laikinas.paz.clear();
        }
        
        else {
            
            cout << "Kiek pažymių turės studentas? ";
            
            int a_paz_kiekis;
            cin >> a_paz_kiekis;
            
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
    
    //isvedimas
    char spausd;
    cout<<"Ar norite, kad rodytų studentų galutinį vidurkį ar medianą? Rašykite 'v', jeigu norite vidurkio, ir 'm', jeigu norite medianos. ";
    cin>>spausd;
    if (spausd == 'v') {
        isvedimas_v(grupe);
    }
    else
    {
        isvedimas_m(grupe);
    }
}
