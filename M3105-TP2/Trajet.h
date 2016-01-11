#ifndef TRAJET_H
#define TRAJET_H

#include <iostream>
#include <iomanip>
#include "NombreContraint.h"

class Trajet {
    

private:
    std::string m_villeDepart;
    std::string m_villeArrivee;
    NombreContraint<int> m_distance;
    static const int m_DISTANCEMIN = 0;
    static const int m_DISTANCEMAX = 1500;

public:
    Trajet(const std::string& villeDep, const std::string& villeArr, int dist);

    const std::string& getVilleDepart() const;

    void setVilleDepart(const std::string& villeDep);

    const std::string& getVilleArrivee() const;

    void setVilleArrivee(const std::string& villeArr);

    const int getDistance() const;

    void saisir(std::istream& in);

    void afficher(std::ostream& out) const;
};

#endif