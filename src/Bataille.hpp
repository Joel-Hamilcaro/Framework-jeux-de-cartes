#ifndef BATAILLE_HPP
#define BATAILLE_HPP

#include <iostream>
#include <string> 
#include "Game.hpp"
#include "Deck32.hpp"

class Bataille: public Game {

  private :

    // CHAMPS ======================================================= //
    // hérités
    /*
    std::vector<Team*> teams;
    std::vector<Player*> players;
    std::vector<std::string> all_actions;
    Deck pioche;
    Deck defausse;
    int joueur_courant;
    bool sens;
    int min_players;
    int max_players;
    bool individual;
    */

  public :

    // CONSTRUCTEURS ================================================ //

    Bataille() ; // Défaut
    Bataille(const Bataille&) ; // Copie

    // DESTRUCTEUR ================================================== //

    virtual ~Bataille();

    // AFFECTATION ================================================== //

    Bataille& operator=(const Bataille&);

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
    virtual std::vector<int> actions_possibles() const;

    // ACCESSEURS =================================================== //

    // hérités de Game.cpp

    // AFFICHAGE ==================================================== //

    friend std::ostream& operator<<(std::ostream& out, const Bataille& x);

};


#endif
