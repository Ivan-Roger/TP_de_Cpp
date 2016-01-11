/* 
 * File:   Produit.cpp
 * Author: rogeri
 * 
 * Created on 25 septembre 2015, 08:52
 */

#include "Produit.h"

Produit::Produit(const std::string& nom, const Client& c) : m_nom(nom), m_client(c) {}

Produit::Produit(const Produit& orig) : m_nom(orig.m_nom), m_client(orig.m_client) {}

Produit::~Produit() {}

void Produit::ajouter(Produit& p) {
    throw "Impossible !";
}

const Client& Produit::getClient() const {
    return m_client;
}

const std::string Produit::getNom() const {
    return m_nom;
}

