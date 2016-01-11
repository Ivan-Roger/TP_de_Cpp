/* 
 * File:   Reservation.h
 * Author: rogeri
 *
 * Created on 30 septembre 2015, 16:41
 */

#ifndef RESERVATION_H
#define	RESERVATION_H

#include <string>
#include "Produit.h"
#include "NombreContraint.h"

class Reservation : public Produit {
public:
    Reservation(const std::string& nom, Client& client, const std::string& hotel,  int nbNuits, float prixNuit);
    const virtual void afficher(std::ostream& out, int level = 0) const;
    virtual float getPrix() const;
private:
    const std::string m_hotel;
    NombreContraint<int> m_nbNuits;
    static const int m_NB_NUITS_MAX;
    static const int m_NB_NUITS_MIN;
    NombreContraint<float> m_prixNuit;
    static const float m_PRIX_NUIT_MAX;
    static const float m_PRIX_NUIT_MIN;
};

#endif	/* RESERVATION_H */

