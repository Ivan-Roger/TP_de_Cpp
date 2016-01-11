#include "Tarif.h"

using namespace std;

float Tarif::m_PRIXMAX = 10.0;
float Tarif::m_PRIXMIN = 0.0;

Tarif::Tarif(const string& unLibelle, float unPrixKilo) : m_libelle(unLibelle), m_prixAuKm(unPrixKilo,m_PRIXMIN,m_PRIXMAX) {
    // ...
}

const string& Tarif::getLibelle() const {
    return m_libelle;
}

void Tarif::setLibelle(string libelle) {
    this->m_libelle = libelle;
}

float Tarif::getPrixAuKm() const {
    return m_prixAuKm.getVal();
}

void Tarif::saisir(istream& in) {
    cout << "Libelle : ";
    in >> m_libelle;
    cout << "Prix au km : ";
    in >> m_prixAuKm;
}

void Tarif::afficher(ostream& out) const {
    out << m_libelle << " : " << m_prixAuKm << " €/Km";
}
