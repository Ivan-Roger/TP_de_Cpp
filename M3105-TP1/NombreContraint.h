/* 
 * File:   NombreContraint.h
 * Author: rogeri
 *
 * Created on 11 septembre 2015, 08:48
 */

#ifndef NOMBRECONTRAINT_H
#define	NOMBRECONTRAINT_H

#include <iostream>
#include <iomanip>

template <class T>
class NombreContraint {
public:
    NombreContraint(T valeur=(T)0, T min=(T)0, T max=(T)100);
    NombreContraint(const NombreContraint<T>& orig);
    virtual ~NombreContraint();
    inline T getMin() const;
    inline T getMax() const;
    inline T getVal() const;
    void setVal(T valeur);
    void saisir(std::istream & in);
    void afficher(std::ostream & out) const;
private:
    T m_min;
    T m_max;
    T m_val;
};
template <class T>
inline T NombreContraint<T>::getMin() const {
    return m_min;
}
template <class T>
inline T NombreContraint<T>::getMax() const {
    return m_max;
}
template <class T>
inline T NombreContraint<T>::getVal() const {
    return m_val;
}
template <class T>
std::ostream& operator<<(std::ostream& out, const NombreContraint<T>& i);

template <class T>
std::istream& operator>>(std::istream& in, NombreContraint<T>& i);

#include "NombreContraint.cpp"
#endif	/* NOMBRECONTRAINT_H */

