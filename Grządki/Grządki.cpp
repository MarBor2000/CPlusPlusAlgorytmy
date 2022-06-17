#include <iostream>


using namespace std;

struct warzywo{
    string nazwa;
    double z; // poziom zakwaszenia gleby
    int d;  // odleglosc nasadow w milimetrach
    int m; // numer miesiaca
};

void sortujKorzeniowe(warzywo warzywa[],int n,int tab[3]) {
    int j = 0;
    string pomNazwa;
    double pomZ;
    int pomD;
    int pomM;
    warzywo pom;
    if (tab[0] == 1 && tab[1] == 2) {//git
        for (int i = 0; i < n; i++) {
            pomZ = warzywa[i].z;
            pomD = warzywa[i].d;
            pomM = warzywa[i].m;
            pom = warzywa[i];
            j = i - 1;
            while (j >= 0 && (warzywa[j].z < pomZ || (warzywa[j].z == pomZ && warzywa[j].d < pomD) || (warzywa[j].z == pomZ && warzywa[j].d == pomD && warzywa[j].m < pomM))) {
                warzywa[j + 1] = warzywa[j];
                --j;
            }
            warzywa[j + 1] = pom;
        }
    }
    else if (tab[0] == 1 && tab[1] == 3) {//git
        for (int i = 0; i < n; i++) {
            pomZ = warzywa[i].z;
            pomD = warzywa[i].d;
            pomM = warzywa[i].m;
            pom = warzywa[i];
            j = i - 1;
            while (j >= 0 && (warzywa[j].z < pomZ || (warzywa[j].z == pomZ && warzywa[j].m < pomM) || (warzywa[j].z == pomZ && warzywa[j].m == pomM && warzywa[j].d < pomD))) {
                warzywa[j + 1] = warzywa[j];
                --j;
            }
            warzywa[j + 1] = pom;
        }


    }
    else if (tab[0] == 2 && tab[1] == 1) {
        for (int i = 0; i < n; i++) {
            pomZ = warzywa[i].z;
            pomD = warzywa[i].d;
            pomM = warzywa[i].m;
            pom = warzywa[i];
            j = i - 1;
            while (j >= 0 && (warzywa[j].d < pomD || (warzywa[j].d == pomD && warzywa[j].z < pomZ) || (warzywa[j].d == pomD && warzywa[j].z == pomZ && warzywa[j].m < pomM))) {
                warzywa[j + 1] = warzywa[j];
                --j;
            }
            warzywa[j + 1] = pom;
        }
    }
    else if (tab[0] == 2 && tab[1] == 3) {//git
        for (int i = 0; i < n; i++) {
            pomZ = warzywa[i].z;
            pomD = warzywa[i].d;
            pomM = warzywa[i].m;
            pom = warzywa[i];
            j = i - 1;
            while (j >= 0  && (warzywa[j].d < pomD || (warzywa[j].d == pomD && warzywa[j].m < pomM) || (warzywa[j].m == pomM && warzywa[j].d == pomD && warzywa[j].z < pomZ))) {
                warzywa[j + 1] = warzywa[j];
                --j;
            }
            warzywa[j + 1] = pom;
        }
    }
    else if (tab[0] == 3 && tab[1] == 1) {//git
        for (int i = 0; i < n; i++) {
            pomZ = warzywa[i].z;
            pomD = warzywa[i].d;
            pomM = warzywa[i].m;
            pom = warzywa[i];
            j = i - 1;
            while (j >= 0 && (warzywa[j].m < pomM || (warzywa[j].m == pomM && warzywa[j].z < pomZ) || (warzywa[j].m == pomM && warzywa[j].z == pomZ && warzywa[j].d < pomD))) {
                warzywa[j + 1] = warzywa[j];
                --j;
            }
            warzywa[j + 1] = pom;
        }
        
    }
    else if (tab[0] == 3 && tab[1] == 2) {
        for (int i = 0; i < n; i++) {
            pomZ = warzywa[i].z;
            pomD = warzywa[i].d;
            pomM = warzywa[i].m;
            pom = warzywa[i];
            j = i - 1;
            while (j >= 0 && (warzywa[j].m < pomM || (warzywa[j].m == pomM && warzywa[j].d < pomD) || (warzywa[j].m == pomM && warzywa[j].d == pomD && warzywa[j].z < pomZ))) {
                warzywa[j + 1] = warzywa[j];
                --j;
            }
            warzywa[j + 1] = pom;
        }
    }

}

