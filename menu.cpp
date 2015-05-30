#include <iostream>
#include <windows.h>
#include <cstddef>
#include <conio.h>
#include <fstream>
#include <wincon.h>


using namespace std;


void gotoxy( const int x, const int y )
{
    COORD coord = { x, y };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}


void tytul()
{

	HANDLE hOut;
	gotoxy(40,5);
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	SetConsoleTextAttribute( hOut, BACKGROUND_RED );
	SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
	cout<<"PROGRAM - MENU Z OPCJAMI WYBORU";
	SetConsoleTextAttribute( hOut, BACKGROUND_BLUE );
	
	gotoxy(30,1);
	cout<< (char)217;
	for (int i=0; i<50; i++)
	{
	cout<< (char)196;
    }  
	
	gotoxy(80,1);
	cout<< (char)170;
	for (int i=0; i<10; i++)
	{
	gotoxy(80,2+i);	
	cout<< (char)179;
    }  
	
	gotoxy(80,11);
	cout<< (char)217;
	for (int i=0; i<50; i++)
	{
	gotoxy(30+i,11);	
	cout<< (char)196;
    }
    gotoxy(30,11);
	cout<<(char)192;
    for (int i=0; i<10; i++) 
	{
	gotoxy(30,10-i);	
	cout<< (char)179;
    }  
    
	gotoxy(30,15);
	
	SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
}


int Akcja0()
{
	gotoxy(15,21);
	cout<<"Dzia�anie Akcji nr 0";
    return 0;
}

int Akcja1()
{
	gotoxy(15,23);
	cout<<"Dzia�anie Akcji nr 1";
    return 0;
}

int Akcja2()
{
	gotoxy(15,25);
	cout<<"Dzia�anie Akcji nr 2";
    return 0;
}

int Akcja3()
{
	gotoxy(15,27);
	cout<<"Dzia�anie Akcji nr 3";
    return 0;
}

int Akcja4()
{
	gotoxy(15,29);
	cout<<"Dzia�anie Akcji nr 4";
    return 0;
}

int main()
{
    int wybor;
    int poprzedniWybor;
    bool wykonujPetle;
    
    
	tytul();
	
	setlocale(LC_ALL,"Polish");
        
	while(true)
    {
        wybor = 0;
        poprzedniWybor = wybor;
        wykonujPetle = true;
       
        //rysowanie menu
        gotoxy( 3, 21 );
        cout << "Wyb�r A";
        gotoxy( 3, 23 );
        cout << "Wyb�r B";
        gotoxy( 3, 25 );
		cout << "Wyb�r C";
        gotoxy( 3, 27 );
        cout << "Wyb�r D";
        gotoxy( 3, 29 );
        cout << "Wyj�cie";
       
        //przesuwanie strza�ki
        while( wykonujPetle )
        {
            //rysowanie strza�ki wyboru
            gotoxy( 1, wybor * 2 + 21 );
            cout << static_cast < char >( 16 );
           
            //obs�uga klawiatury
            poprzedniWybor = wybor;
            switch( getch() )
            {
            case 13:
			   switch( wybor )
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
                     gotoxy(20,20);
					 cout<<"Bye, bye"; 
					 return 0;
                   }
			   
            case 224: //STRZA�KI
                switch( getch() )
                {
                case 72: //strza�ka w g�r�
                    if( 0 < wybor ) wybor--;
                    else wybor = 4;
                   
                    break;
                   
                case 80: //strza�ka w d�
                    if( wybor < 4 ) wybor++;
                    else wybor = 0;
                   
                    break;
                                   
                case 77: // enter wybor Akcji
                   switch( wybor )
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
                     gotoxy(20,20);
					 cout<<"Bye, bye"; 
					 return 0;
                   }
               }
                break;
            }
           
            //czyszczenie strza�ki wyboru
            gotoxy( 1, poprzedniWybor * 2 + 21 );
            cout << " ";       
	    }

    return 0;
   }
   
}

	
    
	

