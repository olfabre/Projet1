///     ___  _ _       _             _____     _
///    / _ \| (_)_   _(_) ___ _ __  |  ___|_ _| |__  _ __ ___
///   | | | | | \ \ / / |/ _ \ '__| | |_ / _` | '_ \| '__/ _ \
///   | |_| | | |\ V /| |  __/ |    |  _| (_| | |_) | | |  __/
///    \___/|_|_| \_/ |_|\___|_|    |_|  \__,_|_.__/|_|  \___|
///
///               _ _____ _   ___  __   ____
///              | | ____| | | \ \/ /  / ___| _     _
///           _  | |  _| | | | |\  /  | |   _| |_ _| |_
///          | |_| | |___| |_| |/  \  | |__|_   _|_   _|
///           \___/|_____|\___//_/\_\  \____||_|   |_|
///
///
/* mon code en ligne: https://github.com/olfabre/Projet1.git  */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include "constantes.hpp"
#include "structures.hpp"
#include "fonctions.hpp"
using namespace std;

int main()
{
  // Initialisation variable et affectation
  srand(time(nullptr));                                             // Initialisation du tirage aléatoire à partir du temps machine
  _structure::player joueur;                                        // Instance de la structure player
  joueur.indicateurSante = _constante::indicateurSantePlayerDefaut; // Initialisation des points sante
  joueur.totalScore = _constante::scorePlayerDefaut;                // Initialisation du score par défaut
  joueur.nombrePartie = 0;                                          // Initialisation du nombre de partie
  joueur.nombreJocker = _constante::jockerPlayerDefaut;             // Initialisation du nombre de jocker par defaut
  joueur.etapeJeux = _constante::debutJeux;                         // Initialisation phase du jeu

  // Initialisation ecran
  _fonction::effacerTerminal();
  _fonction::afficherContenuFichierTerminal(_constante::fichierLogo);

  // Mode du jeu (0 - mode par défaut normal ou 1 mode test)
  joueur.modeJeux = _fonction::afficherModeJoueur();

  // Pseudo du joueur (en mode test, le pseudo est Einstein)

  joueur.pseudo = _fonction::afficherDemandePseudoJoueur(joueur.modeJeux);

  // Choix de la difficulté de la partie
  joueur.forceJeu = _fonction::afficherDemandeForceJeuJoueur(joueur.modeJeux);

  // Affichage des données initiales avant la partie (0 - avant partie, 1 - pendant la partie, 2 - fin de partie)
  _fonction::afficherDataJeuJoueur(joueur.etapeJeux, joueur.modeJeux, joueur.forceJeu, joueur.indicateurSante, joueur.pseudo, joueur.nombrePartie, joueur.nombreJocker, joueur.totalScore);

  // Débuter la partie ?
  _fonction::debuterNouvellePartie(joueur.modeJeux, joueur.etapeJeux, joueur.nombrePartie);

  //

  // Initialisation nouvelle partie
  _fonction::initialisationJeu(joueur.modeJeux, joueur.forceJeu, joueur.chronoStart, joueur.chronoEnd);

  // Détruire toutes les allocations dynamiques
  //  Fin de la fonction principale
  return 0;
}