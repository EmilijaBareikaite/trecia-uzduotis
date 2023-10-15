# **Pirma užduotis (v0.2)**
1. Šioje programoje nuskaitomi duomenys, susiję su studentais - _jų vardai, pavardės, pažymiai ir egzaminų rezultatai._
2. Vartotojas turi keturias opcijas: jis gali **mechaniškai suvesti duomenis**, gali **automatiškai sugeneruoti duomenis**, gali **skaityti duomenis iš pasirinkto failo**, ir gali **sugeneruoti failus**, nurodęs, kiek bus studentų ir kiek namų darbų rezultatų turės kiekvienas studentas.
3. Output'e išvedama studentų _vardai, pavardės ir galutinis rezultatas_, jei vartotojas renkasi suvedinėti duomenis (vartotojas sprendžia ar per **medianą**, ar per **vidurkį** bus rodoma).

Šioje programoje taip pat skaičiuojamas tam tikrų žingsnių laikas: failo generavimui, failo nuskaitymui, išrūšiavimui(pateiktas failas, rūšiuojamas į gudručius (galutinis rezultatas >= 5) ir vargšiukus(galutinis rezultatas < 5)). Todėl buvo atlikta analizė su 5 skirtingų dydžių failais - 1000, 10000, 100000, 1000000, 10000000. 

**Analizės eiga:** buvo kuriamas vienas tam tikro dydžio (tačiau visuose failuose buvo 5 namų darbų rezultatai) failas ir buvo išmatuotajamas jo sukūrimo laikas. Tuomet tas pats failas 3 kartus buvo nuskaitomas, išrūšiuojmas ir vėliau iš jo spausdinami 2 nauji failai. Gavus visus skaičiavimas, buvo vedami vidurkiai 100-tųjų tikslumu (jie ir bus pateikiami išvadose).

**Analizės išvados:**

1. Kai studentų buvo 1000: 
   Failo generavimas užtruko: 0,06 s
   Failo nuskaitymas (vidutiniškai) užtruko: 0,01 s
   Failo išrūšiavimas (vidutiniškai) užtruko: 0 s
   Vargšiukų failo spausdinimas (vidutiniškai) užtruko: 0 s
   Gudručių failo spausdinimas (vidutiniškai) užtruko: 0,01 s

   Bendrai užtrukta: 0,08 s
2. Kai studentų buvo 10000:
   Failo generavimas užtruko: 0,42 s
   Failo nuskaitymas (vidutiniškai) užtruko: 0,05 s
   Failo išrūšiavimas (vidutiniškai) užtruko: 0,01 s 
   Vargšiukų failo spausdinimas (vidutiniškai) užtruko: 0,02 s
   Gudručių failo spausdinimas (vidutiniškai) užtruko: 0,03 s

   Bendrai užtrukta: 0,53 s
   
3. Kai studentų buvo 100000:
   Failo generavimas užtruko: 3,95 s
   Failo nuskaitymas (vidutiniškai) užtruko: 0,36 s
   Failo išrūšiavimas (vidutiniškai) užtruko: 0,05 s
   Vargšiukų failo spausdinimas (vidutiniškai) užtruko: 0,19 s
   Gudručių failo spausdinimas (vidutiniškai) užtruko: 0,27 s

   Bendrai užtrukta: 4,82 s
   
4. Kai studentų buvo 1000000:
   Failo generavimas užtruko: 39,42 s
   Failo nuskaitymas (vidutiniškai) užtruko: 3,5 s
   Failo išrūšiavimas (vidutiniškai) užtruko: 0,49 s
   Vargšiukų failo spausdinimas (vidutiniškai) užtruko: 1,89 s
   Gudručių failo spausdinimas (vidutiniškai) užtruko: 2,64 s

   Bendrai užtrukta: 47,94 s
   
5. Kai studentų buvo 10000000:
   Failo generavimas užtruko: 396,06 s
   Failo nuskaitymas (vidutiniškai) užtruko: 36,6 s
   Failo išrūšiavimas (vidutiniškai) užtruko: 5 s
   Vargšiukų failo spausdinimas (vidutiniškai) užtruko: 20,12 s
   Gudručių failo spausdinimas (vidutiniškai) užtruko: 27,86 s

   Bendrai užtrukta: 485,64 s





   
   
