/* 
 * File:   NombreContraint.cpp
 * Author: rogeri
 * 
 * Created on 11 septembre 2015, 08:48
 */

#include "NombreContraint.h"
#ifdef NOMBRECONTRAINT_H

using namespace std;

template <class J>
NombreContraint<T>::NombreContraint(T valeur, T min, T max) {
    m_min=min;
    m_max=max;
    m_val=valeur;
}

template <class J>
NombreContraint<T>::NombreContraint(const NombreContraint<T>& orig) {
    m_val=orig.getVal();
    m_min=orig.getMin();
    m_max=orig.getMax();
}

template <class J>
NombreContraint<J>::~NombreContraint() {}

template <class J>
void NombreContraint<J>::setVal(J valeur) {
    if (valeur>m_max || valeur<m_min)
        throw "out of bounds !";
    m_val=valeur;
}

template <class J>
void NombreContraint<J>::saisir(std::istream & in) {
    T c_val;
    in >> c_val;
    setVal(c_val);
}

template <class T>
void NombreContraint<T>::afficher(std::ostream & out) const {
    out << m_val;
}

template <class T>
std::ostream& operator<<(std::ostream & out, const NombreContraint<T>& i) {
    i.afficher(out);
    return out;
}

template <class T>
std::istream& operator>>(std::istream & in, NombreContraint<T>& i) {
    i.saisir(in);
    return in;
}

#endif