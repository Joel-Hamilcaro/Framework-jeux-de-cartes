#ifndef BELOTE_HPP
#define BELOTE_HPP

#include <iostream>
#include <string> 
#include "Game.hpp"
#include "Deck32.hpp"

class Belote : public Game {

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
    int tour_de_parole; // défini le tour de parole de la prise

    bool choisir_atout;  // si on est à la prise

    int to_do; // action spéciale à mémoriser
    // -1 : Rien
    // 2 : choisir une couleur
    // 3 : Reinitialiser le jeu
    // 4 : Finir tour

    int atout; // couleur de l'atout courant

    int attaquants; // indice de l'équipe attaquante

    int deck_actions_begin; // indice dans all_actions de "poser carte n°1"

    int maitre; // maitre du pli

    int indication; // représente a une action en cours (pour l'affichage)

    int lastCoupe; // indice dans la defausse de derniere coupe

    int tour;
    std::vector<int> scores;
    std::vector<int> resultat_final;

    bool manche_finie;

    int rebelote;
    // 1 si belote et rebelote mais les points n'ont pas été accordés,
    // 2 si belote et rebelote et les points ont été accordés
    // O sinon

  public :

    // CONSTRUCTEURS ================================================ //

    Belote() ; // Défaut
    Belote(const Belote&) ; // Copie

    // DESTRUCTEUR ================================================== //

    virtual ~Belote();

    // AFFECTATION ================================================== //

    Belote& operator=(const Belote&);

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
    void reinitialiser(); // la redistribution si aucun joueur n'a pris l'atout
    void distribuer2(); // la deuxième distribution des cartes (après choix de l'atout)
    void setValues(); // etablir les valeurs des cartes en fonction de l'atout
    Card setValue(Card& c);
    std::string indicationToString() const;
    void comptagePoints();
    void miseAJourPoints();
    bool setRebelote();
    // ACCESSEURS =================================================== //

    // hérités de Game.cpp

    // AFFICHAGE ==================================================== //

    friend std::ostream& operator<<(std::ostream& out, const Belote& x);

};


#endif
