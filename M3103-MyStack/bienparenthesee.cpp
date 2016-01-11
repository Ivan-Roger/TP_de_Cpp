/* 
 * File:   newmain.cpp
 * Author: hb
 *
 * Created on 16 octobre 2014, 16:23
 */

#include <stack>          // pour les piles
#include <string>         // pour les chaînes
#include <iostream>
#include <cstdlib>
#include "PrecondVioleeExcep.h"

using namespace std;

bool estBienParentheseeSimple(string maChaine) {
    /*
     * A COMPLETER
     */
    stack<char> maPile;
    
    for (char c : maChaine) {
        if (c=='(') {
            maPile.push(c);
        } else if (c==')') {
            maPile.pop();
        }
    }
    
    return maPile.empty();
}

void testeEstBienParentheseeSimple() {
    cout << "DEBUT testeEstBienParentheseeSimple()" << endl << endl;
    string chaineVide;
    cout << "Une chaîne vide est-elle bien parenthésée : " << estBienParentheseeSimple(chaineVide) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine1 = "(";
    cout << "La chaîne \"(\" est-elle bien parenthésée : " << estBienParentheseeSimple(chaine1) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine2 = ")";
    cout << "La chaîne \")\" est-elle bien parenthésée : " << estBienParentheseeSimple(chaine2) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine3 = "()";
    cout << "La chaîne \"()\" est-elle bien parenthésée : " << estBienParentheseeSimple(chaine3) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine4 = "(((()(()))))";
    cout << "La chaîne \"((((()(()))))\" est-elle bien parenthésée : " << estBienParentheseeSimple(chaine4) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine5 = "(((()(())))";
    cout << "La chaîne \"(((()(())))\" est-elle bien parenthésée : " << estBienParentheseeSimple(chaine5) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine6 = "(((()(())))))";
    cout << "La chaîne \"(((()(())))\" est-elle bien parenthésée : " << estBienParentheseeSimple(chaine6) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    cout << "DEBUT testeEstBienParentheseeSimple()" << endl << endl;
}

bool estBienParenthesee(string maChaine) {
    /*
     * A COMPLETER
     */
    stack<char> parentheses;
    stack<char> crochets;
    stack<char> accolades;
    
    for (char c : maChaine) {
        if (c=='(') {
            parentheses.push(c);
        } else if (c==')') {
            parentheses.pop();
        } else if (c=='[') {
            crochets.push(c);
        } else if (c==']') {
            crochets.pop();
        } else if (c=='{') {
            accolades.push(c);
        } else if (c=='}') {
            accolades.pop();
        }
    }
    
    return parentheses.empty() && crochets.empty() && accolades.empty();
}

void testeEstBienParenthesee() {
    cout << "DEBUT testeEstBienParenthesee()" << endl << endl;

    cout << "--> début tests de non régression" << endl << endl;
    string chaineVide;
    cout << "Une chaîne vide est-elle bien parenthésée : " << estBienParenthesee(chaineVide) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine1 = "(";
    cout << "La chaîne \"(\" est-elle bien parenthésée : " << estBienParenthesee(chaine1) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine2 = ")";
    cout << "La chaîne \")\" est-elle bien parenthésée : " << estBienParenthesee(chaine2) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine3 = "()";
    cout << "La chaîne \"()\" est-elle bien parenthésée : " << estBienParenthesee(chaine3) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine4 = "(((()(()))))";
    cout << "La chaîne \"((((()(()))))\" est-elle bien parenthésée : " << estBienParenthesee(chaine4) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine5 = "(((()(())))";
    cout << "La chaîne \"(((()(())))\" est-elle bien parenthésée : " << estBienParenthesee(chaine5) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine6 = "(((()(())))))";
    cout << "La chaîne \"(((()(())))\" est-elle bien parenthésée : " << estBienParenthesee(chaine6) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    cout << "--> fin tests de non régression" << endl << endl;

    cout << "--> début tests généraux" << endl << endl;
    string chaine7 = "({[";
    cout << "La chaîne \"({[\" est-elle bien parenthésée : " << estBienParenthesee(chaine7) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine8 = "({})";
    cout << "La chaîne \"({})\" est-elle bien parenthésée : " << estBienParenthesee(chaine8) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine9 = "({}])";
    cout << "La chaîne \"({}])\" est-elle bien parenthésée : " << estBienParenthesee(chaine9) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine10 = "({}[()(())][{(())}[{}(())]])";
    cout << "La chaîne \"({}[()(())][{(())}[{}(())]])\" est-elle bien parenthésée : " << estBienParenthesee(chaine10) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine11 = "({}[()(())][{(())}[{}((())]])))";
    cout << "La chaîne \"({}[()(())][{(())}[{}((())]])))\" est-elle bien parenthésée : " << estBienParenthesee(chaine11) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine12 = "({}[()(())][{(())}[{}(()()]])";
    cout << "La chaîne \"({}[()(())][{(())}[{}(()()]])\" est-elle bien parenthésée : " << estBienParenthesee(chaine12) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    cout << "--> fin tests généraux" << endl << endl;

    cout << "DEBUT testeEstBienParenthesee()" << endl << endl;
}

