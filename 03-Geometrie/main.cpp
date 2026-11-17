#include "rectangle.hpp"
#include "carre.hpp"
#include <iostream>
#include <string>
#include <type_traits>

// Teste generé par IA
// Verifie a la compilation qu'Objet est bien abstraite
// (si ce n'est pas le cas, le programme ne compile pas)
static_assert(std::is_abstract<Objet>::value, "Objet doit etre abstraite");

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

// ---------- tests Rectangle ----------
static void testRectangle()
{
    std::cout << "\n=== Rectangle ===" << std::endl;

    Rectangle r(2, 5);   // largeur 2, longueur 5 (ordre de l'UML)
    verifier(r.getLargeur() == 2 && r.getLongueur() == 5,
             "Rectangle(2, 5) : largeur 2, longueur 5");
    verifier(r.aire() == 10, "Rectangle(2, 5) : aire = 10");
    verifier(r.perimetre() == 14, "Rectangle(2, 5) : perimetre = 14");

    r.setLargeur(3);
    verifier(r.aire() == 15, "apres setLargeur(3) : aire = 15");

    std::cout << "  Affichage : ";
    r.afficheInfo();
}

// ---------- tests Carre ----------
static void testCarre()
{
    std::cout << "\n=== Carre ===" << std::endl;

    Carre c(4);
    verifier(c.getCote() == 4, "Carre(4) : cote = 4");
    verifier(c.aire() == 16, "Carre(4) : aire = 16");
    verifier(c.perimetre() == 16, "Carre(4) : perimetre = 16");

    c.setCote(1.5);
    verifier(c.aire() == 2.25, "apres setCote(1.5) : aire = 2.25");

    std::cout << "  Affichage : ";
    c.afficheInfo();
}

// ---------- tests polymorphisme ----------
static void testPolymorphisme()
{
    std::cout << "\n=== Polymorphisme (tableau d'Objet*) ===" << std::endl;

    const int taille = 3;
    Objet *formes[taille] = { new Rectangle(2, 5), new Carre(3), new Rectangle(1, 1) };

    double aire_totale = 0;
    for (int i = 0; i < taille; i++) {
        std::cout << "  ";
        formes[i]->afficheInfo();          // chaque forme appelle SA version
        aire_totale += formes[i]->aire();
    }

    verifier(formes[0]->aire() == 10, "formes[0] (Rectangle 2x5) : aire = 10 via Objet*");
    verifier(formes[1]->perimetre() == 12, "formes[1] (Carre 3) : perimetre = 12 via Objet*");
    verifier(aire_totale == 20, "aire totale des 3 formes = 10 + 9 + 1 = 20");

    // Liberation : grace au destructeur virtuel, le bon destructeur est appele
    for (int i = 0; i < taille; i++) {
        delete formes[i];
    }
}

int main()
{
    testRectangle();
    testCarre();
    testPolymorphisme();

    std::cout << "\n=== Bilan : " << nb_ok << " / " << nb_tests << " tests reussis ===" << std::endl;
    return (nb_ok == nb_tests) ? 0 : 1;
}