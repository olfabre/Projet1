#ifndef FONCTIONS_JEUX_HPP
#define FONCTIONS_JEUX_HPP
using namespace std;

//  Source : fonctions.hpp    Contenu : Toutes les fonctions utiles pour le fonctionnement de mon Jeux
namespace _fonction
{

  // Effacer l'ecran du Terminal
  void effacerTerminal()
  {
    system("cls");   // Windows
    system("clear"); // Linux
  }

  // Afficher le contenu d'un fichier à l'écran du Terminal
  void afficherContenuFichierTerminal(string fichierAdresse, bool avecSautLigneDebut = false, bool avecSautLigneFin = false)
  {
    if (avecSautLigneDebut) // Saut de ligne en fin d'ecriture sur l'ecran
      cout << endl;

    ifstream fichier(fichierAdresse, ios::in); // On ouvre le fichier en lecture

    if (fichier) // Si l'ouverture a fonctionné
    {
      string ligne;
      while (getline(fichier, ligne)) // la ligne dans "ligne"
      {
        cout << ligne << endl; // On affiche la ligne
      }

      fichier.close(); // On ferme le fichier
    }

    if (avecSautLigneFin) // Saut de ligne en fin d'ecriture sur l'ecran
      cout << endl;
  }

  // Afficher le menu du joueur
  int afficherModeJoueur()
  {
    int modeJoueur(0);
    int i(0);
    do
    {
      if (i > 0)
      {
        _fonction::effacerTerminal();
        _fonction::afficherContenuFichierTerminal(_constante::fichierLogo);
      }
      cout << "#### MODES JOUEUR #######################################################################" << endl;
      cout << "#                                                                                       #" << endl;
      cout << "#    TAPEZ 0: MODE NORMAL                                                               #" << endl;
      cout << "#    TAPEZ 1: MODE TEST                                                                 #" << endl;
      cout << "#                                                                                       #" << endl;
      cout << "#########################################################################################" << endl;
      cout << "> Tapez:";
      cin >> modeJoueur;
      i++;
    } while (modeJoueur < 0 || modeJoueur > 1);
    return modeJoueur;
  }

  // Afficher la demande du pseudo du joueur
  string afficherDemandePseudoJoueur(int modeJoueur)
  {
    string pseudoJoueur;
    if (modeJoueur == 1)
    {
      pseudoJoueur = _constante::pseudoPlayerModeTest;
    }
    else
    {
      _fonction::effacerTerminal();
      _fonction::afficherContenuFichierTerminal(_constante::fichierLogo);
      cout << "#########################################################################################" << endl;
      cout << "#                                                                                       #" << endl;
      cout << "#    TAPEZ VOTRE PSEUDO                                                                 #" << endl;
      cout << "#                                                                                       #" << endl;
      cout << "#########################################################################################" << endl;
      cout << "> ";
      cin >> pseudoJoueur;
    }
    return (pseudoJoueur);
  }

  // Afficher la demande de difficulté souhaitée du jeu
  int afficherDemandeForceJeuJoueur(int modeJoueur)
  {
    int forcePartie;
    int i(0);
    if (modeJoueur == 1)
    {
      forcePartie = _constante::forceJeuFacile; // Difficulté par defaut en mode test
    }
    else
    {
      do
      {
        if (i > 0)
        {
          _fonction::effacerTerminal();
          _fonction::afficherContenuFichierTerminal(_constante::fichierLogo);
        }
        _fonction::effacerTerminal();
        _fonction::afficherContenuFichierTerminal(_constante::fichierLogo);
        cout << "#### DIFFICULTE DE LA PARTIE ############################################################" << endl;
        cout << "#                                                                                       #" << endl;
        cout << "#    TAPEZ " << _constante::forceJeuFacile << ": FACILE                                                                    #" << endl;
        cout << "#    TAPEZ " << _constante::forceJeuMoyen << ": MOYEN                                                                     #" << endl;
        cout << "#    TAPEZ " << _constante::forceJeuDifficile << ": DIFFICILE                                                                 #" << endl;
        cout << "#                                                                                       #" << endl;
        cout << "#########################################################################################" << endl;
        cout << "> Tapez:";
        cin >> forcePartie;
        i++;
      } while (forcePartie < _constante::forceJeuFacile || forcePartie > _constante::forceJeuDifficile);
    }
    return (forcePartie);
  }

