#include "Belote.hpp"
#include "StringCards.hpp"

Belote::Belote() : Game(false), tour_de_parole(0), choisir_atout(true),
  to_do(-1), atout(-1), attaquants(-1), maitre(-1), indication(-1), lastCoupe(-1),
  tour(0), rebelote(0)
{

  scores.push_back(0);
  scores.push_back(0);
  resultat_final.push_back(0);
  resultat_final.push_back(0);
  all_actions.push_back("Ne pas prendre la carte"); // id all_actions 0
  all_actions.push_back("Prendre la carte"); // id all_actions  1
  all_actions.push_back("Ne pas choisir de couleur"); //id all_actions  2
  all_actions.push_back("Choisir une couleur"); // id all_actions 3
  all_actions.push_back("Choisir ♦"); // id all_actions 4
  all_actions.push_back("Choisir ♥"); // id all_actions 5
  all_actions.push_back("Choisir ♠"); // id all_actions 6
  all_actions.push_back("Choisir ♣"); // id all_actions 7
  all_actions.push_back("Finir tour"); // id all_actions 7

  deck_actions_begin = all_actions.size(); // id all_actions 8
  for (int i=1; i<=32; i++){ // id de all_actions de 9 à 9+32
    all_actions.push_back("Poser la carte n°"+std::to_string(i));
  }

} // Défaut
Belote::Belote(const Belote& g) : Game(g) {}  // Copie

Belote::~Belote(){}

