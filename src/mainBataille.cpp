#include <iostream>
#include "Controller.hpp"
#include "Bataille.hpp"
#include "View.hpp"


using namespace std;

int main(){

  // TEST BATAILLE

  Controller<Bataille>* cont = new Controller<Bataille>( new Bataille() , new View<Bataille>() );
  cont->initPlayers(2,2);
  cont->launch_game_loop();

  delete cont;
  return 0;
}
