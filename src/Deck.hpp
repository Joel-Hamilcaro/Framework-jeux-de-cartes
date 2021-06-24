#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp"
#include <iostream> // std::cout
#include <string> // std::string
#include <vector> // vector

class Deck {

  protected :

    // CHAMPS ======================================================= //

    std::vector<Card> cards;

  public :

    // CONSTRUCTEURS ================================================ //

    Deck() ; // Défaut
    Deck(const Deck&) ; // Copie

    // DESTRUCTEUR ================================================== //

    virtual ~Deck();

    // AFFECTATION ================================================== //

    Deck& operator=(const Deck& x);

    // METHODES ===================================================== //

    Deck& operator+(const Card&); // ajoute la carte à la fin
    Deck& operator+=(const Card&); // ajoute la carte à la fin
    Deck& operator+(const Deck&); // Concatène les paquets
    Deck& operator+=(const Deck&); // Concatène les paquets
    Card& operator[](int); // Retourne la carte d'indice i
    void pop_all(); // Enlève toute les cartes du paquet
    void sort(); // Tri le paquet de carte selon la force des cartes (ordre croissant)
    void shuffle(); // Mélange le paquet de carte
    Card pop(unsigned int); // Enlève la carte i du paquet
    Card pop(); // Enlève la carte en haut du paquet (derniere carte)

    int getPoints(); // Retourne le nombre de points du paquet (dépend du jeu)
    int getMax() ;

    // REPRESENTATION TEXTUELLE ===================================== //

    std::string toString() const; // Renvoie la représentation textuelle du deck
    std::string toStringHidden() const; // Renvoie la représentation textuelle du deck face cachée

    // AFFICHAGE ==================================================== //

    friend std::ostream& operator<<(std::ostream& out, const Deck& x);

    // ACCESSEURS =================================================== //

    const std::vector<Card>& getCards() const;
    unsigned int size() const; // Renvoie la taille du paquet

};

// FONCTION NORMALE (pas méthode de classe) ========================= //

Deck operator+(const Card&, const Card&);
Deck operator+(const Card&, const Deck&);

#endif