Belote& Belote::operator=(const Belote& g) {
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

bool Belote::joueursConformes() const {
  for (unsigned int i=0; i<teams.size(); i++){
    if (teams[i]->getPlayers().size() != 2){
      return false;
    }
  }
  return (players.size()==4)
    && (teams.size()==2);
}

void Belote::distribuer(Deck& d){
  for (int k=0; k<4; k++){
    for (int i=0; i<5; i++){
      Card c = d.pop();
      players[k]->addCard(c);
    }
  }
  while (d.size()>0){
    Card c = d.pop();
    pioche+=(c);
  }
  Card a = pioche.pop();
  defausse += a;
}

void Belote::distribuer2(){
  for (unsigned int k=0; k<4; k++){
    for (int i=0; i<3; i++){
      if ( !(joueur_courant==k && i==0) ){
        Card c = pioche.pop();
        players[k]->addCard(c);
      }
    }
  }
}

Card Belote::setValue(Card& c){
  if (c.getColor()==atout){
    if (c.getValue()==11){ // valet
      c.setPoint(20);
    }
    else if (c.getValue()==9){ // 9
      c.setPoint(14);
    }
    else if (c.getValue()==1){ // As
      c.setPoint(11);
    }
    else if (c.getValue()==10){ // 10
      c.setPoint(10);
    }
    else if (c.getValue()==14){ // Roi
      c.setPoint(4);
    }
    else if (c.getValue()==13){ // Dame
      c.setPoint(3);
    }
    else if (c.getValue()==8){ // 8
      c.setPoint(0);
    }
    else if (c.getValue()==7){ // 7
      c.setPoint(0);
    }
  }
  else {
    if (c.getValue()==11){ // valet
      c.setPoint(2);
    }
    else if (c.getValue()==9){ // 9
      c.setPoint(0);
    }
    else if (c.getValue()==1){ // As
      c.setPoint(11);
    }
    else if (c.getValue()==10){ // 10
      c.setPoint(10);
    }
    else if (c.getValue()==14){ // Roi
      c.setPoint(4);
    }
    else if (c.getValue()==13){ // Dame
      c.setPoint(3);
    }
    else if (c.getValue()==8){ // 8
      c.setPoint(0);
    }
    else if (c.getValue()==7){ // 7
      c.setPoint(0);
    }
  }
  return c;
}

void Belote::setValues(){
  for (unsigned int i=0; i<defausse.size(); i++){
    Card c = defausse.pop();
    c = setValue(c);
    defausse = c+defausse;
  }

  for (unsigned int i= 0; i<pioche.size(); i++){
    Card c = pioche.pop();
    c = setValue(c);
    pioche = c+pioche;
  }

  for (unsigned int k = 0; k<players.size(); k++){
    for (unsigned int i=0; i<players[k]->getHand().size(); i++){
      Card c = players[k]->takeCard();
      c = setValue(c);
      players[k]->addCardEnd(c);
    }
  }

}

void Belote::initialisation(){
  Deck32 d = Deck32();
  for (int i=0; i<10; i++) d.shuffle();
  distribuer(d);
  joueur_courant = 0;
  indication = 0;
}

void Belote::reinitialiser(){
  to_do=-1;
  atout=-1;
  indication = 0;
  tour_de_parole=0;
  choisir_atout=true;
  for (unsigned int i=0; i<players.size(); i++){
    players[i]->removeAllCard();
  }
  pioche.pop_all();
  defausse.pop_all();
  initialisation();
}


void Belote::comptagePoints(){
  if (scores[attaquants]>=82){
    resultat_final[attaquants] = scores[attaquants];
    resultat_final[(attaquants+1)%2] = scores[(attaquants+1)%2];
  }
  else{
    resultat_final[attaquants]=0;
    resultat_final[(attaquants+1)%2]=162;
  }
}

void Belote::miseAJourPoints(){
  scores[players[maitre]->getIdTeam()]+=defausse.getPoints();
  defausse.pop_all();
  if (tour==8){
    scores[players[maitre]->getIdTeam()]+= 10; // 10 DE DER
    comptagePoints();
  }
}

bool Belote::setRebelote() {
  bool belot = false;
  bool rebelot = false;
  for (unsigned int i=0; i<players[joueur_courant]->getHand().size(); i++){
    Card c = players[joueur_courant]->getHand()[i];
    if (c.getColor()==atout && c.getValue()==14) belot = true;
    else if (c.getColor()==atout && c.getValue()==13) rebelot = true;
  }
  if (belot && rebelot){
    scores[players[joueur_courant]->getIdTeam()]+=20;
    return true;
  }
  return false;
}

void Belote::executerAction(int i){

  if (i>=deck_actions_begin && i<(int)all_actions.size()){ // poser une carte
    Card c = players[joueur_courant]->takeCard(i-deck_actions_begin);
    defausse+=c;
    if ( defausse.getMax() == (int)defausse.size()-1 ){
      maitre = joueur_courant;
    }
    indication = -1;
    return;
  }

  Card c;

  switch(i){

    case 0 : // Ne pas prendre de carte
      break;

    case 1 : // Prendre la carte
      c = defausse.pop();
      players[joueur_courant]->addCardEnd(c);
      atout = c.getColor();
      break;

    case 2 : // ne pas choisir de couleur
      if (joueur_courant==players.size()-1) to_do = 3; // réinitialiser le jeu
      break;

    case 3 : // Choisir une couleur
      to_do = 2; // --> choix de la couleur
      break;

    case 4 : // choisir carreaux
      to_do = -1;
      atout = 0;
      break;

    case 5 : // choisir coeur
      to_do = -1;
      atout = 1;
      break;

    case 6 : // choisir pique
      to_do = -1;
      atout = 2;
      break;

    case 7 : // choisir trefle
      to_do = -1;
      atout = 3;
      break;

    case 8 : // Finir tour
      to_do=4;
      break;

  }
}

bool Belote::estFini() const{
  return ( (players[0]->getHand().size()==0 && defausse.size()==0 ) ||
  (players[1]->getHand().size()==0 && defausse.size()==0));
}


void Belote::jouerTour(){

  // SPECIALES /////////////////////////////////////////////////////////
  if (to_do==2) return; // le joueur doit choisir une couleur
  if (to_do==3){ // aucun atout n'a été choisi
    reinitialiser();
    return;
  }
  if (to_do==4){ // remporter le pli
    to_do = -1;
    miseAJourPoints();
    joueur_courant = maitre;
    maitre = -1;
    lastCoupe = -1;
    tour++;
    return;
  }

  // PRISE /////////////////////////////////////////////////////////////

  if (choisir_atout==true){ // on est en train de choisir l'atout

    if (atout!=-1){ // l'atout vient d'être choisi par executerAction
      choisir_atout = false;
      tour_de_parole = -1;
      if (joueur_courant<2) attaquants = 0;
      else attaquants = 1;
      if (defausse.size()>0){
        Card c = defausse.pop();
        players[joueur_courant]->addCard(c);
      }
      distribuer2();
      joueur_courant=0;
      maitre = -1;
      indication = 1;
      tour++;
      setValues();
      return;
    }

    else { // l'atout n'a pas encore été choisi
      if (joueur_courant==players.size()-1){
        tour_de_parole++;
      }
      incrJoueur(1);
      return;
    }
    return;
  }

  //////////////////////////////////////////////////////////////////////
  incrJoueur(1);
  if (rebelote==0 && setRebelote()) rebelote = 1;
  else if (rebelote==1){
    rebelote = 2;
  }
  // NORMAL ////////////////////////////////////////////////////////////

  if (defausse.size()==0) indication = 1; // OUVERTURE DU PLI
  else if (defausse.size()>0 && defausse.size()<4){
    int color = defausse.getCards()[0].getColor();
    bool flag = false;
    for (unsigned int i=0; i<players[joueur_courant]->getHand().size(); i++){
      if (color == players[joueur_courant]->getHand()[i].getColor()){
        indication = 2; // couleur demandée
        flag = true;
        break;
      }
    }
    if (!flag){ // pas de même couleur
      if ( players[joueur_courant]->getIdTeam() == players[maitre]->getIdTeam() ){
        indication = 3; // maitre du pli est partenaire
        flag = true;
      }

      else { // on teste s'il y en a de la couleur de l'atout
        for (unsigned int i=0; i<players[joueur_courant]->getHand().size(); i++){
          if (atout == players[joueur_courant]->getHand()[i].getColor() && (players[joueur_courant]->getHand()[i]>defausse[lastCoupe] && lastCoupe!=-1)){
            flag = true;
            indication = 4; // on peut SURCOUPER
            lastCoupe = defausse.getCards().size();
            break;

          }
        }
        if (!flag){ // on peut pas surcouper
          for (unsigned int i=0; i<players[joueur_courant]->getHand().size(); i++){
            if (atout == players[joueur_courant]->getHand()[i].getColor() ){
              flag = true;
              indication = 5; // on a des cartes de couleur de l'atout : COUPER
              break;
            }
          }
        }
      }
    }
    if (!flag) indication = 6;
  }


  return;

}

std::string Belote::classement() const{

  std::string s = "";

  s += "+-----------------------------------------------.\n";
  if (scores[attaquants]>=82){
    s+= "| Les attaquants ont rempli leur contrat !\n|\n";
  }
  else{
    s+= "| Les attaquants n'ont pas rempli leur contrat !\n| ( ATT : ";
    s+= std::to_string(scores[attaquants]);
    s+= " points , DEF : ";
    s+= std::to_string(scores[(attaquants+1)%2]);
    s+= " points)\n|\n";
  }

  for (unsigned int i=0; i<resultat_final.size(); i++){
      s += "|  Equipe n°"+std::to_string(i+1)+" : "+std::to_string(resultat_final[i])+" points\n";
  }
  s += "+-----------------------------------------------.\n";
  return s;
}

std::string Belote::indicationToString() const{
  if (indication==0) return "PRISE";
  if (indication==1) return "OUVERTURE DU PLI";
  if (indication==2) return "COULEUR DEMANDÉE";
  if (indication==3) return "L'EQUIPE EST MAÎTRE";
  if (indication==4) return "SURCOUPER À L'ATOUT";
  if (indication==5) return "JOUER UN ATOUT";
  if (indication==6) return "PISSER";

  return "";
}
std::string Belote::configuration() const{

  std::string s = "";
  if(tour==8) s+= "~~~~~ 10 DE DER ~~~~~\n";
  if(rebelote==1) s+= "~~~~~ BELOTE & REBELOTE ~~~~~\n";
  if (atout!=-1) s += "ATOUT : [[ "+(StringCards::color(atout))+" ]]\n";
  if (maitre!=-1) s += "MAITRE DU PLI : "+players[maitre]->getName()+"\n" ;
  if (attaquants!=-1) s += "ATT ("+to_string(scores[attaquants])+" pts) : "+teams[attaquants]->toStringHidden()+"\n";
  if (attaquants!=-1) s += "DEF ("+to_string(scores[(attaquants+1)%2])+" pts) : "+teams[(attaquants+1)%2]->toStringHidden()+"\n";

  s += "+----------------------------------------.\n";
  s += "|         "+indicationToString()+"\n";
  s += "|                              \n";
  s += "|         "+defausse.toString()+"            \n" ;
  s += "|                              \n";
  s += "+----------------------------------------.\n";
  s += ""+ (players[joueur_courant])->toString() + "\n";
  return s;
}

std::vector<int> Belote::actions_possibles() const {

  std::vector<int> ap;

  if (to_do==2){ // le joueur doit choisir une couleur
    ap.push_back(4);
    ap.push_back(5);
    ap.push_back(6);
    ap.push_back(7);
    return ap;
  }

  if (tour_de_parole==0){ // le joueur doit choisir s'il prend l'atout ou pas
    ap.push_back(0);
    ap.push_back(1);
    return ap;
  }

  else if (tour_de_parole==1){ // le joueur doit choisir s'il choisi une couleur ou pas
    ap.push_back(2);
    ap.push_back(3);
    return ap;
  }

  else if (defausse.size()==0){ // on peut poser n'importe quelle carte (le joueur ouvre le pli)

    for (unsigned int i=0; i<players[joueur_courant]->getHand().size(); i++){
      ap.push_back(deck_actions_begin+i);
    }
    return ap;
  }

  else if (defausse.size()>0 && defausse.size()<4){ // le joueur n'a pas ouvert le pli

    int color = defausse.getCards()[0].getColor(); // couleur demandée

    for (unsigned int i=0; i<players[joueur_courant]->getHand().size(); i++){
      if (color == players[joueur_courant]->getHand()[i].getColor()) ap.push_back(deck_actions_begin+i);
    }
    if (!ap.empty()){
      return ap; // le joueur a des cartes de la couleur demandée
    }

    // le joueur n'a aucune carte de la couleur demandée mais le maitre du pli est le partenaire
    if ( players[joueur_courant]->getIdTeam() == players[maitre]->getIdTeam() ){
      for (unsigned int i=0; i<players[joueur_courant]->getHand().size(); i++){
        ap.push_back(deck_actions_begin+i);
      }
    }
    if (!ap.empty()) return ap;

    for (unsigned int i=0; i<players[joueur_courant]->getHand().size(); i++){
      if (atout == players[joueur_courant]->getHand()[i].getColor() && (players[joueur_courant]->getHand()[i]>defausse.getCards()[lastCoupe])  && lastCoupe!=-1 ) ap.push_back(deck_actions_begin+i);
    }
    if (!ap.empty()){
      return ap; // le joueur a des cartes de la couleur de l'atout et peut surcouper
    }

    for (unsigned int i=0; i<players[joueur_courant]->getHand().size(); i++){
      if (atout == players[joueur_courant]->getHand()[i].getColor() ) ap.push_back(deck_actions_begin+i);
    }
    if (!ap.empty()){
      return ap; // le joueur a des cartes de la couleur de l'atout
    }

    if (ap.empty()){ // aucune carte de la couleur de l'atout
      for (unsigned int i=0; i<players[joueur_courant]->getHand().size(); i++){
        ap.push_back(deck_actions_begin+i); // on peut poser n'importe quelle carte
      }
    }

    return ap;

  }

  else if (defausse.size()==4){
    ap.push_back(8);
    return ap;
  }


  return ap;

}


// AFFICHAGE ==================================================== //

std::ostream& operator<<(std::ostream& out, const Belote& x){
  out << x.configuration();
  return out;
}
