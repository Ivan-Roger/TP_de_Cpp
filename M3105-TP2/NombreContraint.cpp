/* 
 * File:   NombreContraint.cpp
 * Author: rogeri
 * 
 * Created on 11 septembre 2015, 08:48
 */

//#include "NombreContraint.h"
#ifdef NOMBRECONTRAINT_H

using namespace std;

template <class T>
NombreContraint<T>::NombreContraint(T valeur, T min, T max) {
    if (valeur<min || valeur>max) {
        throw "Out of bounds !";
    }
    m_min=min;
    m_max=max;
    m_val=valeur;
}

template <class T>
NombreContraint<T>::NombreContraint(const NombreContraint<T>& orig) {
    m_val=orig.getVal();
    m_min=orig.getMin();
    m_max=orig.getMax();
}

template <class T>
NombreContraint<T>::~NombreContraint() {}

template <class T>
void NombreContraint<T>::setVal(T valeur) {
    if (valeur>m_max || valeur<m_min)
        throw "out of bounds !";
    m_val=valeur;
}

template <class T>
void NombreContraint<T>::saisir(std::istream & in) {
    T c_val;
    in >> c_val;
    setVal(c_val);
}

template <class T>
void NombreContraint<T>::afficher(std::ostream & out) const {
    out << m_val;
}

template <class T>
T NombreContraint<T>::operatorT() {
    return m_val;
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