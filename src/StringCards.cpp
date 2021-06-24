#include "StringCards.hpp"
#include <iostream> // cout

const string StringCards::cards = "🂠🃁🃂🃃🃄🃅🃆🃇🃈🃉🃊🃋🃌🃍🃎🂱🂲🂳🂴🂵🂶🂷🂸🂹🂺🂻🂼🂽🂾🂡🂢🂣🂤🂥🂦🂧🂨🂩🂪🂫🂬🂭🂮🃑🃒🃓🃔🃕🃖🃗🃘🃙🃚🃛🃜🃝🃞🃟" ;

string StringCards::french_card(unsigned int i){
  if (i<0 || i>57){

    throw std::invalid_argument("StringCards::french_card() --> "+std::to_string(i)) ;
  }
  return cards.substr((i)*4,4);
}

string StringCards::color(unsigned int i){
  if (i==0) return "♦";
  if (i==1) return "♥";
  if (i==2) return "♠";
  if (i==3) return "♣";
  else return "Indéfini";
}
