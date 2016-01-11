/* 
 * File:   recursivite.cpp
 * Author: rogeri
 *
 * Created on 2 novembre 2015, 15:18
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>
#include <inttypes.h>

using namespace std;

/*
 * 
 */
int factorielleIter(int n) {
    // {n ≥ 0} => {résultat = n! (soit 1×2×...×n−1×n)}
    int i=1;
    int r=1;
    while (i<=n) {
        r=r*i;
        i++;
    }
    return r;
}

int factorielleRec(int n) {
    // {n ≥ 0} => {résultat = n!(soit (n-1)!×n)}
    if (n==0) {
        return 1;
    } else {
        return factorielleRec(n-1)*n;
    }
}

bool estPair(int n) {
    // {n ≥ 0} => {résultat = true si n est pair; false sinon}
    if (n<2 && n>=0) {
        return n==0;
    } else {
        return estPair(n-2);
    }
}

bool estPairQcq(int n) {
    // {} => {résultat = true si n est pair; false sinon}
    if (n<=1 && n>=0) {
        return n==0;
    } else {
        if (n<0) {
            return estPairQcq(n+2);
        } else {
            return estPairQcq(n-2);
        }
    }
}

bool estImpairCroisee(int n);
bool estPairCroisee(int n) {
    // {n ≥ 0} => {résultat = true si n est pair; false sinon}
    if (n<2) {
        return n==0;
    } else {
        return estImpairCroisee(n-1);
    }
}
bool estImpairCroisee(int n) {
    // {n ≥ 0} => {résultat = true si n est impair; false sinon}
    if (n<2) {
        return n==1;
    } else {
        return estPairCroisee(n-1);
    }
    
}

bool estImpairQcqCroisee(int n);
bool estPairQcqCroisee(int n) {
    // {} => {résultat = true si n est pair; false sinon}
    if (n<2 && n>=0) {
        return n==0;
    } else {
        if (n<0)
            return estImpairQcqCroisee(n+1);
        else
            return estImpairQcqCroisee(n-1);
    }
}

bool estImpairQcqCroisee(int n) {
    // {} => {résultat = true si n est pair; false sinon}
    if (n<2 && n>=0) {
        return n==1;
    } else {
        if (n<0)
            return estPairQcqCroisee(n+1);
        else
            return estPairQcqCroisee(n-1);
    }
}

int fonction91(int n) {
    if (n>100) {
        return n-10;
    } else {
        return fonction91(fonction91(n+11));
    }
}

template<class T>
int rechercherIter(vector<T> v, T val) {
    int i=0;
    while (i<v.size()-1 && v[i]<val) {
        i++;
    }
    return (v[i]==val?1:-1)*(i+1);
}

template<class T>
int dichoIter(vector<T> v, T val) {
    int m, iMin = 0, iMax = v.size()-1;
    if (v[iMax] < val)
        return -(v[iMax]+1);
    while (iMin <= iMax) {
        m = (iMin+iMax)/2;
        if (v[m] < val) {
            iMin = m+1;
        } else if (v[m] > val) {
            iMax = m-1;
        } else {
            iMin=iMax+1;
        }
    }
    return (v[m]==val?1:-1)*(m+1);
}
template<class T>
int dichoRecWorker(vector<T> v,int min, int max, T val);
template<class T>
int dichoRec(vector<T> v, T val) {
    if (v[v.size()-1] < val)
        return -v.size();
    return dichoRecWorker(v,0,(int)(v.size()-1),val);
}
template<class T>
int dichoRecWorker(vector<T> v,int min, int max, T val) {
    if (min > max) {
        if (v[min]== val)
            return min+1;
        else
            return -(min+1);
    } else {
        int m = (min+max)/2;
        if (v[m] < val)
            return dichoRecWorker(v,m+1,max,val);
        else
            return dichoRecWorker(v,min,m-1,val);
    }
}

void hanoi(int nbDisques, char depart, char intermediaire, char arrivee) {
    // {n ≥1} => {affiche les déplacement à effectuer pour résoudre le pb}
    if (nbDisques == 1) {
        cout << "Deplacement disque 1 du piquet " << depart << " vers le piquet " << arrivee << endl;
    } else {
        hanoi(nbDisques-1,depart,arrivee,intermediaire);
        cout << "Deplacement disque " << nbDisques << " du piquet " << depart << " vers le piquet " << arrivee << endl;
        hanoi(nbDisques-1,intermediaire,depart,arrivee);
    }
}

