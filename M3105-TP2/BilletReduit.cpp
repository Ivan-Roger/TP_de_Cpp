#include "Billet.h"
#include "BilletReduit.h"
#include "Trajet.h"
#include "Tarif.h"
#include "Promotion.h"

BilletReduit::BilletReduit(const Client& unClient, const Trajet& unTrajet, const Tarif& unTarif, const Promotion& unePromo) : Billet(unClient, unTrajet, unTarif), m_promotion(unePromo) {
    // ...
}

float BilletReduit::getPrix() const {
    return m_promotion.calculePrixReduit(Billet::getPrix());
}

const Promotion& BilletReduit::getPromotion() const {
    return m_promotion;
}
