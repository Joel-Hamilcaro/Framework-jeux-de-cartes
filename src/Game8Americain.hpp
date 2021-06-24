#ifndef Game8Americain_HPP
#define Game8Americain_HPP

#include <iostream> // std::cout
#include <string> // std::string
#include "Game.hpp"
#include "Deck54.hpp"

class Game8Americain: public Game {

  private :

    // CHAMPS ======================================================= //
    // hérités
    int todo;
    Card carte_courant;

  public :

    // CONSTRUCTEURS ================================================ //

    Game8Americain() ; // Défaut
    Game8Americain(const Game8Americain&) ; // Copie

    // DESTRUCTEUR ================================================== //

    virtual ~Game8Americain();

    // AFFECTATION ================================================== //

    Game8Americain& operator=(const Game8Americain&);

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

    friend std::ostream& operator<<(std::ostream& out, const Game8Americain& x);
};


#endif
