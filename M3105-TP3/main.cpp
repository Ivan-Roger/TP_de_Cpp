/* 
 * File:   main.cpp
 * Author: rogeri
 *
 * Created on 16 septembre 2015, 15:06
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include "Billet.h"
#include "Promotion.h"
#include "BilletReduit.h"
#include "Client.h"
#include "Conteneur.h"
#include "Produit.h"
#include "Reservation.h"
#include "Pack.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        Conteneur<Trajet> lTrajet = *Conteneur<Trajet>::getInstance();
        Conteneur<Tarif> lTarif = *Conteneur<Tarif>::getInstance();
        Conteneur<Promotion> lPromo = *Conteneur<Promotion>::getInstance();
        Conteneur<Produit> lProduit = *Conteneur<Produit>::getInstance();

        int choice = 0;
        bool continuer = false;
        string nom;

        cout << "=== SNCF ===" << endl;
        cout << "Votre nom : ";
        cin >> nom;
        Client client(nom);
        do {
            choice = -1;
            do {
                cout << "--- Menu ---" << endl;
                cout << "\t0) Quitter" << endl;
                cout << "\t1) Trajet" << endl;
                cout << "\t2) Tarif" << endl;
                cout << "\t3) Promotion" << endl;
                cout << "\t4) Billet" << endl;
                cout << "\t5) Pack" << endl;
                cout << "Votre choix : ";
                cin >> choice;
            } while (choice < 0 || choice > 5);
            string dep = "";
            string arr = "";
            string label = "";
            string promo = "";
            string nomPack = "";
            Trajet trajet("", "", 0);
            Tarif tarif("", 0.0);
            Promotion promotion("", 0.0);
            Produit* produit = nullptr;
            Pack* pack = nullptr;
            bool ajouter = false;
            switch (choice) {
                case 0:
                    continuer = false;
                    break;
                case 1:
                    int dist;
                    cout << "\n--- Trajet ---" << endl;
                    trajet.saisir(cin);
                    lTrajet.ajouter(trajet);
                    break;
                case 2:
                    float prixKm;
                    cout << "\n--- Tarif ---" << endl;
                    tarif.saisir(cin);
                    lTarif.ajouter(tarif);
                    break;
                case 3:
                    float taux;
                    cout << "\n--- Promotion ---" << endl;
                    promotion.saisir(cin);
                    lPromo.ajouter(promotion);
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
                        promotion = lPromo.choisirElement();
                        lProduit.ajouter(*new BilletReduit("Billet Reduit", client, trajet, tarif, promotion));
                    } else {
                        lProduit.ajouter(*new Billet("Billet", client, trajet, tarif));
                    }
                    break;
                case 5:
                    cout << "\n--- Pack ---" << endl;
                    cout << "Nom : ";
                    cin >> nomPack;
                    cout << "Selectionnez le produit :" << endl;
                    produit = (Produit*) & lProduit.choisirElement();
                    pack = new Pack(nomPack, client, *produit);
                    do {
                        do {
                            cout << "Ajouter : " << endl;
                            cout << "\t0) Fin" << endl;
                            cout << "\t1) Ajouter" << endl;
                            cout << "Votre choix : ";
                            cin >> choice;
                        } while (choice < 0 || choice > 1);
                        switch (choice) {
                            case 1:
                                cout << "Selectionnez le produit :" << endl;
                                pack->ajouter((Produit&) lProduit.choisirElement());
                                break;
                        }
                    } while (ajouter);
                    lProduit.ajouter(*pack);
                    break;
            }
        } while (continuer);
    } catch (char const* err) {
        cout << "ERROR : " << err << endl;
    } catch(...) {
        cout << "Error" << endl;
    }
    return 0;
}

