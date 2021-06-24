#ifndef GAMEUNO_HPP
#define GAMEUNO_HPP

#include <iostream> // std::cout
#include <string> // std::string
#include "Game.hpp"
#include "DeckUno.hpp"

class GameUno: public Game {

  private :

    // CHAMPS ======================================================= //
    // hérités
    int todo;
    Card carte_courant;

  public :

    // CONSTRUCTEURS ================================================ //

    GameUno() ; // Défaut
    GameUno(const GameUno&) ; // Copie

    // DESTRUCTEUR ================================================== //

    virtual ~GameUno();

    // AFFECTATION ================================================== //

    GameUno& operator=(const GameUno&);

    // METHODES ===================================================== //

    /*

    // hérités
    void addTeam(Team*);
    void addPlayer(Player*);
    void changerJoueur(int);
    void changerSens();
    Card piocher();
    void defausser(const Card&);
    */

    virtual bool joueursConformes() const;
    virtual void distribuer(Deck&) ;
    virtual void initialisation() ;
    virtual void executerAction(int) ;
    virtual bool estFini() const ;
    virtual void jouerTour() ;
    virtual std::string classement() const ;
    virtual std::string configuration() const ;
    virtual std::vector<int> actions_possibles() const ;

    // ACCESSEURS =================================================== //

    // hérités de Game.cpp

    // AFFICHAGE ==================================================== //

    friend std::ostream& operator<<(std::ostream& out, const GameUno& x);
};


#endif
