/* 
 * File:   Conteneur.h
 * Author: rogeri
 *
 * Created on 23 septembre 2015, 16:36
 */

#ifndef CONTENEUR_H
#define	CONTENEUR_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "NombreContraint.h"

template<class T>
class Conteneur {
public:
    static Conteneur* getInstance();
    void ajouter(const T& element);
    void afficher() const;
    const T & choisirElement() const;
protected:
    Conteneur();
private:
    static Conteneur* m_instance;
    std::vector<const T*> m_contenu;
};

#include "Conteneur.cpp"
#endif	/* CONTENEUR_H */

