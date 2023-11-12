# **Pirma užduotis (v1.0)**
1. Šioje programoje nuskaitomi duomenys, susiję su studentais - _jų vardai, pavardės, pažymiai ir egzaminų rezultatai._
2. Vartotojas turi keturias opcijas: jis gali **mechaniškai suvesti duomenis**, gali **automatiškai sugeneruoti duomenis**, gali **skaityti duomenis iš pasirinkto failo**, ir gali **sugeneruoti failus**, nurodęs, kiek bus studentų ir kiek namų darbų rezultatų turės kiekvienas studentas.
3. Output'e išvedama studentų _vardai, pavardės, galutinis rezultatas bei objektų saugojimo atmintyje adresai_ (sukurtų grupių ir studentų), jei vartotojas renkasi suvedinėti duomenis (vartotojas sprendžia ar per **medianą**, ar per **vidurkį** bus rodoma).

Šioje programoje yra opcija visą programą vykdyti su dviem skirtingais konteineriais - vector ir list (vartotojas pasirenka). Taip pat skaičiuojamas tam tikrų žingsnių laikas: failo generavimo, failo nuskaitymo, išrūšiavimo(pateiktas failas, rūšiuojamas į gudručius (galutinis rezultatas >= 5) ir vargšiukus(galutinis rezultatas < 5)). Tuo tikslu buvo atlikta analizė su 5 skirtingų dydžių failais - 1000, 10000, 100000, 1000000, 10000000, norint palyginti šių dviejų konteinerių veikimo spartą. 

Taip pat programoje buvo implementuotos **3 strategijos, skirtos optimizuoti faile esančių studentų rūšiavimą į dvi grupes (vargšiukus ir gudručius)**. _1 strategija_ rūšiuoja studentus, pereidamas per visus studentus ir nukopijuojant juos į naujus konteinerius; _2 strategija_ dirba tik su vargšiukų konteineriu, t. y. studentai, kurių galutinis rezultatass <5 yra pridedami į minėtą konteinerį ir paskui ištrinami iš visos grupės, taip pabaigoje grupėje lieka tik gudtučiai; _3 strategija_ dirba su 1 arba 2 strategija, priklausomai, kuri yra greitesnė, ir prideda dar nenaudotų funkcijų, kurios paspartina programos veikimą. Visų trijų strategijų išvados bus pateikiama žemiau.

**Analizės eiga:** buvo kuriamas vienas tam tikro dydžio (tačiau visuose failuose buvo 5 namų darbų rezultatai) failas ir buvo išmatuojamas jo sukūrimo laikas. Tuomet tas pats failas 5 kartus buvo nuskaitomas, išrūšiuojmas ir vėliau iš jo spausdinami 2 nauji failai naudojant vektorių arba listą. Gavus visus skaičiavimas, buvo vedami vidurkiai 100-tųjų tikslumu (jie ir bus pateikiami išvadose) ir lyginami rezultatai.

**Analizės išvados:**

_Vector konteinerio atveju_

|                                               |  1000   |  10000  | 100000 | 1000000 | 10000000  |
| --------------------------------------------- |:-------:|:-------:|:------:|:-------:|:---------:|
|  Failo generavimo laikas                      | 0,06 s  |  0,42 s | 3,95 s | 39,42 s |  396,06 s |
|  Failo nuskaitymo vidutinis laikas            | 0,01 s  |  0,05 s | 0,36 s | 3,5 s   |  36,6 s   |
|  Failo išrūšiavimo vidutinis laikas           | 0 s     |  0,01 s | 0,05 s | 0,49 s  |  5 s      |
|  Vargšiukų failo spausdinimo vidutinis laikas | 0 s     |  0,02 s | 0,19 s | 1,89 s  |  20,12 s  |
|  Gudručių failo spausdinimo vidutinis laikas  | 0,01 s  |  0,03 s | 0,27 s | 2,64 s  |  27,86 s  |
|  **Bendrai užtrukta**                         | **0,08 s** |  **0,53 s** | **4,82 s** | **47,94 s** |  **485,64 s** |

_List konteinerio atveju_

|                                               |  1000   |  10000  | 100000 | 1000000 | 10000000  |
| --------------------------------------------- |:-------:|:-------:|:------:|:-------:|:---------:|
|  Failo generavimo laikas                      | 0,06 s  |  0,42 s | 3,95 s | 39,42 s |  396,06 s |
|  Failo nuskaitymo vidutinis laikas            | 0,01 s  |  0,05 s | 0,39 s | 3,78 s  |  38,4 s   |
|  Failo išrūšiavimo vidutinis laikas           | 0 s     |  0,01 s | 0,08 s | 0,93 s  |  10,92 s  |
|  Vargšiukų failo spausdinimo vidutinis laikas | 0 s     |  0,02 s | 0,19 s | 1,99 s  |  20,93 s  |
|  Gudručių failo spausdinimo vidutinis laikas  | 0 s     |  0,03 s | 0,28 s | 2,75 s  |  31,20 s  |
|  **Bendrai užtrukta**                         | **0,07 s** |  **0,53 s** | **4,88 s** | **48,87 s** |  **497,5 s** |

