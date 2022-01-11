#ifndef STRUCTURES_JEUX_HPP
#define STRUCTURES_JEUX_HPP

//  Source : structures.hpp    Contenu : Toutes les structures utiles pour le fonctionnement de mon Jeux
namespace _structure
{
  // Structure du type playeur
  struct player
  {
    string pseudo;
    int modeJeux;        // le mode du jeu
    int totalScore;      // le total du score d'un joueur
    int indicateurSante; // l'indicateur santé d'un joueur
    int nombrePartie;    // nombre de partie d'un joueur
    int forceJeu;        // difficulté souhaitée d'un joueur
    int nombreJocker;    // nombre de jocker d'un joueur
    int etapeJeux;       // étape d'un joueur dans le jeu
    time_t chronoStart;  // heure de départ d'une partie d'un joueur
    time_t chronoEnd;    // heure de fin d'une partie d'un joueur
  };

  // Structure du type grille
  struct grille
  {
    bool grillePrivate;
    int nbrColonne; // nombre de colonne dans une grille
    int nbrLigne;   // nombre de ligne dans une grille
    int **Tableau;  // Tableau d'entiers dans un tableau d'entiers
  };

}
#endif