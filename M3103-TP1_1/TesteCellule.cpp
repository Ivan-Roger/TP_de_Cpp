/* 
 * File:   TestCellules.cpp
 * Author: hb
 *
 * Created on 16 août 2014, 17:53
 */

#include <cstdlib>
#include <iostream>

#include "Cellule.h"

using namespace std;

/**
 * Une procédure modèle qui affiche des Cellules contenant n'importe quel type d'information
 * ATTENTION il faut que les éléments puissent s'afficher savec la méthode
 *            -> affiche() de la classe Cellule
 * 
 * @param unePile
 */
template<typename TypeInfo>
void afficheCellules(Cellule<TypeInfo>* ptrCell) {
    //variable pour le parcours le la liste de cellules initialisée avec la valeur du paramètre effectif
    Cellule<TypeInfo>* ptrCellCour;
    // Initialisaton
    ptrCellCour = ptrCell;
    cout << "la liste de cellules contient -> ";
    // Tant qu'il y a une cellule
    while (ptrCellCour) {
        // Afficher le contenu de la Cellule courante
        ptrCellCour->affiche();
        cout << ' ';
        // Avancer sur la Cellule suivante
        ptrCellCour = ptrCellCour->getSuivante();
    }
    cout << endl;
} // end afficheCellulesFromCell

