/* 
 * File:   Salarie.cpp
 * Author: rogeri
 * 
 * Created on 2 octobre 2015, 09:48
 */

#include "Salarie.h"
using namespace std;

Salarie::Salarie(string& nom, std::string& numSS, float salaire) : m_nom(nom), m_numSS(numSS), m_salaireMensuel(salaire) {
}

Salarie::Salarie(const Salarie& orig) {
}

Salarie::~Salarie() {
}
/*

    const std::string& getNom() const;
    void setNom(std::string& nom);
    const std::string& getNumSS() const;
    void setNumSS(std::string& numSS);
    const float& getSalaire() const;
    void setSalaire(float& salaire); 
*/

