/* 
 * File:   Reservation.cpp
 * Author: rogeri
 * 
 * Created on 30 septembre 2015, 16:41
 */

#include "Reservation.h"

const int Reservation::m_NB_NUITS_MAX = 365;
const int Reservation::m_NB_NUITS_MIN = 1;
const float Reservation::m_PRIX_NUIT_MAX = 1000.0;
const float Reservation::m_PRIX_NUIT_MIN = 1.0;

Reservation::Reservation(const std::string& nom, Client& client, const std::string& hotel, int nbNuits, float prixNuit) : Produit(nom,client), m_hotel(hotel), m_nbNuits(nbNuits,m_NB_NUITS_MIN,m_NB_NUITS_MAX), m_prixNuit(prixNuit,m_PRIX_NUIT_MIN,m_PRIX_NUIT_MAX) {
}

const void Reservation::afficher(std::ostream& out, int level) const {
    string prefix = "";
    for (int i=0; i<level; i++) {
        prefix.append("\t");
    }
    out << prefix << "Reservation : " << m_hotel << " (" << m_nbNuits.getVal() << " nuits à " << m_prixNuit << "E), Prix : " << getPrix() << "E";
}

float Reservation::getPrix() const {
    return m_nbNuits.getVal() * m_prixNuit.getVal();
}

