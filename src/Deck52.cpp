#include "Deck52.hpp"

Deck52::Deck52() :Deck32(){


  const Card deuxCoeur = Card (0,2);
  const Card deuxCarreaux = Card (1,2);
  const Card deuxTrefle = Card (2,2);
  const Card deuxPique = Card (3,2);
  (*this)+=deuxCoeur+deuxCarreaux+deuxTrefle+deuxPique;

  const Card troisCoeur = Card (0,3);
  const Card troisCarreaux = Card (1,3);
  const Card troisTrefle = Card (2,3);
  const Card troisPique = Card (3,3);
  (*this)+=troisCoeur+troisCarreaux+troisTrefle+troisPique;

  const Card quatreCoeur = Card (0,4);
  const Card quatreCarreaux = Card (1,4);
  const Card quatreTrefle = Card (2,4);
  const Card quatrePique = Card (3,4);
  (*this)+=quatreCoeur+quatreCarreaux+quatreTrefle+quatrePique;

  const Card cinqCoeur = Card (0,5);
  const Card cinqCarreaux = Card (1,5);
  const Card cinqTrefle = Card (2,5);
  const Card cinqPique = Card (3,5);
  (*this)+=cinqCoeur+cinqCarreaux+cinqTrefle+cinqPique;

  const Card sixCoeur = Card (0,6);
  const Card sixCarreaux = Card (1,6);
  const Card sixTrefle = Card (2,6);
  const Card sixPique = Card (3,6);
  (*this)+=sixCoeur+sixCarreaux+sixTrefle+sixPique;
}
