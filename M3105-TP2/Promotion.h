#ifndef PROMOTION_H
#define PROMOTION_H

#include <iostream>
#include <iomanip>
#include "NombreContraint.h"

class Promotion {

private:
    std::string m_libelle;
    NombreContraint<float> m_tauxReduction;
    static float m_TAUXMIN;
    static float m_TAUXMAX;

public :
    Promotion(const std::string& unLibelle, float unTaux);

    const std::string& getLibelle() const;

    void setLibelle(const std::string& libelle);

    float calculePrixReduit(float prix) const;

    void saisir(std::istream& in);

    void afficher(std::ostream& out) const;
};

#endif