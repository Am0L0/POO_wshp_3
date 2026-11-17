#include "maison.hpp"
#include "salle_bain.hpp"
#include "chambre.hpp"
#include <iostream>
#include <list>
#include <memory>
#include <string>

// Teste generé par IA
// ---------- petit outil de test ----------
static int nb_tests = 0;
static int nb_ok = 0;

static void verifier(bool condition, const std::string &description)
{
    nb_tests++;
    if (condition) {
        nb_ok++;
        std::cout << "  [OK]    " << description << std::endl;
    } else {
        std::cout << "  [ECHEC] " << description << std::endl;
    }
}

// ---------- tests des pieces seules ----------
static void testPieces()
{
    std::cout << "\n=== Pieces ===" << std::endl;

    Piece p;
    verifier(p.getNbWindows() == 3 && p.getColor() == "red",
             "Piece par defaut : 3 fenetres, rouge");
    verifier(!p.is_sdb() && !p.is_br(), "Piece : ni salle de bain ni chambre");

    SalleDeBain s;
    verifier(s.getNbWindows() == 1 && s.getColor() == "white" && !s.getHasShower(),
             "SalleDeBain par defaut : 1 fenetre, blanche, sans douche");
    verifier(s.is_sdb(), "SalleDeBain : is_sdb() vaut true");

    SalleDeBain s2(2, "blue", true);
    SalleDeBain s3(s2);
    verifier(s3.getNbWindows() == 2 && s3.getColor() == "blue" && s3.getHasShower(),
             "SalleDeBain : constructeur de copie");

    Chambre c;
    verifier(c.getNbBed() == 1 && c.getColor() == "white", "Chambre par defaut : 1 lit, blanche");
    verifier(c.is_br(), "Chambre : is_br() vaut true");

    Chambre c2(2, "green", 2);
    verifier(c2.getNbBed() == 2, "Chambre(2, \"green\", 2) : 2 lits");

    // Appel a travers une reference de type Piece : teste le polymorphisme
    const Piece &ref_s = s;
    const Piece &ref_c = c;
    verifier(ref_s.is_sdb(), "SalleDeBain vue comme une Piece& : is_sdb() vaut true");
    verifier(ref_c.is_br(), "Chambre vue comme une Piece& : is_br() vaut true");
}

// ---------- tests Maison ----------
static void testMaison()
{
    std::cout << "\n=== Maison ===" << std::endl;

    Maison m1;
    verifier(m1.getListPiece().size() == 1, "Maison par defaut : 1 piece");
    verifier(m1.getNbBathrooms() == 0 && m1.getNbRooms() == 0,
             "Maison par defaut : 0 salle de bain, 0 chambre");

    std::list<std::shared_ptr<Piece>> vide;
    Maison m2(vide);
    verifier(m2.getListPiece().size() == 1, "Maison avec une liste vide : 1 piece par defaut");

    // 1 piece simple + 2 salles de bain + 3 chambres
    std::list<std::shared_ptr<Piece>> pieces = {
        std::make_shared<Piece>(),
        std::make_shared<SalleDeBain>(), std::make_shared<SalleDeBain>(),
        std::make_shared<Chambre>(), std::make_shared<Chambre>(), std::make_shared<Chambre>()
    };
    Maison m3(pieces);
    verifier(m3.getListPiece().size() == 6, "Maison de 6 pieces : 6 pieces dans la liste");
    verifier(m3.getNbBathrooms() == 2, "Maison de 6 pieces : 2 salles de bain");
    verifier(m3.getNbRooms() == 3, "Maison de 6 pieces : 3 chambres");

    Maison m4(m3);
    verifier(m4.getNbBathrooms() == 2 && m4.getNbRooms() == 3,
             "constructeur de copie : memes comptes que l'original");

    std::cout << "\n  Pieces de la maison m3 :" << std::endl;
    for (const std::shared_ptr<Piece> &p : m3.getListPiece()) {
        std::cout << "    ";
        p->affiche();
    }
}

int main()
{
    testPieces();
    testMaison();

    std::cout << "\n=== Bilan : " << nb_ok << " / " << nb_tests << " tests reussis ===" << std::endl;
    return (nb_ok == nb_tests) ? 0 : 1;
}