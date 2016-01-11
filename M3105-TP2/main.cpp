/* 
 * File:   main.cpp
 * Author: rogeri
 *
 * Created on 16 septembre 2015, 15:06
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Billet.h"
#include "Promotion.h"
#include "BilletReduit.h"
#include "Client.h"
#include "Conteneur.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        Conteneur<Trajet> lTrajet;
        Conteneur<Tarif> lTarif;
        Conteneur<Promotion> lPromotion;
        Conteneur<Billet> lBillet;
        int choice = 0;
        bool continuer = true;
        string nom;
        cout << "=== SNCF ===" << endl;
        cout << "Votre nom : ";
        cin >> nom;
        Client client(nom);
        do {
            do {
                cout << "--- Menu ---" << endl;
                cout << "\t0) Quitter" << endl;
                cout << "\t1) Trajet" << endl;
                cout << "\t2) Tarif" << endl;
                cout << "\t3) Promotion" << endl;
                cout << "\t4) Billet" << endl;
                cout << "Votre choix : ";
                cin >> choice;
            } while (choice < 0 || choice > 4);
            string dep = "";
            string arr = "";
            string label = "";
            string promo = "";
            Trajet trajet("", "", 0);
            Tarif tarif("", 0.0);
            Promotion promotion("", 0.0);
            switch (choice) {
                case 0:
                    continuer = false;
                    break;
                case 1:
                    int dist;
                    cout << "\n--- Trajet ---" << endl;
                    cout << "Ville de départ : ";
                    cin >> dep;
                    cout << "Ville d'arrivée : ";
                    cin >> arr;
                    cout << "Distance : ";
                    cin >> dist;
                    lTrajet.ajouter(*new Trajet(dep, arr, dist));
                    break;
                case 2:
                    float prixKm;
                    cout << "\n--- Tarif ---" << endl;
                    cout << "Libellé : ";
                    cin >> label;
                    cout << "Prix au KM : ";
                    cin >> prixKm;
                    lTarif.ajouter(*new Tarif(label, prixKm));
                    break;
                case 3:
                    float taux;
                    cout << "\n--- Promotion ---" << endl;
                    cout << "Libellé : ";
                    cin >> label;
                    cout << "Taux de réduction : ";
                    cin >> prixKm;
                    lPromotion.ajouter(*new Promotion(label, taux));
                    break;
                case 4:
                    cout << "\n--- Billet ---" << endl;
                    cout << "Selectionnez le trajet :" << endl;
                    trajet = lTrajet.choisirElement();
                    cout << "Selectionnez le tarif :" << endl;
                    tarif = lTarif.choisirElement();
                    do {
                        cout << "Promotion (Oui/Non) : ";
                        cin >> promo;
                    } while (promo != "Oui" && promo != "Non");
                    if (promo == "Oui") {
                        promotion = lPromotion.choisirElement();
                        lBillet.ajouter(*new BilletReduit(client, trajet, tarif, promotion));
                    } else {
                        lBillet.ajouter(*new Billet(client, trajet, tarif));
                    }
                    break;
            }
        } while (continuer);
    } catch (char const* err) {
        cout << "ERROR : " << err << endl;
    }
    return 0;
}

