#ifndef VIEW_HPP
#define VIEW_HPP

#include <iostream> // std::cout
#include <string> // std::string
#include <limits>
#include "Game.hpp"
#include "StringCards.hpp"

template <typename T> class View {

  private :


  public :

    // CONSTRUCTEURS ================================================ //

    View(){
      if ( ! std::is_base_of<Game, T>::value ) { // if (T not instanceof Game)
        throw invalid_argument("Le type <T> n'hérite pas de Game");
        exit(0);
      }
    }

    View(const View<T>&){} // Copie

    // DESTRUCTEUR ================================================== //

    virtual ~View(){}

    // AFFECTATION ================================================== //

    View& operator=(const View&){}

    // AFFICHAGE ===================================================== //

    void showGame(const T& game){
      std::cout << game << std::endl;
    }

    void showClassement(const T&  game){
      std::cout << game.classement() << std::endl;
    }

    void showDeck(const Deck&  deck){
      std::cout << deck << std::endl;
    }

    void showCard(const Card& card){
      std::cout << card << std::endl;
    }

    void showHiddenCard(){
      std::cout << StringCards::french_card(0) << std::endl;
    }

    void showPlayer(const Player& player){
      std::cout << player << std::endl;
    }

    void showPlayers(const T& game){
      for (unsigned int i=0; i<game.getPlayers().size(); i++){
        std::cout << game.getPlayers()[i]->toString() << std::endl;
      }
    }

    void showTeam(const Team& team){
      std::cout << team << std::endl;
    }

    void showTeams(const T& game){
      std::cout << game.teamsToString() << std::endl;
    }


    void showActions(const T& game){
      std::vector<int> ap = game.actions_possibles();

      for (unsigned int i=0; i<ap.size(); i++){
        std::cout << i+1 ;
        std::cout << " : " << game.getAllActions()[ap[i]] ;
        //std::cout << " (id all_actions : " ;
        //std::cout << ap[i] << ")"<< std::endl;
        std::cout << endl;
      }
    }

    void show_message(const std::string s){
      std::cout << s << std::endl ;
    }

    // INTERACTIONS USER ============================================ //

    string askName(){
      string name;
      std::cout << "Quel est le nom du joueur ? (veuillez l'écrire au clavier)" << std::endl;
      std::cin >> name;
      std::cout << "Le nom a été sauvegardé : " << name << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return name;
    }

    bool askHuman(){
      int human=0;
      std::cout << "Le joueur est-il humain ou IA ?" << std::endl;
      std::cout << "1 : Humain \t 2 : IA" << std::endl;
      std::cin >> human;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      while (human!=1 && human!=2){
        clear();
        std::cout << "(Veuillez taper soit 1 ou soit 2)" << std::endl;
        std::cout << "Le joueur est-il humain ou IA ?" << std::endl;
        std::cout << "1 : Humain \t 2 : IA" << std::endl;
        std::cin >> human;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      return human==1;
    }

    int askNbTeams(unsigned int min,unsigned int max){
      unsigned int nb = 0;
      std::cout << "Combien y a t-il d'équipes ? (entre " << min << " et " << max << ")" << std::endl;
      if (min==1){
        std::cout << "(Taper 1 pour qu'il n'y ait aucune équipe (jeu individuel))"  << std::endl;
      }
      std::cin >> nb;
      std::cin.clear();
      std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');
      while (nb<min || nb>max){
        clear();
        std::cout << "(Veuillez taper un nombre entre " << min << " et " << max << ")" << std::endl;
        std::cout << "Combien y a t-il d'équipes ? (entre " << min << " et " << max << ")" << std::endl;
        if (min==1){
          std::cout << "(Taper 1 pour qu'il n'y ait aucune équipe (jeu individuel))"  << std::endl;
        }
        std::cin >> nb;
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');
      }
      return nb;
    }

    int askTeam(const T& game){
      unsigned int team_id = game.getTeams().size()+1;
      std::cout << game.teamsToString() << std::endl;
      std::cout << "Dans quelle équipe sera le joueur ? (taper le n° de l'équipe)" << std::endl;
      std::cin >> team_id;
      std::cin.clear();
      std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');
      while (team_id<1 || team_id>game.getTeams().size()){
        clear();
        std::cout << game.teamsToString() << std::endl;
        std::cout << "(Veuillez taper un nombre entre " << 1 << " et " << game.getTeams().size() << ")" << std::endl;
        std::cout << "Dans quelle équipe sera le joueur ? (taper le n° de l'équipe)" << std::endl;
        std::cin >> team_id;
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');
      }
      return team_id-1;
    }

    int askNbPlayers(unsigned int min,unsigned int max){
      unsigned int nb = 0;
      std::cout << "Combien y a t-il de joueurs ? (entre " << min << " et " << max << ")" << std::endl;
      std::cin >> nb;
      std::cin.clear();
      std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');
      while (nb<min || nb>max){
        clear();
        std::cout << "(Veuillez taper un nombre entre " << min << " et " << max << ")" << std::endl;
        std::cout << "Combien y a t-il de joueurs ? (entre " << min << " et " << max << ")" << std::endl;
        std::cin >> nb;
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');
      }
      return nb;
    }

    int askAction(const T& game){
      unsigned int nb = 0;
      bool possible = false;
      std::cin >> nb; // 0 1 ...
      std::cin.clear();
      std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');

      if (nb>0 && nb<=game.actions_possibles().size()) possible = true;
      while (!possible){

        std::cout << "(Cette action est impossible...)" << std::endl;
        std::cin >> nb;
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');

        if (nb>0 && nb<=game.actions_possibles().size()) possible = true;

      }

      return game.actions_possibles()[nb-1];
    }

    void askFinirTour(const T& game){
      int nb = 0;
      while (nb!=1){

        std::cout << "Continuer ? (Taper 1 pour continuer)." << std::endl;
        std::cin >> nb;
        std::cin.clear();
        std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n');
      }
    }


    void clear(){
      for (int i=0; i<100; i++){
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
      }
    }

};

#endif
