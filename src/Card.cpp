#include "Card.hpp"
#include "StringCards.hpp"

// CONSTRUCTEURS ================================================ //

Card::Card() : color(0), value(0), point(16) {
} // Défaut

Card::Card(const Card& x) : color(x.getColor()) , value(x.getValue()) , point(x.getPoint()) { // Copie
}

Card::Card(int c, int v, int p) : color(c), value(v), point(p) {
}

Card::Card(int c, int v) : color(c), value(v) {
  if (v==0) this->point=16;
  else if (v==1) this->point=15;
  else this->point=v;
}

// DESTRUCTEUR ================================================== //

Card::~Card(){}

// AFFECTATION ================================================== //

Card& Card::operator=(const Card& x){
  this->value = x.getValue();
  this->color = x.getColor();
  this->point = x.getPoint();
  return (*this);
}

// COMPARAISON ================================================== //

bool Card::operator<(const Card& x){
  return this->point < x.getPoint();
}
bool Card::operator>(const Card& x){
  return this->point > x.getPoint();
}
bool Card::operator==(const Card& x){
  return this->point == x.getPoint();
}
bool Card::operator>=(const Card& x){
  return this->point >= x.getPoint();
}
bool Card::operator<=(const Card& x){
  return this->point <= x.getPoint();
}
bool Card::operator!=(const Card& x){
  return this->point != x.getPoint();
}

// REPRESENTATION TEXTUELLE ===================================== //

std::string Card::toString() const{
  std::string s = "";
  if (this->color == 4){
    return s+"["+std::to_string(this->value)+"]"+"";
  }

  if (this->value==0){
    return s+StringCards::french_card(57)+"";
  }

  int i = this->color*14+this->value;
  return s+StringCards::french_card(i)+"";
}

std::string Card::toStringHidden() const{
  return StringCards::french_card(0);
}

// AFFICHAGE ==================================================== //

std::ostream& operator<<(std::ostream& out, const Card& x){
  out << x.toString();
  return out;
}

// ACCESSEURS =================================================== //

int Card::getColor() const{
  return this->color;
}

int Card::getValue() const{
  return this->value;
}

int Card::getPoint() const{
  return this->point;
}

void Card::setPoint(int x){
  this->point = x;
}
