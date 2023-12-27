# **Trečia užduotis (v3.0)**

**Tęsinys 1 užduoties**

Šioje programoje atliekama tas pats, kaip ir pirmos užduoties programoje, tačiau visas veikimas realizuotas ne su struktūromis, o su **_klasėmis_**. Kode paliktas darbas tik su vektoriaus konteineriu ir palikta greičiausiai veikianti strategija, skirta rūšiuoti studentus į dvi atskiras grupes. Programoje realizuoti **"Rule of three"** operatoriai bei **įvesties/išvesties** operatoriai sukurtai studento klasei. Įvesties/išvesties operatoriai pritaikyti pačiai programai, o "Rule of three" operatorių veikimui pademonstruoti buvo sukurtas atskira kodo dalis, kurią vartotojas gali pasirinkti paleisti. Programoje sukurtos dvi klasės - viena iš jų yra bazinė (Žmogaus klasė): jos objektų negalima sukurti, o kita išvestinė (Studentas) klasė, kuri pavledi bazinės kalsės metodus.

Taip pat prie repozicijos yra prisegtas html.zip, kuris savyje turi šios programos dokumentaciją, sukurtą naudojant Doxygen. Atidarius aplankalą ir paspaudus failą index.html, atsidarys puslapis, kuriame bus aprašyta esminė informacija apie sukurtą programą.

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
|  Failo nuskaitymo vidutinis laikas             | 0,26 s | 2,15 s   |  
|  Failo išrūšiavimo vidutinis laikas           | 0,04 s | 0,30 s  |  
|  Vargšiukų failo spausdinimo vidutinis laikas | 0,12 s | 1,20 s  |  
|  Gudručių failo spausdinimo vidutinis laikas  | 0,17 s | 1,68 s  |  
|  **Bendrai užtrukta**                         | **4,54 s** | **44,75s** |

**Palyginimas:** Iš lentelės rezultatų matoma, kad su struktūra ir klase veikimo sparta yra gana panaši, tačiau **naudojant klases sparta yra greitesnė.**

Taip pat buvo atlikta spartos analizė naudojant Flag'us O1, O2, O3 klasėms ir struktūroms. **Rezultatai:**

**Naudojant struktūrą**
_O1 flag_
|                                                | 100000 | 1000000 | 
| --------------------------------------------- |:-------:|:-------:|
|  Failo generavimo laikas                      | 3,95 s | 39,42 s |  
|  Failo nuskaitymo vidutinis laikas             | 0,12 s | 0,78 s   |  
|  Failo išrūšiavimo vidutinis laikas           | 0 s | 0,02 s  |  
|  Vargšiukų failo spausdinimo vidutinis laikas | 0,12 s | 1,11 s  |  
|  Gudručių failo spausdinimo vidutinis laikas  | 0,15 s | 1,55 s  |  
|  **Bendrai užtrukta**                         | **4,34 s** | **42,88 s** |

exe failo dydis: 127 136 bytes

_O2 flag_
|                                                | 100000 | 1000000 | 
| --------------------------------------------- |:-------:|:-------:|
|  Failo generavimo laikas                      | 3,95 s | 39,42 s |  
|  Failo nuskaitymo vidutinis laikas             | 0,11 s | 0,78 s   |  
|  Failo išrūšiavimo vidutinis laikas           | 0 s | 0,02 s  |  
|  Vargšiukų failo spausdinimo vidutinis laikas | 0,12 s | 1,11 s  |  
|  Gudručių failo spausdinimo vidutinis laikas  | 0,16 s | 1,61 s  |  
|  **Bendrai užtrukta**                         | **4,34 s** | **42,94 s** |

exe failo dydis: 127 040 bytes

_O3 flag_
|                                                | 100000 | 1000000 | 
| --------------------------------------------- |:-------:|:-------:|
|  Failo generavimo laikas                      | 3,95 s | 39,42 s |  
|  Failo nuskaitymo vidutinis laikas             | 0,11 s | 0,77 s   |  
|  Failo išrūšiavimo vidutinis laikas           | 0 s | 0,02 s  |  
|  Vargšiukų failo spausdinimo vidutinis laikas | 0,13 s | 1,16 s  |  
|  Gudručių failo spausdinimo vidutinis laikas  | 0,16 s | 1,73 s  |  
|  **Bendrai užtrukta**                         | **4,35 s** | **43,1 s** |

