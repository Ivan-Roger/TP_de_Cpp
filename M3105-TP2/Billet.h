#ifndef BILLET_H
#define BILLET_H

#include <iostream>
#include <iomanip>
#include "Trajet.h"
#include "Tarif.h"
#include "Client.h"

class Billet {

private:
    const Trajet& m_trajet;
    const Tarif& m_tarif;
    const Client& m_client;

public:
    Billet(const Client& unClient, const Trajet& untrajet, const Tarif& untarif);

    const Trajet& getTrajet() const;

    const Tarif& getTarif() const;
    
    const Client& getClient() const;

    virtual float getPrix() const;

    const void afficher(std::ostream& out) const;
};

#endif