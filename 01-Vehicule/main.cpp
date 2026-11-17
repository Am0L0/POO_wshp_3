#include "schoolbus.hpp"
#include <iostream>
#include <string>

// Teste fais par IA
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

// ---------- tests Vehicule ----------
static void testVehicule()
{
    std::cout << "\n=== Vehicule ===" << std::endl;

    Vehicule v1;
    verifier(v1.getVmax() == 240, "constructeur par defaut : v_max = 240");
    verifier(v1.getKilometrage() == 0, "constructeur par defaut : kilometrage = 0");

    Vehicule v2(250, 1000);
    verifier(v2.getVmax() == 250, "constructeur (250, 1000) : v_max = 250");
    verifier(v2.getKilometrage() == 1000, "constructeur (250, 1000) : kilometrage = 1000");

    Vehicule v3(100, 500);
    verifier(v3.getVmax() == 240, "constructeur avec v_max < 200 : v_max remis a 240");

    Vehicule v4(250, -50);
    verifier(v4.getKilometrage() == 0, "constructeur avec kilometrage negatif : remis a 0");

    Vehicule v5(v2);
    verifier(v5.getVmax() == 250 && v5.getKilometrage() == 1000,
             "constructeur de copie : memes valeurs que l'original");

    v2.setKilometrage(-10);
    verifier(v2.getKilometrage() == 0, "setKilometrage(-10) : remis a 0");

    v2.setVmax(300);
    verifier(v2.getVmax() == 300, "setVmax(300) : v_max = 300");
}

// ---------- tests Bus ----------
static void testBus()
{
    std::cout << "\n=== Bus ===" << std::endl;

    Bus b1;
    verifier(b1.getVmax() == 240 && b1.getKilometrage() == 0,
             "constructeur par defaut : v_max = 240, kilometrage = 0");
    verifier(b1.getCapacite() >= 10 && b1.getCapacite() <= 50,
             "constructeur par defaut : capacite dans [10, 50]");

    Bus b2(220, 5000, 30);
    verifier(b2.getVmax() == 220, "constructeur (220, 5000, 30) : v_max = 220");
    verifier(b2.getKilometrage() == 5000, "constructeur (220, 5000, 30) : kilometrage = 5000");
    verifier(b2.getCapacite() == 30, "constructeur (220, 5000, 30) : capacite = 30");

    Bus b3(220, 5000, 80);
    verifier(b3.getCapacite() == 50, "constructeur avec capacite 80 : remise a 50");

    Bus b4(220, 5000, 5);
    verifier(b4.getCapacite() == 50, "constructeur avec capacite 5 : remise a 50");

    Bus b5(b2);
    verifier(b5.getVmax() == 220 && b5.getKilometrage() == 5000 && b5.getCapacite() == 30,
             "constructeur de copie : memes valeurs que l'original");

    Bus b6(220, 0, 45);
    b6.setCapacite(20);
    verifier(b6.getCapacite() == 20, "setCapacite(20) sur un bus de 45 places : capacite = 20");
    b6.setCapacite(100);
    verifier(b6.getCapacite() == 50, "setCapacite(100) : remise a 50");

    std::cout << "\n  Affichage de b2 :" << std::endl;
    b2.afficher();
}

// ---------- tests SchoolBus ----------
static void testSchoolBus()
{
    std::cout << "\n=== SchoolBus ===" << std::endl;

    SchoolBus sb("Lycee Victor Hugo");
    verifier(sb.getSn() == "Lycee Victor Hugo", "constructeur : nom de l'ecole enregistre");

    sb.setSn("College Jean Moulin");
    verifier(sb.getSn() == "College Jean Moulin", "setSn : nom de l'ecole modifie");

    verifier(sb.getVmax() == 240 && sb.getKilometrage() == 0,
             "herite de Bus : v_max = 240, kilometrage = 0");
    verifier(sb.getCapacite() >= 10 && sb.getCapacite() <= 50,
             "herite de Bus : capacite dans [10, 50]");
}

// ---------- tests countBigBus ----------
static void testCountBigBus()
{
    std::cout << "\n=== countBigBus ===" << std::endl;

    SchoolBus flotte[4] = { SchoolBus("A"), SchoolBus("B"), SchoolBus("C"), SchoolBus("D") };

    // A : gros et peu roule -> compte
    flotte[0].setCapacite(45); flotte[0].setKilometrage(10000);
    // B : gros mais trop roule -> ne compte pas
    flotte[1].setCapacite(45); flotte[1].setKilometrage(250000);
    // C : petit -> ne compte pas
    flotte[2].setCapacite(20); flotte[2].setKilometrage(10000);
    // D : pile 40 places, 199 999 km -> compte (limites)
    flotte[3].setCapacite(40); flotte[3].setKilometrage(199999);

    std::cout << "  Capacites : ";
    for (int i = 0; i < 4; i++) std::cout << flotte[i].getCapacite() << " ";
    std::cout << std::endl;

    verifier(countBigBus(flotte, 4) == 2, "flotte de 4 bus : 2 gros bus attendus");
    verifier(countBigBus(flotte, 1) == 1, "seulement le premier bus : 1 gros bus attendu");
    verifier(countBigBus(flotte, 0) == -1, "taille 0 : renvoie -1");
}

int main()
{
    testVehicule();
    testBus();
    testSchoolBus();
    testCountBigBus();

    std::cout << "\n=== Bilan : " << nb_ok << " / " << nb_tests << " tests reussis ===" << std::endl;
    return (nb_ok == nb_tests) ? 0 : 1;
}