  // Calculer et retourner la jauge Santé en pourcentage
  int calculerJaugeIndicateurSantePourcentage(int sante)
  {

    sante = (sante * 100) / _constante::indicateurSantePlayerDefaut;
    return sante;
  }

  // Afficher les données utilisateurs selon la situation dans le jeu (0 - avant partie, 1 - pendant la partie, 2 - fin de partie)
  void afficherDataJeuJoueur(int momentJeu, int modeJoueur, int force, int sante, string nomJoueur, int nbrJeu, int nbrJocker, int score, bool avecSautLigneDebut = false, bool avecSautLigneFin = false)
  {

    if (avecSautLigneDebut) // Saut de ligne en fin d'ecriture sur l'ecran
      cout << endl;

    // Affichage debut jeux
    if (momentJeu == _constante::debutJeux)
    {
      _fonction::effacerTerminal();
      _fonction::afficherContenuFichierTerminal(_constante::fichierLogo);
      cout << "+=======================================================================================/" << endl;
      cout << "| Salut " << nomJoueur << "!" << endl;
      cout << "|=======================================================================================/" << endl;
      cout << "|    " << endl;
      cout << "|    "
           << "MODE.........." << (modeJoueur > 0 ? "Test" : "Normal") << endl;
      cout << "|    "
           << "DIFFICULTÉ....";
      if (force == _constante::forceJeuFacile)
      {
        cout << "Facile" << endl;
      }
      else if (force == _constante::forceJeuMoyen)
      {
        cout << "Moyen" << endl;
        ;
      }
      else if (force == _constante::forceJeuDifficile)
      {
        cout << "Difficile" << endl;
        ;
      }
      cout << "|    "
           << "SCORE........." << score << " pts" << endl;
      cout << "|    "
           << "JOCKER........" << nbrJocker << endl;
      cout << "|    "
           << "JAUGE SANTÉ..." << _fonction::calculerJaugeIndicateurSantePourcentage(sante) << "%" << endl;
      cout << "|" << endl;
      cout << "+=======================================================================================/" << endl;

    } // Fin affichage debut jeux

    // Affichage jeux en cours
    if (momentJeu == _constante::encoursJeux)
    {
      cout << endl;
      cout << "+=======================================================================================/" << endl;
      cout << "| Joueur: " << nomJoueur << endl;
      cout << "|=======================================================================================/" << endl;
      cout << "|    " << endl;
      cout << "|    "
           << "MODE.........." << (modeJoueur > 0 ? "Test" : "Normal") << endl;
      cout << "|    "
           << "DIFFICULTÉ....";
      if (force == _constante::forceJeuFacile)
      {
        cout << "Facile" << endl;
      }
      else if (force == _constante::forceJeuMoyen)
      {
        cout << "Moyen" << endl;
        ;
      }
      else if (force == _constante::forceJeuDifficile)
      {
        cout << "Difficile" << endl;
        ;
      }
      cout << "|    "
           << "SCORE........." << score << " pts" << endl;
      cout << "|    "
           << "JOCKER........" << nbrJocker << endl;
      cout << "|    "
           << "JAUGE SANTÉ..." << _fonction::calculerJaugeIndicateurSantePourcentage(sante) << "%" << endl;
      cout << "|" << endl;

    } // Fin affichage debut jeux

    if (avecSautLigneFin) // Saut de ligne en fin d'ecriture sur l'ecran
      cout << endl;
  }

