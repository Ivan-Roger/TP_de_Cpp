#include "Billet.h"

using namespace std;

Billet::Billet(const string& nom, const Client& unClient, const Trajet& untrajet, const Tarif& untarif) : Produit::Produit(nom, unClient), m_trajet(untrajet), m_tarif(untarif) {
    // ...
}

const Trajet& Billet::getTrajet() const {
    return m_trajet;
}

const Tarif& Billet::getTarif() const {
    return m_tarif;
}

float Billet::getPrix() const {
    return m_trajet.getDistance()*m_tarif.getPrixAuKm();
}

const void Billet::afficher(std::ostream& out, int level) const {
    string prefix = "";
    for (int i=0; i<level; i++) {
        prefix.append("\t");
    }
    out << prefix << "Billet : ";
    Produit::getClient().afficher(out);
    out << " | ";
    m_trajet .afficher(out);
    out << " - ";
    m_tarif.afficher(out);
    out << " [" << getPrix() << "E]";
}
