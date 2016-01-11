#include "Trajet.h"

using namespace std;

Trajet::Trajet(const string& villeDep, const string& villeArr, int dist) : m_villeDepart(villeDep), m_villeArrivee(villeArr), m_distance(dist,m_DISTANCEMIN,m_DISTANCEMAX) {
    // ...
}

const string& Trajet::getVilleDepart() const {
    return m_villeDepart;
}

void Trajet::setVilleDepart(const string& villeDep) {
    m_villeDepart=villeDep;
}

const string& Trajet::getVilleArrivee() const {
    return m_villeArrivee;
}

void Trajet::setVilleArrivee(const string& villeArr) {
    m_villeArrivee = villeArr;
}

const int Trajet::getDistance() const {
    return m_distance.getVal();
}

void Trajet::saisir(istream& in) {
    cout << "Ville Depart : ";
    in >> m_villeDepart;
    cout << "Ville Arrivee : ";
    in >> m_villeArrivee;
    cout << "Distance : ";
    in >> m_distance;
}

void Trajet::afficher(ostream& out) const {
    out << m_villeDepart << " - " << m_villeArrivee << " : " <<  m_distance << " Km";
}
