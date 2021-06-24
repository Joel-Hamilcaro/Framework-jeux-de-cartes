#include "Deck32.hpp"

Deck32::Deck32() : Deck() {

  //{ As 7 8 9 10 Valet Dame Roi } * { Coeur Carreaux Trèfle Pique }
  const Card asCarreaux = Card(0,1);
  const Card asCoeur = Card(1,1);
  const Card asPique = Card(2,1);
  const Card asTrefle = Card(3,1);
  (*this)+=asCarreaux+asCoeur+asPique+asTrefle;

  const Card septCarreaux = Card (0,7);
  const Card septCoeur = Card (1,7);
  const Card septPique = Card (2,7);
  const Card septTrefle = Card (3,7);
  (*this)+=septCarreaux+septCoeur+septPique+septTrefle;

  const Card huitCarreaux = Card (0,8);
  const Card huitCoeur = Card (1,8);
  const Card huitPique = Card (2,8);
  const Card huitTrefle = Card (3,8);
  (*this)+=huitCarreaux+huitCoeur+huitPique+huitTrefle;

  const Card neufCarreaux = Card (0,9);
  const Card neufCoeur = Card (1,9);
  const Card neufPique = Card (2,9);
  const Card neufTrefle = Card (3,9);
  (*this)+=neufCarreaux+neufCoeur+neufPique+neufTrefle;

  const Card dixCarreaux = Card (0,10);
  const Card dixCoeur = Card (1,10);
  const Card dixPique = Card (2,10);
  const Card dixTrefle = Card (3,10);
  (*this)+=dixCarreaux+dixCoeur+dixPique+dixTrefle;

  const Card ValetCarreaux = Card (0,11);
  const Card ValetCoeur = Card (1,11);
  const Card ValetPique = Card (2,11);
  const Card ValetTrefle = Card (3,11);
  (*this)+=ValetCarreaux+ValetCoeur+ValetPique+ValetTrefle;

  const Card DameCarreaux = Card (0,13); 
  const Card DameCoeur = Card (1,13);
  const Card DamePique = Card (2,13);
  const Card DameTrefle = Card (3,13);
  (*this)+=DameCarreaux+DameCoeur+DamePique+DameTrefle;

  const Card RoiCarreaux = Card (0,14);
  const Card RoiCoeur = Card (1,14);
  const Card RoiPique = Card (2,14);
  const Card RoiTrefle = Card (3,14);
  (*this)+=RoiCarreaux+RoiCoeur+RoiPique+RoiTrefle;

}
