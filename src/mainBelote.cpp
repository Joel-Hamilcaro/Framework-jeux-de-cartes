#include <iostream>
#include "Controller.hpp"
#include "Belote.hpp"
#include "View.hpp"


using namespace std;

int main(){

  // TEST BELOTE

  Belote* model = new Belote();
  View<Belote>* view = new View<Belote>();
  Controller<Belote>* cont = new Controller<Belote>( model , view );


  // REMPLACER LA LIGNE 36 PAR CELLES-CI POUR TESTER PLUS VITE (SANS ENTRER LES PRENOMS A CHAQUE FOIS)
  /*
  Team* t1 = new Team();
  Team* t2 = new Team();
  Player* p1 = new Player("J1",false,0);
  Player* p2 = new Player("J2",false,1);
  Player* p3 = new Player("J3",false,1);
  Player* p4 = new Player("J4",false,0);
  t1->addPlayer(p1);
  t1->addPlayer(p4);
  t2->addPlayer(p2);
  t2->addPlayer(p3);
  model->addTeam(t1);
  model->addTeam(t2);
  model->addPlayer(p1);
  model->addPlayer(p2);
  model->addPlayer(p3);
  model->addPlayer(p4);
  */
  cont->initPlayers(2,2,4,4); // peut être remplacé par les lignes au-dessus
  cont->launch_game_loop();

  delete cont;
  return 0;
}
