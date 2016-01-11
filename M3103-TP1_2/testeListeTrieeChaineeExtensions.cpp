/*
 * POUR TESTER LES EXTENTIONS
 */

#include <iostream>
#include <string>
#include "ListeTrieeChainee.h"


using namespace std;

/*
 * faire vos tests vous-même
 */
void testCompteNbOccIter(ListeTrieeChainee<string>* ptrMaListe) {
    
}

int main(int argc, char** argv) {
    ListeTrieeChainee<string>* ptrMaListe = new ListeTrieeChainee<string>();
    ptrMaListe->insere("1");
    ptrMaListe->insere("2");
    ptrMaListe->insere("3");
    ptrMaListe->insere("4");
    ptrMaListe->insere("5");
    testCompteNbOccIter(ptrMaListe);
    return 0;
}