/* 
 * File:   Client.cpp
 * Author: rogeri
 * 
 * Created on 18 septembre 2015, 09:23
 */

#include "Client.h"

using namespace std;

Client::Client(string nom) : m_nom(nom) {
    // ...
}

Client::Client(const Client& orig) : m_nom(orig.m_nom) {
    // ...
}

Client::~Client() {
    // ...
}

const string& Client::getNom() const {
    return m_nom;
}

void Client::saisir(istream& in) {
    in >> m_nom;
}

void Client::afficher(ostream& out) const {
    out << m_nom;
}