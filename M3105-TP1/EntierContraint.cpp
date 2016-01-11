/* 
 * File:   EntierContraint.cpp
 * Author: rogeri
 * 
 * Created on 9 septembre 2015, 15:31
 */

#include "EntierContraint.h"
using namespace std;
EntierContraint::EntierContraint(const EntierContraint& orig) {
    m_val=orig.getVal();
    m_min=orig.getMin();
    m_max=orig.getMax();
}

EntierContraint::~EntierContraint() {}

EntierContraint::EntierContraint(int valeur, int min, int max) {
    if (valeur>max || valeur<min)
        throw "out of bounds !";
    m_val=valeur;
    m_min=min;
    m_max=max;
}

EntierContraint::operator int() {
    return m_val;
}

void EntierContraint::setVal(int valeur) {
    if (valeur>m_max || valeur<m_min)
        throw "out of bounds !";
    m_val=valeur;
}

void EntierContraint::saisir(std::istream & in) {
    int c_val;
    in >> c_val;
    setVal(c_val);
}

void EntierContraint::afficher(std::ostream & out) const {
    out << m_val;
}
std::ostream& operator<<(std::ostream & out, const EntierContraint& i) {
    i.afficher(out);
    return out;
}
std::istream& operator>>(std::istream & in, EntierContraint& i) {
    i.saisir(in);
    return in;
}