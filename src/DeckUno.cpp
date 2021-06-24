#include "DeckUno.hpp"

DeckUno::DeckUno():Deck(){
  //{ (0)*1 (1 2 3 4 5 6 7 8 9)*2 (+2)*2 (inversion)*2 (passer)*2 (joker)*1 (+4)*1 } * { bleu vert rouge jaune }
  //i pour couleur
  for (int i =0;i<4;i++){
    //carte 0
    const Card zero = Card (i,0);
    (*this)+= zero;

    // 1 2 3 4 5 6 7 8 9
    for (int j=1;j<10;j++){
      const Card carte0 = Card (i,j);
      const Card carte1 = Card (i,j);
      (*this)+= carte0+carte1;
    }

    //plus2  mettre valeur 10
    const Card plus2 = Card (i,10);
    const Card plus2prime = Card (i,10);
    (*this)+= plus2 +plus2prime;

    //inversion (mettre valeur  11)
    const Card inversion0 = Card (i,11);
    const Card inversion1 = Card (i,11);
    (*this)+= inversion0 +inversion1;

    //passer (mettre valeur 12)
    const Card passer0 = Card (i,12);
    const Card passer1 = Card (i,12);
    (*this)+= passer0 +passer1;

    //joker (mettre valeur 13)
    const Card joker = Card (i,13);
    (*this)+=joker;

    //+4 (mettre valeur 14)
    const Card plus4 = Card (i,14);
    (*this)+= plus4;
  }
}
