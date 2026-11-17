#ifndef VEHICULE_HPP
#define VEHICULE_HPP

class Vehicule
{
private:
    double v_max;
    double kilometrage;
public:
// constructeurs
    Vehicule(): v_max(240), kilometrage(0){}
    Vehicule(double n_v_max, double n_kilometrage){
        setVmax(n_v_max);
        setKilometrage(n_kilometrage);
    }
    Vehicule(const Vehicule &v): v_max(v.v_max), kilometrage(v.kilometrage){}
    ~Vehicule(){}
// getters & setters
    void setVmax(double n_v_max){if (n_v_max >= 200){v_max = n_v_max;}else{v_max = 240;}}
    void setKilometrage(double n_kilometrage){if (n_kilometrage >= 0){kilometrage = n_kilometrage;}else{kilometrage = 0;}}

    double getVmax() const {return v_max;}
    double getKilometrage() const {return kilometrage;}
};

#endif