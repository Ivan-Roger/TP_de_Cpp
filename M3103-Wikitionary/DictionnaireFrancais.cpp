/* 
 * File:   FrDico.cpp
 * Author: hb
 * 
 * Created on 22 mai 2014, 15:13
 */

#include "DictionnaireFrancais.h"

/*
 * in : chemin d'accès au fichier qui contient le dictionnaire
 * appel du constructeur de Dictionnaire
 */
DictionnaireFrancais::DictionnaireFrancais(const char* filename) : Dictionnaire(filename) {
}

DictionnaireFrancais::~DictionnaireFrancais() {
}

void DictionnaireFrancais::afficheSubLevelDefS(XMLElement* subDef) {
        
    /*
     *  A COMPLETER
     */
    XMLElement* def = subDef->FirstChildElement("sublevel-def");
    int subNb=1;
    while (def!=nullptr) { // <sublevel-def>
        cout << endl << setw(8) << " " << subNb << ") Sens:" << endl;
        cout << setw(10) << " " << "Definition: " <<def->FirstChildElement("gloss")->GetText() << endl;

        //-----------

        cout << setw(10) << " " << "Exemple: " <<def->FirstChildElement("example")->GetText() << endl;

        def = def->NextSiblingElement("sublevel-def");
        subNb++;
        cout << endl;
    } // </sublevel-def>
}

void DictionnaireFrancais::afficheTopLevelDef(XMLElement* def) {
        
    /*
     *  A COMPLETER
     */

}

/*
 * in : entryForm -> entrée du dictionnaire
 *      entryPos -> partie du discours considérée
 *      defsElement -> un element <defs> qui contient des <toplevel-def>
 */
void DictionnaireFrancais::afficheTopLevelDefS(const string entryForm, const string entryPos, XMLElement* defsElement) {
        
    /*
     *  A COMPLETER
     */
    XMLElement* defFamily = defsElement->FirstChildElement("toplevel-def");
    int topNb=1;
    while (defFamily!=nullptr) { // <toplevel-def>
        cout << setw(6) << topNb << ") Famille de sens:" << endl;
        cout << setw(8) << " " << "Definition: " << defFamily->FirstChildElement("gloss")->GetText() << endl;

        // <sublevel-def>
        afficheSubLevelDefS(defFamily);

        cout << setw(8) << " " << "Exemple: " <<defFamily->FirstChildElement("example")->GetText() << endl;                

        defFamily = defFamily->NextSiblingElement("toplevel-def");
        topNb++;
        cout << endl;
    } // </toplevel-def>

}

/*
 * in : entry une entrée du dictionnaire <etym>? <lexeme>* (dans la pratique +)
 * affiche les définitions de chaque lexème correspondant à l'entrée
 */
void DictionnaireFrancais::afficheEntryLexemesDefS(XMLElement* entry) {
        
    /*
     *  A COMPLETER
     */
    XMLElement* child = entry->FirstChildElement("etym");
    if (child!=nullptr)
        cout << setw(2) << " " << "Etymologie: " << child->GetText() << endl;
    
    XMLElement* lexeme = entry->FirstChildElement("lexeme");
    int lexID=1;
    while (lexeme!=nullptr) { // <lexeme>
        cout << endl << setw(2) << " " << lexID  << ") Lexeme: " << lexeme->Attribute("pos") << endl;
        
        XMLElement* defs = lexeme->FirstChildElement("defs");
        int nb=1;
        while (defs!=nullptr) { // <defs>
            cout << setw(4) << " " << lexID << "." << nb << ") Ensemble de familles de sens:" << endl;
            
            // <toplevel-def>
            afficheTopLevelDefS("","",defs);
            
            defs = defs->NextSiblingElement("defs");
            nb++;
        } // </defs>

        XMLElement* trans = lexeme->FirstChildElement("trans");
        if (trans!=nullptr) { // <trans>
            cout << setw(6) << " " << "Traductions: " << endl;
            XMLElement* item = trans->FirstChildElement();
            while (item!=nullptr) {
                cout << setw(8) << " " << "-> " << item->GetText() << endl;
                item = item->NextSiblingElement();
            }
            cout << endl;
        } // </trans>

        XMLElement* syn = lexeme->FirstChildElement("syn");
        if (syn!=nullptr) { // <syn>
            cout << setw(6) << " " << "Synonymes: " << endl;
            XMLElement* item = syn->FirstChildElement();
            while (item!=nullptr) {
                cout << setw(8) << " " << "-> " << item->GetText() << endl;
                item = item->NextSiblingElement();
            }
            cout << endl;
        } // </syn>
        
        lexeme = lexeme->NextSiblingElement("lexeme");
        lexID++;
    } // </lexeme>
}

/**
 * Un pretty print pour une entrée
 * @param entry
 */
void DictionnaireFrancais::afficheEntry(XMLElement* entry) {
        
    /*
     *  A COMPLETER
     */
    
    if (entry==nullptr) {
        cout << "Entrée Invalide !" << endl;
        return;
    }

    //Dictionnaire::debugPrint(entry);
    
    cout << "----- MOT: " << entry->Attribute("form") << " -----" << endl;    
    // <lexeme>
    afficheEntryLexemesDefS(entry);
}

/**
 * Un pretty print pour une entrée
 * @param entry
 */
void DictionnaireFrancais::afficheEntryForForm(const string aForm) {

        
    /*
     *  A COMPLETER
     */
    afficheEntry(getEntryForForm(aForm));

}

/*
 * une entrée est ambiguë si pour une même partie du discours, l'entrée possède plusieurs lexèmes
 */
bool DictionnaireFrancais::isEntryAmbiguous(XMLElement* entry) {
        
    /*
     *  A COMPLETER
     */
    
    return true;

}

