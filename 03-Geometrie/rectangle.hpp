#ifndef REC_HPP
#define REC_HPP

#include "objet.hpp"
#include <iostream>

class Rectangle : public Objet
{
private:
    double largeur;
    double longueur;
public:
    Rectangle(double larg, double longu){
        setLongueur(longu);
        setLargeur(larg);
    }

    void setLongueur(double n_long){longueur = n_long;}
    void setLargeur(double n_larg){largeur = n_larg;}

    double getLongueur() const {return longueur;}
    double getLargeur() const {return largeur;}

    double aire() const override {return longueur*largeur;}

    double perimetre() const override {return 2*longueur+2*largeur;}

    void afficheInfo() const override {
        std::cout << "Rectangle de " << getLongueur() << " par " << getLargeur() << std::endl;
    }
};

#endif