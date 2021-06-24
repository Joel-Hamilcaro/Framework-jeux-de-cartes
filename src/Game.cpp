#include "Game.hpp"


Game::Game() : pioche(Deck()), defausse(Deck()), joueur_courant(0), sens(true), individual(true) {} // Défaut
Game::Game(bool individual) : pioche(Deck()), defausse(Deck()), joueur_courant(0), sens(true), individual(individual) {}
Game::Game(const Game& g) :
  teams(g.teams),
  players(g.players),
  all_actions(g.all_actions),
  pioche(g.pioche),
  defausse(g.defausse),
  joueur_courant(g.joueur_courant),
  sens(g.sens),
  individual(g.individual)
  {}  // Copie


Game::~Game(){
  deleteTeams(); // Rq : delete team =/=> delete players
  deletePlayers();
}

Game& Game::operator=(const Game& g) {
  teams = g.teams;
  players = (g.players);
  all_actions = (g.all_actions);
  pioche = (g.pioche);
  defausse = (g.defausse);
  joueur_courant = (g.joueur_courant);
  sens = (g.sens);
  individual = (g.individual);
  return (*this);
}

// METHODES ==================================================== //

void Game::addTeam(Team* t){
  teams.push_back(t);
}

void Game::addPlayer(Player* p){
  players.push_back(p);
}

void Game::changerJoueur(int i){
  joueur_courant = i;
}

void Game::incrJoueur(int i){
  joueur_courant = (joueur_courant+i)%players.size();
}

void Game::changerSens(){
  sens = !sens;
}

Card Game::piocher(){
  return pioche.pop();
}

void Game::defausser(const Card& x){
  defausse+=x;
}

std::string Game::teamsToString() const{
  if (teams.size()==0){
    std::string s = "";
    s += "+-------------------------------------+\n";
    s += "|            Pas d'équipe             |\n";
    s += "+-------------------------------------+\n";
    return s;
  }
  std::string s = "+----------------+---------------------------------\n";
  for (unsigned int i=0; i<teams.size(); i++){
    s += "|   Equipe n°" ;
    s += std::to_string(i+1) ;
    s += "   |" ;
    s += (*teams[i]).toString() ;
    s += "\n" ;
    s += "+----------------+---------------------------------\n";
  }
  return s;
}

bool Game::same_team(Player* p1, Player* p2) const {
  for (unsigned int i=0; i<teams.size(); i++){
    if (teams[i]->same_team(p1,p2)) return true;
  }
  return false;
}

// ACCESSEURS =================================================== //

std::vector<Team*> Game::getTeams() const{
  return teams;
}
std::vector<Player*> Game::getPlayers() const{
  return players;
}
Deck Game::getPioche() const{
  return pioche;
}
Deck Game::getDefausse() const{
  return defausse;
}
int Game::getJoueurCourant() const{
  return joueur_courant;
}
bool Game::getSens() const{
  return sens;
}

bool Game::isIndividual() const{
  return individual;
}

bool Game::noHuman() const{
  bool b = true;
  for(unsigned int i=0; i<players.size(); i++){
    if(players[i]->isHuman()){
      b = false;
      break;
    }
  }
  return b;
}



std::vector<std::string> Game::getAllActions() const{
  return all_actions;
}


// MUTATEURS ==================================================== //

void Game::deletePlayers(){
  while(!players.empty()){
    delete players.back();
    players.pop_back();
  }
}

void Game::deleteTeams(){
  while(!teams.empty()){
    delete teams.back();
    teams.pop_back();
  }
}