bool estBienParentheseeAlt(string maChaine) {
    /*
     * A COMPLETER
     */
    const int SIZE = 3;
    char open[SIZE] = {'(','[','{'};
    char close[SIZE] = {')',']','}'};
    int counters[SIZE] = {0,0,0};
    
    for (char c : maChaine) {
        for (int i=0; i<sizeof(open); i++) {
            if (c==open[i]) {
                counters[i]++;
            }
        }
        for (int i=0; i<sizeof(close); i++) {
            if (c==close[i]) {
                counters[i]--;
            }
        }
    }
    int sum=0;
    for (int c : counters)
        sum+=c;
    return sum==0;
}

void testeEstBienParentheseeAlt() {
    cout << "DEBUT testeEstBienParentheseeAlt()" << endl << endl;

    cout << "--> début tests de non régression" << endl << endl;
    string chaineVide;
    cout << "Une chaîne vide est-elle bien parenthésée : " << estBienParentheseeAlt(chaineVide) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine1 = "(";
    cout << "La chaîne \"(\" est-elle bien parenthésée : " << estBienParentheseeAlt(chaine1) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine2 = ")";
    cout << "La chaîne \")\" est-elle bien parenthésée : " << estBienParentheseeAlt(chaine2) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine3 = "()";
    cout << "La chaîne \"()\" est-elle bien parenthésée : " << estBienParentheseeAlt(chaine3) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine4 = "(((()(()))))";
    cout << "La chaîne \"((((()(()))))\" est-elle bien parenthésée : " << estBienParentheseeAlt(chaine4) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine5 = "(((()(())))";
    cout << "La chaîne \"(((()(())))\" est-elle bien parenthésée : " << estBienParentheseeAlt(chaine5) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine6 = "(((()(())))))";
    cout << "La chaîne \"(((()(())))\" est-elle bien parenthésée : " << estBienParentheseeAlt(chaine6) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    cout << "--> fin tests de non régression" << endl << endl;

    cout << "--> début tests généraux" << endl << endl;
    string chaine7 = "({[";
    cout << "La chaîne \"({[\" est-elle bien parenthésée : " << estBienParentheseeAlt(chaine7) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine8 = "({})";
    cout << "La chaîne \"({})\" est-elle bien parenthésée : " << estBienParentheseeAlt(chaine8) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine9 = "({}])";
    cout << "La chaîne \"({}])\" est-elle bien parenthésée : " << estBienParentheseeAlt(chaine9) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine10 = "({}[()(())][{(())}[{}(())]])";
    cout << "La chaîne \"({}[()(())][{(())}[{}(())]])\" est-elle bien parenthésée : " << estBienParentheseeAlt(chaine10) << " ; devrait rendre 1 (true)" << endl;
    cout << endl;
    string chaine11 = "({}[()(())][{(())}[{}((())]])))";
    cout << "La chaîne \"({}[()(())][{(())}[{}((())]])))\" est-elle bien parenthésée : " << estBienParentheseeAlt(chaine11) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    string chaine12 = "({}[()(())][{(())}[{}(()()]])";
    cout << "La chaîne \"({}[()(())][{(())}[{}(()()]])\" est-elle bien parenthésée : " << estBienParentheseeAlt(chaine12) << " ; devrait rendre 0 (false)" << endl;
    cout << endl;
    cout << "--> fin tests généraux" << endl << endl;

    cout << "DEBUT testeEstBienParentheseeAlt()" << endl << endl;
}

/*
 * 
 */
int main() {
    testeEstBienParentheseeSimple();
    testeEstBienParenthesee();
    testeEstBienParentheseeAlt();
    return 0;
}

// TRACE ATTENDUE
/*
DEBUT testeEstBienParentheseeSimple()

Une chaîne vide est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "(" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne ")" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne "()" est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "((((()(()))))" est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "(((()(())))" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne "(((()(())))" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

DEBUT testeEstBienParentheseeSimple()

DEBUT testeEstBienParenthesee()

--> début tests de non régression

Une chaîne vide est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "(" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne ")" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne "()" est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "((((()(()))))" est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "(((()(())))" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne "(((()(())))" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

--> fin tests de non régression

--> début tests généraux

La chaîne "({[" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne "({})" est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "({}])" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne "({}[()(())][{(())}[{}(())]])" est-elle bien parenthésée : 1 ; devrait rendre 1 (true)

La chaîne "({}[()(())][{(())}[{}((())]])" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

La chaîne "({}[()(())][{(())}[{}(()()]])" est-elle bien parenthésée : 0 ; devrait rendre 0 (false)

--> fin tests généraux

DEBUT testeEstBienParenthesee() 
 */