**Palyginimas**: matoma, kad, kai failai yra sudaryti iš 1000 arba 10000 studentų, su list konteineriu programa veikia sparčiau arba taip pat, tačiau jau didėjant studentų kiekiui (esant 100000, 1000000, 10000000 studentų) programa veikia sparčiau su vector konteineriu.

**Strategijų išvados:**

_Vector konteinerio atveju_
|            |   1 strategija     |    2 strategija   |   3 strategija   | 
| ---------- |:------------------:|:-----------------:|:----------------:|
|  1000      | 0 s     |  0 s    |  0 s    |
|  10000     | 0,01 s  |  0 s    |  0 s    |
|  100000    | 0,05 s  |  0,05 s |  0,03 s |
|  1000000   | 0,49 s  |  0,32 s |  0,3 s  |
|  10000000  | 5 s     |  4,52 s |  3,1 s  |

_List konteinerio atveju_
|            |   1 strategija     |    2 strategija   |   3 strategija   | 
| ---------- |:------------------:|:-----------------:|:----------------:|
|  1000      | 0 s     |  0 s    |  0 s     |
|  10000     | 0,01 s  |  0,01 s |  0,01 s  |
|  100000    | 0,08 s  |  0,07 s |  0,06 s  |
|  1000000   | 0,93 s  |  0,7 s  |  0,56 s  |
|  10000000  | 10,92 s |  9,62 s |  8,78 s  |


**Išvados apie strategijas:** Iš duomenų galima matyti, kad **3 strategija yra greičiausia**, o **1 strategija - lėčiausia**. (abiejų, list ir vector, konteinerių atveju)

**Įdiegimo bei naudojimosi instukcija:** reikia atsisiųsti pateiktus failus ir susidėti į bendrą aplanką. Šiame aplankale sukurkite "src" ir "include" aplankalus, į "src" sudėkite visus .cpp failus, o į "include" visus .h failus, o visus kitus failus palikite aplankale. Toliau intrukcijos pateiktos "mac OS" operacinės naudotojiems: atidarykite terminalą ir pasiekite Jūsų aplankalo direktoriją, tada rašykite "chmod +x RUNMEE.sh", tada suveskite "./RUNMEE.sh". To turi pakakti, kad programa pasileistų terminale. Toliau, suvedinėkite į terminalą tai, ką nurodo terminale pateikiamos instrukcijos, ir atsižvelkite į tai, ką norite  nuveikti (opcijos aprašytos viršuje) su programa. Be to, jeigu turite failų su kuriais norėsite dirbti (juos nuskaityti), įdėkite failus į src aplankalą ir pakeiskite (nukopijuokite, jei turite daugiau failų, arba ištrinkite šias eilutes, jeigu neturite) RUNMEE.sh 4, 5, 6, 7, 8 eilutes su jūsų failo pavadinimais.

**Kompiuterio duomenys**:

CPU - Apple M1 chip 8-core CPU with 4 perform­ance cores and 4 efficiency cores

RAM - 8 GB 

HDD - 256 GB SSD

Output, kai suvedami mechaniškai duomenys
<img width="883" alt="duomenu_mechaninis_suvedimas" src="https://github.com/EmilijaBareikaite/pirma-uzduotis/assets/145277411/8b1b4286-e600-43e3-a5dc-3bf6ba5920f8">

Output, kai suvedami automatiškai duomenys
<img width="896" alt="Duomenu_suvedimo_pvz" src="https://github.com/EmilijaBareikaite/pirma-uzduotis/assets/145277411/c95a1cb3-0d48-40ab-a401-992efbf64a96">  

Output, kai generuojamas failas
<img width="887" alt="failo_generavimo_pvz" src="https://github.com/EmilijaBareikaite/pirma-uzduotis/assets/145277411/3ad276bd-dae2-4001-bd78-7f1d36a9e906">

Output, kai nuskaitomas failas

<img width="725" alt="Screenshot 2023-11-12 at 13 50 28" src="https://github.com/EmilijaBareikaite/pirma-uzduotis/assets/145277411/c704e701-3760-4fb7-a46e-c49a94a9210f">