  // Confirmer Début une nouvelle partie
  void debuterNouvellePartie(int modeJoueur, int &joueuretapeJeux, int &joueurnombrePartie)
  {
    string jeCommence;

    do
    {
      cout << "Démarrer une nouvelle partie maintenant? (o/n) > ";
      cin >> jeCommence;
      _fonction::effacerTerminal();
      _fonction::afficherContenuFichierTerminal(_constante::fichierLogo);

    } while ((jeCommence != "o" && jeCommence != "O") && (jeCommence != "n" && jeCommence != "N"));

    if (jeCommence == "o" || jeCommence == "O")
    {
      // Changer etat jeu du joueur
      joueuretapeJeux = _constante::encoursJeux;
      // Incrémenter le nbr de partie jouée
      joueurnombrePartie += 1;
    }
  }

  // Afficher le menu action joeur
  int afficherMenuActionJoueur()
  {
    int forcePartie;
    int i(0);

    do
    {
      cout << "+=== ACTIONS JOUEUR ====================================================================/" << endl;
      cout << "|" << endl;
      cout << "|    TAPEZ " << _constante::forceJeuFacile << ": FACILE" << endl;
      cout << "|    TAPEZ " << _constante::forceJeuMoyen << ": MOYEN" << endl;
      cout << "|    TAPEZ " << _constante::forceJeuDifficile << ": DIFFICILE" << endl;
      cout << "|" << endl;
      cout << "+=======================================================================================/" << endl;
      cout << "> Tapez:";
      cin >> forcePartie;
      i++;
    } while (forcePartie < _constante::forceJeuFacile || forcePartie > _constante::forceJeuDifficile);

    return (forcePartie);
  }

  //
  void calculerIndicesPresenceMine(_structure::grille &uneGrille)
  {
    // Boucle FOR imbriquées
    for (int i = 0; i < uneGrille.nbrLigne; ++i)
    {
      for (int j = 0; j < uneGrille.nbrColonne; ++j)
        if (uneGrille.Tableau[i][j] == _constante::mineCodeMarquage)
        {
          // cout << "Li:" << i << "-Col:" << j << " / ";
          //  Nord
          if (i - 1 > -1 && uneGrille.Tableau[i - 1][j] != _constante::mineCodeMarquage)
            uneGrille.Tableau[i - 1][j]++;

          // Sud
          if (i + 1 < _constante::nbrLigneGrilleJeu && uneGrille.Tableau[i + 1][j] != _constante::mineCodeMarquage)
            uneGrille.Tableau[i + 1][j]++;

          // Est
          if (j + 1 < _constante::nbrColonneGrilleJeu && uneGrille.Tableau[i][j + 1] != _constante::mineCodeMarquage)
            uneGrille.Tableau[i][j + 1]++;

          // Ouest
          if (j - 1 > -1 && uneGrille.Tableau[i][j - 1] != _constante::mineCodeMarquage)
            uneGrille.Tableau[i][j - 1]++;

          // Nord Ouest
          if ((i - 1 > -1) && (j - 1 > -1) && (uneGrille.Tableau[i - 1][j - 1] != _constante::mineCodeMarquage))
            uneGrille.Tableau[i - 1][j - 1]++;

          // Nord Est
          if ((i - 1 > -1) && (j + 1 < _constante::nbrColonneGrilleJeu) && (uneGrille.Tableau[i - 1][j + 1] != _constante::mineCodeMarquage))
            uneGrille.Tableau[i - 1][j + 1]++;

          // Sud Ouest
          if ((i + 1 < _constante::nbrLigneGrilleJeu) && (j - 1 > -1) && (uneGrille.Tableau[i + 1][j - 1] != _constante::mineCodeMarquage))
            uneGrille.Tableau[i + 1][j - 1]++;

          // Sud Est
          if ((i + 1 < _constante::nbrLigneGrilleJeu) && (j + 1 < _constante::nbrColonneGrilleJeu) && (uneGrille.Tableau[i + 1][j + 1] != _constante::mineCodeMarquage))
            uneGrille.Tableau[i + 1][j + 1]++;
        }
    }
    // uneGrille.Tableau[0][7] = 9;
  }

