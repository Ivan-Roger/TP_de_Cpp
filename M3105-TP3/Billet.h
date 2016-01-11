#ifndef BILLET_H
#define BILLET_H

#include <iostream>
#include <iomanip>
#include "Trajet.h"
#include "Tarif.h"
#include "Client.h"
#include "Produit.h"

class Billet : public Produit {

private:
    const Trajet& m_trajet;
    const Tarif& m_tarif;

public:
    Billet(const std::string& nom, const Client& unClient, const Trajet& untrajet, const Tarif& untarif);
    const Trajet& getTrajet() const;
    const Tarif& getTarif() const;
    virtual float getPrix() const;
    const virtual void afficher(std::ostream& out, int level = 0) const;
};

#endif