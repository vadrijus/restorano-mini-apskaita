#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

int getData(menuItemType menuList[]) {
    ifstream failas("menu.txt");
    int n = 0;
    while (n < 100 && getline(failas, menuList[n].menuItem, ';')) {
        if (!(failas >> menuList[n].menuPrice)) break;
        failas.ignore(1000, '\n');
        n++;
    }
    return n;
}

void showMenu(menuItemType menuList[], int n) {
    cout << fixed << setprecision(2);
    cout << "Pusryciu meniu\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << menuList[i].menuItem
             << " - " << menuList[i].menuPrice << " EUR\n";
    }
    cout << "Iveskite patiekalo numeri ir porciju kieki. Baigti - 0.\n";
}

void printCheck(menuItemType menuList[], int kiekiai[], int n) {
    ostringstream cekis;
    cekis << fixed << setprecision(2);
    cekis << "Sveiki atvyke i restorana Rytas\n\n";
    double suma = 0;
    for (int i = 0; i < n; i++) {
        if (kiekiai[i] > 0) {
            double patiekaloSuma = menuList[i].menuPrice * kiekiai[i];
            suma += patiekaloSuma;
            cekis << kiekiai[i] << " x " << menuList[i].menuItem
                  << " - " << patiekaloSuma << " EUR\n";
        }
    }
    double pvm = round(suma * 0.21 * 100) / 100;
    cekis << "\nTarpine suma: " << suma << " EUR\n";
    cekis << "Mokesciai (21%): " << pvm << " EUR\n";
    cekis << "Galutine suma: " << suma + pvm << " EUR\n";
    cout << cekis.str();
    ofstream failas("receipt.txt");
    if (!failas) {
        cout << "Nepavyko sukurti receipt.txt\n";
        return;
    }
    failas << cekis.str();
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    menuItemType menuList[100];
    int kiekiai[100] = {};
    int n = getData(menuList);
    if (n == 0) {
        cout << "Nepavyko nuskaityti menu.txt\n";
        return 1;
    }
    showMenu(menuList, n);
    int numeris, kiekis;
    while (true) {
        cout << "Patiekalo numeris: ";
        if (!(cin >> numeris) || numeris == 0) break;
        if (numeris < 1 || numeris > n) {
            cout << "Tokio patiekalo nera\n";
            continue;
        }
        cout << "Porciju kiekis: ";
        if (!(cin >> kiekis)) break;
        if (kiekis > 0 && kiekis <= 100 - kiekiai[numeris - 1])
            kiekiai[numeris - 1] += kiekis;
        else
            cout << "Galima nuo 1 iki 100 porciju vienam patiekalui\n";
    }
    printCheck(menuList, kiekiai, n);
    return 0;
}
