#include "DeckItaliennes.hpp"


DeckItaliennes::DeckItaliennes():Deck() {
  //{ As 2 3 4 5 6 7 Valet Cavalier Roi } * { Coupe baton denier épee }
  const Card asCoupe = Card(0,1);
  const Card asBaton = Card(1,1);
  const Card asDenier = Card(2,1);
  const Card asEpee = Card(3,1);
  (*this)+=asCoupe+asBaton+asDenier+asEpee;

  const Card deuxCoupe = Card (0,2);
  const Card deuxBaton = Card (1,2);
  const Card deuxDenier = Card (2,2);
  const Card deuxEpee = Card (3,2);
  (*this)+=deuxCoupe+deuxBaton+deuxDenier+deuxEpee;

  const Card troisCoupe = Card (0,3);
  const Card troisBaton = Card (1,3);
  const Card troisDenier = Card (2,3);
  const Card troisEpee = Card (3,3);
  (*this)+=troisCoupe+troisBaton+troisDenier+troisEpee;

  const Card quatreCoupe = Card (0,4);
  const Card quatreBaton = Card (1,4);
  const Card quatreDenier = Card (2,4);
  const Card quatreEpee = Card (3,4);
  (*this)+=quatreCoupe+quatreBaton+quatreDenier+quatreEpee;

  const Card cinqCoupe = Card (0,5);
  const Card cinqBaton = Card (1,5);
  const Card cinqDenier = Card (2,5);
  const Card cinqEpee = Card (3,5);
  (*this)+=cinqCoupe+cinqBaton+cinqDenier+cinqEpee;

  const Card sixCoupe = Card (0,6);
  const Card sixBaton = Card (1,6);
  const Card sixDenier = Card (2,6);
  const Card sixEpee = Card (3,6);
  (*this)+=sixCoupe+sixBaton+sixDenier+sixEpee;

  const Card septCoupe = Card (0,7);
  const Card septBaton = Card (1,7);
  const Card septDenier = Card (2,7);
  const Card septEpee = Card (3,7);
  (*this)+=septCoupe+septBaton+septDenier+septEpee;

  const Card ValetCoupe = Card (0,11);
  const Card ValetBaton = Card (1,11);
  const Card ValetDenier = Card (2,11);
  const Card ValetEpee = Card (3,11);
  (*this)+=ValetCoupe+ValetBaton+ValetDenier+ValetEpee;

  const Card CavalierCoupe = Card (0,12);
  const Card CavalierBaton = Card (1,12);
  const Card CavalierDenier = Card (2,12);
  const Card CavalierEpee = Card (3,12);
  (*this)+=CavalierCoupe+CavalierBaton+CavalierDenier+CavalierEpee;

  const Card RoiCoupe = Card (0,14);
  const Card RoiBaton = Card (1,14);
  const Card RoiDenier = Card (2,14);
  const Card RoiEpee = Card (3,14);
  (*this)+=RoiCoupe+RoiBaton+RoiDenier+RoiEpee;
}
