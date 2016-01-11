/* 
 * File:   main.cpp
 * Author: rogeri
 *
 * Created on 9 septembre 2015, 15:05
 */

#include <cstdlib>
#include "EntierContraint.h"
#include "NombreContraint.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        EntierContraint a1;
        cout<<"A = "<<a1<<endl;
        
        EntierContraint b1 (15) ;
        cout<<"B = "<<b1<<endl;
        
        cout<<"A ? ";
        cin >> a1;
        EntierContraint c1 (a1);
        cout<<"C = "<<c1<<endl;
        
        cout<<"A+B="<<a1+b1<<endl;
        //-----------------------
        NombreContraint<float> a2;
        cout<<"A = "<<a2;
        
        NombreContraint<float> b2 (75.0,-2.5,75.5);
        cout<<"B = "<<b2<<endl;
        cout<<"min = "<<b2.getMin()<<" /max = "<<b2.getMax()<<endl;
        
        NombreContraint<float> c2 (a2);
        cout<<c2<<endl;
    } catch (char const* err) {
        cout << "ERROR : " << err << endl;
    }
    return 0;
}