  // Affichage d'une grille Joueur
  void affichageGrilleJoueur(_structure::grille &uneGrille)
  {
    cout << "++ GRILLE JOUEUR ++";
    cout << endl;
    cout << endl;
    // Chiffre dessus
    for (int i = 0; i < uneGrille.nbrLigne; i++)
    {
      cout << "\t" << i + 1 << "\t";
    }
    cout << endl;
    // Trait dessus

    for (int i = 0; i < uneGrille.nbrLigne; i++)
    {
      cout << "  ....."
           << "....."
           << "..."
           << "\t";
    }

    cout << endl;

    // Ligne verticale
    for (int i = 0; i < uneGrille.nbrLigne; i++)
    {
      // Ligne1
      for (int j = 0; j < uneGrille.nbrColonne; j++)
      {
        if (i % 1 == 0 && j == 0)
          cout << " |";
        cout << "\t";

        if (uneGrille.Tableau[i][j] == _constante::mineCodeMarquage)
        {
          cout << " ";
        }
        else
        {
          cout << " ";
        }

        cout << "\t";
        cout << "|";
      }
      cout << endl;
      // Ligne 2
      for (int j = 0; j < uneGrille.nbrColonne; j++)
      {
        if (i % 1 == 0 && j == 0)
          cout << " |";
        cout << "\t";

        if (uneGrille.Tableau[i][j] == _constante::mineCodeMarquage)
        {
          cout << " ";
        }
        else
        {
          cout << " ";
        }

        cout << "\t";
        cout << "|";
      }
      cout << endl;
      // Ligne3
      for (int j = 0; j < uneGrille.nbrColonne; j++)
      {
        if (i % 1 == 0 && j == 0)
          cout << i + 1 << "|";
        cout << "\t";

        if (uneGrille.Tableau[i][j] == _constante::mineCodeMarquage)
        {
          cout << "💣";
        }
        else
        {
          cout << uneGrille.Tableau[i][j];
        }

        cout << "\t";
        cout << "|";
      }
      cout << endl;
      // Ligne4
      for (int j = 0; j < uneGrille.nbrColonne; j++)
      {
        if (i % 1 == 0 && j == 0)
          cout << " |";
        cout << "\t";

        if (uneGrille.Tableau[i][j] == _constante::mineCodeMarquage)
        {
          cout << " ";
        }
        else
        {
          cout << " ";
        }

        cout << "\t";
        cout << "|";
      }
      cout << endl;
      // Ligne5
      for (int j = 0; j < uneGrille.nbrColonne; j++)
      {
        if (i % 1 == 0 && j == 0)
          cout << " |";
        cout << "\t";

        if (uneGrille.Tableau[i][j] == _constante::mineCodeMarquage)
        {
          cout << " ";
        }
        else
        {
          cout << " ";
        }

        cout << "\t";
        cout << "|";
      }
      cout << endl;
    }

    for (int i = 0; i < uneGrille.nbrLigne; i++)
    {
      cout << "  ....."
           << "....."
           << "..."
           << "\t";
    }
    cout << endl;
  }

