#include "Deck.hpp"
#include <random> // std::default_random_engine
#include <chrono> // std::chrono::system_clock
#include <algorithm> // shuffle

// CONSTRUCTEURS ================================================ //

Deck::Deck() {} // Défaut

Deck::Deck(const Deck& x) : cards(x.cards) { // Copie
}

// DESTRUCTEUR ================================================== //

Deck::~Deck(){
  pop_all();
}

// AFFECTATION ================================================== //

Deck& Deck::operator=(const Deck& x){
  if (&x == this) return *this;
  pop_all();
  for (unsigned int i=0; i<x.getCards().size(); i++){
    this->cards.push_back(x.getCards()[i]);
  }
  return *this;
}

// METHODES ===================================================== //

Deck& Deck::operator+(const Card& x){
  this->cards.push_back(x);
  return *this;
}


Deck& Deck::operator+=(const Card& x){
  this->cards.push_back(x);
  return *this;
}

Deck& Deck::operator+(const Deck& x){
  for (unsigned int i=0; i<x.getCards().size(); i++){
    this->cards.push_back(x.getCards()[i]);
  }
  return *this;
}


Deck& Deck::operator+=(const Deck& x){
  for (unsigned int i=0; i<x.getCards().size(); i++){
    this->cards.push_back(x.getCards()[i]);
  }
  return *this;
}

Card& Deck::operator[](int i){
  return this->cards[i];
}


void Deck::pop_all(){
  while(!cards.empty()){
    cards.pop_back();
  }
}

void Deck::sort(){
  std::sort(this->cards.begin(),this->cards.end());
}

void Deck::shuffle(){
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::shuffle(this->cards.begin(),this->cards.end(),std::default_random_engine(seed));
}

Card Deck::pop(unsigned int i){
  Card x = (this->cards)[i];
  if (i==this->cards.size()-1){
    this->cards.pop_back();
    return x;
  }
  this->cards.erase(this->cards.begin()+i);
  return x;
}

Card Deck::pop(){
  Card x = (this->cards)[cards.size()-1];
  this->cards.pop_back();
  return x;
}

int Deck::getPoints(){
  int score = 0;
  for (unsigned int i=0; i<cards.size(); i++){
    score += cards[i].getPoint();
  }
  return score;
}

int Deck::getMax() {
  int max = 0;
  for (unsigned int i=0; i<cards.size(); i++){
    if (cards[i]>cards[max]) max = i;
  }
  return max;
}

// REPRESENTATION TEXTUELLE ===================================== //

std::string Deck::toString() const{
  if (this->cards.size()==0) return "";
  std::string s = "";
  for (unsigned int i=0; i<cards.size(); i++){
    s = s+cards[i].toString()+" " ;
  }
  return s;
}


std::string Deck::toStringHidden() const{
  if (this->cards.size()==0) return "";
  std::string s = "";
  for (unsigned int i=0; i<cards.size(); i++){
    s = s+cards[i].toStringHidden()+" " ;
  }
  return s;
}

// AFFICHAGE ==================================================== //

std::ostream& operator<<(std::ostream& out, const Deck& x){
  out << x.toString();
  return out;
}

// ACCESSEURS =================================================== //

const std::vector<Card>& Deck::getCards() const{
  return this->cards;
}

unsigned int Deck::size() const{
  return this->cards.size();
}

// FONCTION NORMALE (pas méthode de classe) ========================= //

Deck operator+(const Card& x, const Card& y){
  Deck d = Deck();
  d+=x;
  d+=y;
  return d;
}

Deck operator+(const Card& x, const Deck& y){
  Deck d = Deck();
  d+=x;
  d+=y;
  return d;
}
