#ifndef CHAMBRE_HPP
#define CHAMBRE_HPP

#include "piece.hpp"

class Chambre : public Piece
{
private:
    int nb_bed;
public:
    Chambre(): nb_bed(1){setNbWindows(1);setColor("white");}
    Chambre(int nb_wind, string color, int n_nbb){
        setNbWindows(nb_wind);
        setColor(color);
        setNbBed(n_nbb);
    }
    Chambre(const Chambre &c): Piece{c}, nb_bed(c.getNbBed()){}
    ~Chambre(){}

    void setNbBed(int n_nbb){nb_bed = n_nbb;}

    int getNbBed() const {return nb_bed;}
// methode 
    bool is_br() const override {return true;}
};

#endif