template<class T>
T maxVectWorker(vector<T> v,int inf,int sup);
template<class T>
T maxVect(vector<T> v) {
    // {} => {résutlat = valeur du plus grand élément de v; 0 si v est vide}
    return maxVectWorker(v,0,v.size()-1);
}
template<class T>
T maxVectWorker(vector<T> v,int inf,int sup) {
    if (inf>sup)
        return 0;
    else if (inf==sup)
        return v[inf];
    else {
        int m=(inf+sup)/2;
        return max(maxVectWorker(v,inf,m),maxVectWorker(v,m+1,sup));
    }
}

double puissance(float x, int n) {
    // {} => {résultat = x puissance n }
    if (n==0)
        return 1;
    else
        return x*puissance(x,n-1);
}

double puissanceNbMult(float x, int n, int & nb) {
    // {} => {résultat = x puissance n; nb = nombre d'operations}
    nb++;
    if (n==0)
        return 1;
    else
        return x*puissanceNbMult(x,n-1,nb);
}

int main(int argc, char** argv) {
    cout << endl << "--- > Factorielle < ---" << endl;
    cout <<  "5! = " <<factorielleIter(5) << endl;
    cout <<  "4! = " <<factorielleRec(4) << endl;
    
    cout << endl << "--- > Parité < ---" << endl;
    cout << "14 est " << (estPair(14)?"pair":"impair") << "." << endl;
    cout << "-6 est " << (estPairQcq(-6)?"pair":"impair") << "." << endl;
    cout << "-9 est " << (estPairQcq(-9)?"pair":"impair") << "." << endl;
    cout << "6 est " << (estPairCroisee(6)?"pair":"impair") << "." << endl;
    cout << "9 est " << (estPairCroisee(9)?"pair":"impair") << "." << endl;
    cout << "8 est " << (estImpairCroisee(8)?"impair":"pair") << "." << endl;
    cout << "17 est " << (estImpairCroisee(17)?"impair":"pair") << "." << endl;
    cout << "-5 est " << (estPairQcqCroisee(-5)?"pair":"impair") << "." << endl;
    cout << "-4 est " << (estPairQcqCroisee(-4)?"pair":"impair") << "." << endl;
    cout << "-21 est " << (estImpairQcqCroisee(-21)?"impair":"pair") << "." << endl;
    cout << "-26 est " << (estImpairQcqCroisee(-26)?"impair":"pair") << "." << endl;
    
    cout << endl << "--- > Fonction 91 < ---" << endl;
    cout << "F91(101) = " << fonction91(101) << endl;
    cout << "F91(54) = " << fonction91(54) << endl;
    cout << "F91(127) = " << fonction91(127) << endl;
    
    cout << endl << "--- > Recherche < ---" << endl;
    vector<int> vect = {2,4,8,12,15,17,24,38,64,65,87};
    cout << "Position de 12 dans le vecteur : " << rechercherIter(vect,12) << endl;
    cout << "Position de 21 dans le vecteur : " << rechercherIter(vect,21) << endl;
    
    cout << endl << "--- > Dichotomie < ---" << endl;
    cout << "Position de 17 dans le vecteur : " << dichoIter(vect,17) << endl;
    cout << "Position de 39 dans le vecteur : " << dichoIter(vect,39) << endl;
    cout << "Position de 24 dans le vecteur : " << dichoRec(vect,24) << endl;
    cout << "Position de 67 dans le vecteur : " << dichoRec(vect,67) << endl;
    
    cout << endl << "--- > Tour de Hanoï < ---" << endl;
    hanoi(5,'D','I','A');
    
    cout << endl << "--- > Maximum < ---" << endl;
    cout << "Maximum de vect : " << maxVect(vect) << endl;
    
    cout << endl << "--- > Puissance < ---" << endl;
    cout << "3⁴ = " << puissance(3,4) << endl;
    int n=0;
    cout << "2⁴ = " << puissanceNbMult(2,4,n) << " (";
    cout << n << " opérations)" << endl;
    return 0;
}

