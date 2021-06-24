#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <iostream> // std::cout
#include "Game.hpp"
#include "View.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

template <typename T> class Controller {

  private :

    // CHAMPS ======================================================= //

    T* model;
    View<T>* view;

    // METHODES PRIVEES ============================================= //
    // NON NECESSAIRES A L'EXTERIEUR DE LA CLASSE =================== //

    void addTeam(){ // Ajouter une equipe
      Team* t1 = new Team();
      model->addTeam(t1);
    }

    void addPlayer(){ // Ajouter un joueur
      std::string name = view->askName();
      bool human = view->askHuman();
      Player* p = new Player(name,human);
      model->addPlayer(p);
    }

    void addPlayerInTeam(){ // Ajouter un joueur dans une equipe
      std::string name = view->askName();
      bool human = view->askHuman();
      int team_id = view->askTeam(*model);
      Player* p = new Player(name,human,team_id);
      model->addPlayer(p);
      (model->getTeams()[team_id])->addPlayer(p);
      view->clear();
      view->showTeams(*model);
    }


        void playAction(){
          if ( ( (model->getPlayers())[model->getJoueurCourant()] )->isHuman() ){ // if isHuman
            int act = view->askAction(*model);
            model->executerAction(act);
          }
          else { // if isIA
            std::vector<int> actions_possibles = model->actions_possibles();
            srand(time(0));
            int act = rand() % actions_possibles.size();
            for (int i=0; i<act+10;i++){
              rand();
            }
            model->executerAction(actions_possibles[act]);
            // TODO (faire des actions possibles aléatoire)
          }
        }

        void jouerTour(){
          if (  ! (model->noHuman()) ){
            //view->askFinirTour(*model);
          }
          model->jouerTour();
        }

        void reinitialiserJoueurs(){
          model->deleteTeams();
          model->deletePlayers();
        }

  public :

    // CONSTRUCTEURS ================================================ //

    Controller(T* model, View<T>* view) : model(model) , view(view) {
      if ( ! std::is_base_of<Game, T>::value ) { // if (T not instanceof Game)
        throw invalid_argument("Le type <T> n'hérite pas de Game");
        exit(0);
      }
    }

    Controller(const Controller<T>& c) : model(c.model), view(c.view) {} // Copie

    // DESTRUCTEUR ================================================== //

    virtual ~Controller(){
      delete view;
      delete model;
    }

    // AFFECTATION ================================================== //

    Controller& operator=(const Controller& c){
      view = c.view;
      model = c.model;
    }

    // METHODES PUBLIQUES =========================================== //


    void initPlayers(unsigned int min_p,unsigned int max_p){ // initialiser le nombre de joueur (entre min_p et max_p)
      bool first_try = true;
      do {
        view->clear();
        if (!first_try){
          view->showPlayers(*model);
          view->show_message("La configuration des joueurs n'est pas conforme aux règles du jeu.");
        }
        first_try = false;
        reinitialiserJoueurs();
        int nb_players = 0;
        if (min_p!=max_p) nb_players = view->askNbPlayers(min_p,max_p);
        else nb_players = min_p;
        for (int i=0; i<nb_players; i++){
          addPlayer();
        }

      } while (!model->joueursConformes());

    }

    void initPlayers(unsigned int min_t,unsigned int max_t,unsigned int min_p, unsigned int max_p){ // initialiser les equipes (nombre d'équipes entre min et max nombre de joueurs min et max).

      if (!model->isIndividual()){
        bool first_try = true;
        do {
          view->clear();
          if (!first_try){
            view->showPlayers(*model);
            view->showTeams(*model);
            view->show_message("La configuration des équipes n'est pas conforme aux règles du jeu.");
          }

          first_try = false;
          reinitialiserJoueurs();
          int nb_teams = 0;

          if (min_t != max_t) nb_teams = view->askNbTeams(min_t,max_t);
          else nb_teams = min_t;
          for (int i=0; i<nb_teams; i++){
            addTeam();
          }
          int nb_players = 0;
          if (min_p != max_p) nb_players = view->askNbPlayers(min_p,max_p);
          else nb_players = min_p;
          for (int i=0; i<nb_players; i++){
            if (nb_teams<=1) addPlayer();
            else addPlayerInTeam();
          }

        } while (!model->joueursConformes());

      }

      else {
        initPlayers(min_p,max_p);
      }

    }

    void launch_game_loop(){

      model->initialisation();

      while(!model->estFini()){
        view->showGame(*model);
        if (model->getPlayers()[model->getJoueurCourant()]->isHuman() ) view->showActions(*model);
        playAction();
        //view->showGame(*model);
        jouerTour();

      }
      view->showClassement(*model);
    }


};

#endif
