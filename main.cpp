#include "my_lib.h"

int main() {
    
    studentas laikinas;
    vector <studentas> grupe;
    char suvedimas;
    cout << "Ar studentų duomenis norite nuskaityti iš failo, ar norite suvedinėti? Spauskite 'f', jei iš failo, ir 's', jei norite suvedinėti. ";
    cin >> suvedimas;
    
    if (suvedimas == 's') {
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
        sort(grupe.begin(), grupe.end());
        if (spausd == 'v') {
            isvedimas_v(grupe);
        }
        else
        {
            isvedimas_m(grupe);
        }
    
    }
    
    
    else {
        
      
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
        
        std::istringstream iss(eilute);
        string zodis;
        
        int count_nd_words = 0;
        
        while (iss >> zodis) {
            if (zodis.substr(0, 2) == "ND") {
                count_nd_words++;
            }
        }
        
        while(myfile >> laikinas.pavard >> laikinas.vard) {
            
            for(int i=0; i<count_nd_words; i++) {
                int nd_skaicius;
                myfile >> nd_skaicius;
                laikinas.paz.push_back(nd_skaicius);
            }
            myfile >> laikinas.egz;
            laikinas.rez = gal_vid(laikinas.paz, laikinas.egz);
            laikinas.mediana = count_median(laikinas.paz);
            grupe.push_back(laikinas);
            laikinas.paz.clear();
        }
        
        myfile.close();
        char ats;
        cout<<"Norite, kad rodytų galutinį rezultatą pagal vidurkį ar medianą? spauskite 'v', jei vidurkį, ir 'm', jei medianą ";
        cin>>ats;
        sort(grupe.begin(), grupe.end());
        if (ats == 'v')
            isvedimas_v(grupe);
        else isvedimas_m(grupe);
    }
   
}
        

