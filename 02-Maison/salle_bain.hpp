#ifndef SDB_HPP
#define SDB_HPP

#include "piece.hpp"

class SalleDeBain : public Piece
{
private:
    bool has_shower;
public:
    SalleDeBain(): has_shower(false){setNbWindows(1);setColor("white");}
    SalleDeBain(int nb_wind, string color, bool n_hs){
        setNbWindows(nb_wind);
        setColor(color);
        setHasShower(n_hs);
    }
    SalleDeBain(const SalleDeBain &s): Piece{s}, has_shower(s.getHasShower()){}
    ~SalleDeBain(){}

    void setHasShower(bool n_hs){has_shower = n_hs;}

    bool getHasShower() const {return has_shower;}
// methode 
    bool is_sdb() const override{return true;}
};

#endif