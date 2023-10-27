# **Pirma užduotis (v0.2)**
1. Šioje programoje nuskaitomi duomenys, susiję su studentais - _jų vardai, pavardės, pažymiai ir egzaminų rezultatai._
2. Vartotojas turi keturias opcijas: jis gali **mechaniškai suvesti duomenis**, gali **automatiškai sugeneruoti duomenis**, gali **skaityti duomenis iš pasirinkto failo**, ir gali **sugeneruoti failus**, nurodęs, kiek bus studentų ir kiek namų darbų rezultatų turės kiekvienas studentas.
3. Output'e išvedama studentų _vardai, pavardės ir galutinis rezultatas_, jei vartotojas renkasi suvedinėti duomenis (vartotojas sprendžia ar per **medianą**, ar per **vidurkį** bus rodoma).

Šioje programoje taip pat skaičiuojamas tam tikrų žingsnių laikas: failo generavimo, failo nuskaitymo, išrūšiavimo(pateiktas failas, rūšiuojamas į gudručius (galutinis rezultatas >= 5) ir vargšiukus(galutinis rezultatas < 5)). Todėl buvo atlikta analizė su 5 skirtingų dydžių failais - 1000, 10000, 100000, 1000000, 10000000. 

**Analizės eiga:** buvo kuriamas vienas tam tikro dydžio (tačiau visuose failuose buvo 5 namų darbų rezultatai) failas ir buvo išmatuotajamas jo sukūrimo laikas. Tuomet tas pats failas 5 kartus buvo nuskaitomas, išrūšiuojmas ir vėliau iš jo spausdinami 2 nauji failai. Gavus visus skaičiavimas, buvo vedami vidurkiai 100-tųjų tikslumu (jie ir bus pateikiami išvadose).

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
|  Failo generavimo laikas                      | 0,01 s  |  0,42 s | 3,95 s | 39,42 s |  396,06 s |
|  Failo nuskaitymo vidutinis laikas            | 0 s     |  0,05 s | 0,39 s | 3,5 s   |  38,4 s   |
|  Failo išrūšiavimo vidutinis laikas           | 0 s     |  0,01 s | 0,08 s | 0,49 s  |  10,92 s  |
|  Vargšiukų failo spausdinimo vidutinis laikas | 0 s     |  0,02 s | 0,19 s | 1,89 s  |  20,93 s  |
|  Gudručių failo spausdinimo vidutinis laikas  | 0 s     |  0,03 s | 0,28 s | 2,64 s  |  31,20 s  |
|  **Bendrai užtrukta**                             | **0,01 s** |  **0,53 s** | **4,88 s** | **47,94 s** |  **497,5 s** |
   
   
