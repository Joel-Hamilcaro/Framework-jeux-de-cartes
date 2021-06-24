#include "Deck53.hpp"


Deck53::Deck53() :Deck52(){
  //{ As 2 3 4 5 6 7 8 9 10 Valet Dame Roi Joker} * { Coeur Carreaux Trèfle Pique }
  const Card Joker = Card ();
  (*this)+=Joker;
}
