/* 
 * File:   EntierContraint.h
 * Author: rogeri
 *
 * Created on 9 septembre 2015, 15:31
 */

#ifndef ENTIERCONTRAINT_H
#define	ENTIERCONTRAINT_H

#include <iostream>
#include <iomanip>

class EntierContraint {
public:
    EntierContraint(int valeur=0, int min=0, int max=100);
    EntierContraint(const EntierContraint& orig);
    virtual ~EntierContraint();
    inline int getMin() const;
    inline int getMax() const;
    inline int getVal() const;
    void setVal(int valeur);
    void saisir(std::istream & in);
    void afficher(std::ostream & out) const;
    operator int();
private:
    int m_min;
    int m_max;
    int m_val;
};
inline int EntierContraint::getMin() const {
    return m_min;
}
inline int EntierContraint::getMax() const {
    return m_max;
}
inline int EntierContraint::getVal() const {
    return m_val;
}
std::ostream & operator<<(std::ostream & out, const EntierContraint& i);
std::istream & operator>>(std::istream & in, EntierContraint& i);
#endif	/* ENTIERCONTRAINT_H */

