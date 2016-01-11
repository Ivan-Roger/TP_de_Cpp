/* 
 * File:   Conteneur.cpp
 * Author: rogeri
 * 
 * Created on 23 septembre 2015, 16:36
 */

//#include "Conteneur.h"
#ifdef CONTENEUR_H

using namespace std;

template<class T>
Conteneur<T>* Conteneur<T>::m_instance = nullptr;

template<class T>
Conteneur<T>* Conteneur<T>::getInstance() {
    if (m_instance==nullptr) {
        m_instance = new Conteneur<T>;
    }
    return m_instance;
}

template<class T>
Conteneur<T>::Conteneur() : m_contenu() {}

template<class T>
void Conteneur<T>::ajouter(const T& element) {
  m_contenu.push_back(&element);
}

template<class T>
void Conteneur<T>::afficher() const {
    for(int i =0; i < m_contenu.size(); i++) {
        cout << "\t" << i+1 << ") ";
        m_contenu[i]->afficher(cout);
        cout << endl;
    }
}

template<class T>
const T & Conteneur<T>::choisirElement() const {
    NombreContraint<int> n(1,1,m_contenu.size());
    bool ok;
    do {
        try {
            afficher();
            cout << endl << "Choix : ";
            n.saisir(cin);
            ok =true;
        } catch(const char * e) {
            cout << "Entre 1 et " << m_contenu.size() << endl;
            ok = false;
        }
    } while (!ok);
    return *m_contenu[n.getVal()-1];
}

#endif
