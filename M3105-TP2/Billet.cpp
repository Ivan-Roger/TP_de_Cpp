#include "Billet.h"

using namespace std;

Billet::Billet(const Client& unClient, const Trajet& untrajet, const Tarif& untarif) : m_client(unClient), m_trajet(untrajet), m_tarif(untarif) {
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

const Client& Billet::getClient() const{
    return m_client;
}

const void Billet::afficher(ostream& out) const {
    m_trajet .afficher(out);
    out << " - " << m_tarif.getLibelle() << " : " << getPrix() << "€";
}
