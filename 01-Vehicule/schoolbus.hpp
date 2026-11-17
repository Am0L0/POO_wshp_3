#ifndef SCHOOLBUS_HPP
#define SCHOOLBUS_HPP

#include "bus.hpp"
#include <string>
#include <iostream>

using namespace std;

class SchoolBus : public Bus 
{
private:
    string school_name;
public:
// constructeur
    SchoolBus(string sn){school_name = sn;}
// getter & setter
    void setSn(string n_sn){school_name = n_sn;}

    string getSn(){return school_name;}
};

static int countBigBus(SchoolBus t[], int taille){
    int cpt=0;
    if (taille <= 0) {cerr << "La taille ne peux etre inferieur ou egale a 0" << endl;return -1;}
    for (int i=0; i < taille; i++){
        if (t[i].getCapacite() >= 40 && t[i].getKilometrage() < 200000){
            cpt++;
        }
    }
    return cpt;
}

#endif