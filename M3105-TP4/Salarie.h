/* 
 * File:   Salarie.h
 * Author: rogeri
 *
 * Created on 2 octobre 2015, 09:48
 */

#ifndef SALARIE_H
#define	SALARIE_H

class Salarie {
public:
    Salarie(std::string& nom, std::string& numSS, float salaire);
    Salarie(const Salarie& orig);
    virtual ~Salarie();
    const std::string& getNom() const;
    void setNom(std::string& nom);
    const std::string& getNumSS() const;
    void setNumSS(std::string& numSS);
    const float& getSalaire() const;
    void setSalaire(float& salaire);
private:
    std::string m_nom;
    std::string& m_numSS;
    float m_salaireMensuel;
};

#endif	/* SALARIE_H */