int main() {
    /*
     * UNE TRACE DU RESULTAT A OBTENIR EST PROPOSEE EN FIN DE FICHIER
     */

    // PREMIERE PARTIE
    cout << "MANIPULATION DE POINTEUR SUR DES CELLULES CONTENANT DES ENTIERS" << endl;
    // Déclarer et construire une variable ptrCelInt1 de type pointeur sur une Cellule entière (Cellule<int>*) contenant la valeur 2
    /*
     * A COMPLETER, une instruction
     */
    Cellule<int>* ptrCelInt1 = new Cellule<int>(2);

    cout << "L'information portée par la cellule CelInt1 est : ";
    // Afficher l'information portée par la cellule
    /*
     * A COMPLETER, une instruction
     */
    cout << ptrCelInt1->getInfo();

    cout << endl;

    // Déclarer et construire une variable ptrCelInt2 de type pointeur sur une Cellule entière (Cellule<int>*) contenant la valeur 3
    /*
     * A COMPLETER, une instruction
     */
    Cellule<int>* ptrCelInt2 = new Cellule<int>(3);

    // Faire en sorte que CelInt2 soit la cellule qui suit la cellule CelInt1
    /*
     * A COMPLETER, une instruction
     */
    ptrCelInt1->setSuivante(ptrCelInt2);

    // Afficher la liste dont la tête de liste est CelInt1 avec la procédure afficheCellules()
    cout << "A partir de CelInt1, ";
    /*
     * A COMPLETER, une instruction
     */
    afficheCellules(ptrCelInt1);

    // Déclarer et construire une variable ptrCelInt3 de type pointeur sur une Cellule entière (Cellule<int>*) contenant la valeur 1
    // et qui est suivie de CelInt1
    /*
     * A COMPLETER, une instruction
     */
    Cellule<int>* ptrCelInt3 = new Cellule<int>(1,ptrCelInt1);

    // Afficher la liste dont la tête de liste est CelInt3 avec la procédure afficheCellules()
    cout << "A partir de CelInt3, ";
    /*
     * A COMPLETER, une instruction
     */
    afficheCellules(ptrCelInt3);


    // DEUXIEME PARTIE
    cout << endl << endl << "MANIPULATION DE CELLULES CONTENANT DES ENTIERS" << endl;
    // Déclarer et construire une variable CelInt1 de type Cellule entière (Cellule<int>) contenant la valeur 2
    /*
     * A COMPLETER, une instruction
     */
    Cellule<int> celInt1(2);

    cout << "L'information portée par la cellule CelInt1 est : ";
    // Afficher l'information portée par la cellule
    /*
     * A COMPLETER, une instruction
     */
    cout << celInt1.getInfo();

    cout << endl;

    // Déclarer et construire une variable ptrCelInt2 de type Cellule entière (Cellule<int>) contenant la valeur 3
    /*
     * A COMPLETER, une instruction
     */
    Cellule<int> celInt2(3);

    // Faire en sorte que CelInt2 soit la cellule qui suit la cellule CelInt1
    /*
     * A COMPLETER, une instruction
     */
    celInt1.setSuivante(&celInt2);

    // Afficher la liste dont la tête de liste est CelInt1 avec la procédure afficheCellules()
    cout << "A partir de CelInt1, ";
    /*
     * A COMPLETER, une instruction
     */
    afficheCellules(&celInt1);

    // Déclarer et construire une variable celInt3 de type Cellule entière (Cellule<int>) contenant la valeur 1
    // et qui est suivie de CelInt1
    /*
     * A COMPLETER, une instruction
     */
    Cellule<int> celInt3(1,&celInt1);

    // Afficher la liste dont la tête de liste est CelInt3 avec la procédure afficheCellules()
    cout << "A partir de CelInt3, ";
    /*
     * A COMPLETER, une instruction
     */
    afficheCellules(&celInt3);
    


    // TROISIEME PARTIE
    cout << endl << endl << "MANIPULATION DE POINTEUR SUR DES CELLULES CONTENANT DES CHAINES" << endl;
    // Déclarer et construire une variable ptrCelString1 de type pointeur sur une Cellule entière (Cellule<string>*) contenant la valeur "deux"
    /*
     * A COMPLETER, une instruction
     */
    Cellule<string>* ptrCelString1 = new Cellule<string>("deux");

    cout << "L'information portée par la cellule CelString1 est : ";
    // Afficher l'information portée par la cellule
    /*
     * A COMPLETER, une instruction
     */
    cout << ptrCelString1->getInfo();

    cout << endl;

    // Déclarer et construire une variable ptrCelString2 de type pointeur sur une Cellule entière (Cellule<string>*) contenant la valeur "trois"
    /*
     * A COMPLETER, une instruction
     */
    Cellule<string>* ptrCelString2 = new Cellule<string>("trois");

    // Faire en sorte que ptrCelString2 soit la cellule qui suit la cellule ptrCelString1
    /*
     * A COMPLETER, une instruction
     */
    ptrCelString1->setSuivante(ptrCelString2);

    // Afficher la liste dont la tête de liste est ptrCelString1 avec la procédure afficheCellules()
    cout << "A partir de CelString1, ";
    /*
     * A COMPLETER, une instruction
     */
    afficheCellules(ptrCelString1);

    // Déclarer et construire une variable ptrCelString3 de type pointeur sur une Cellule entière (Cellule<string>*) contenant la valeur "un"
    // et qui est suivie de ptrCelString1
    /*
     * A COMPLETER, une instruction
     */
    Cellule<string>* ptrCelString3 = new Cellule<string>("un",ptrCelString1);

    // Afficher la liste dont la tête de liste est CelString3 avec la procédure afficheCellules()
    cout << "A partir de CelString3, ";
    /*
     * A COMPLETER, une instruction
     */
    afficheCellules(ptrCelString3);


    // QUATRIEME PARTIE
    cout << endl << endl << "MANIPULATION DE CELLULES CONTENANT DES CHAINES" << endl;
    // Déclarer et construire une variable CelString1 de type Cellule entière (Cellule<string>) contenant la valeur "deux"
    /*
     * A COMPLETER, une instruction
     */
    Cellule<string> celString1("deux");

    cout << "L'information portée par la cellule CelString1 est : ";
    // Afficher l'information portée par la cellule
    /*
     * A COMPLETER, une instruction
     */
    cout << celString1.getInfo();

    cout << endl;

    // Déclarer et construire une variable celString2 de type Cellule entière (Cellule<string>) contenant la valeur "trois"
    /*
     * A COMPLETER, une instruction
     */
    Cellule<string> celString2("trois");


    // Faire en sorte que CelString2 soit la cellule qui suit la cellule CelString1
    /*
     * A COMPLETER, une instruction
     */
    celString1.setSuivante(&celString2);

    // Afficher la liste dont la tête de liste est CelString1 avec la procédure afficheCellules()
    cout << "A partir de CelString1, ";
    /*
     * A COMPLETER, une instruction
     */
    afficheCellules(&celString1);

    // Déclarer et construire une variable CelString3 de type Cellule entière (Cellule<string>) contenant la valeur "un"
    // et qui est suivie de CelString1
    /*
     * A COMPLETER, une instruction
     */
    Cellule<string> celString3("un",&celString1);

    // Afficher la liste dont la tête de liste est CelString3 avec la procédure afficheCellules()
    cout << "A partir de CelString3, ";
    /*
     * A COMPLETER, une instruction
     */
    afficheCellules(&celString3);

    return 0;
}

// TRACE A OBTENIR
/*
 MANIPULATION DE POINTEUR SUR DES CELLULES CONTENANT DES ENTIERS
L'information portée par la cellule CelInt1 est : 2
A partir de CelInt1, la liste de cellules contient -> 2 3
A partir de CelInt3, la liste de cellules contient -> 1 2 3 

MANIPULATION DE CELLULES CONTENANT DES ENTIERS
L'information portée par la cellule CelInt1 est : 2
A partir de CelInt1, la liste de cellules contient -> 2 3
A partir de CelInt3, la liste de cellules contient -> 1 2 3 

MANIPULATION DE POINTEUR SUR DES CELLULES CONTENANT DES CHAINES
L'information portée par la cellule CelString1 est : deux
A partir de CelString1, la liste de cellules contient -> deux trois 
A partir de CelString3, la liste de cellules contient -> un deux trois 

MANIPULATION DE CELLULES CONTENANT DES CHAINES
L'information portée par la cellule CelString1 est : deux
A partir de CelString1, la liste de cellules contient -> deux trois 
A partir de CelString3, la liste de cellules contient -> un deux trois 
 */

