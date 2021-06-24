#include "Deck58.hpp"


Deck58::Deck58() :Deck56(){
  //Jeu de 56 + Joker Noir + Joker rouge
  const Card JokerNoir = Card ();
  const Card JokerRouge = Card ();
  (*this)+=JokerNoir+JokerRouge;
}
