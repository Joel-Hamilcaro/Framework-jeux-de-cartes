#ifndef BRISCOLA_HPP
#define BRISCOLA_HPP

#include <iostream> // std::cout
#include <string> // std::string
#include "Game.hpp"
#include "DeckItaliennes.hpp"

class Briscola : public Game {

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
    int atout; // couleur de l'atout courant
    int deck_actions_begin; // indice dans all_actions de "poser carte n°1"
    Card la_briscola;
    std::vector<int> scores;
    std::vector<int> resultat_manches;
    bool manche_finie;

  public :

    // CONSTRUCTEURS ================================================ //

    Briscola() ; // Défaut
    Briscola(const Briscola&) ; // Copie

    // DESTRUCTEUR ================================================== //

    virtual ~Briscola();

    // AFFECTATION ================================================== //

    Briscola& operator=(const Briscola&);

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
    int indexCarteGagnantTour(); // index dans la defausse de la carte gagnant le tour
    int indexJoueurGagnantTour(); // index du joueur ayant posé la carte gagnante
    Deck setValues(Deck&); // etablir les valeurs des cartes en fonction de l'atout
    Card setValue(Card&);
    void tousLesJoueursPiochentUneCarte();
    void miseAJourPoints(int); // met à jour les points en passant le numero du joueur gagnant en param (/!\ la defausse doit être plein à l'appel de fonciton)
    // ACCESSEURS =================================================== //

    // hérités de Game.cpp

    // AFFICHAGE ==================================================== //

    friend std::ostream& operator<<(std::ostream& out, const Briscola& x);

};


#endif
