# Restorano mini apskaitos sistema

C++ pusryciu uzsakymo programa.

Meniu skaitomas is menu.txt. Eiluteje rasomas pavadinimas ir kaina,
atskirti kabliataskiu. Failas turi buti tame paciame aplanke, is kurio
paleidziama programa.

Pasirenkamas patiekalo numeris ir porciju kiekis. Galima rinktis kelis
patiekalus ir ta pati pakartotinai. Ivedus 0 parodoma saskaita su 21 % PVM
ir ji issaugoma receipt.txt. Nauja saskaita perraso sena.

Naudojama menuItemType struktura, menuList masyvas ir funkcijos
getData, showMenu, printCheck.

Kompiliavimas su g++:
```
g++ -std=c++17 main.cpp -o restoranas
```

Su Visual Studio Developer Command Prompt:
```
cl /EHsc /utf-8 main.cpp /Fe:restoranas.exe
```

Windows paleidimas: restoranas.exe. Linux: ./restoranas.

Patikrinta: 1 sonine, 2 keksiukai ir 1 kava = 4.93 EUR,
PVM 1.04 EUR, galutine suma 5.97 EUR.
