#include "Bataille.hpp"


Bataille::Bataille() : Game() {
  all_actions.push_back("Abandonner");
  all_actions.push_back("Poser la carte");
} // Défaut
Bataille::Bataille(const Bataille& g) : Game(g) {}  // Copie

Bataille::~Bataille(){}

Bataille& Bataille::operator=(const Bataille& g) {
  teams = g.teams;
  players = g.players;
  all_actions = (g.all_actions);
  pioche = (g.pioche);
  defausse = (g.defausse);
  joueur_courant = (g.joueur_courant);
  sens = (g.sens);
  individual = (g.individual);
  return (*this);
}

// METHODES ==================================================== //

bool Bataille::joueursConformes() const {
  return players.size()==2 ;
}

void Bataille::distribuer(Deck& d){
  int i = 0;
  while (d.size()>0){
    Card c = d.pop();
    players[i%2]->addCard(c);
    i++;
  }
}

void Bataille::initialisation(){
  Deck32 d = Deck32();
  for (int i=0; i<10; i++) d.shuffle();
  distribuer(d);
}

void Bataille::executerAction(int i){
  switch(i){
    case 0 : // Abandonner
      break;
    case 1 : // Poser carte
      Card c = players[joueur_courant]->takeCard();
      defausse+=c;
      break;
  }
}

bool Bataille::estFini() const{
  return ( (players[0]->getHand().size()==0 && defausse.size()==0 ) ||
  (players[1]->getHand().size()==0 && defausse.size()==0));
}

void Bataille::jouerTour(){
  // La défausse contient un nombre de carte impaire,
  // i.e. le deuxième joueur n'a pas encore joué.
  if (defausse.size()%2==1){
    joueur_courant = (joueur_courant+1)%2;
    return;
  }

  Card carte_courant = defausse[defausse.size()-1];
  Card carte_adverse = defausse[defausse.size()-2];

  int joueur_adverse = (joueur_courant+1)%2;

  if (carte_courant==carte_adverse){ // Bataille
    if (players[joueur_adverse]->getHand().size()>0){
      carte_adverse = players[joueur_adverse]->takeCard();
      defausse+=carte_adverse;
    }
    else return;
    if (players[joueur_courant]->getHand().size()>0){
      carte_courant = players[joueur_courant]->takeCard();
      defausse+=carte_courant;
    }
    else return;
    joueur_courant = joueur_adverse;
    return;
  }

  else if (carte_courant>carte_adverse){
    players[joueur_courant]->addCardsEnd(defausse);
  }

  else {
    players[joueur_adverse]->addCardsEnd(defausse);
  }

  // Changer Joueur
  joueur_courant = (joueur_courant+1)%2;

}

std::string Bataille::classement() const{
  if (players[0]->getHand().size()==0 && defausse.size()==0 )
    return players[1]->getName()+" a gagné.";
  if (players[1]->getHand().size()==0 && defausse.size()==0 )
    return players[0]->getName()+" a gagné.";
  return "Pas encore fini.";
}

std::string Bataille::configuration() const{
  std::string s = "";
  s += "+------------------------------+\n";
  s += "|                              |\n";
  s += "           "+defausse.toString()+"            \n" ;
  s += "|                              |\n";
  s += "+------------------------------+\n";
  s += ""+ (players[joueur_courant])->toString() + "\n";
  return s;
}


std::vector<int> Bataille::actions_possibles() const {
  std::vector<int> ap;
  if (players[joueur_courant]->getHand().size()<=0){
    ap.push_back(0);
  }
  else {
    ap.push_back(1);
  }
  return ap;
}


// AFFICHAGE ==================================================== //

std::ostream& operator<<(std::ostream& out, const Bataille& x){
  out << x.configuration();
  return out;
}
