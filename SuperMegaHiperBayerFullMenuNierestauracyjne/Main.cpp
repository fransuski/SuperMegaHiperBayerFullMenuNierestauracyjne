/****************************************************************** 

Program zaliczeniowy I rok INF Z, 2 semestr (2015)
Copyright by: Maciej Kajanek, Tomasz Fr�czyk, Krzystof Juszcze

Tytu�: SuperMegaHiperHipster ;) (wiadomo - do zmiany) /TF


******************************************************************/


/************************

Moje ma�e uwagi i pro�by:

1) Og�lnie starajmy si� u�ywa� angielskich nazw na zmienne i metody oraz CamelCase, bite :)
	Czemu ta pro�ba?
	Przyzwyczajenia!
	Przyzwyczaicie si� do PL nazw, a wsz�dzie w firmach s� angloj�zyczne i b�d� kwiatki w stylu: "OnNazwaPromocjiTextChanged"... :D
	Tak wi�c EN :)

2) Klasy trzymamy w osobnych plikach

Jak co�, to wyt�umacz� :)

3) Komentarze do kodu zapisujmy: "TF: jaki� koment", "KJ: jaki� koment" - b�dzie �atwiej
	Najlepiej u�ywa� region�w, ale to mo�e zrobi� na ko�cu.

4) Refactoring, Mastering ca�o�ci mog� zrobi� ja, bo co nieco wiem na ten temat ;)

5) Nie przejmujcie si� - w kupie si�a (no i nie mam na my�li tej kupy) ;)

6) zastanawiam si� na tym repozytorium GIT (taki Source Control do trzymania kodu w chmurze z dost�pem dla nas poprzez wtyczk� do VS) i my�l�, �e jak ka�dy z nas ma Visual Studio (Maciej - za�atw prosz� chocia� wersj� Community - jest za free, trzeba mie� chyba tylko konto MS'a, albo dost�p do DreamSpark'a)

7) Sorry, �e nie t�umacz� niekt�rych s��w, etc. ale licz� na Wasz� inteligencj�, kt�r� jak wiem - macie no i google zawsze pomo�e - nie ma PMS'a i innych takich tam :D

8) Powodzenia i do mi�ego kontaktu!

P.S. Na razie wszystko wrzucamy do tego pliku - na ko�cu to poro�dzielam, zreszt� dogadamy si� :) Do akcji na kodzie niestety preferuj� Skype'a, bo to fajnie dzia�a (��cznie z "szerowaniem" ekranu); 

**************************/


/****************************

TF: Poni�ej wrzucony po prostu (tak jak by�) kod Ma�ka - tak jak si� umawiali�my :) W razie rozwoju kodu b�d� refactoryzowa� kolejne cz�ci.
	Kod kompipluje si� i odpala poprzez F5 lub naci�ni�cie symbolu PLAY na g�rnym pasku.

	Enjoy!

*****************************/


#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <vector>
#include <conio.h>

using namespace std;

void gotoxy(const int x, const int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void tytul()
{

	HANDLE hOut;
	gotoxy(40, 5);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, BACKGROUND_RED);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "PROGRAM - MENU Z OPCJAMI WYBORU";
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);

	gotoxy(30, 1);
	cout << (char)217;
	for (int i = 0; i<50; i++)
	{
		cout << (char)196;
	}

	gotoxy(80, 1);
	cout << (char)170;
	for (int i = 0; i<10; i++)
	{
		gotoxy(80, 2 + i);
		cout << (char)179;
	}

	gotoxy(80, 11);
	cout << (char)217;
	for (int i = 0; i<50; i++)
	{
		gotoxy(30 + i, 11);
		cout << (char)196;
	}
	gotoxy(30, 11);
	cout << (char)192;
	for (int i = 0; i<10; i++)
	{
		gotoxy(30, 10 - i);
		cout << (char)179;
	}

	gotoxy(30, 15);

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}


int Akcja0()
{
	gotoxy(15, 21);
	cout << "Dzia�anie Akcji nr 0";
	return 0;
}

int Akcja1()
{
	gotoxy(15, 23);
	cout << "Dzia�anie Akcji nr 1";
	return 0;
}

int Akcja2()
{
	gotoxy(15, 25);
	cout << "Dzia�anie Akcji nr 2";
	return 0;
}

int Akcja3()
{
	gotoxy(15, 27);
	cout << "Dzia�anie Akcji nr 3";
	return 0;
}

int Akcja4()
{
	gotoxy(15, 29);
	cout << "Dzia�anie Akcji nr 4";
	return 0;
}






/************************ START: G��wna metoda startowa ***************************/


int main(void)
{
	int wybor;
	int poprzedniWybor;
	bool wykonujPetle;


	tytul();

	setlocale(LC_ALL, "Polish");

	while (true)
	{
		wybor = 0;
		poprzedniWybor = wybor;
		wykonujPetle = true;

		//rysowanie menu
		gotoxy(3, 21);
		cout << "Wyb�r A";
		gotoxy(3, 23);
		cout << "Wyb�r B";
		gotoxy(3, 25);
		cout << "Wyb�r C";
		gotoxy(3, 27);
		cout << "Wyb�r D";
		gotoxy(3, 29);
		cout << "Wyj�cie";

		//przesuwanie strza�ki
		while (wykonujPetle)
		{
			//rysowanie strza�ki wyboru
			gotoxy(1, wybor * 2 + 21);
			cout << static_cast < char >(16);

			//obs�uga klawiatury
			poprzedniWybor = wybor;
			switch (_getch())  //TF: Zmiana z powodu na nie u�ywanie ju� getch() - kompilator nie przepu�ci� ;)
			{
			case 13:
				switch (wybor)
				{
				case 0:
					Akcja0();
					break;

				case 1:
					Akcja1();
					break;

				case 2:
					Akcja2();
					break;

				case 3:
					Akcja3();
					break;

				case 4:
					system("cls");
					gotoxy(20, 20);
					cout << "Bye, bye";
					return 0;
				}

			case 224: //STRZA�KI
				switch (_getch()) //TF: Zmiana z powodu na nie u�ywanie ju� getch() - kompilator nie przepu�ci� ;)
				{
				case 72: //strza�ka w g�r�
					if (0 < wybor) wybor--;
					else wybor = 4;

					break;

				case 80: //strza�ka w d�
					if (wybor < 4) wybor++;
					else wybor = 0;

					break;

				case 77: // enter wybor Akcji
					switch (wybor)
					{
					case 0:
						Akcja0();
						break;

					case 1:
						Akcja1();
						break;

					case 2:
						Akcja2();
						break;

					case 3:
						Akcja3();
						break;

					case 4:
						system("cls");
						gotoxy(20, 20);
						cout << "Bye, bye";
						return 0;
					}
				}
				break;
			}

			//czyszczenie strza�ki wyboru
			gotoxy(1, poprzedniWybor * 2 + 21);
			cout << " ";
		}

		
	}




	return 0;
}

/************************ END: G��wna metoda startowa ***************************/






