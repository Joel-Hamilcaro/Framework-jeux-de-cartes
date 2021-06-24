#include "Deck57.hpp"


Deck57::Deck57() :Deck56(){
  //Jeu de 56 + Joker
  const Card Joker = Card ();
  (*this)+=Joker;
}