  // Affichage d'une grille Machine
  void affichageGrilleMachine(_structure::grille &uneGrille)
  {

    // Calcul des indices de présence voisine de mines
    _fonction::calculerIndicesPresenceMine(uneGrille);

    cout << "++ GRILLE MACHINE ++";
    cout << endl;
    cout << endl;
    // Chiffre dessus
    for (int i = 0; i < uneGrille.nbrLigne; i++)
    {
      cout << "\t" << i + 1 << "\t";
    }
    cout << endl;
    // Trait dessus

    for (int i = 0; i < uneGrille.nbrLigne; i++)
    {
      cout << "  ....."
           << "....."
           << "..."
           << "\t";
    }

    cout << endl;

    // Ligne verticale
    for (int i = 0; i < uneGrille.nbrLigne; i++)
    {
      // Ligne1
      for (int j = 0; j < uneGrille.nbrColonne; j++)
      {
        if (i % 1 == 0 && j == 0)
          cout << " |";
        cout << "\t";

        if (uneGrille.Tableau[i][j] == _constante::mineCodeMarquage)
        {
          cout << " ";
        }
        else
        {
          cout << " ";
        }

        cout << "\t";
        cout << "|";
      }
      cout << endl;
      // Ligne 2
      for (int j = 0; j < uneGrille.nbrColonne; j++)
      {
        if (i % 1 == 0 && j == 0)
          cout << " |";
        cout << "\t";

        if (uneGrille.Tableau[i][j] == _constante::mineCodeMarquage)
        {
          cout << " ";
        }
        else
        {
          cout << " ";
        }

        cout << "\t";
        cout << "|";
      }
      cout << endl;
      // Ligne3
      for (int j = 0; j < uneGrille.nbrColonne; j++)
      {
        if (i % 1 == 0 && j == 0)
          cout << i + 1 << "|";
        cout << "\t";

        if (uneGrille.Tableau[i][j] == _constante::mineCodeMarquage)
        {
          cout << "💣";
        }
        else
        {
          cout << uneGrille.Tableau[i][j];
        }

        cout << "\t";
        cout << "|";
      }
      cout << endl;
      // Ligne4
      for (int j = 0; j < uneGrille.nbrColonne; j++)
      {
        if (i % 1 == 0 && j == 0)
          cout << " |";
        cout << "\t";

        if (uneGrille.Tableau[i][j] == _constante::mineCodeMarquage)
        {
          cout << " ";
        }
        else
        {
          cout << " ";
        }

        cout << "\t";
        cout << "|";
      }
      cout << endl;
      // Ligne5
      for (int j = 0; j < uneGrille.nbrColonne; j++)
      {
        if (i % 1 == 0 && j == 0)
          cout << " |";
        cout << "\t";

        if (uneGrille.Tableau[i][j] == _constante::mineCodeMarquage)
        {
          cout << " ";
        }
        else
        {
          cout << " ";
        }

        cout << "\t";
        cout << "|";
      }
      cout << endl;
    }

    for (int i = 0; i < uneGrille.nbrLigne; i++)
    {
      cout << "  ....."
           << "....."
           << "..."
           << "\t";
    }
    cout << endl;
  }
  // Démarrer le chrono de la partie
  void demarrerChronoPartie(time_t &tempsDepart)
  {
    tempsDepart = time(0);
  }

  // Arrêter le chrono de la partie
  void arreterChronoPartie(time_t &tempsFin)
  {
    tempsFin = time(0);
  }

  int calculerNbrMines(int forceJeu, int nbrColonne, int nbrLigne)
  {
    int nbrMines;
    if (forceJeu == _constante::forceJeuFacile)
    {
      nbrMines = (nbrColonne * nbrLigne) / (nbrColonne + nbrLigne);
    }
    else if (forceJeu == _constante::forceJeuMoyen)
    {
      nbrMines = ((nbrColonne * nbrLigne) / (nbrColonne)) + 1;
    }
    else if (forceJeu == _constante::forceJeuDifficile)
    {
      nbrMines = ((nbrColonne * nbrLigne) / (nbrColonne / 2));
    }

    return (nbrMines);
  }

  // Remplir la grille de mines de façon aléatoire et selon la difficulté
  void minerGrilleMachine(_structure::grille &grilleMachine, int forceJeu, int nbrColonne, int nbrLigne)
  {

    int nbrMines(0);

    // retourner le nombre de mines en fonction de la difficulté
    nbrMines = calculerNbrMines(forceJeu, nbrColonne, nbrLigne);

    // Remplir avec boucle
    for (int i = 0; i < nbrMines; i++)
    {
      int x = rand() % (nbrColonne - 1) + 0;                      // Colonne aléatoire
      int y = rand() % (nbrLigne - 1) + 0;                        // Ligne aléatoire
      grilleMachine.Tableau[x][y] = _constante::mineCodeMarquage; // x est le code de présence de mine dans la case
    }
  }

