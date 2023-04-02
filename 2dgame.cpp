#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
int x = 15;
int y = 15;
char L = 219;
int score = 0;
//user boat
char userboat1[4][9] = {{' ', ' ', ' ', '-', '-', '|', ' ', ' ', ' '},
{' ', ' ', ' ', '-', '-', '|', ' ', ' ', ' '},
 {' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' '},
 {L, L, L, L, L, L, L, '>', '>'}
 };

int enemyx = 110;
int enemyy = 2;
string enemydirection = "Up";
 
 //first enemy boat
char enemy1[7][9] = {{' ', ' ', ' ', ' ', '-', '-', '-', ' ', ' '},
                {' ', ' ', ' ', ' ', ')', '-', '(', ' ', ' '},
                {' ', ' ', ' ', ' ', '-', '-', '-', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', ' ', '-', '-', '-', '-', '-', '-', '-'},
                {'<', '[', '\\', 'B', 'A', 'N', 'G', '!', '/'},
                {' ', ' ', ' ', '-', '-', '-', '-', '-', ' '}};


//second enemy boat

char Benemy1[5][6] ={{' ',' ','-','-',' ',' '},
 {' ',' ','|','-',' ',' '},
 {'-','-','-','-','-','-'},
 {'\\','B','O','O','M','/'},
 {' ','-','-','-','-',' '}};


int Benemyy=5;
int Benemyx=5;
string Benemydirection = "Right";
 

//Third enemy boat

char Aenemy1[5][6]= {{' ',' ','-','-',' ',' '},
      {' ',' ','|','-',' ',' '}, 
      {'[','[','[','[','[','['}, 
      {'C','L','E','V','E','R'}, 
      {'-','-','-','-','-','-'}};

int Aenemyy=20;
int Aenemyx=90;
string Aenemydirection = "Up";

//four enemy boat

char Cenemy1[5][6] ={{' ',' ','-','-',' ',' '},
{' ',' ','|','-',' ',' '},
{'-','-','-','-','-','-'},
{'\\','B','O','O','M','/'},
{' ','-','-','-','-',' '}};


int Cenemyy=30;
int Cenemyx=5;
string Cenemydirection = "Right";

 



int bulletx[150];
int bullety[150];
bool isbulletactive[150];
int bulletcount = 0;

void gethelp();
void startlogo();
void userboat();
void eraseuserboat();
void moveuserboatright();
void moveuserboatleft();
void moveuserboatup();
void moveuserboatdown();

void enmeyboat();
void eraseenemy1();
void enemy1move();

void Benmeyboat();
void Beraseenemy();
void Benemymove();


void Aenmeyboat();
void Aeraseenemy();
void Aenemymove();


void Cenmeyboat();
void Ceraseenemy();
void Cenemymove();

void generatebullet();
void printbullet(int x, int y);
void erasebullet(int x, int y);
void makebulletinactive(int index);
void bulletcollisionwithenemy();
void movebullet();

void addscore();
void printscore();

void generateColors(int k);

void mainmenu();
void printmaze();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);



main()
{
   char key;    
  string choice;
  system("cls");
  generateColors(10);

  startlogo();
m:
  system("cls");
  mainmenu();
w:
cout<<endl;
  cout << "Enter your choice: ";
  cin >> choice;
  if (choice == "a")
  {
    cout << ">>>>>>>>>>>>>>>>>>>GAME START ";
    Sleep(1000);
    system("cls");
    printmaze();
    gotoxy(x, y);
    generateColors(5);
    userboat();
    enmeyboat();
    while (1)
    {
      Sleep(40);
      if (GetAsyncKeyState(VK_RIGHT))
      {
        moveuserboatright();
      }
      if (GetAsyncKeyState(VK_LEFT))
      {
        moveuserboatleft();
      } 
      if (GetAsyncKeyState(VK_UP))
      {
        moveuserboatup();
      }
      if (GetAsyncKeyState(VK_DOWN))
      {
        moveuserboatdown();
      }
      if (GetAsyncKeyState(VK_SPACE))
      {
        generatebullet();
      }
      

      movebullet();
      bulletcollisionwithenemy();
      generateColors(12);     
      enemy1move(); 
           generateColors(1); 
      Benemymove(); 
          generateColors(5);
      Aenemymove();
          generateColors(13);
      Cenemymove(); 
          generateColors(2);
      printscore();

     
    }
  }

  else if (choice == "b")
  {
    char key;
    system("cls");
    cout << ">>>>>>>>>>>>>>>>>>>>GET HELP MENUE" << endl;
    gethelp();
    cout << endl;
    cout << "Press any key to go to main menu : ";
    key = getch();
    goto m;
  }
  else if (choice == "c")
  {
  }
  else
  {
    cout << endl
         << endl
         << " OOPS !  your choice is wrong " << endl;
             cout << "Press any key to go to main menu : ";
    key = getch();
    goto w;
  }
}

void startlogo()
{
  cout << endl
       << endl;
  cout << "                                     |----                                               /                             " << endl;
  cout << "              eee                    | z |              eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee   ********************SHOOT!                                     " << endl;
  cout << "               eee                   |---|             eee                              \\                                      " << endl;
  cout << "                eee                  |                eee                                                                      " << endl;
  cout << "                 eee                eeee             eee eeeeeeeeeeee eeeeeeeeeeee                                              " << endl;
  cout << "                  eee             eee eee           eee  eee      eee eee      eee                   " << endl;
  cout << "                   eee           eee   eee         eee   eeeeeeeeeeee eeeeeeeeee                                 " << endl;
  cout << "                    eee        eee      eee       eee    eee      eee eee    eee                          " << endl;
  cout << "                     eeeeeeeeeeee        eeeeeeeeeee     eee      eee eee     eeeeeee  " << endl;
  cout << "                                                                                      " << endl;
  cout << "                                  eeeeeeeeeeee eeeeeeeeeeee                        " << endl;
  cout << "                                  eee      eee eee                  " << endl;
  cout << "                                  eee      eee eeeeeeeeeeee           " << endl;
  cout << "                                  eee      eee eee      " << endl;
  cout << "                                  eeeeeeeeeeee eee       " << endl;
  cout << endl;
  cout << "                                   eeeeeeeeeeee eee      eee eeeeeeeeeeee eeeeeeeeeeee eeeeeeeeeeee          " << endl;
  cout << "                                   eee          eee      eee     eee      eee      eee eee                     " << endl;
  cout << "                                   eeeeeeeeeeee eeeeeeeeeeee     eee      eeeeeeeeeeee eeeeeeeeeeee          " << endl;
  cout << "                                            eee eee      eee     eee      eee                   eee      " << endl;
  cout << "                                   eeeeeeeeeeee eee      eee eeeeeeeeeeee eee          eeeeeeeeeeee                   " << endl;

  cout << endl<<endl<<endl<<endl;

       
  cout << "_____________________________LOADING ";
  Sleep(500);
  generateColors(1);
  cout << " *****";
  Sleep(1000);
  generateColors(2);
  cout << " *****";
  Sleep(1000);
  generateColors(3);
  cout << " *****";
  Sleep(1000);
  generateColors(4);
  cout << " *****";
  Sleep(500);
  generateColors(7);
  cout << " *****";
  generateColors(10);
}
void userboat()
{

  gotoxy(x, y);
for(int row=0;row<4;row++)
{
  for(int col=0;col<9;col++)
 
  {
      cout<<userboat1[row][col];
  }
  y++;
  gotoxy(x, y);
}
y=y-4;
}

void enmeyboat()
{
  gotoxy(enemyx, enemyy);
for(int row=0;row<7;row++)
{
  for(int col=0;col<9;col++)
 
  {
      cout<<enemy1[row][col];
  }
  enemyy++;
  gotoxy(enemyx, enemyy);
}
enemyy=enemyy-7;
}
void eraseuserboat()

{

gotoxy(x, y);
for(int row=0;row<4;row++)
{ 
  for(int col=0;col<9;col++)
  {
      cout<<" ";
  }
    y++;
    gotoxy(x,y);
}
y=y-4;
}
void moveuserboatright()
{
  char next = getCharAtxy(x + 9, y);
  if (next == ' ')
  {
    eraseuserboat();
    x++;
    userboat();
  }

}
void moveuserboatleft()
{
  char next = getCharAtxy(x - 1, y);
  if (next == ' ')
  {
    eraseuserboat();
    x--;
    userboat();
  }
}
void moveuserboatup()
{
  char next = getCharAtxy(x, y - 1);
  if (next == ' ')
  {
    eraseuserboat();
    y--;
    userboat();
  }

}
void moveuserboatdown()
{
  char next = getCharAtxy(x, y + 4);
  if (next == ' ')
  {
    eraseuserboat();
    y++;
    userboat();
  }
}

void mainmenu()
{
  system("cls");
  gotoxy(40,15);
  cout << "(a)-------------START GAME-------------------------" <<endl;
  gotoxy(40,16);
  cout << "(b)-------------GET HELP ABOUT GAME----------------" <<endl;
  gotoxy(40,17);
  cout << "(c)-------------EXIT----------------" <<endl;
}
void gethelp()
{
  cout << "1--PRESS LEFT KEY TO MOVE THE BOAT TOWARD LEFT SIDE" << endl;
  cout << "2--PRESS RIGHT KEY TO MOVE THE BOAT TOWARD RIGHT SIDE" << endl;
  cout << "3--PRESS UP KEY TO MOVE THE BOAT UPPER SIDE" << endl;
  cout << "4--PRESS DOWN KEY TO MOVE THE BOAT DOWN SIDE" << endl;
  cout << "5--SHOOT THE ENEMY SHIPS WITH THE SPACE KEY" << endl;
  cout<<  "6--AVOID TOUCHING ANY ENMEY IN CASE OF ACCIDENT THE WILL OVER "<<endl;
  }
void printmaze()
{
  system("cls");
  cout<<"SHOOT THE BANG SHIP"<<endl;
  cout << "*****************************************************************************************************************************" << endl;
  cout << "*                                                                                                        *                  *" << endl;
  cout << "*                                                                                   *                    *                  *" << endl;
  cout << "*                                                                                   *                    *                  *" << endl;
  cout << "*                                                                                   *                    *                  *" << endl;
  cout << "*                                                                                                        *                  *" << endl;
  cout << "*                                                                                                                           *" << endl;
  cout << "*                                                                                                                           *" << endl;
  cout << "*                                                                                                                           *" << endl;
  cout << "*                                                                                                                           *" << endl;
  cout << "*                                                                                                                           *" << endl;
  cout << "*                                                                                                                           *" << endl;
  cout << "*                                                                                                       *                   *" << endl;
  cout << "*                                                                                                       *                   *" << endl;
  cout << "*                                                                                                       *                   *" << endl;
  cout << "*                                                                                                       *                   *" << endl;
  cout << "*                                                                                                       *                   *" << endl;
  cout << "*                                                                                                       *                   *" << endl;
  cout << "*                                                                                                       *                   *" << endl;
  cout << "*                                                                                                                           *" << endl;
  cout << "*                                                                                                       *                   *" << endl; 
  cout << "*                                                                                                       *                   *" << endl;
  cout << "*                                                                                                                           *" << endl;
  cout << "*                                                                                                                           *" << endl;
  cout << "*                                                                                                                           *" << endl;
  cout << "*                                                                                                                           *" << endl;
  cout << "*                                                                                                                           *" << endl;
  cout << "*                                                                                                       *                   *" << endl;
  cout << "*                                                                                                       *                   *" << endl;
  cout << "*                                                                                    *                  *                   *" << endl;
  cout << "*                                                                                    *                  *                   *" << endl;
  cout << "*                                                                                    *                                      *" << endl;
  cout << "*                                                                                    *                                      *" << endl;
  cout << "*                                                                                                       *                   *" << endl;
  cout << "*                                                                                                       *                   *" << endl;
  cout << "*                                                                                                                           *" << endl;
  cout << "*                                                                                                                           *" << endl;
  cout << "*****************************************************************************************************************************" << endl;
}
void gotoxy(int x, int y)
{
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
  CHAR_INFO ci;
  COORD xy = {0, 0};
  SMALL_RECT rect = {x, y, x, y};
  COORD coordBufSize;
  coordBufSize.X = 1;
  coordBufSize.Y = 1;
  return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void enemy1move()
{
  if (enemydirection == "Up")
  {
    char next = getCharAtxy(enemyx, enemyy - 1);
    if (next == ' ')
    {
      eraseenemy1();
      enemyy--;
      enmeyboat();
    }
    if (next == '*')
    {
      enemydirection = "Down";
    }
  }
  if (enemydirection == "Down")
  {
    char next = getCharAtxy(enemyx, enemyy + 7);
    if (next == ' ')
    {
      eraseenemy1();
      enemyy++;
      enmeyboat();
    }
    if (next == '*')
    {
      enemydirection = "Up";
    }
  }
}
void eraseenemy1()
{
  gotoxy(enemyx, enemyy);
for(int row=0;row<7;row++)
{ 
  for(int col=0;col<9;col++)
  {
      cout<<" ";
  }
    enemyy++;
    gotoxy(enemyx,enemyy);
}
enemyy=enemyy-7;
}
void generatebullet()
{
  bulletx[bulletcount] = x + 10;
  bullety[bulletcount] = y;
  isbulletactive[bulletcount] = true;
  gotoxy(x + 10, y);
  cout << "+";
  bulletcount++;
}
void printbullet(int x, int y)
{
  gotoxy(x, y);
  cout << "+";
}
void erasebullet(int x, int y)
{
  gotoxy(x, y);
  cout << " ";
}
void makebulletinactive(int index)
{
  isbulletactive[index] = false;
}
void movebullet()
{
  for (int x = 0; x < bulletcount; x++)
  {
    if (isbulletactive[x] == true)
    {
      char next = getCharAtxy(bulletx[x] + 1, bullety[x]);
      if (next != ' ')
      {
        erasebullet(bulletx[x], bullety[x]);
        makebulletinactive(x);
      }
      else
      {
        erasebullet(bulletx[x], bullety[x]);
        bulletx[x] = bulletx[x] + 1;
        printbullet(bulletx[x], bullety[x]);
      }
    }
  }
}
void addscore()
{
  score++;
}
void printscore()
{
  gotoxy(130, 10);
  cout << "<<<<-----SCORE----->> " << score;
}
void bulletcollisionwithenemy()
{
  for (int x = 0; x < bulletcount; x++)
  {
    if (isbulletactive[x] == true)
    {
      if (bulletx[x] + 1 == enemyx && (bullety[x] == enemyy || bullety[x] == enemyy + 2 || bullety[x] == enemyy + 3 || bullety[x] == enemyy + 4 || bullety[x] == enemyy + 5 || bullety[x] == enemyy + 6))
        addscore();
      if (enemyx - 1 == bulletx[x] && enemyy + 1 == bullety[x])
        addscore();
    }
  }
}

void Benmeyboat()
{
   gotoxy(Benemyx, Benemyy);
for(int row=0;row<5;row++)
{
  for(int col=0;col<6;col++)
 
  {
      cout<<Benemy1[row][col];
  }
  Benemyy++;
  gotoxy(Benemyx, Benemyy);
}
Benemyy=Benemyy-5;

}
void Beraseenemy()
{
    gotoxy(Benemyx, Benemyy);
for(int row=0;row<5;row++)
{ 
  for(int col=0;col<6;col++)
  {
      cout<<" ";
  }
    Benemyy++;
    gotoxy(Benemyx,Benemyy);
}
Benemyy=Benemyy-5;
}
void Benemymove()
{
     if (Benemydirection == "Right")
    {
        char next = getCharAtxy(Benemyx + 6,Benemyy);
        if (next == ' ')
        {
            Beraseenemy();
            Benemyx++;
            Benmeyboat();
        }
        if (next == '*')
        {
           Beraseenemy();
           Benemydirection = "left";
        }
    }
    if (Benemydirection == "left")
    {
        char next = getCharAtxy(Benemyx - 1, Benemyy);
        if (next == ' ')
        {
            Beraseenemy();
           Benemyx--;
             Benmeyboat();
        }
        if (next == '*')
        {
            Beraseenemy();
           Benemydirection = "Right";
        }
    }

}

void Aenmeyboat()
{
   gotoxy(Aenemyx, Aenemyy);
for(int row=0;row<5;row++)
{
  for(int col=0;col<6;col++)
 
  {
      cout<<Aenemy1[row][col];
  }
  Aenemyy++;
  gotoxy(Aenemyx, Aenemyy);
}
Aenemyy=Aenemyy-5;
}
void Aeraseenemy()
{
    gotoxy(Aenemyx, Aenemyy);
for(int row=0;row<5;row++)
{ 
  for(int col=0;col<6;col++)
  {
      cout<<" ";
  }
    Aenemyy++;
    gotoxy(Aenemyx,Aenemyy);
}
Aenemyy=Aenemyy-5;
 
}


  void Aenemymove()
  {

{
     if (Aenemydirection == "Up")
    {
        char next = getCharAtxy(Aenemyx ,Aenemyy -1);
        if (next == ' ')
        {
            Aeraseenemy();
            Aenemyy--;
            Aenmeyboat();
        }
        if (next == '*')
        {
           Aeraseenemy();
           Aenemydirection = "Down";
        }
    }
    if (Aenemydirection == "Down")
    {
        char next = getCharAtxy(Aenemyx , Aenemyy+5);
        if (next == ' ')
        {
            Aeraseenemy();
           Aenemyy++;
             Aenmeyboat();
        }
        if (next == '*')
        {
            Aeraseenemy();
           Aenemydirection = "Up";
        }
    }

}

}
void Cenmeyboat()
{
   gotoxy(Cenemyx, Cenemyy);
for(int row=0;row<5;row++)
{
  for(int col=0;col<6;col++)
 
  {
      cout<<Cenemy1[row][col];
  }
  Cenemyy++;
  gotoxy(Cenemyx, Cenemyy);
}
Cenemyy=Cenemyy-5;
}
void Ceraseenemy()
{
    gotoxy(Cenemyx, Cenemyy);
for(int row=0;row<5;row++)
{ 
  for(int col=0;col<6;col++)
  {
      cout<<" ";
  }
    Cenemyy++;
    gotoxy(Cenemyx,Cenemyy);
}
Cenemyy=Cenemyy-5;
}
void Cenemymove()
{
     if (Cenemydirection == "Right")
    {
        char next = getCharAtxy(Cenemyx + 6,Cenemyy);
        if (next == ' ')
        {
            Ceraseenemy();
            Cenemyx++;
            Cenmeyboat();
        }
        if (next == '*')
        {
           Ceraseenemy();
           Cenemydirection = "left";
        }
    }
    if (Cenemydirection == "left")
    {
        char next = getCharAtxy(Cenemyx - 1, Cenemyy);
        if (next == ' ')
        {
            Ceraseenemy();
           Cenemyx--;
             Cenmeyboat();
        }
        if (next == '*')
        {
            Ceraseenemy();
           Cenemydirection = "Right";
        }
    }

}
void generateColors(int k)
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);
  }


