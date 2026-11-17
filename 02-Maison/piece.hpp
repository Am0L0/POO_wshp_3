#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>
#include <iostream>

using namespace std;

class Piece
{
private:
    int nb_windows;
    string color;
public:
    Piece(): nb_windows(3), color("red"){}
    Piece(int n_nb_windows, string n_color){
        setNbWindows(n_nb_windows);
        setColor(n_color);
    }
    Piece(const Piece &p): nb_windows(p.getNbWindows()), color(p.getColor()){}
    virtual ~Piece(){}

    void setNbWindows(int n_nb_wondows){nb_windows = n_nb_wondows;}
    void setColor(string n_color){color = n_color;}

    int getNbWindows() const {return nb_windows;}
    string getColor() const {return color;}
// methode 
    void affiche();
    virtual bool is_sdb() const {return false;}
    virtual bool is_br() const {return false;}
};

void Piece::affiche(){
    cout << "Piece " << getColor() << " avec " << getNbWindows() << " fenetres." << endl;
}

#endif