  // Remettre à zéro une grille
  void initialiserZeroGrille(_structure::grille &uneGrille)
  {
    // Boucle FOR imbriquées
    for (int i = 0; i < uneGrille.nbrLigne; i++)
    {
      for (int j = 0; j < uneGrille.nbrColonne; j++)
        uneGrille.Tableau[i][j] = 00;
    }
  }

  // Creer un tableau à 2 dimensions
  int **creerTableau2D(int nbrColonne, int nbrLigne)
  {
    int **p = new int *[nbrLigne];
    for (int i = 0; i < nbrLigne; i++)
    {
      p[i] = new int[nbrColonne];
    }
    return (p);
  }

  // Instancier une structure grille
  _structure::grille *instancierGrille(int nbrColonne, int nbrLigne, bool grillePrivate = true)
  {
    _structure::grille *p = new _structure::grille;
    (*p).nbrColonne = nbrColonne;
    (*p).nbrLigne = nbrLigne;
    (*p).grillePrivate = grillePrivate; // Grille privée ou public
    (*p).Tableau = _fonction::creerTableau2D(nbrColonne, nbrLigne);
    return (p);
  }

  // Initialiser une nouvelle partie de jeu
  void initialisationJeu(int modeJeux, int forceJeu, time_t &tempsDepart, time_t &tempsFin, int &etapeJeux, int &indicateurSante, string pseudo, int &nombrePartie, int &nombreJocker, int &totalScore)
  {
    // Départ du chrono
    demarrerChronoPartie(tempsDepart);

    // Instance de la structure Grille en une grilleMachine qui comportera tous les éléments cachés (mines, les indices de présences de mines)
    _structure::grille *grilleMachine = _fonction::instancierGrille(_constante::nbrColonneGrilleJeu, _constante::nbrLigneGrilleJeu);

    // Instance de la structure Grille en une grilleJoueur qui comportera tous les éléments visibles et réels de la partie
    _structure::grille *grilleJoueur = _fonction::instancierGrille(_constante::nbrColonneGrilleJeu, _constante::nbrLigneGrilleJeu, _constante::grillePublic);

    //(*grilleMachine).Tableau[1][5] = 14;
    //(*grilleJoueur).Tableau[1][5] = 12;

    // Initialiser la grilleMachine
    initialiserZeroGrille(*grilleMachine);

    // Initialiser la grilleJoueur
    initialiserZeroGrille(*grilleJoueur);

    // Remplir la grille grilleMachine
    minerGrilleMachine((*grilleMachine), forceJeu, (*grilleMachine).nbrColonne, (*grilleMachine).nbrLigne);

    // Remplir les indices de présence de mines sur la grille grilleMachine

    // Jeux
    do
    {
      // Effacer ecran terminal
      _fonction::effacerTerminal();

      // Affichage grilleMachine en mode test
      if (modeJeux == 1)
      {

        _fonction::affichageGrilleMachine((*grilleMachine));
      }

      // Affichage grilleJoueur
      _fonction::affichageGrilleJoueur((*grilleJoueur));

      // Affichage des données initiales avant la partie (0 - avant partie, 1 - pendant la partie, 2 - fin de partie)
      _fonction::afficherDataJeuJoueur(etapeJeux, modeJeux, forceJeu, indicateurSante, pseudo, nombrePartie, nombreJocker, totalScore);

      // Affiche le menu Joueur
      _fonction::afficherMenuActionJoueur();

    } while (etapeJeux != _constante::finJeux);
  }

  // Fin du namespace
}
#endif