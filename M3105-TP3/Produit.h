/* 
 * File:   Produit.h
 * Author: rogeri
 *
 * Created on 25 septembre 2015, 08:52
 */

#ifndef PRODUIT_H
#define	PRODUIT_H

#include "Client.h"
#include <iostream>
#include <iomanip>

class Produit {
public:
    Produit(const std::string& nom, const Client& c);
    Produit(const Produit& orig);
    virtual ~Produit();
    const virtual void afficher(std::ostream& out, int level = 0) const = 0;
    virtual void ajouter(Produit& p);
    virtual float getPrix() const = 0;
    const Client& getClient() const;
    const std::string getNom() const;
private:
    const Client& m_client;
    const std::string m_nom;
};

#endif	/* PRODUIT_H */

