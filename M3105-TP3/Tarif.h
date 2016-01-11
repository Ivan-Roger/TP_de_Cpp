#ifndef TARIF_H
#define TARIF_H

#include <iostream>
#include <iomanip>
#include "NombreContraint.h"

class Tarif {

private:
    std::string m_libelle;
    NombreContraint<float> m_prixAuKm;
    static float m_PRIXMIN;
    static float m_PRIXMAX;

public:
    Tarif(const std::string& unLibelle, float unPrixKilo);

    const std::string& getLibelle() const;

    void setLibelle(std::string libelle);

    float getPrixAuKm() const;

    void saisir(std::istream& in);

    void afficher(std::ostream& out) const;
};

#endif