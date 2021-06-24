#include "Team.hpp"


int Team::cpt = -1;

Team::Team() : id(++cpt) {} // Défaut
Team::Team(const Team& t) : id(t.id), players(t.players) {}  // Copie

Team::~Team(){
}

Team& Team::operator=(const Team& x) {
  id = x.getId();
  players = x.getPlayers();
  return (*this);
}

// METHODES ===================================================== //

void Team::addPlayer(Player* p){
  players.push_back(p);
}

std::string Team::toString() const{
  std::string s = "";
  for (unsigned int i=0; i<players.size(); i++){
    s += (*players[i]).toString() ;
    s += "\t";
  }
  return s;
}

std::string Team::toStringHidden() const{
  std::string s = "";
  for (unsigned int i=0; i<players.size(); i++){
    s += (*players[i]).toStringHidden() ;
    s += "\t";
  }
  return s;
}

bool Team::contains(Player* p) const{
  for (unsigned int i=0; i<players.size(); i++){
    if (p==players[i]) return true;
  }
  return false;
}

bool Team::same_team(Player* p1, Player* p2) const{
  return contains(p1) && contains(p2);
}

// AFFICHAGE ===================================================== //

std::ostream& operator<<(std::ostream& out, const Team& x){
  out << x.toString();
  return out;
}

// METHODES ==================================================== //

int Team::getPoints(){
  int score = 0;
  for (unsigned int i=0; i<players.size(); i++){
    score += players[i]->getPoints();
  }
  return score;
}


// ACCESSEURS =================================================== //

int Team::getId() const {
  return id;
}

std::vector<Player*> Team::getPlayers() const{
  return players;
}
