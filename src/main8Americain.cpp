#include <iostream> // cout

#include "Deck.hpp"
#include "Deck54.hpp"
#include "Player.hpp"
#include "Team.hpp"

#include "Controller.hpp"
#include "Game8Americain.hpp"
#include "View.hpp"

//#include "StringCards.hpp" // french_card()


using namespace std;

int main(){

  // TEST GameUno
  Game8Americain* model = new Game8Americain();
  View<Game8Americain>* view = new View<Game8Americain>();
  Controller<Game8Americain>* cont = new Controller<Game8Americain>( model , view );


  // CHOIX 1 : TESTER TOUT
  cont->initPlayers(2,5);


  // CHOIX 2 : TESTER PLUS VITE (players deja initialisés)
  /*
  int NB_JOUEURS = 5;
  for (int i=0; i<NB_JOUEURS; i++) model->addPlayer(new Player("J"+std::to_string(i),true));
  */

  // CHOIX 3 : TESTER TRÈS TRÈS VITE (que des IA) --> le jeu est automatique
  /*
  int NB_JOUEURS = 5;
  for (int i=0; i<NB_JOUEURS; i++) model->addPlayer(new Player("J"+std::to_string(i),false));
  */



  cont->launch_game_loop();

  delete cont;
  return 0;
}
