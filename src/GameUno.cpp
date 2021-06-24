#include "GameUno.hpp"
#include <iostream>
#include<string>

GameUno::GameUno() : Game(true) {
  todo =-1;

  for (int i=0;i<108;i++){
    all_actions.push_back("Choisir la carte " + std::to_string(i));
  }
  all_actions.push_back("Piocher et passer le tour"); // 108
  all_actions.push_back("Poser la carte de meme valeur"); // 109
  all_actions.push_back("Poser la carte de meme couleur"); // 110
  all_actions.push_back("Poser la carte plus2");
  all_actions.push_back("Poser la carte plus4");
  all_actions.push_back("Poser la carte Joker");
  all_actions.push_back("Choisir la couleur");
  all_actions.push_back("Choisir le carreau");
  all_actions.push_back("Choisrr le coeur");
  all_actions.push_back("Choisir la pique");
  all_actions.push_back("Choisir le trèfle");



} // Défaut
GameUno::GameUno(const GameUno& g) : Game(g) {}  // Copie

GameUno::~GameUno(){}

GameUno& GameUno::operator=(const GameUno& g) {
  teams = g.teams;
  players = g.players;
  all_actions = (g.all_actions);
  pioche = (g.pioche);
  defausse = (g.defausse);
  joueur_courant = (g.joueur_courant);
  sens = (g.sens);
  individual = (g.individual);
  todo = (g.todo);
  carte_courant = (g.carte_courant);
  return (*this);
}

// METHODES ==================================================== //

bool GameUno::joueursConformes() const {
  return (players.size()>=2 && players.size()<=10) ;
}


void GameUno::distribuer(Deck& d){
  unsigned int i = 0;
  while (i<players.size()*7){
    Card c = d.pop();
    players[i%players.size()]->addCard(c);
    i++;
  }
  Card c = d.pop();
  carte_courant = c;
  defausse += c;
  pioche = Deck (d);

}

void GameUno::initialisation(){
  DeckUno d = DeckUno();
  for (int i=0; i<10; i++) d.shuffle();
  distribuer(d);
  joueur_courant=0;
}

void GameUno::executerAction(int i){
  if (players[joueur_courant]->getHand().size()==0){
    return;
  }

  if (i>=0 && i<108){
    Card pose = players[joueur_courant]->getHand()[i];
    defausse += pose;
    carte_courant = Card(pose);
    players[joueur_courant]->takeCard(i);
    int suivant =(joueur_courant+1)%players.size();
    if (!sens) suivant =(joueur_courant-1)%players.size();
    if (carte_courant.getValue()==10 ){
      for (int i=0;i<2;i++){
        //verifer si pioche est vide;
        if (pioche.size()==0){
          pioche = Deck(defausse);
          defausse.pop_all();
        }
        if (pioche.size()!=0){
          Card c = pioche [pioche.size()-1];
          players[suivant]->addCard(c);
          pioche.pop();
        }


      }
    }
    else if (carte_courant.getValue()==14 ){
      for (int i=0;i<4;i++){
        if (pioche.size()==0){
          pioche = Deck(defausse);
          defausse.pop_all();
        }
        if (pioche.size()!=0){
          Card c = pioche [pioche.size()-1];
          players[suivant]->addCard(c);
          pioche.pop();
        }
      }
    }

    if (carte_courant.getValue()==14||carte_courant.getValue()==13){
      i=114;
    }else{
      todo=-1;
    }

  }


  switch(i){
    case 108:{//rein faire , passer le joueur suivante
      if (pioche.size()==0){
        pioche = Deck(defausse);
        defausse.pop_all();
      }
      if (pioche.size()!=0){
        Card c = pioche [pioche.size()-1];
        players[joueur_courant]->addCard(c);
        pioche.pop();
      }

      todo=-1;
    }break;

    case 109:{// valeur
      todo=1;
    }break;

    case 110:{//couleur
    todo=2;
    }break;

    case 111:{//plus2
      todo=3;
    }break;

    case 112:{//plus4
    todo=4;
    }break;

    case 113: {// joker a faire
    todo=5;
    } break;

    case 114:{// choisir color
    todo=6;
    } break;

    case 115: {// careaux
      int vle = carte_courant.getValue();
      carte_courant = Card (0,vle);
      todo  = -1;
    } break;

    case 116: {// Coeur
      int vle =carte_courant.getValue();
      carte_courant = Card (1,vle);
      todo  = -1;
    } break;

    case 117: {// pique
      int vle =carte_courant.getValue();
      carte_courant = Card (2,vle);
      todo  = -1;
    } break;

    case 118: {// trefle
      int vle =carte_courant.getValue();
      carte_courant = Card (3,vle);
      todo  = -1;
    } break;
  }
}

