#include <iostream>
#include "Controller.hpp"
#include "Briscola.hpp"
#include "View.hpp"


int main(){

  // TEST Briscola
  Briscola* model = new Briscola();
  Controller<Briscola>* cont = new Controller<Briscola>( model , new View<Briscola>() );

  // REMPLACER LA LIGNE 32 PAR CELLES-CI POUR TESTER PLUS VITE (SANS ENTRER LES PRENOMS A CHAQUE FOIS)
  /*
  Team* t1 = new Team();
  Team* t2 = new Team();
  Player* p1 = new Player("J1",false,0);
  Player* p2 = new Player("J2",false,1);
  Player* p3 = new Player("J3",false,1);
  Player* p4 = new Player("J4",false,0);
  t1->addPlayer(p1);
  t2->addPlayer(p2);
  t2->addPlayer(p3);
  t1->addPlayer(p4);
  model->addTeam(t1);
  model->addTeam(t2);
  model->addPlayer(p1);
  model->addPlayer(p2);
  model->addPlayer(p3);
  model->addPlayer(p4);
  */
  cont->initPlayers(1,2,2,5); // peut être remplacé par les lignes au dessus
  cont->launch_game_loop();

  delete cont;
  return 0;
}
