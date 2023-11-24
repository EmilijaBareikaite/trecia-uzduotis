# **Antra užduotis (v1.1)**

**Tęsinys 1 užduoties**

Šioje programoje atliekama tas pats, kaip ir pirmos užduoties programoje, tačiau visas veikimas realizuotas ne su struktūromis, o su **_klasėmis_**. Kode paliktas darbas tik su vektoriaus konteineriu ir palikta greičiausiai veikianti strategija, skirta rūšiuoti studentus į dvi atskiras grupes. 

Taip pat buvo atlikta analizė, skirta palyginti spartą naudojant struktūrą ir klasę. Analizė atlikta su vektoriaus konteinerius, greičiausia strategija ir 100000, 1000000 failais.


**Analizės išvados:**

_Naudojant struktūrą_

|                                                | 100000 | 1000000 | 
| --------------------------------------------- |:-------:|:-------:|
|  Failo generavimo laikas                      | 3,95 s | 39,42 s |  
|  Failo nuskaitymo vidutinis laikas             | 0,36 s | 3,5 s   |  
|  Failo išrūšiavimo vidutinis laikas           | 0,05 s | 0,49 s  |  
|  Vargšiukų failo spausdinimo vidutinis laikas | 0,19 s | 1,89 s  |  
|  Gudručių failo spausdinimo vidutinis laikas  | 0,27 s | 2,64 s  |  
|  **Bendrai užtrukta**                         | **4,82 s** | **47,94 s** |

_Naudojant klasę_

|                                                | 100000 | 1000000 | 
| --------------------------------------------- |:-------:|:-------:|
|  Failo generavimo laikas                      | 3,95 s | 39,42 s |  
|  Failo nuskaitymo vidutinis laikas             | 0,34 s | 3,26 s   |  
|  Failo išrūšiavimo vidutinis laikas           | 0,03 s | 0,36 s  |  
|  Vargšiukų failo spausdinimo vidutinis laikas | 0,19 s | 1,95 s  |  
|  Gudručių failo spausdinimo vidutinis laikas  | 0,29 s | 2,84 s  |  
|  **Bendrai užtrukta**                         | **4,8 s** | **48,83s** |

**Palyginimas:** Iš lentelės rezultatų matoma, kad su struktūra ir klase veikimo sparta panaši, bet galima pastebėti, kad failo nuskaitymas ir išrūšiavimas veikia sparčiau naudojant klases, o vargšiukų bei gudručių spausdinimas veikia greičiau naudojant struktūras. 



**Įdiegimo bei naudojimosi instukcija:** reikia atsisiųsti pateiktus failus ir susidėti į bendrą aplanką. Šiame aplankale sukurkite "src" ir "include" aplankalus, į "src" sudėkite visus .cpp failus, o į "include" visus .h failus, o visus kitus failus palikite aplankale. Toliau intrukcijos pateiktos "mac OS" operacinės naudotojiems: atidarykite terminalą ir pasiekite Jūsų aplankalo direktoriją, tada rašykite "chmod +x RUNMEE.sh", tada suveskite "./RUNMEE.sh". To turi pakakti, kad programa pasileistų terminale. Toliau, suvedinėkite į terminalą tai, ką nurodo terminale pateikiamos instrukcijos, ir atsižvelkite į tai, ką norite  nuveikti (opcijos aprašytos viršuje) su programa. Be to, jeigu turite failų su kuriais norėsite dirbti (juos nuskaityti), įdėkite failus į src aplankalą ir pakeiskite (nukopijuokite, jei turite daugiau failų, arba ištrinkite šias eilutes, jeigu neturite) RUNMEE.sh 4, 5, 6, 7, 8 eilutes su jūsų failo pavadinimais.

**Kompiuterio duomenys**:

CPU - Apple M1 chip 8-core CPU with 4 perform­ance cores and 4 efficiency cores

RAM - 8 GB 

HDD - 256 GB SSD

