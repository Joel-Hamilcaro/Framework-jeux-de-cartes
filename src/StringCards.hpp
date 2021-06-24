#ifndef STRINGCARDS_HPP
#define STRINGCARDS_HPP

#include <string>

using namespace std;

// Classe non instanciable

class StringCards{

  private :
    static const string cards ;
    StringCards(){}; // construction impossible
    StringCards(StringCards &){} // copie impossible
    void operator=(StringCards &){} // affectation impossible
    ~StringCards(){} // destruction impossible

  public :
    /*
    Fonction qui renvoie le string d'une carte correspondant à un entier
      0 (carte face cachée)
      1 -> 14 (carreaux)
      15 -> 28 (coeurs)
      29-> 42 (piques)
      43-> 56 (trèfles)
      57 (joker)
     */
    static string french_card(unsigned int);
    static string color(unsigned int);

};

#endif
