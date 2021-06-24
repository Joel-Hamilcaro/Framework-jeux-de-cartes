#include "Briscola.hpp"
#include "StringCards.hpp"


Briscola::Briscola() : Game(false), atout(-1), manche_finie(false)
{
  all_actions.push_back("Finir tour"); // action 0
  all_actions.push_back("Finir manche"); // action 1
  deck_actions_begin = all_actions.size(); // action 1 à 32
  for (int i=1; i<=32; i++){
    all_actions.push_back("Poser la carte n°"+std::to_string(i));
  }
} // Défaut

Briscola::Briscola(const Briscola& g) : Game(g) {}  // Copie

Briscola::~Briscola(){}

Briscola& Briscola::operator=(const Briscola& g) {
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

bool Briscola::joueursConformes() const {
  if (teams.size()==2){
    for (unsigned int i=0; i<teams.size(); i++){
      if (teams[i]->getPlayers().size() != 2){
        return false;
      }
    }
  }
  if (teams.size()>2 || teams.size()<0) return false;
  return (players.size()>=2 || players.size()<=5);
}

void Briscola::distribuer(Deck& d){
  for (unsigned int k=0; k<players.size(); k++){
    for (int i=0; i<3; i++){
      Card c = d.pop();
      players[k]->addCard(c); // MAIN DE 3 CARTES
    }
  }
  while (d.size()>0){
    Card c = d.pop();
    pioche+=(c); // PIOCHE
  }
  Card a = pioche.pop();
  this->la_briscola = a; // BRISCOLA
  atout = a.getColor();
}

void Briscola::tousLesJoueursPiochentUneCarte(){
  for (unsigned int k=0; k<players.size(); k++){
    if (pioche.size()>0){
      Card c = pioche.pop();
      players[k]->addCard(c); // MAIN DE 3 CARTES
    } else if (la_briscola.getValue()!=0){
      players[k]->addCard(la_briscola);
      la_briscola = Card();
    }
  }
}

Card Briscola::setValue(Card& c){
    if (c.getValue()==1){ // As
      c.setPoint(11);
    }
    else if (c.getValue()==3){ // 3
      c.setPoint(10);
    }
    else if (c.getValue()==14){ // Roi
      c.setPoint(4);
    }
    else if (c.getValue()==12){ // Cavalier
      c.setPoint(3);
    }
    else if (c.getValue()==11){ // Valet
      c.setPoint(2);
    }
    else { // Autres cartes
      c.setPoint(0);
    }
    return c;
}

Deck Briscola::setValues(Deck& d){

  for (unsigned int i=0; i<d.size(); i++){
    Card c = d.pop();
    c = setValue(c);
    d = c+d;
  }
  return d;
}

void Briscola::initialisation(){
  if (!joueursConformes()) throw std::invalid_argument("Joueurs non-conformes") ;
  Deck d = DeckItaliennes();
  d = setValues(d);
  for (int i=0; i<10; i++) d.shuffle();
  distribuer(d);
  if (teams.size()>1) individual = false;
  else individual = true;
  for (unsigned int i=0; i<players.size(); i++) scores.push_back(0);
  if (individual){
    for (unsigned int i=0; i<players.size(); i++) resultat_manches.push_back(0);
  }
  else {
    for (unsigned int i=0; i<teams.size(); i++) resultat_manches.push_back(0);
  }
  joueur_courant = 0;

}

int Briscola::indexCarteGagnantTour(){

  int atout_le_plus_grand = -1;
  int non_atout_le_plus_grand = 0;

  for (unsigned int i=0; i<defausse.size(); i++){

    if (defausse[i].getColor()==atout){
      if (atout_le_plus_grand==-1) atout_le_plus_grand = i;
      else if (defausse[i].getValue()==1 || ( (defausse[i].getValue()>defausse[atout_le_plus_grand].getValue()) && (defausse[atout_le_plus_grand].getValue()!=1) ) )  atout_le_plus_grand = i;
    }

    else if (atout_le_plus_grand==-1){ // il n'y a pas d'atout
      if (defausse[0].getColor() == defausse[i].getColor()){
         if (defausse[i].getValue()==1 || ( (defausse[i].getValue()>defausse[non_atout_le_plus_grand].getValue()) && (defausse[non_atout_le_plus_grand].getValue()!=1) ) ) non_atout_le_plus_grand = i;
      }
    }

  }

  if (atout_le_plus_grand!=-1) return atout_le_plus_grand;
  return non_atout_le_plus_grand;

}

int Briscola::indexJoueurGagnantTour(){
  int indexCarteGagnante = indexCarteGagnantTour();
  return (joueur_courant+indexCarteGagnante)%players.size();
}

void Briscola::miseAJourPoints(int gagnantTour){
  scores[gagnantTour]+=defausse.getPoints();
}

void Briscola::executerAction(int i){

  if (i==0){ // finir tour
      int gagnantTour = indexJoueurGagnantTour();
      miseAJourPoints(gagnantTour);
      defausse.pop_all();
      tousLesJoueursPiochentUneCarte();
      joueur_courant = (gagnantTour-1)%players.size(); // par l'incrément jouerTour() le joueur gagnant va jouer en premier
      return;
  }

  if (i==1){ // finir manche
    if (individual){
      for (unsigned int i=0; i<players.size(); i++){
        if (scores[i]>=60) resultat_manches[i]++;
      }
    }
    else {
      for (unsigned int i=0; i<players.size(); i++){
        if (scores[i]>=60) resultat_manches[players[i]->getIdTeam()]++;
      }
    }
  }

  if (i>=deck_actions_begin && i<(int)all_actions.size()){ // Poser une carte
    Card c = players[joueur_courant]->takeCard(i-deck_actions_begin);
    defausse+=c;
    return;
  }
  manche_finie = true;
}

bool Briscola::estFini() const{
  return manche_finie;
}


void Briscola::jouerTour(){
  incrJoueur(1);
  return;
}

std::string Briscola::classement() const{
  std::string s = "";

  s += "+-----------------------------------------------.\n";
  if (individual){
    for (unsigned int i=0; i<resultat_manches.size(); i++){
      s += players[i]->getName()+" : "+std::to_string(resultat_manches[i])+" points\n";
    }
  }

  else {
    for (unsigned int i=0; i<resultat_manches.size(); i++){
      s += "|  Equipe n°"+std::to_string(i+1)+" : "+std::to_string(resultat_manches[i])+" points\n";
    }
  }

  s += "+-----------------------------------------------.\n";
  return s;

}

std::string Briscola::configuration() const{
  std::string s = "";
  s+="PIOCHE : "+pioche.toStringHidden()+"\n";
  if (la_briscola.getValue()!=0) s += "BRISCOLA :"+la_briscola.toString()+"\n";
  if (atout!=-1) s += "ATOUT : [[ "+(StringCards::color(atout))+" ]]\n";
  for (unsigned int i=0; i<players.size(); i++){
    s+= players[i]->toStringHidden();
    s+= std::to_string(scores[i])+" pts\n";
  }
  s += "\n";
  s += "+-------------------------------------.\n";
  s += "|                              \n";
  s += "|         "+defausse.toString()+"            \n" ;
  s += "|                              \n";
  s += "+-------------------------------------.\n";
  s += ""+ (players[joueur_courant])->toString() + "\n";
  return s;
}

std::vector<int> Briscola::actions_possibles() const {
  std::vector<int> ap;
  if (defausse.size()<players.size()){ // on peut poser n'importe quelle carte ("maître du pli")
    for (unsigned int i=0; i<players[joueur_courant]->getHand().size(); i++){
      ap.push_back(deck_actions_begin+i);
    }
    return ap;
  }
  else if (defausse.size()==players.size() && players[joueur_courant]->getHand().size()>0){ // on peut poser n'importe quelle carte ("maître du pli")
    ap.push_back(0); // finir tour
    return ap;
  }

  ap.push_back(1); // finir manche
  return ap;
}


// AFFICHAGE ==================================================== //

std::ostream& operator<<(std::ostream& out, const Briscola& x){
  out << x.configuration();
  return out;
}
