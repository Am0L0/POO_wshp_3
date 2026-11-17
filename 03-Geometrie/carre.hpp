#ifndef CARRE_HPP
#define CARRE_HPP

#include "objet.hpp"
#include <iostream>

class Carre : public Objet
{
private:
    double cote;
public:
    Carre(double n_cote){
        setCote(n_cote);
    }

    void setCote(double n_cote){cote = n_cote;}
    double getCote() const {return cote;}

    double aire() const override{return cote * cote;}
    double perimetre() const override{return 4*cote;}

    void afficheInfo() const override{
        std::cout << "Carre de coté " << getCote() << std::endl;
    }
};

#endif