exe failo dydis: 126 672 bytes

**Naudojant klasę**
_O1 flag_
|                                                | 100000 | 1000000 | 
| --------------------------------------------- |:-------:|:-------:|
|  Failo generavimo laikas                      | 3,95 s | 39,42 s |  
|  Failo nuskaitymo vidutinis laikas             | 0,13 s | 0,92 s   |  
|  Failo išrūšiavimo vidutinis laikas           | 0,01 s | 0,06 s  |  
|  Vargšiukų failo spausdinimo vidutinis laikas | 0,12 s | 1,11 s  |  
|  Gudručių failo spausdinimo vidutinis laikas  | 0,17 s | 1,55 s  |  
|  **Bendrai užtrukta**                         | **4,38 s** | **43,06 s** |

exe failo dydis: 109 920 bytes

_O2 flag_
|                                                | 100000 | 1000000 | 
| --------------------------------------------- |:-------:|:-------:|
|  Failo generavimo laikas                      | 3,95 s | 39,42 s |  
|  Failo nuskaitymo vidutinis laikas             | 0,13 s | 0,89 s   |  
|  Failo išrūšiavimo vidutinis laikas           | 0,01 s | 0,06 s  |  
|  Vargšiukų failo spausdinimo vidutinis laikas | 0,12 s | 1,1 s  |  
|  Gudručių failo spausdinimo vidutinis laikas  | 0,2 s | 1,65 s  |  
|  **Bendrai užtrukta**                         | **4,41 s** | **43,12 s** |

exe failo dydis: 109 232 bytes

_O3 flag_
|                                                | 100000 | 1000000 | 
| --------------------------------------------- |:-------:|:-------:|
|  Failo generavimo laikas                      | 3,95 s | 39,42 s |  
|  Failo nuskaitymo vidutinis laikas             | 0,13 s | 0,9 s   |  
|  Failo išrūšiavimo vidutinis laikas           | 0,01 s | 0,06 s  |  
|  Vargšiukų failo spausdinimo vidutinis laikas | 0,12 s | 1,09 s  |  
|  Gudručių failo spausdinimo vidutinis laikas  | 0,16 s | 1,59 s  |  
|  **Bendrai užtrukta**                         | **4,37 s** | **43,06 s** |

exe failo dydis: 108 848 bytes

**Išvados**: programa veikia greičiau su šiais flag'ais. Iš lentelių matoma, kad struktūroms greičiausiai veikia su O1 flag'u, o klasėms - O3.  

**Įdiegimo bei naudojimosi instukcija:** reikia atsisiųsti pateiktus failus ir susidėti į bendrą aplanką. Šiame aplankale sukurkite "src" ir "include" aplankalus, į "src" sudėkite visus .cpp failus, o į "include" visus .h failus, o visus kitus failus palikite aplankale. Toliau intrukcijos pateiktos "mac OS" operacinės naudotojiems: atidarykite terminalą ir pasiekite Jūsų aplankalo direktoriją, tada rašykite "chmod +x RUNMEE.sh", tada suveskite "./RUNMEE.sh". To turi pakakti, kad programa pasileistų terminale. Toliau, suvedinėkite į terminalą tai, ką nurodo terminale pateikiamos instrukcijos, ir atsižvelkite į tai, ką norite  nuveikti (opcijos aprašytos viršuje) su programa. Be to, jeigu turite failų su kuriais norėsite dirbti (juos nuskaityti), įdėkite failus į src aplankalą ir pakeiskite (nukopijuokite, jei turite daugiau failų, arba ištrinkite šias eilutes, jeigu neturite) RUNMEE.sh 4, 5, 6, 7, 8 eilutes su jūsų failo pavadinimais.