void sortujNiekorzeniowe(warzywo warzywa[],int n,int tab[3]) {
    int j = 0;
    double pomZ;
    int pomD;
    int pomM; 
    warzywo pom;
    if (tab[0] == 1 && tab[1] == 2) {
        for (int i = 0+n; i < n*2; i++) {
            pomZ = warzywa[i].z;
            pomD = warzywa[i].d;
            pomM = warzywa[i].m;
            pom = warzywa[i];
            j = i - 1;
            while (j >= 0+n && (warzywa[j].z < pomZ || (warzywa[j].z == pomZ && warzywa[j].d < pomD) || (warzywa[j].z == pomZ && warzywa[j].d == pomD && warzywa[j].m < pomM))) {
                warzywa[j + 1] = warzywa[j];
                --j;
            }
            warzywa[j+1] = pom;
        }
    }
    else if (tab[0] == 1 && tab[1] == 3) {
        for (int i = 0+n; i < n*2; i++) {
            pomZ = warzywa[i].z;
            pomD = warzywa[i].d;
            pomM = warzywa[i].m;
            pom = warzywa[i];
            j = i - 1;
            while (j >= 0+n && (warzywa[j].z < pomZ || (warzywa[j].z == pomZ && warzywa[j].m < pomM) || (warzywa[j].z == pomZ && warzywa[j].m == pomM && warzywa[j].d < pomD))) {
                warzywa[j + 1] = warzywa[j];
                --j;
            }
            warzywa[j + 1] = pom;
        }
    }
    else if (tab[0] == 2 && tab[1] == 1) {
        for (int i = 0+n; i < n*2; i++) {
            pomZ = warzywa[i].z;
            pomD = warzywa[i].d;
            pomM = warzywa[i].m;
            pom = warzywa[i];
            j = i - 1;
            while (j >= 0 + n && (warzywa[j].d < pomD || (warzywa[j].d == pomD && warzywa[j].z < pomZ) || (warzywa[j].d == pomD && warzywa[j].z == pomZ && warzywa[j].m < pomM))) {
                warzywa[j + 1] = warzywa[j];
                --j;
            }
            warzywa[j + 1] = pom;
        }
    }
    else if (tab[0] == 2 && tab[1] == 3) { 
        for (int i = 0+n; i < n * 2 ; i++) {
            pomZ = warzywa[i].z;
            pomD = warzywa[i].d;
            pomM = warzywa[i].m;
            pom = warzywa[i];

            j = i - 1;
            while (j >= 0+n && (warzywa[j].d < pomD || (warzywa[j].d == pomD && warzywa[j].m < pomM) || (warzywa[j].m == pomM && warzywa[j].d == pomD && warzywa[j].z < pomZ))) {
                warzywa[j + 1] = warzywa[j];
                --j;
            }
            warzywa[j + 1] = pom;
        }
    }
    else if (tab[0] == 3 && tab[1] == 1) {
        for (int i = 0 + n; i < n * 2; i++) {
            pomZ = warzywa[i].z;
            pomD = warzywa[i].d;
            pomM = warzywa[i].m;
            pom = warzywa[i];

            j = i - 1;
            while (j >= 0+n && (warzywa[j].m < pomM || (warzywa[j].m == pomM && warzywa[j].z < pomZ) || (warzywa[j].m == pomM && warzywa[j].z == pomZ && warzywa[j].d < pomD))) {
                warzywa[j + 1] = warzywa[j];
                --j;
            }
            warzywa[j + 1] = pom;
        }
    }
    else if(tab[0] == 3 && tab[1] == 2) {
        for (int i = 0+n; i < n*2; i++) {
            pomZ = warzywa[i].z;
            pomD = warzywa[i].d;
            pomM = warzywa[i].m;
            pom = warzywa[i];
            j = i - 1;
            while (j >= 0+n && (warzywa[j].m < pomM || (warzywa[j].m == pomM && warzywa[j].d < pomD) || (warzywa[j].m == pomM && warzywa[j].d == pomD && warzywa[j].z < pomZ))) {
                warzywa[j + 1] = warzywa[j];
                --j;
            }
            warzywa[j + 1] = pom;
        }
    }

}

void wyswietl(warzywo warzywa[], int n) {
    for (int i = 0; i < n; i++) {
        cout <<warzywa[i].nazwa << "-" << warzywa[i+n].nazwa <<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    cin >> n;
    warzywo *warzywa = new warzywo[n*2];
    int tab[3];
    cin >> tab[0]>>tab[1]>>tab[2];
    for (int i = 0; i < n * 2; i++) {
        cin >> warzywa[i].nazwa >> warzywa[i].z >> warzywa[i].d >> warzywa[i].m;
    }
    sortujKorzeniowe(warzywa, n, tab);
    sortujNiekorzeniowe(warzywa, n, tab);
    wyswietl(warzywa, n);
}