/* 
 * File:   xmlwiktionary.cpp
 * Author: hb
 * 
 * Created on 22 mai 2014, 14:57
 */

#include "Dictionnaire.h"
#include <iostream>     // pour cout
#include <iomanip>      // pour setw()
#include <limits>       // pour numeric_limits<unsigned int>::max()

using namespace std;

/**
 * Constucteur de dictionnaire
 * 
 * @param filename  chemin d'accès au fichier XML qui contient le dictionnaire
 */
Dictionnaire::Dictionnaire(const char* filename) {
    // Chargement du fichier XML en mémoire
    imageDictionnaire.LoadFile(filename);
    // Initialisation de l'attribut dictionnary avec le premier fils (element <wiktionary>)
    leDictionnaire = imageDictionnaire.FirstChildElement();
}

/*
 * out : nombre d'entrées dans le dictionnaire
 */
int Dictionnaire::getNbEntries() const {
    // initialisation du nombre d'entrées
    int nb = 0;
    
    /*
     *  A COMPLETER
     */
    XMLElement* currentEntry = leDictionnaire->FirstChildElement();
    while (currentEntry!=nullptr) {
        nb++;
        currentEntry = currentEntry->NextSiblingElement();
    }
    
    return nb;
}

/*
 * in : entry une entrée du dictionnaire
 * out : nombres de lexmèmes (ou unité lexicale) -> unité de sens et de son
 */
int Dictionnaire::getNbLexemesEntry(XMLElement* entry) const {
    int nbLexems = 0; //on doit avoir de toute manière au moins un lexème par entrée
        
    /*
     *  A COMPLETER
     */

    return nbLexems;
}

/*
 * in : entry une entrée du dictionnaire
 * out : pointeur sur l'étymologie de entry si elle existe (NULL sinon)
 * l'étymologie est unique, il suffit donc d'accèder au fils de entry de type etym
 */
XMLElement* Dictionnaire::getEtymEntry(XMLElement* entry) {
        
    /*
     *  A COMPLETER
     */

    return nullptr;
}



/*
 * in : defs un élement contenant les définitions d'un lexeme, peut être NULL !
 *      s'il n'est pas nul <tolevel-def>+ (dans la partique +)
 * out : nombres de définitions
 */
int Dictionnaire::getNbTopLevelDefS(XMLElement* defs) const {
    int nbDefs = 0; //on n'a pas forcément de définition
        
    /*
     *  A COMPLETER
     */

    return nbDefs;
}


int Dictionnaire::getNbEntriesRecWorker(const XMLElement* entreeCourante) const {
        
    /*
     *  A COMPLETER
     */
    if (entreeCourante==nullptr) {
        return 0;
    } else {
        return getNbEntriesRecWorker(entreeCourante->NextSiblingElement())+1;
    }
}


int Dictionnaire::getNbEntriesRec() const {
    return getNbEntriesRecWorker(leDictionnaire->FirstChildElement());
}


//void Dictionnaire::Print() const {
//    dictionaryfile.Print();
//}


void Dictionnaire::afficheEntriesForm() {
        
    /*
     *  A COMPLETER
     */
    unsigned int rang=1;
    XMLElement* currentEntry = leDictionnaire->FirstChildElement();
    while (currentEntry!=nullptr) {
        cout << setw(5) << rang << ": " << currentEntry->Attribute("form") << endl;
        currentEntry = currentEntry->NextSiblingElement();
        rang++;
    }
}


/*
 * affichage des entrées du dictionnaire dans un intervalle
 */
void Dictionnaire::afficheRangedEntriesForm(unsigned int inf, unsigned int sup) {
    
    /*
     *  A COMPLETER
     */

    unsigned int rang=1;
    XMLElement* currentEntry = leDictionnaire->FirstChildElement();
    while (currentEntry!=nullptr && rang<inf) {
        currentEntry = currentEntry->NextSiblingElement();
        rang++;
    }
    while (currentEntry!=nullptr && rang<=sup) {
        cout << setw(7) << rang << ": " << currentEntry->Attribute("form") << endl;
        currentEntry = currentEntry->NextSiblingElement();
        rang++;
    }
}

/*
 * pointeur sur l'élément <entry> correspondant à la forme form
 */
XMLElement* Dictionnaire::getEntryForForm(string entryForm) {
        
    /*
     *  A COMPLETER
     */

    unsigned int rang=1;
    XMLElement* currentEntry = leDictionnaire->FirstChildElement();
    while (currentEntry!=nullptr) {
        if (currentEntry->Attribute("form",entryForm.c_str())) {
            return currentEntry;
        }
        currentEntry = currentEntry->NextSiblingElement();
        rang++;
    }
    return nullptr;
}

void const Dictionnaire::debugPrint(tinyxml2::XMLElement* entry) const {
    cout << setw(50) << "-" << endl;
    XMLPrinter prt;
    entry->Accept(&prt);
    cout << prt.CStr();
    cout << setw(50) << "-" << endl;
}

Dictionnaire::~Dictionnaire() {
}

