# **Pirma užduotis (v0.3)**
1. Šioje programoje nuskaitomi duomenys, susiję su studentais - _jų vardai, pavardės, pažymiai ir egzaminų rezultatai._
2. Vartotojas turi keturias opcijas: jis gali **mechaniškai suvesti duomenis**, gali **automatiškai sugeneruoti duomenis**, gali **skaityti duomenis iš pasirinkto failo**, ir gali **sugeneruoti failus**, nurodęs, kiek bus studentų ir kiek namų darbų rezultatų turės kiekvienas studentas.
3. Output'e išvedama studentų _vardai, pavardės, galutinis rezultatas bei objektų saugojimo atmintyje adresai_ (sukurtų grupių ir studentų), jei vartotojas renkasi suvedinėti duomenis (vartotojas sprendžia ar per **medianą**, ar per **vidurkį** bus rodoma).

Šioje programoje yra opcija visą programą vykdyti su dviem skirtingais konteineriais - vector ir list (vartotojas pasirenka). Taip pat skaičiuojamas tam tikrų žingsnių laikas: failo generavimo, failo nuskaitymo, išrūšiavimo(pateiktas failas, rūšiuojamas į gudručius (galutinis rezultatas >= 5) ir vargšiukus(galutinis rezultatas < 5)). Tuo tikslu buvo atlikta analizė su 5 skirtingų dydžių failais - 1000, 10000, 100000, 1000000, 10000000, norint palyginti šių dviejų konteinerių veikimo spartą. 

**Analizės eiga:** buvo kuriamas vienas tam tikro dydžio (tačiau visuose failuose buvo 5 namų darbų rezultatai) failas ir buvo išmatuotajamas jo sukūrimo laikas. Tuomet tas pats failas 5 kartus buvo nuskaitomas, išrūšiuojmas ir vėliau iš jo spausdinami 2 nauji failai naudojant vektorių arba listą. Gavus visus skaičiavimas, buvo vedami vidurkiai 100-tųjų tikslumu (jie ir bus pateikiami išvadose) ir lyginami rezultatai.

**Analizės išvados:**

_Vector konteinerio atveju_

|                                               |  1000   |  10000  | 100000 | 1000000 | 10000000  |
| --------------------------------------------- |:-------:|:-------:|:------:|:-------:|:---------:|
|  Failo generavimo laikas                      | 0,06 s  |  0,42 s | 3,95 s | 39,42 s |  396,06 s |
|  Failo nuskaitymo vidutinis laikas            | 0,01 s  |  0,05 s | 0,36 s | 3,5 s   |  36,6 s   |
|  Failo išrūšiavimo vidutinis laikas           | 0 s     |  0,01 s | 0,05 s | 0,49 s  |  5 s      |
|  Vargšiukų failo spausdinimo vidutinis laikas | 0 s     |  0,02 s | 0,19 s | 1,89 s  |  20,12 s  |
|  Gudručių failo spausdinimo vidutinis laikas  | 0,01 s  |  0,03 s | 0,27 s | 2,64 s  |  27,86 s  |
|  **Bendrai užtrukta**                             | **0,08 s** |  **0,53 s** | **4,82 s** | **47,94 s** |  **485,64 s** |

_List konteinerio atveju_

|                                               |  1000   |  10000  | 100000 | 1000000 | 10000000  |
| --------------------------------------------- |:-------:|:-------:|:------:|:-------:|:---------:|
|  Failo generavimo laikas                      | 0,06 s  |  0,42 s | 3,95 s | 39,42 s |  396,06 s |
|  Failo nuskaitymo vidutinis laikas            | 0,01 s     |  0,05 s | 0,39 s | 3,5 s   |  38,4 s   |
|  Failo išrūšiavimo vidutinis laikas           | 0 s     |  0,01 s | 0,08 s | 0,49 s  |  10,92 s  |
|  Vargšiukų failo spausdinimo vidutinis laikas | 0 s     |  0,02 s | 0,19 s | 1,89 s  |  20,93 s  |
|  Gudručių failo spausdinimo vidutinis laikas  | 0 s     |  0,03 s | 0,28 s | 2,64 s  |  31,20 s  |
|  **Bendrai užtrukta**                             | **0,07 s** |  **0,53 s** | **4,88 s** | **47,94 s** |  **497,5 s** |

**Palyginimas**: matoma, kad, kai failai yra sudaryti iš 1000 arba 10000 studentų, su list konteineriu programa veikia sparčiau arba taip pat, tačiau jau didėjant studentų kiekiui (esant 100000, 1000000, 10000000 studentų) programa veikia sparčiau su vector konteineriu.

**Kompiuterio duomenys**:
CPU - Apple M1 chip 8-core CPU with 4 perform­ance cores and 4 efficiency cores
RAM - 8 GB 
HDD - 256 GB SSD

Output, kai suvedami duomenys
   <img width="879" alt="duomenu_suvedimo_pvz" src="https://github.com/EmilijaBareikaite/pirma-uzduotis/assets/145277411/281e7c9b-eb6c-4a25-9875-dde41baf4efd">

Output, kai generuojamas failas
   <img width="887" alt="failo_generavimo_pvz" src="https://github.com/EmilijaBareikaite/pirma-uzduotis/assets/145277411/3ad276bd-dae2-4001-bd78-7f1d36a9e906">

Output, kai nuskaitomas failas
<img width="890" alt="failo_nuskaitymo_pvz" src="https://github.com/EmilijaBareikaite/pirma-uzduotis/assets/145277411/54d8351c-eefd-4d63-ae1c-90ab619c015f">
