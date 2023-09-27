
#include "my_lib.h"

int main() {
    
    
    studentas laikinas;
    vector <studentas> grupe;
    
    int m, k;
    cout << "Kiek studentų mokosi? ";
    cin >> m;
    char budas;
    
    cout << "Ar norite suvesti studentų pažymius ir egzamino rezultatą automatiškai ar mechaniškai? Rašykite 'a', jei automatiškai ir 'm', jei mechaniškai.  ";
    cin >> budas;
    
    if (budas == 'm')
    
    {
        for (int j=0; j<m; j++) {
            cout<<"Įveskite studento vardą ir pavardę: ";
            cin>>laikinas.vard>>laikinas.pavard;
            
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
            
            sort(laikinas.paz.begin(), laikinas.paz.end());
            
            cout<<"Įveskite egzamino rezultatą: ";
            cin>>laikinas.egz;
            
            //skaiciuojam vidurki
            float suma=0;
            for (int v=0; v<n; v++) {
                int pazimys = laikinas.paz.at(v);
                suma = suma + pazimys;
            }
            laikinas.vidurkis = suma/n;
            laikinas.rez = 0.4*laikinas.vidurkis+0.6*laikinas.egz;
            
            
            //skaiciuojam mediana
            if (n % 2 == 0)
                laikinas.mediana = (laikinas.paz.at(n/2)+laikinas.paz.at((n/2)-1))/2.0;
            else
                laikinas.mediana = laikinas.paz.at(n/2);
            
            grupe.push_back(laikinas);
            laikinas.paz.clear(); //grupeje laikomi pazymiai
        }
    }
    else {
        
        for (int j=0; j<m; j++) {
            
            cout << "Kiek pažymių turės studentas? ";
            int a_paz_kiekis;
            cin >> a_paz_kiekis;
            
            cout << "Įveskite studento vardą ir pavardę: ";
            cin >> laikinas.vard>>laikinas.pavard;
            
            srand(time(NULL));
            
            for (int u=0; u<a_paz_kiekis; u++) {
                laikinas.paz.push_back((rand() % 10) + 1);}
            
            sort(laikinas.paz.begin(), laikinas.paz.end());
            
            laikinas.egz = (rand() % 10) + 1;
    
            //skaiciuojam vidurki
            float suma=0;
            for (int v=0; v<a_paz_kiekis; v++) {
                int pazymys = laikinas.paz.at(v);
                suma = suma + pazymys;
            }
            laikinas.vidurkis = suma/a_paz_kiekis;
            laikinas.rez = 0.4*laikinas.vidurkis+0.6*laikinas.egz;
            
            
            //skaiciuojam mediana
            if (a_paz_kiekis % 2 == 0)
                laikinas.mediana = (laikinas.paz.at(a_paz_kiekis/2)+laikinas.paz.at((a_paz_kiekis/2)-1))/2.0;
            else
                laikinas.mediana = laikinas.paz.at(a_paz_kiekis/2);
            
            grupe.push_back(laikinas);
        
            laikinas.paz.clear();
        }
      
    
    }

    //isvedimas
    char spausd;
    cout<<"Ar norite, kad rodytų studentų galutinį vidurkį ar medianą? Rašykite 'v', jeigu norite vidurkio, ir 'm', jeigu norite medianos. ";
    cin>>spausd;
    if (spausd == 'v') {
        printf("%-25s%-25s%-15s\n", "Pavardė","Vardas","Galutinis (Vid.)" );
        cout<<"----------------------------------------------------------------"<<endl;
        for (auto &a: grupe){
            cout<<left<<setw(25)<<a.pavard<<setw(25)<<a.vard<<setw(15)<<fixed<<setprecision(2)<<a.rez<<endl;
        }
    }
    else
    {
        printf("%-25s%-25s%-15s\n", "Pavardė","Vardas","Galutinis (Med.)" );
        cout<<"---------------------------------------------------------------"<<endl;
        for (auto &a: grupe){
            cout<<left<<setw(25)<<a.pavard<<setw(25)<<a.vard<<setw(15)<<fixed<<setprecision(2)<<a.mediana<<endl;
            
        }
    }
    
}