bool GameUno::estFini() const{
  for (unsigned int i=0;i<players.size();i++){
    if (players[i]->getHand().size()==0||(pioche.size()==0&&defausse.size()==0)){
      return true;
    }
  }
  return false;
}

void GameUno::jouerTour(){

  if (todo!=-1){
    return ;
  }
    if (sens){
      if (carte_courant.getValue()==11){
        unsigned int js =joueur_courant-1;
        while(js<0){
          js+=players.size();
        }
        joueur_courant=(js)%players.size();
        //si il y a une carte inversion , alos le sens modifie
        //int clr= carte_courant.getColor();
        //carte_courant = Card (clr,-1);
        sens =false;
        return;
      } else if (carte_courant.getValue()==12 ){
        joueur_courant=(joueur_courant+2)%players.size();
        return;
      }else{
        joueur_courant=(joueur_courant+1)%players.size();
        return ;
      }

    }else{
      if (carte_courant.getValue()==11 ){
        joueur_courant=(joueur_courant+1)%players.size();
        sens=true;
        return;
      } else if (carte_courant.getValue()==12 ){
        unsigned int js =joueur_courant-2;
        while(js<0){
          js+=players.size();
        }
        joueur_courant=(js)%players.size();
        //int clr= carte_courant.getColor();
        //carte_courant = Card (clr,-1);
        return;
      }else{
        unsigned int js =joueur_courant-1;
        while(js<0){
          js+=players.size();
        }
        joueur_courant=(js)%players.size();
        //int clr= carte_courant.getColor();
        //carte_courant = Card (clr,-1);
        return;
      }

    }
}

std::string GameUno::classement() const {

  for (unsigned int i =0 ;i<players.size();i++){
    if (players[i]->getHand().size()==0  )
      return players[i]->getName()+" a gagné.";
  }

  int score [players.size()];
  int max =0;
  for (unsigned int i=0;i<players.size();i++){
    int somme = 0;
    for ( unsigned int j =0 ;j<(players[i]->getHand().size());j++){
      int vle= players[i]->getHand()[j].getValue();
      somme += vle ;

      if (vle ==10 ){
        somme += 10;
      }
      if (vle ==11 ){
        somme += 9;
      }
      if (vle ==12 ){
        somme += 8;
      }
      if (vle ==13 ){//50
        somme += 37;
      }
      if (vle ==14 ){//50
        somme += 36;
      }
    }
    if (somme >=max){
      max=somme;
    }
    score[i]=somme;

  }

  std::string rst="";
  for (unsigned int i=0;i<players.size();i++){

    if (score[i]==max){
      rst+= players[i]->getName()+" a gagné.";
    }

  }
  return rst;



}

std::string GameUno::configuration() const{

  std::string s = "\n\n================================================\n";
  for (unsigned int i =0; i<players.size();i++){
    if ( i != joueur_courant){
      s += ""+ (players[i])->toStringHidden() + "\n";
    }
  }
  s += "PIOCHE : Card*"+ std::to_string(pioche.size()) + "\n";
  //s += "PIOCHE : "+ pioche.toStringHidden() + "\n";
  s += "+------------------------------+\n";
  s += "|                              |\n";
  if (defausse.size()==0){
    s += "                                \n" ;
  }else{
    if (carte_courant.getValue()<0){
      if (carte_courant.getColor()==0){
        s += "           Carreaux            \n" ;
      }else if (carte_courant.getColor()==1){
        s += "           Coeur            \n" ;
      }else if (carte_courant.getColor()==2){
        s += "           Pique           \n" ;
      }else if (carte_courant.getColor()==3){
        s += "           Trefle           \n" ;
      }
    }else{
      s += "           "+carte_courant.toString()+"            \n" ;
    }
  }
  s += "|                              |\n";
  s += "+------------------------------+\n";
  s += ""+ (players[joueur_courant])->toString() + "\n";
  return s;
}


