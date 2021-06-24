#include "Game8Americain.hpp"
#include <iostream>
#include<string>

Game8Americain::Game8Americain() : Game(true) {
  todo =-1;

  for (int i=0;i<108;i++){
    all_actions.push_back("Choisir la carte " + std::to_string(i));
  }
  all_actions.push_back("Piocher et passer le tour");
  all_actions.push_back("Poser la carte de meme valeur");
  all_actions.push_back("Poser la carte de meme couleur");
  all_actions.push_back("Poser la carte 2(plus2)");
  all_actions.push_back("Poser la carte Joker(plus4)");
  all_actions.push_back("Poser la carte 8");
  all_actions.push_back("Choisir la couleur");
  all_actions.push_back("Choisir le carreau");
  all_actions.push_back("Choisrr le coeur");
  all_actions.push_back("Choisir la pique");
  all_actions.push_back("Choisir le trafle");



} // Défaut
Game8Americain::Game8Americain(const Game8Americain& g) : Game(g) {}  // Copie

Game8Americain::~Game8Americain(){}

Game8Americain& Game8Americain::operator=(const Game8Americain& g) {
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
//a modifier

bool Game8Americain::joueursConformes() const {
  return (players.size()>=2 && players.size()<=5) ;
}


void Game8Americain::distribuer(Deck& d){
  unsigned int i = 0;
  while (i<players.size()*7){
    Card c = d.pop();
    players[i%players.size()]->addCard(c);
    i++;
  }
  Card c = d.pop();
  carte_courant = Card(c);
  defausse += c;
  pioche = Deck (d);

}

void Game8Americain::initialisation(){
  Deck54 d = Deck54();
  Deck54 d2 = Deck54();
  d+=d2;
  for (int i=0; i<10; i++) d.shuffle();
  distribuer(d);
  joueur_courant=0;
}

void Game8Americain::executerAction(int i){
  if (players[joueur_courant]->getHand().size()==0){
    return;
  }

  if (i>=0 && i<108){
    //poser la cartes
    Card pose = players[joueur_courant]->getHand()[i];
    defausse += pose;
    carte_courant = Card(pose);
    players[joueur_courant]->takeCard(i);
    int suivant =(joueur_courant+1)%players.size();
    if (!sens) suivant =(joueur_courant-1)%players.size();
    if (carte_courant.getValue()==2 ){
      for (int i=0;i<2;i++){
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
    else if (carte_courant.getValue()==0 ){
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

    if (carte_courant.getValue()==0||carte_courant.getValue()==8){
      i=114;
    }else{
      todo=-1;
    }

  }


  switch(i){
    case 108:{//piocher , passer le joueur suivante
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
    case 109:{//poser meme valeur
    todo=1;
    }break;
    case 110:{//poser meme couleur
    todo=2;
    }break;
    case 111:{//poser plus2
      todo=3;
    }break;
    case 112:{//poser plus4
    todo=4;
    }break;

    case 113: {//poser joker
    todo=5;
    } break;

    case 114:{// choisir color
    todo=6;
    } break;
    case 115: {// careaux
      int vle =carte_courant.getValue();
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

bool Game8Americain::estFini() const{
  for (unsigned int i=0;i<players.size();i++){
    if (players[i]->getHand().size()==0||(pioche.size()==0&&defausse.size()==0)){
      return true;
    }
  }
  return false;
}

void Game8Americain::jouerTour(){

  if (todo!=-1){
    return ;
  }

    if (sens){
      if (carte_courant.getValue()==1){

        unsigned int js =joueur_courant-1;
        while(js<0){
          js+=players.size();
        }
        joueur_courant=(js)%players.size();
        //si il y a une carte inversion , alos le sens modifie
        sens =false;

        int clr= carte_courant.getColor();
        carte_courant = Card (clr,-1);

        return;
      } else if (carte_courant.getValue()==11 ){
        joueur_courant=(joueur_courant+2)%players.size();

        int clr= carte_courant.getColor();
        carte_courant = Card (clr,-11);

        return;
      }else{
        joueur_courant=(joueur_courant+1)%players.size();
        return ;
      }

    }else{
      if (carte_courant.getValue()==1 ){
        joueur_courant=(joueur_courant+1)%players.size();
        sens=true;

        int clr= carte_courant.getColor();
        carte_courant = Card (clr,-1);

        return;
      } else if (carte_courant.getValue()==11 ){
        unsigned int js =joueur_courant-2;
        while(js<0){
          js+=players.size();
        }
        joueur_courant=(js)%players.size();

        int clr= carte_courant.getColor();
        carte_courant = Card (clr,-11);
        return;
      }else{
        unsigned int js =joueur_courant-1;
        while(js<0){
          js+=players.size();
        }
        joueur_courant=(js)%players.size();
        return;
      }

    }
}

std::string Game8Americain::classement() const {

  for (unsigned int i =0 ;i<players.size();i++){
    if (players[i]->getHand().size()==0  )
      return players[i]->getName()+" a gagné.";
  }

  int score [players.size()];
  int max =0;
  for (unsigned int i=0;i<players.size();i++){
    int somme = 0;
    for ( unsigned int j =0 ;j<(players[i]->getHand().size());j++){
      int vle = players[i]->getHand()[j].getValue();
      somme += vle ;

      if (vle ==0 ){//50
        somme += 50;
      }
      if (vle ==1 ){//20
        somme += 19;
      }
      if (vle ==2 ){//20
        somme += 18;
      }
      if (vle ==8 ){//50
        somme += 42;
      }
      if (vle ==11 ){//20
        somme += 9;
      }
      if (vle ==13 ){//10
        somme -=3;
      }
      if (vle ==14 ){//10
        somme -=4;
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

std::string Game8Americain::configuration() const{

  std::string s = "";
  for (unsigned int i =0; i<players.size();i++){
    if ( i != joueur_courant){
      s += ""+ (players[i])->toStringHidden() + "\n";
    }
  }
  s += "PIOCHE : Card*"+ std::to_string(pioche.size()) + "\n";
  s += "+------------------------------+\n";
  s += "|                              |\n";

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

  s += "|                              |\n";
  s += "+------------------------------+\n";
  s += ""+ (players[joueur_courant])->toString() + "\n";
  return s;
}


std::vector<int> Game8Americain::actions_possibles() const {
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
      if (players[joueur_courant]->getHand()[i].getValue()==2 && players[joueur_courant]->getHand()[i].getColor()==carte_courant.getColor()){
        ap.push_back(i);
      }
    }
  }
  if (todo==4){
    for (unsigned  int i =0 ;i<(players[joueur_courant]->getHand().size());i++){
      if (players[joueur_courant]->getHand()[i].getValue()==0){
          ap.push_back(i);
      }
    }
  }
  if (todo==5){
    for (unsigned  int i =0 ;i<(players[joueur_courant]->getHand().size());i++){
      if (players[joueur_courant]->getHand()[i].getValue()==8){
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
      if (vle==carte_courant.getValue() && vle!=2 && vle!=1 && vle!=11 && vle!=8 && vle!=0){
        ap.push_back(109);
        break;
      }

    }
    for ( unsigned int i =0 ;i<players[joueur_courant]->getHand().size();i++){
      if (players[joueur_courant]->getHand()[i].getColor()==carte_courant.getColor()){
        ap.push_back(110);
        break;
      }

    }
    //si il exite le carte plus2, push back 111,mais il faut le meme couleu
    for (unsigned  int i =0 ;i<players[joueur_courant]->getHand().size();i++){
      if (players[joueur_courant]->getHand()[i].getValue()==2 && players[joueur_courant]->getHand()[i].getColor()==carte_courant.getColor()){
        ap.push_back(111);
        break;
      }

    }
    //si il exite la carte plus4 ,push back 112
    for ( unsigned int i =0 ;i<players[joueur_courant]->getHand().size();i++){
      if (players[joueur_courant]->getHand()[i].getValue()==0){
        ap.push_back(112);
        break;
      }

    }

    // si il exite la carte joker,push back 113
    for (unsigned  int i =0 ;i<players[joueur_courant]->getHand().size();i++){
      if (players[joueur_courant]->getHand()[i].getValue()==8){
        ap.push_back(113);
        break;
      }

    }

  }
  if (ap.empty()) ap.push_back(108);
  return ap;
}
// AFFICHAGE ==================================================== //

std::ostream& operator<<(std::ostream& out,  const Game8Americain& x){
  out << x.configuration();
  return out;
}

// ACCESSEURS =================================================== //
