#include "Promotion.h"

using namespace std;

float Promotion::m_TAUXMAX = 1.0;
float Promotion::m_TAUXMIN = 0.0;

Promotion::Promotion(const string& unLibelle, float unTaux) : m_libelle(unLibelle), m_tauxReduction(unTaux,m_TAUXMIN,m_TAUXMAX) {
    // ...
}

const string& Promotion::getLibelle() const {
    return m_libelle;
}

void Promotion::setLibelle(const string& libelle) {
    m_libelle=libelle;
}

float Promotion::calculePrixReduit(float prix) const {
    return prix * m_tauxReduction.getVal();
}

void Promotion::saisir(istream& in) {
    cout << "Libelle : ";
    in >> m_libelle;
    cout << "Taux : ";
    in >> m_tauxReduction;
}

void Promotion::afficher(ostream& out) const {
    out << "Libelle : " << m_libelle << " / Taux : " << m_tauxReduction;
}