std::vector<int> GameUno::actions_possibles() const {
  std::vector<int> ap;

  if (todo==1){
    for ( unsigned int i =0 ;i<(players[joueur_courant]->getHand().size());i++){
      if (players[joueur_courant]->getHand()[i].getValue()==carte_courant.getValue()){
        ap.push_back(i);
      }
    }
  }
  if (todo==2){
    for ( unsigned int i =0 ;i<(players[joueur_courant]->getHand().size());i++){
      if (players[joueur_courant]->getHand()[i].getColor()==carte_courant.getColor()){
        ap.push_back(i);
      }
    }
  }
  if (todo==3){

    for (unsigned  int i =0 ;i<(players[joueur_courant]->getHand().size());i++){
      if (players[joueur_courant]->getHand()[i].getValue()==10 && players[joueur_courant]->getHand()[i].getColor()==carte_courant.getColor()){
        ap.push_back(i);
      }
    }

  }
  if (todo==4){
    for (unsigned  int i =0 ;i<(players[joueur_courant]->getHand().size());i++){
      if (players[joueur_courant]->getHand()[i].getValue()==14){
            ap.push_back(i);
      }
    }
  }
  if (todo==5){
    for (unsigned  int i =0 ;i<(players[joueur_courant]->getHand().size());i++){
      if (players[joueur_courant]->getHand()[i].getValue()==13){
            ap.push_back(i);
      }
    }
  }
  //====
  if (todo==6){
    ap.push_back(115);
    ap.push_back(116);
    ap.push_back(117);
    ap.push_back(118);
  }


  if (todo==-1){

    for (unsigned  int i =0 ;i<players[joueur_courant]->getHand().size();i++){
      int vle = players[joueur_courant]->getHand()[i].getValue();
      if (vle==carte_courant.getValue() && vle!=10 && vle!=11 && vle!=12 && vle!=13 && vle!=14){
        ap.push_back(109); // poser carte même valeur
        break;
      }
    }
    for ( unsigned int i =0 ;i<players[joueur_courant]->getHand().size();i++){
      if (players[joueur_courant]->getHand()[i].getColor()==carte_courant.getColor()){
        ap.push_back(110); // carte meme color
        break;
      }
    }

    //si il exite le carte plus2, push back 3,mais il faut le meme couleur
    for (unsigned  int i =0 ;i<players[joueur_courant]->getHand().size();i++){
      if (players[joueur_courant]->getHand()[i].getValue()==10 && players[joueur_courant]->getHand()[i].getColor()==carte_courant.getColor()){
        ap.push_back(111); // poser +2
        break;
      }
    }
    //si il exite la carte plus4 ,push back 112
    for ( unsigned int i =0 ;i<players[joueur_courant]->getHand().size();i++){
      if (players[joueur_courant]->getHand()[i].getValue()==14){
        ap.push_back(112); // poser +4
        break;
      }
    }

    // si il exite la carte joker,push back 113
    for (unsigned  int i =0 ;i<players[joueur_courant]->getHand().size();i++){
      if (players[joueur_courant]->getHand()[i].getValue()==13){
        ap.push_back(113); // Joker
        break;
      }
    }
  }

  if (ap.empty()) ap.push_back(108);
  return ap;
}
// AFFICHAGE ==================================================== //

std::ostream& operator<<(std::ostream& out,  const GameUno& x){
  out << x.configuration();
  return out;
}

// ACCESSEURS =================================================== //
