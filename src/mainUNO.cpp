#include <iostream>

#include "Deck.hpp"
#include "DeckUno.hpp"
#include "Player.hpp"
#include "Team.hpp"

#include "Controller.hpp"
#include "GameUno.hpp"
#include "View.hpp"


using namespace std;

int main(){

  // TEST GameUno
  GameUno* model = new GameUno();
  View<GameUno>* view = new View<GameUno>();
  Controller<GameUno>* cont = new Controller<GameUno>( model , view );


  // CHOIX 1 : TOUT TESTER
  cont->initPlayers(2,10);

  // CHOIX 2 : TESTER PLUS VITE (players deja initialisés)
  /*
  int NB_JOUEURS = 3;
  for (int i=0; i<NB_JOUEURS; i++) model->addPlayer(new Player("J"+std::to_string(i),true));
  */

  // CHOIX 3 : TESTER TRÈS TRÈS VITE (que des IA) --> le jeu est automatique
  /*
  int NB_JOUEURS = 7;
  for (int i=0; i<NB_JOUEURS; i++) model->addPlayer(new Player("J"+std::to_string(i),false));
  */



  cont->launch_game_loop();

  delete cont;
  return 0;
}
