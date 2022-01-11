// D�mineur.cpp�: d�finit le point d'entr�e pour l'application console.
// Projet de cr�ation du d�mineur
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

typedef enum
{
	faux,
	vrai
}; // type bool�en pour enum�rer vrai ou faux � chaque it�ration
const int m = 10;
const int n = 10;

/*========================================================================
	|--|
	|1 |  SAISIR LE NOMBRE DE MINES QUE L'ON SOUHAITE
	|--|
=========================================================================*/
int saisir_nb_mines(int m, int n)
{
	int nb;

	do
	{
		cout << "Veuillez saisir le nombre de mines que vous voulez placez" << endl
				 << endl;
		cin >> nb;
	} while (nb <= 0 || nb > m * n);

	return (nb);
}
/*========================================================================
	|--|
	|2 |  INITIALISE TOUTES LES CASES DU TABLEAU BIDIMETIONNEL A 0
	|--|
=========================================================================*/
void init_tab_2Dentier_0(int M[m][n], int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			M[i][j] = 0;
		}
	}
}
/*ALGORITHME DE PROGRESSION PAS A PAS { 3 et 4 } */
/*========================================================================
	|--|
	|3 |  AFFICHER LE TABLEAU AVEC TOUT SES 0
	|--|
=========================================================================*/
/*void afficher_tab2Dentier(int M[m][n], int m, int n){
	int i,j=0;

	cout<<"0 1 2 3 4 5 6 7 8 9"<<endl<<endl;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cout<<""<<M[i][j]<<" " ;
		}
		cout<<"  "<<i;
		cout<<endl<<endl;
	}
}*/
/*========================================================================
	|--|
	|4 |  PLACE LES MINES DE MANIERE ALEATOIRE
	|--|
=========================================================================*/
/*void placer_mines(int M[m][n], int m, int n, int nb_mines){

	int i,j;
	srand(time(0));
	rand();

	do{
		i = int(((double)(rand())/RAND_MAX)*m);
		j = int(((double)(rand())/RAND_MAX)*n);
		if (M[i][j] != -1) {M[i][j] = -1; nb_mines--;}
	}while(nb_mines!=0);

}
*/
/*========================================================================
	|--|
	|5 |  PLACE LES MINES DE MANIERE ALEATOIRE + INITIALISE LES 8 CASES AUTOUR DE LA MINE
	|--|
=========================================================================*/
void initialiser_champ(int M[m][n], int m, int n, int nb_mines)
{

	int i, j;
	srand(time(0));
	rand();

	do
	{
		i = int(((double)(rand()) / RAND_MAX) * m);
		j = int(((double)(rand()) / RAND_MAX) * n);
		if (M[i][j] != 9)
		{
			M[i][j] = 9;
			nb_mines--;
		}
	} while (nb_mines != 0);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			/* 1 */ if (M[i][j] != 9 && M[i + 1][j + 1] == 9 && j < n - 1)
				M[i][j]++; //	1	2	3  //
			/* 2 */ if (M[i][j] != 9 && M[i + 1][j] == 9)
				M[i][j]++; //  #	#	#  //
			/* 3 */ if (M[i][j] != 9 && M[i + 1][j - 1] == 9 && j > 0)
				M[i][j]++; //	   ---	   //
			/* 4 */ if (M[i][j] != 9 && M[i][j + 1] == 9 && j < n - 1)
				M[i][j]++; //  4  |9|	5  //
			/* 5 */ if (M[i][j] != 9 && M[i][j - 1] == 9 && j > 0)
				M[i][j]++; //	#  |9|	#  //
			/* 6 */ if (M[i][j] != 9 && M[i - 1][j + 1] == 9 && j < n - 1)
				M[i][j]++; //	   ---	   //
			/* 7 */ if (M[i][j] != 9 && M[i - 1][j] == 9)
				M[i][j]++; //	6	7	8  //
			/* 8 */ if (M[i][j] != 9 && M[i - 1][j - 1] == 9 && j > 0)
				M[i][j]++; //	#	#	#  //
		}
	}
}
/*========================================================================
	|--|
	|6 |  VARIABLE BOOLEENNE V INIATIALISER A FAUX POUR TOUTES LES CASES DU TABLEAU
	|--|
=========================================================================*/
void init_tab2Dbool(bool V[m][n], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			V[i][j] = false;
		}
	}
}
/*========================================================================
	|--|
	|7 |  AFFICHE LE TABLEAU SELON LE CARACTERE BOOLEEN DE V
	|--|
=========================================================================*/
void afficher_champ(bool V[m][n], int M[m][n], int m, int n, char vf, char vm)
{
	for (int i = 0; i < m; i++)
	{
		cout << " " << i;
	}
	cout << endl
			 << endl
			 << " ";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (V[i][j] == true)
			{
				if (M[i][j] != 9)
					cout << M[i][j] << " ";
				if (M[i][j] == 9)
					cout << vm << " ";
			}
			else
				cout << vf << " ";
		}
		cout << "  " << i;
		cout << endl
				 << endl
				 << " ";
	}
}
/*========================================================================
	|--|
	|8 |  RETOURNE LE NOMBRE D'ELEMENT VISIBLE
	|--|
=========================================================================*/
int nb_el_visible(bool V[m][n], int m, int n)
{
	int ele;
	ele = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (V[i][j] == true)
			{
				ele = ele + 1;
			}
		}
	}
	return (ele);
}
/*========================================================================
	|--|
	|9 |  REND VISIBLE TOUTES LES MINES
	|--|
=========================================================================*/
void decouverte_mines(bool V[m][n], int M[m][n], int m, int n)
{

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (M[i][j] == 9)
			{
				V[i][j] = true;
			}
		}
	}
}
/*========================================================================
	|---|
	|10 |  AFFICHE TOUTES LES CASES AYANT 0 ET + PAR RECURSIVITE
	|---|
=========================================================================*/
void decouvrir_carre(bool V[m][n], int M[m][n], int m, int n, int i, int j)
{
	if (V[i][j] == false)
	{
		V[i][j] = true;
		if (M[i][j] == 0)
		{
			if (i > 0)
			{
				decouvrir_carre(V, M, m, n, i - 1, j);
			}
			if (i > 0 && j > 0)
			{
				decouvrir_carre(V, M, m, n, i - 1, j - 1);
			}
			if (j > 0)
			{
				decouvrir_carre(V, M, m, n, i, j - 1);
			}
			if (j > 0 && i < m - 1)
			{
				decouvrir_carre(V, M, m, n, i + 1, j - 1);
			}
			if (i < m - 1)
			{
				decouvrir_carre(V, M, m, n, i + 1, j);
			}
			if (i > m - 1 && j < n - 1)
			{
				decouvrir_carre(V, M, m, n, i + 1, j + 1);
			}
			if (j < n - 1)
			{
				decouvrir_carre(V, M, m, n, i, j + 1);
			}
			if (i > 0 && j < n - 1)
			{
				decouvrir_carre(V, M, m, n, i - 1, j + 1);
			}
		}
	}
}
/*========================================================================
	|-------|
	|11 bis |  BONUS
	|-------|
=========================================================================*/
// PERMET d'afficher des infos � chaque affichage du tableau
void CLS(int nb, int ele, int coup)
{
	system("CLS");
	cout << "__________________________________________________" << endl;
	cout << "Nombres de Mines en jeu : " << nb << endl
			 << endl;
	cout << "Cases visibles : " << ele << endl
			 << endl;
	cout << "Nombre de coup joue : " << coup << endl;
	cout << "__________________________________________________" << endl
			 << endl
			 << endl;
}
// une proc�dure pour quittez quand le jeu est terminer
void quitter(char menu)
{
	cout << "Voulez-vous recommencer\? O/N ";
	do
	{
		cin >> menu;
		if (menu != 'O' && menu != 'o' && menu != 'N' && menu != 'n')
			cout << "Mauvais caractere" << endl;
	} while (menu != 'O' && menu != 'o' && menu != 'N' && menu != 'n');
	if (menu == 'O' || menu == 'o')
	{
		system("CLS");
	}
	if (menu == 'N' || menu == 'n')
	{
		exit(0);
	}
}
/*========================================================================
	|---|
	|11 |  PROGRAMME PRINCIPAL
	|---|
=========================================================================*/
int main(int argc)
{ // permet de lancer l'application en fullscreen, gr�ce a l'appel de windows.h
	typedef BOOL(WINAPI * PFONCTION)(HANDLE, DWORD, PCOORD);
	HMODULE hDLL = LoadLibrary("kernel32.dll");
	PFONCTION SetDisplayMode = (PFONCTION)GetProcAddress(hDLL, "SetConsoleDisplayMode");
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	SetDisplayMode(hconsole, 1, &coord);
	// fin fullscreen

	int champ[m][n], nb, ele, l, c, coup;
	int couleur1, couleur2;
	bool visible[m][n];
	char vf, vm, menu;

	vf = '-';
	vm = '*';
	menu = ' ';

	textcolor(30); // affiche la console sur la couleur 30 -ecriture en jaune, fond en bleu
	system("CLS"); // actualise la console, sinon la couleur reste sur "n" caract�re imprim�

	do
	{
		ele = 0;
		coup = 0;

		nb = saisir_nb_mines(m, n);
		system("CLS");
		init_tab_2Dentier_0(champ, m, n);
		// placer_mines(champ, m, n, nb);
		initialiser_champ(champ, m, n, nb);
		init_tab2Dbool(visible, m, n);

		do
		{
			CLS(nb, ele, coup); // affiche les infos en haut du tableau
			afficher_champ(visible, champ, m, n, vf, vm);
			do
			{
				cout << endl
						 << "Entrez la ligne du carre a rendre visible : ";
				cin >> l;
			} while (l < 0 && l > m);
			do
			{
				cout << endl
						 << "Entrez la colonne du carre a rendre visible : ";
				cin >> c;
			} while (c < 0 && c > n);
			coup++;
			if (champ[l][c] != 9)
			{
				decouvrir_carre(visible, champ, m, n, l, c);
				ele = nb_el_visible(visible, m, n);
				CLS(nb, ele, coup); // permettra d'afficher les infos en sorti de boucle, cad sur l'�tat gagnant
			}
		} while ((nb + ele < n * m) && (champ[l][c] != 9));
		if (champ[l][c] == 9)
		{
			CLS(nb, ele, coup);
			decouverte_mines(visible, champ, m, n);
			afficher_champ(visible, champ, m, n, vf, vm);
			cout << endl
					 << endl
					 << endl
					 << endl
					 << "-----   -----  -----   -----   |    | " << endl;
			cout << "|    |  |      |    |  |    \\  |    | " << endl;
			cout << "|----   |----  |----   |    |  |    | " << endl;
			cout << "|       |      |   \\   |    /  |    | " << endl;
			cout << "|       -----  |    \\  -----   ------ \a" << endl
					 << endl
					 << endl
					 << endl
					 << endl
					 << endl
					 << endl
					 << endl
					 << endl
					 << endl;
			quitter(menu); // continuer ou quitter
		}
		else
		{
			decouverte_mines(visible, champ, m, n);
			afficher_champ(visible, champ, m, n, vf, vm);
			cout << endl
					 << endl
					 << endl
					 << endl
					 << "-------      /\\      -------   |\\    |   ------     *  * " << endl;
			cout << "|           /  \\     |         | \\   |   |          *  * " << endl;
			cout << "| |---|    /----\\    | |---|   |  \\  |   |-----     *  * " << endl;
			cout << "|     |   /      \\   |     |   |   \\ |   | " << endl;
			cout << "-------  /        \\  -------   |    \\|   ------     #  # \a \a" << endl
					 << endl
					 << endl
					 << endl
					 << endl
					 << endl
					 << endl
					 << endl
					 << endl
					 << endl;
			quitter(menu);
		}
	} while (m > 0);

	// afficher_tab2Dentier(champ, m, n);

	return 0;
}
