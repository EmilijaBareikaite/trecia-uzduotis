
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
    
    for (int j=0; j<m; j++) {
        cout<<"Iveskite studento varda ir pavarde: ";
        cin>>laikinas.vard>>laikinas.pavard;
        for (int i=0; i<n; i++) {
            int k;
            cout<<"Iveskite "<<i+1<<" pazymi: ";
            cin>>k;
            laikinas.paz.push_back(k);
        }
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
        grupe.push_back(laikinas);
        laikinas.paz.clear(); //grupeje laikomi pazymiai
       
        
    }
    //isvedimas
    printf("%-15s%-15s%-10s\n", "Vardas","Pavardė","Rezultatas" );
    cout<<"-----------------------------------"<<endl;
    for (auto &a: grupe){
        cout<<left<<setw(15)<<a.vard<<setw(15)<<a.pavard<<setw(10)<<fixed<<setprecision(2)<<a.rez<<endl;
    
    }
}
