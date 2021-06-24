#ifndef TEAM_HPP
#define TEAM_HPP

#include "Player.hpp"
#include <iostream> // std::cout
#include <string> // std::string
#include <vector> // vector

class Team {

  private :

    // CHAMPS ======================================================= //
    static int cpt; // CHAMP STATIQUE
    int id;
    std::vector<Player*> players;

  public :

    // CONSTRUCTEURS ================================================ //

    Team() ; // Défaut
    Team(const Team&) ; // Copie
    Team(const std::vector<Player*>&);

    // DESTRUCTEUR ================================================== //

    virtual ~Team();

    // AFFECTATION ================================================== //

    Team& operator=(const Team& x);

    // METHODES ===================================================== //

    void addPlayer(Player*);
    std::string toString() const;
    std::string toStringHidden() const;
    bool contains(Player*) const;
    bool same_team(Player*,Player*) const;
    
    // AFFICHAGE ==================================================== //

    friend std::ostream& operator<<(std::ostream& out, const Team& x);

    // METHODES ==================================================== //

    int getPoints();

    // ACCESSEURS =================================================== //

    int getId() const;
    std::vector<Player*> getPlayers() const;


};

#endif
