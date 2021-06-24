#include <iostream> // cout
#include "Card.hpp"
#include "Deck.hpp"
#include "Deck32.hpp"
#include "Deck52.hpp"
#include "Deck53.hpp"
#include "Deck54.hpp"
#include "Deck54.hpp"
#include "Deck56.hpp"
#include "Deck57.hpp"
#include "Deck58.hpp"
#include "DeckItaliennes.hpp"
#include "DeckTarot.hpp"
#include "DeckUno.hpp"


using namespace std;

int main(){

  Deck mydeck;

  cout << "\n================= TEST DECK32 =====================\n" << endl;
  cout << "--> Deck32 mydeck = Deck32();" << endl << endl;
  mydeck = Deck32();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.shuffle();\n" << endl;
  mydeck.shuffle();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.sort(); // tri selon la force des cartes\n" << endl;
  mydeck.sort(); // tri selon la force des cartes
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "mydeck.size() : " <<  mydeck.size() << endl << endl;
  cout << "===================================================\n" << endl;



  cout << "\n================= TEST DECK52 =====================\n" << endl;
  cout << "--> Deck52 mydeck = Deck52();" << endl << endl;
  mydeck = Deck52();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.shuffle();\n" << endl;
  mydeck.shuffle();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.sort(); // tri selon la force des cartes\n" << endl;
  mydeck.sort(); // tri selon la force des cartes
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "mydeck.size() : " <<  mydeck.size() << endl << endl;
  cout << "===================================================\n" << endl;



  cout << "\n================= TEST DECK53 =====================\n" << endl;
  cout << "--> Deck53 mydeck = Deck53();" << endl << endl;
  mydeck = Deck53();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.shuffle();\n" << endl;
  mydeck.shuffle();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.sort(); // tri selon la force des cartes\n" << endl;
  mydeck.sort(); // tri selon la force des cartes
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "mydeck.size() : " <<  mydeck.size() << endl << endl;
  cout << "===================================================\n" << endl;



  cout << "\n================= TEST DECK54 =====================\n" << endl;
  cout << "--> Deck54 mydeck = Deck54();" << endl << endl;
  mydeck = Deck54();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.shuffle();\n" << endl;
  mydeck.shuffle();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.sort(); // tri selon la force des cartes\n" << endl;
  mydeck.sort(); // tri selon la force des cartes
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "mydeck.size() : " <<  mydeck.size() << endl << endl;
  cout << "===================================================\n" << endl;

  cout << "\n================= TEST DECK56 =====================\n" << endl;
  cout << "--> Deck56 mydeck = Deck56();" << endl << endl;
  mydeck = Deck56();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.shuffle();\n" << endl;
  mydeck.shuffle();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.sort(); // tri selon la force des cartes\n" << endl;
  mydeck.sort(); // tri selon la force des cartes
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "mydeck.size() : " <<  mydeck.size() << endl << endl;
  cout << "===================================================\n" << endl;

  cout << "\n================= TEST DECK57 =====================\n" << endl;
  cout << "--> Deck57 mydeck = Deck57();" << endl << endl;
  mydeck = Deck57();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.shuffle();\n" << endl;
  mydeck.shuffle();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.sort(); // tri selon la force des cartes\n" << endl;
  mydeck.sort(); // tri selon la force des cartes
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "mydeck.size() : " <<  mydeck.size() << endl << endl;
  cout << "===================================================\n" << endl;

  cout << "\n================= TEST DECK58 =====================\n" << endl;
  cout << "--> Deck58 mydeck = Deck58();" << endl << endl;
  mydeck = Deck58();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.shuffle();\n" << endl;
  mydeck.shuffle();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.sort(); // tri selon la force des cartes\n" << endl;
  mydeck.sort(); // tri selon la force des cartes
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "mydeck.size() : " <<  mydeck.size() << endl << endl;
  cout << "===================================================\n" << endl;

cout << "\n================= TEST DECKITALIENNE =====================\n" << endl;
  cout << "--> DeckTarot mydeck = DeckTarot();" << endl << endl;
  mydeck = DeckItaliennes();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.shuffle();\n" << endl;
  mydeck.shuffle();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.sort(); // tri selon la force des cartes\n" << endl;
  mydeck.sort(); // tri selon la force des cartes
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "mydeck.size() : " <<  mydeck.size() << endl << endl;
  cout << "===================================================\n" << endl;

  cout << "\n================= TEST DECKTAROT =====================\n" << endl;
  cout << "--> DeckTarot mydeck = DeckTarot();" << endl << endl;
  mydeck = DeckTarot();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.shuffle();\n" << endl;
  mydeck.shuffle();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.sort(); // tri selon la force des cartes\n" << endl;
  mydeck.sort(); // tri selon la force des cartes
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "mydeck.size() : " <<  mydeck.size() << endl << endl;
  cout << "===================================================\n" << endl;

  cout << "\n================= TEST DECKUNO =====================\n" << endl;
  cout << "--> DeckUNO mydeck = DeckUNO();" << endl << endl;
  mydeck = DeckUno();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.shuffle();\n" << endl;
  mydeck.shuffle();
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "--> mydeck.sort(); // tri selon la force des cartes\n" << endl;
  mydeck.sort(); // tri selon la force des cartes
  cout << "mydeck :" <<  mydeck << endl << endl;
  cout << "mydeck.size() : " <<  mydeck.size() << endl << endl;
  cout << "===================================================\n" << endl;

  return 0;
}
