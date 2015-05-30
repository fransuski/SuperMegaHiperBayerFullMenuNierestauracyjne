/****************************************************************** 

Program zaliczeniowy I rok INF Z, 2 semestr (2015)
Copyright by: Maciej Kajanek, Tomasz Fr¹czyk, Krzystof Juszcze

Tytu³: SuperMegaHiperHipster ;) (wiadomo - do zmiany) /TF


******************************************************************/


/************************

Moje ma³e uwagi i proœby:

1) Ogólnie starajmy siê u¿ywaæ angielskich nazw na zmienne i metody oraz CamelCase, bite :)
	Czemu ta proœba?
	Przyzwyczajenia!
	Przyzwyczaicie siê do PL nazw, a wszêdzie w firmach s¹ anglojêzyczne i bêd¹ kwiatki w stylu: "OnNazwaPromocjiTextChanged"... :D
	Tak wiêc EN :)

2) Klasy trzymamy w osobnych plikach

Jak coœ, to wyt³umaczê :)

3) Komentarze do kodu zapisujmy: "TF: jakiœ koment", "KJ: jakiœ koment" - bêdzie ³atwiej
	Najlepiej u¿ywaæ regionów, ale to mo¿e zrobiê na koñcu.

4) Refactoring, Mastering ca³oœci mogê zrobiæ ja, bo co nieco wiem na ten temat ;)

5) Nie przejmujcie siê - w kupie si³a (no i nie mam na myœli tej kupy) ;)

6) zastanawiam siê na tym repozytorium GIT (taki Source Control do trzymania kodu w chmurze z dostêpem dla nas poprzez wtyczkê do VS) i myœlê, ¿e jak ka¿dy z nas ma Visual Studio (Maciej - za³atw proszê chocia¿ wersjê Community - jest za free, trzeba mieæ chyba tylko konto MS'a, albo dostêp do DreamSpark'a)

7) Sorry, ¿e nie t³umaczê niektórych s³ów, etc. ale liczê na Wasz¹ inteligencjê, któr¹ jak wiem - macie no i google zawsze pomo¿e - nie ma PMS'a i innych takich tam :D

8) Powodzenia i do mi³ego kontaktu!

P.S. Na razie wszystko wrzucamy do tego pliku - na koñcu to poroŸdzielam, zreszt¹ dogadamy siê :) Do akcji na kodzie niestety preferujê Skype'a, bo to fajnie dzia³a (³¹cznie z "szerowaniem" ekranu); 

**************************/


/****************************

TF: Poni¿ej wrzucony po prostu (tak jak by³) kod Maæka - tak jak siê umawialiœmy :) W razie rozwoju kodu bêdê refactoryzowa³ kolejne czêœci.
	Kod kompipluje siê i odpala poprzez F5 lub naciœniêcie symbolu PLAY na górnym pasku.

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
	cout << "Dzia³anie Akcji nr 0";
	return 0;
}

int Akcja1()
{
	gotoxy(15, 23);
	cout << "Dzia³anie Akcji nr 1";
	return 0;
}

int Akcja2()
{
	gotoxy(15, 25);
	cout << "Dzia³anie Akcji nr 2";
	return 0;
}

int Akcja3()
{
	gotoxy(15, 27);
	cout << "Dzia³anie Akcji nr 3";
	return 0;
}

int Akcja4()
{
	gotoxy(15, 29);
	cout << "Dzia³anie Akcji nr 4";
	return 0;
}






/************************ START: G³ówna metoda startowa ***************************/


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
		cout << "Wybór A";
		gotoxy(3, 23);
		cout << "Wybór B";
		gotoxy(3, 25);
		cout << "Wybór C";
		gotoxy(3, 27);
		cout << "Wybór D";
		gotoxy(3, 29);
		cout << "Wyjœcie";

		//przesuwanie strza³ki
		while (wykonujPetle)
		{
			//rysowanie strza³ki wyboru
			gotoxy(1, wybor * 2 + 21);
			cout << static_cast < char >(16);

			//obs³uga klawiatury
			poprzedniWybor = wybor;
			switch (_getch())  //TF: Zmiana z powodu na nie u¿ywanie ju¿ getch() - kompilator nie przepuœci³ ;)
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

			case 224: //STRZA£KI
				switch (_getch()) //TF: Zmiana z powodu na nie u¿ywanie ju¿ getch() - kompilator nie przepuœci³ ;)
				{
				case 72: //strza³ka w górê
					if (0 < wybor) wybor--;
					else wybor = 4;

					break;

				case 80: //strza³ka w dó³
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

			//czyszczenie strza³ki wyboru
			gotoxy(1, poprzedniWybor * 2 + 21);
			cout << " ";
		}

		
	}




	return 0;
}

/************************ END: G³ówna metoda startowa ***************************/






