
#include "my_lib.h"



int main() {
    
    
    
    studentas laikinas;
    vector <studentas> grupe;
    int m;
    cout<<"Kiek studentų mokosi? ";
    cin>>m;
    cout<<"Ivesk kiek pazymiu turi studentai: ";
    int n;
    cin>>n;
    //mediana
    
    
    for (int j=0; j<m; j++) {
        cout<<"Iveskite studento varda ir pavarde: ";
        cin>>laikinas.vard>>laikinas.pavard;
        for (int i=0; i<n; i++) {
            int k;
            cout<<"Iveskite "<<i+1<<" pazymi: ";
            cin>>k;
            laikinas.paz.push_back(k);
        }
        sort(laikinas.paz.begin(), laikinas.paz.end());
        
        cout<<"iveskite egzamino rez: ";
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
            laikinas.mediana = (laikinas.paz[n/2]+laikinas.paz[(n/2)-1])/2.0;
        else
            laikinas.mediana = laikinas.paz[(n/2)];
    
        grupe.push_back(laikinas);
        laikinas.paz.clear(); //grupeje laikomi pazymiai
    }
    

    //isvedimas
    char spausd;
    cout<<"Ar norite, kad rodytų studentų galutinį vidurkį ar medianą? Rašykite 'v', jeigu norite vidurkio, ir 'm', jeigu norite medianos. ";
    cin>>spausd;
    if (spausd == 'v') {
        printf("%-20s%-20s%-10s\n", "Pavardė","Vardas","Galutinis (Vid.)" );
        cout<<"-----------------------------------"<<endl;
        for (auto &a: grupe){
            cout<<left<<setw(20)<<a.pavard<<setw(20)<<a.vard<<setw(10)<<fixed<<setprecision(2)<<a.rez<<endl;
        }
    }
    else
    {
        printf("%-20s%-20s%-10s\n", "Pavardė","Vardas","Galutinis (Med.)" );
        cout<<"-----------------------------------"<<endl;
        for (auto &a: grupe){
            cout<<left<<setw(20)<<a.pavard<<setw(20)<<a.vard<<setw(10)<<fixed<<setprecision(2)<<a.mediana<<endl;
            
        }
    }
    
}

