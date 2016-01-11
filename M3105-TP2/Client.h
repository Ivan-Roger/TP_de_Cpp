/* 
 * File:   Client.h
 * Author: rogeri
 *
 * Created on 18 septembre 2015, 09:23
 */

#ifndef CLIENT_H
#define	CLIENT_H

#include <iostream>
#include <iomanip>
#include <string>

class Client {
public:
    Client(std::string nom);
    Client(const Client& orig);
    virtual ~Client();
    const std::string& getNom() const;
    void saisir(std::istream& in);
    void afficher(std::ostream& out) const;
private:
    std::string m_nom;
};

#endif	/* CLIENT_H */

