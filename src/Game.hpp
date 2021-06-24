#ifndef GAME_HPP
#define GAME_HPP

#include <iostream> // std::cout
#include <string> // std::string
#include <vector> // vector
#include "Team.hpp"

class Game {

  protected :

    // CHAMPS ======================================================= //
    std::vector<Team*> teams;
    std::vector<Player*> players;
    std::vector<std::string> all_actions;
    Deck pioche;
    Deck defausse;
    unsigned int joueur_courant;
    bool sens;
    int min_players;
    int max_players;
    bool individual;

  public :

    // CONSTRUCTEURS ================================================ //

    Game() ; // Défaut
    Game(bool) ; // individuel ou non
    Game(const Game&) ; // Copie

    // DESTRUCTEUR ================================================== //

    virtual ~Game();

    // AFFECTATION ================================================== //

    Game& operator=(const Game&);

    // METHODES ===================================================== //

    void addTeam(Team*);
    void addPlayer(Player*);
    void changerJoueur(int);
    void incrJoueur(int);
    void changerSens();
    Card piocher();
    void defausser(const Card&);
    virtual std::string teamsToString() const;
    bool same_team(Player*,Player*) const;

    // METHODES VIRTUELLES PURES ==================================== //

    virtual bool joueursConformes() const = 0; // verifie que les joueurs sont conformes aux règles
    // exemple : verifie qu'il y a bien deux joueurs pour un jeu de bataille,
    // exemple : verifie qu'il y a bien deux equipe de deux pour la belote ... etc.


    virtual void distribuer(Deck&) = 0;
    // la fonction va distribuer les cartes du deck pour les joueurs/pioche/ ect...
    // (ex bataille : distribuer la moitié au joueur 1 l'autre moitié au joueur 2)

    virtual void initialisation() = 0;
    // on suppose que les joueurs et équipes sont deja créés. La fonction va distribuer les cartes
    // (appel a distribuer() ) , puis définir le joueur courant, ect...


    virtual void executerAction(int) = 0;
    // l'entier correspond a une action possible (par ex : la fonction overrided contient un switch)
    // les actions possibles sont définies dans actions_possibles()


    virtual bool estFini() const = 0;
    // Retourne vrai si le jeu est fini. Par exemple pour bataille, on verifie si un joueur possède toutes les cartes


    virtual void jouerTour() = 0;
    // on suppose que l'action a été effectuée. (ex bataille : le joueur 2 a déjà posé sa carte par executerAction() )
    // jouerTour executer les consequence de l'action (ex bataille : on compare les cartes posées,
    // on transfert toutes les cartes au joueur qui a posé la plus forte, on definit le joueur 1 comme joueur courant)


    virtual std::string classement() const = 0;
    // retourne le resultat final sous forme textuelle


    virtual std::string configuration() const = 0;
    // retourne la configuration du plateau sous forme textuelle


    virtual std::vector<int> actions_possibles() const = 0;
    // retourne la liste des actions possibles (les int correspondants aux indices de all_actions)

    // ACCESSEURS =================================================== //

    std::vector<Team*> getTeams() const;
    std::vector<Player*> getPlayers() const;
    Deck getPioche() const;
    Deck getDefausse() const;
    int getJoueurCourant() const;
    bool getSens() const;
    bool isIndividual() const;
    bool noHuman() const;
    std::vector<std::string> getAllActions() const;

    // MUTATEURS ==================================================== //
    void deletePlayers();
    void deleteTeams();

};

#endif
