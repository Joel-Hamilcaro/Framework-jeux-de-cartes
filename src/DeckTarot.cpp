#include "DeckTarot.hpp"

DeckTarot::DeckTarot():Deck56(){
  sort();
  for (int i=0; i<36; i++){ // Cartes 2 à 10
    cards[i].setPoint(1);
  }
  for (int i=36; i<40; i++){ // Valets
    cards[i].setPoint(2);
  }
  for (int i=40; i<44; i++){ // Cavalier
    cards[i].setPoint(3);
  }
  for (int i=44; i<48; i++){ // Dame
    cards[i].setPoint(4);
  }
  for (int i=48; i<52; i++){ // Roi
    cards[i].setPoint(5);
  }
  for (int i=52; i<56; i++){ // As
    cards[i].setPoint(1);
  }

  for (int i=1;i<22;i++){
    if (i==1 || i == 21){
      const Card atouts = Card(4,i,5);
      (*this)+=atouts;
    }
    else {
      const Card atouts = Card(4,i,1);
      (*this)+=atouts;
    }
  }
  const Card excuse = Card(0,0,5);
  (*this)+= excuse;
}
