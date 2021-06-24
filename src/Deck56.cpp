#include "Deck56.hpp"


Deck56::Deck56() :Deck52(){
  //{ As 2 3 4 5 6 7 8 9 10 Valet Cavalier Dame Roi } * { Coeur Carreaux Trèfle Pique }
  const Card CavalierCoeur = Card (0,12);
  const Card CavalierCarreaux = Card (1,12);
  const Card CavalierTrefile = Card (2,12);
  const Card CavalierPique = Card (3,12);
  (*this)+=CavalierCoeur+CavalierCarreaux+CavalierTrefile+CavalierPique;
}
