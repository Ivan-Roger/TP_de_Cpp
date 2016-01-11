/* 
 * File:   Pack.h
 * Author: rogeri
 *
 * Created on 25 septembre 2015, 08:50
 */

#ifndef PACK_H
#define	PACK_H

#include "Produit.h"
#include "Client.h"
#include <vector>
#include <iostream>
#include <iomanip>

class Pack : public Produit {
public:
    Pack(const std::string& nom, const Client& c, Produit& p);
    Pack(const Pack& orig);
    virtual ~Pack();
    const virtual void afficher(std::ostream& out, int level = 0) const;
    virtual void ajouter(Produit& p);
    virtual float getPrix() const;
private:
    std::vector<Produit*> m_contenu;
};

#endif	/* PACK_H */

