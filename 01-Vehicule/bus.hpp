#ifndef BUS_HPP
#define BUS_HPP

#include "vehicule.hpp"
#include <iostream>

class Bus : public Vehicule 
{
private:
    int capacite;
public:
// constructeurs
    Bus(): capacite(10){setVmax(240);setKilometrage(0);}
    Bus(double n_v_max, double n_kilo, int n_capa){
        setVmax(n_v_max);
        setKilometrage(n_kilo);
        setCapacite(n_capa);
    }
    Bus(const Bus &b): capacite(b.capacite){setVmax(b.getVmax()); setKilometrage(b.getKilometrage());}
    ~Bus(){}
// getters & setters
    void setCapacite(int n_capa){if (n_capa >=10 && n_capa <= 50){capacite = n_capa;}else{capacite = 50;}}

    int getCapacite() const {return capacite;}
// methode
    void afficher(void);
};
void Bus::afficher(){
    std::cout << "Ce bus a une vitesse max de " << getVmax() << " km/h" << std::endl;
    std::cout << "Il a " << getKilometrage() << " km au compteur" << std::endl;
    std::cout << "Il peux accueillir " << getCapacite() << "personne a son bord" << std::endl;
}

#endif