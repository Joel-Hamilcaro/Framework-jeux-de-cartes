#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string> 

class Card {

  private :

    // CHAMPS ======================================================= //

    int color;
    /*
      0 : Carreaux
      1 : Coeur
      2 : Pique
      3 : Trèfle
      4 : atouts
    */

    int value;
    /*
      0 : Joker
      1 : As
      2...10 : 2...10
      11 : Valet
      12 : Cavalier
      13 : Dame
      14 : Roi
    */

    int point;
    /*
      Valeur de la carte en nombre de point
      (dépend du jeu)
    */

  public :

    // CONSTRUCTEURS ================================================ //

    Card() ; // Défaut (Joker)
    Card(const Card&); // Copie
    Card(int,int,int); // Initialisation manuelle (color,value,point)
    Card(int,int); // Initialisation manuelle (color,value, point (par défaut))

    // DESTRUCTEUR ================================================== //

    virtual ~Card();

    // AFFECTATION ================================================== //

    Card& operator=(const Card& x);

    // COMPARAISON ================================================== //

    bool operator<(const Card& x); // this moins forte que x
    bool operator>(const Card& x); // this plus forte que x
    bool operator==(const Card& x); // this aussi forte que x
    bool operator>=(const Card& x); // this au moins aussi forte que x
    bool operator<=(const Card& x); // this au plus aussi forte que x
    bool operator!=(const Card& x); // this et x n'ont pas la même force

    // REPRESENTATION TEXTUELLE ===================================== //

    std::string toString() const;
    std::string toStringHidden() const;

    // AFFICHAGE ==================================================== //

    friend std::ostream& operator<<(std::ostream& out, const Card& x) ;

    // ACCESSEURS =================================================== //

    int getColor() const ;
    int getValue() const ;
    int getPoint() const ;

    // MUTATEURS =================================================== //
    void setPoint(int);

};

#endif

/*
  POUR LE RAPPORT :
  Classe Carte.
  Les 3 entiers représentent respectivement sa couleur, sa valeur et sa force
  Exemple :
  La couleur (0,1,2,3) ~ (carreaux,coeur,pique,trèfle) ~ (Baton,Coupe,Denier,Epee)
  La valeur (1,2,3...14) ~ (As,2,3,...,Valet,Cavalier,Dame,Roi)
  Le point représente la force de la carte (va dépendre du jeu).
  Par exemple dans la plupart des jeux, l'As est plus fort de que Roi.
  Dans ce cas, la valeur de 'point' sera supérieur pour l'As.
*/