**Darbo su .dmg failu instrukcija:** repozitorijoje yra prisegtas failas: "galutine.dmg", skirtas atlikti panašią funkciją, kurią atlieka setup.exe/msi failai. Jų nebuvo galima realizuoti, kadangi dirbama ant macOS opearicnės sistemos. Todėl buvo sukurtas .dmg failas. Tai atminties diskas, kuris savyje laiko šios programos .exe failą bei pavyzdinį tektstinį failą, jeigu būtų norima išsitestuoti darbą su failais. Su .dmg failo pagalba, galima dalintis .exe failu su kitais macOS naudotoajais. _Kaip jis veikia:_ du kartus paspaudus failą (geriausia jį įsikelti į darbalaukį), darbalaukyje atsiranda diskas, kuriame laikomi minėti .exe ir .txt failai. Atidarius diską, atsiranda langas su failais, kuriuos vartotojas jau gali pasiekti ir išsikelti į kokią nori direktoriją (tarkim darbalaukį). Tuomet vartotojas gali paleisti sukurtą programą (.exe failą). 

**Papildoma informacija**: taip pat prie visų failų yra prisegtas "DMG.sh" failas. Jį paleidus per terminalą ir turint .dmg failą darbalaukyje, .exe ir .txt failai atsiranda darbalaukyje ir papildomoje direktorijoje (šiuo metu nustatyta, kad keliautų į VU/Vardenis-Pavrdenis direktoriją). T. y. šis .sh failas automatiškai atidaro tiek .dmg failą, tiek diską, sukelia failus, kur jiems nurodyta nukeliauti, ir tada uždaro diską. Tačiau nroint, kad šis failas veiktų reikia atlikti keletą veiksmų:
1. Atidarius DMG.sh failą, reikės pakeisti pirmų trijų eilučių direktorijas (pirma skirta pasiekti .dmg failą, antra vienai direktorijai, trečia darbalaukiui pasiekti).
2. Išsaugoti pakeitimus.
3. Atidaryti terminalą ir pasiekti direktoriją, kur yra .sh failas.
4. Suvesti: chmod +x DMG.sh
5. Suvesti: ./DMG.sh 

To turi pakakti, kad failas pasileistų ir rastumėte .exe ir .txt failus darbalaukyje ir kitoje, jūsų nurodytoje direktorijoje.

**Kompiuterio duomenys**:

CPU - Apple M1 chip 8-core CPU with 4 perform­ance cores and 4 efficiency cores

RAM - 8 GB 

HDD - 256 GB SSD

Kaip atrodo klasės

<img width="675" alt="image" src="https://github.com/EmilijaBareikaite/antra-uzduotis/assets/145277411/7589f296-02ee-45e6-bae7-c69fa0d5aa35">

<img width="591" alt="image" src="https://github.com/EmilijaBareikaite/antra-uzduotis/assets/145277411/c698a058-caca-4213-b35e-f396326e830f">


Studento klasėje realizuoti minėti operatoriai ("Rule of three", išvesties, įvesties)

<img width="591" alt="Screenshot 2023-12-03 at 18 30 51" src="https://github.com/EmilijaBareikaite/antra-uzduotis/assets/145277411/471aef39-5365-4643-8966-71cd1ba03237">



Kaip atrodo "Rule of three" operatoriai

<img width="581" alt="image" src="https://github.com/EmilijaBareikaite/antra-uzduotis/assets/145277411/0de5c6a8-6bb3-4714-9f37-6b2ca3f7db5b">



Demonstarvimas, kad bazinės klasės objektų neįmanoma sukurti bei "Rule of three" kodo demonstravimo dalis
<img width="627" alt="image" src="https://github.com/EmilijaBareikaite/antra-uzduotis/assets/145277411/0bdabce1-dde0-4bd9-9e8c-919c127d8790">

Output, kai pasirenkama demonstruoti
<img width="896" alt="image" src="https://github.com/EmilijaBareikaite/antra-uzduotis/assets/145277411/631d0f83-d7d1-4d83-9faa-a97d2b01de21">






