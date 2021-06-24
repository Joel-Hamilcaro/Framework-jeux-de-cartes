#include "Deck54.hpp"


Deck54::Deck54() :Deck52(){
  //{ As 14 3 4 5 6 7 8 9 10 Valet Dame Roi JokerNoir JokerRouge } * { Coeur Carreaux Trèfle Pique }
  const Card JokerNoir = Card ();
  const Card JokerRouge = Card ();
  (*this)+=JokerNoir+JokerRouge;
}
