#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream> // std::cout
#include <string> // std::string

#include "Deck.hpp"

class Player {

  private :

    // CHAMPS ======================================================= //
    static int cpt; // CHAMP STATIQUE
    int id_team;
    std::string name;
    Deck hand;
    const bool human;

  public :

    // CONSTRUCTEURS ================================================ //

    Player() ; // Défaut
    Player(const Player&) ; // Copie
    Player(const std::string&);
    Player(const std::string&, const bool);
    Player(const std::string&, const Deck&, const bool);
    Player(const std::string&, const bool, const int id_team);

    // DESTRUCTEUR ================================================== //

    virtual ~Player();

    // AFFECTATION ================================================== //

    Player& operator=(const Player& x);

    // REPRESENTATION TEXTUELLE ===================================== //
    std::string toString() const;
    std::string toStringHidden() const;

    // AFFICHAGE ==================================================== //

    friend std::ostream& operator<<(std::ostream& out, const Player& x);

    // METHODES ==================================================== //

    void shuffleHand();
    void sortHand();
    int getPoints();
    void addCard(Card& x); // transfère x dans hand (au dessus du paquet)
    void addCardEnd(Card& x); // transfère x dans hand (sous le paquet)
    void addCards(Deck& x); // transfère les cartes de x dans hand (au dessus du paquet)
    void addCardsEnd(Deck& x); // transfère les cartes de x dans hand (sous le paquet)
    void putCard(int i, Deck& x); // enleve la carte et la met dans x (au dessus du paquet)
    void putCardEnd(int i, Deck& x); // enleve la carte et la met dans x (sous le paquet)
    Card takeCard(int i); // enleve la carte à la position i
    Card takeCard(); // enleve la carte au dessus du paquet
    void removeAllCard(); // enleve toutes les cartes

    // ACCESSEURS =================================================== //

    std::string getName() const;
    int getIdTeam() const;
    Deck getHand() const;
    bool isHuman() const;

    // MUTATATEURS ================================================== //

    void setIdTeam(int);

};

#endif
