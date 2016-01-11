/* 
 * File:   Pack.cpp
 * Author: rogeri
 * 
 * Created on 25 septembre 2015, 08:50
 */

#include "Pack.h"

using namespace std;

Pack::Pack(const string& nom, const Client& c, Produit& p) : Produit::Produit(nom, c) {
    m_contenu.push_back(&p);
}

Pack::Pack(const Pack& orig) : Produit::Produit(orig) {
    m_contenu = orig.m_contenu;
}

Pack::~Pack() {
}

const void Pack::afficher(ostream& out, int level) const {
    string prefix = "";
    for (int i=0; i<level; i++) {
        prefix.append("\t");
    }
    out << prefix << "Pack : " << Produit::getNom() << endl;
    for (auto p : m_contenu) {
        p->afficher(out,level+1);
        out << endl;
    }
}

void Pack::ajouter(Produit& p) {
    m_contenu.push_back(&p);
}

float Pack::getPrix() const {
    
}