#ifndef MAISON_HPP
#define MAISON_HPP

#include "piece.hpp"
#include <list>
#include <memory>

class Maison
{
private:
    std::list<std::shared_ptr<Piece>> l_piece;
public:
// constructeurs
    Maison(): l_piece({std::make_shared<Piece>()}){}
    Maison(std::list<std::shared_ptr<Piece>> n_lp){
        setListPiece(n_lp);
    }
    Maison(const Maison &m): l_piece(m.getListPiece()){}
    ~Maison(){}
// getter & setter
    void setListPiece(std::list<std::shared_ptr<Piece>> n_lp){if (!n_lp.empty()){l_piece = n_lp;}else{l_piece = {std::make_shared<Piece>()};}}

    std::list<std::shared_ptr<Piece>> getListPiece() const {return l_piece;}
// methode
    int getNbBathrooms();
    int getNbRooms();
};

int Maison::getNbBathrooms(){
    int cpt = 0;
    for (const std::shared_ptr<Piece> &p : l_piece){
        if (p->is_sdb()){
            cpt++;
        }
    }
    return cpt;
}

int Maison::getNbRooms(){
    int cpt = 0;
    for (const std::shared_ptr<Piece> &p : l_piece){
        if (p->is_br()){
            cpt++;
        }
    }
    return cpt;
}

#endif