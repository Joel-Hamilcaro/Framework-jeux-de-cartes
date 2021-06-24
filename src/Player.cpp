#include "Player.hpp"


int Player::cpt = 1;

Player::Player() : id_team(-1), name("Joueur "+std::to_string(cpt)), hand(Deck()), human(true) {
  cpt++;
} // Défaut
Player::Player(const Player& p) : id_team(-1), name(p.name), hand(p.hand),  human(p.human){}  // Copie
Player::Player(const std::string& n) : id_team(-1) , name(n), hand(Deck()), human(true) {}
Player::Player(const std::string& n, const bool b) : id_team(-1), name(n), human(b) {}
Player::Player(const std::string& n, const Deck& h, const bool b) : id_team(-1), name(n), hand(h), human(b) {}
Player::Player(const std::string& n, const bool b, const int id) : id_team(id), name(n), human(b) {}

Player::~Player(){}

Player& Player::operator=(const Player& x) {
  name = x.getName();
  id_team = x.getIdTeam();
  hand = x.getHand();
  return (*this);
}

// REPRESENTATION TEXTUELLE ===================================== //

std::string Player::toString() const{
  std::string s = " " + name;
  if (!human) s += " (IA) ";
  if (id_team!=-1) s += " (Equipe n°"+std::to_string(id_team+1)+")" ;
  s += " " + hand.toString() + " " ;
  return s;
}

std::string Player::toStringHidden() const{
  std::string s = " " + name;
  if (!human) s += " (IA) ";
  s += " " + hand.toStringHidden() + " " ;
  return s;
}

// AFFICHAGE ===================================================== //

std::ostream& operator<<(std::ostream& out, const Player& x){
  out << x.toString();
  return out;
}

// METHODES ==================================================== //

void Player::shuffleHand(){
  hand.shuffle();
}

void Player::sortHand(){
  hand.sort();
}

int Player::getPoints(){
  return hand.getPoints();
}

void Player::addCard(Card& x){
  hand += x;
}

void Player::addCardEnd(Card& x){
  hand=x+hand;
}

void Player::addCards(Deck& x){
  hand+=x;
  x.pop_all();
}

void Player::addCardsEnd(Deck& x){
  hand=x+hand;
  x.pop_all();
}

Card Player::takeCard(int i){
  Card c = hand.pop(i);
  return c;
}

Card Player::takeCard(){
  return hand.pop();
}

void Player::removeAllCard(){
  return hand.pop_all();
}


void Player::putCard(int i, Deck& x){
  Card c = hand.pop(i);
  x+=c;
}

void Player::putCardEnd(int i, Deck& x){
  Card c = hand.pop(i);
  x=c+x;
}

// ACCESSEURS =================================================== //

std::string Player::getName() const{
  return name;
}

int Player::getIdTeam() const {
  return id_team;
}

Deck Player::getHand() const{
  return hand;
}

bool Player::isHuman() const{
  return human;
}

void Player::setIdTeam(int x){
  id_team = x;
}
