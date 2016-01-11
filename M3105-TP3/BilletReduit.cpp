#include "Billet.h"
#include "BilletReduit.h"
#include "Trajet.h"
#include "Tarif.h"
#include "Promotion.h"

BilletReduit::BilletReduit(const std::string& nom, const Client& unClient, const Trajet& unTrajet, const Tarif& unTarif, const Promotion& unePromo) : Billet(nom, unClient, unTrajet, unTarif), m_promotion(unePromo) {
    // ...
}

float BilletReduit::getPrix() const {
    return m_promotion.calculePrixReduit(Billet::getPrix());
}

const Promotion& BilletReduit::getPromotion() const {
    return m_promotion;
}

const void BilletReduit::afficher(std::ostream& out) const {
    Billet::afficher(out);
    out << " (";
    m_promotion.afficher(out);
    out << ")";
}
