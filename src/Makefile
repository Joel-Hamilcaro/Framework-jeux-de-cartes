CPP = g++ --std=c++11 -I/usr/include/stl -Wall

all : main mainBataille mainBelote mainBriscola mainUNO main8Americain

main8Americain : StringCards.o Card.o Deck.o Deck32.o Deck52.o Deck54.o Player.o Team.o Game.o Game8Americain.o main8Americain.o
	$(CPP) -o main8Americain StringCards.o Card.o Deck.o Deck32.o Deck52.o Deck54.o Player.o Team.o Game.o Game8Americain.o main8Americain.o

mainUNO : StringCards.o Card.o Deck.o DeckUno.o Player.o Team.o Game.o GameUno.o mainUNO.o
	$(CPP) -o mainUNO StringCards.o Card.o Deck.o DeckUno.o Player.o Team.o Game.o GameUno.o mainUNO.o

mainBriscola : StringCards.o Card.o Deck.o DeckItaliennes.o Player.o Team.o Game.o Briscola.o mainBriscola.o
	$(CPP) -o mainBriscola StringCards.o Card.o Deck.o DeckItaliennes.o Player.o Team.o Game.o Briscola.o mainBriscola.o

mainBelote : StringCards.o Card.o Deck.o Deck32.o Player.o Team.o Game.o Belote.o mainBelote.o
	$(CPP) -o mainBelote StringCards.o Card.o Deck.o Deck32.o Player.o Team.o Game.o Belote.o mainBelote.o

mainBataille : StringCards.o Card.o Deck.o Deck32.o Player.o Team.o Game.o Bataille.o mainBataille.o
	$(CPP) -o mainBataille StringCards.o Card.o Deck.o Deck32.o Player.o Team.o Game.o Bataille.o mainBataille.o

main : StringCards.o Card.o Deck.o Deck32.o DeckItaliennes.o Deck52.o Deck53.o Deck54.o Deck56.o Deck57.o Deck58.o DeckTarot.o DeckUno.o main.o
	$(CPP) -o main StringCards.o Card.o Deck.o Deck32.o DeckItaliennes.o Deck52.o Deck53.o Deck54.o Deck56.o Deck57.o Deck58.o DeckTarot.o DeckUno.o main.o

main8Americain.o : main8Americain.cpp View.hpp Controller.hpp
	$(CPP) -c main8Americain.cpp View.hpp Controller.hpp

mainUNO.o : mainUNO.cpp View.hpp Controller.hpp
	$(CPP) -c mainUNO.cpp View.hpp Controller.hpp

mainBriscola.o : mainBriscola.cpp View.hpp Controller.hpp
	$(CPP) -c mainBriscola.cpp View.hpp Controller.hpp

mainBelote.o : mainBelote.cpp View.hpp Controller.hpp
	$(CPP) -c mainBelote.cpp View.hpp Controller.hpp

mainBataille.o : mainBataille.cpp View.hpp Controller.hpp
	$(CPP) -c mainBataille.cpp View.hpp Controller.hpp

main.o : main.cpp
	$(CPP) -c main.cpp

Game8Americain.o : Game8Americain.cpp Game8Americain.hpp Game.hpp Deck54.hpp
	$(CPP) -c Game8Americain.cpp Game8Americain.hpp Game8Americain.hpp Deck54.hpp

GameUno.o : GameUno.cpp GameUno.hpp Game.hpp DeckUno.hpp
	$(CPP) -c GameUno.cpp GameUno.hpp Game.hpp DeckUno.hpp

Briscola.o : Briscola.cpp Briscola.hpp Game.hpp DeckItaliennes.hpp
	$(CPP) -c Briscola.cpp Briscola.hpp Game.hpp DeckItaliennes.hpp

Belote.o : Belote.cpp Belote.hpp Game.hpp Deck32.hpp
	$(CPP) -c Belote.cpp Belote.hpp Game.hpp Deck32.hpp

Bataille.o : Bataille.cpp Bataille.hpp Game.hpp Deck32.hpp
	$(CPP) -c Bataille.cpp Bataille.hpp Game.hpp Deck32.hpp

Game.o : Game.cpp Game.hpp Team.hpp
	$(CPP) -c Game.cpp Game.hpp Team.hpp

Team.o : Team.cpp Team.hpp Player.hpp
	$(CPP) -c Team.cpp Team.hpp Player.hpp

Player.o : Player.cpp Player.hpp Deck.hpp
	$(CPP) -c Player.cpp Player.hpp Deck.hpp

DeckUno.o : DeckUno.cpp DeckUno.hpp Deck.hpp
	$(CPP) -c DeckUno.cpp DeckUno.hpp Deck.hpp

DeckTarot.o : DeckTarot.cpp DeckTarot.hpp Deck56.hpp
	$(CPP) -c DeckTarot.cpp DeckTarot.hpp Deck56.hpp

Deck58.o : Deck58.cpp Deck58.hpp Deck56.hpp
	$(CPP) -c Deck58.cpp Deck58.hpp Deck56.hpp

Deck57.o : Deck57.cpp Deck57.hpp Deck56.hpp
	$(CPP) -c Deck57.cpp Deck57.hpp Deck56.hpp

Deck56.o : Deck56.cpp Deck56.hpp Deck52.hpp
	$(CPP) -c Deck56.cpp Deck56.hpp Deck52.hpp

Deck54.o : Deck54.cpp Deck54.hpp Deck52.hpp
	$(CPP) -c Deck54.cpp Deck54.hpp Deck52.hpp

Deck53.o : Deck53.cpp Deck53.hpp Deck52.hpp
	$(CPP) -c Deck53.cpp Deck53.hpp Deck52.hpp

Deck52.o : Deck52.cpp Deck52.hpp Deck32.hpp
	$(CPP) -c Deck52.cpp Deck52.hpp Deck32.hpp

DeckItaliennes.o : DeckItaliennes.cpp DeckItaliennes.hpp Deck.hpp
	$(CPP) -c DeckItaliennes.cpp DeckItaliennes.hpp Deck.hpp

Deck32.o : Deck32.cpp Deck32.hpp Deck.hpp
	$(CPP) -c Deck32.cpp Deck32.hpp Deck.hpp

Deck.o : Deck.cpp Deck.hpp
	$(CPP) -c Deck.cpp Deck.hpp

Card.o : Card.cpp Card.hpp
	$(CPP) -c Card.cpp Card.hpp

StringCards.o : StringCards.cpp StringCards.hpp
	$(CPP) -c StringCards.cpp StringCards.hpp

clean :
	rm *.o *.hpp.gch main mainBataille mainBelote mainBriscola mainUNO main8Americain

valgrind :
	make clean ; make main; valgrind --leak-check=full ./main

valgrindBataille :
	make clean ; make mainBataille; valgrind --leak-check=full ./mainBataille

valgrindBelote :
	make clean ; make mainBelote; valgrind --leak-check=full ./mainBelote

valgrindBriscola :
	make clean ; make mainBriscola; valgrind --leak-check=full ./mainBriscola

valgrindUNO :
	make clean ; make mainUNO; valgrind --leak-check=full ./mainUNO

valgrind8Americain :
	make clean ; make main8Americain; valgrind --leak-check=full ./main8Americain
