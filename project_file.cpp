//MUHAMMAD HASEEB, SHAHARYAR RIZWAN
//I22-1001         I22-0999

#include<iostream>
#include<cmath>
//#include<conio.h>
using namespace std;
void start();

void opponent(char*** pointer, int);//first player 
void player(char*** pointer, int);//opponent of first player

void king_o(char***, int, char);//opponent rook restriction
void king(char***, int, char);//player king
bool isvalid(int x, int y);//for king validation
bool kingisvalid(int&, int&, int, int);//for king validation


void rook(char*** pointer, int x, char y);//player rook//left rook
void rook_o(char*** , int x, char y);//opponent rook //left rook
bool checkingrook(int, int, int, int);//left rook restriction move checking
void r_rook(char*** pointer, int x, char y);//for opponent rook //right rook
void o_rook(char*** pointer, int x, char y);//for player rook //right rook


void queen_o(char*** , int , char);//opponent queen
void queen(char***, int, char);//player queen
bool que1(char ***, int, int, int, int);//checks player queen movement validity
bool que2(char ***, int, int, int, int);//checks opponent queen movement validity



void knight(char***, int, char);//player knight of left side
void knightmoves(char*** pointer, int, int);
void r_knight(char***, int, char);//opponent knight of right side
void l_knight(char***, int, char);//opponent knight of left side
void t_knight(char***, int, char);//player knight of right side

char *** bishop_o(char *** pointer, int, char);//bishop of opponent//left bishop
bool bishopcheck_o(char*** pointer ,int ,int , int, int);//restriction for opponent bishop
char*** bishopmoves(char*** pointer, int, char);//for bishop to initiate for player
bool checkbishop(char*** pointer ,int ,int , int, int);//restriction for bishop for player and opponent
int r(int row);//for player  bishop
char *** r_bishop(char *** pointer, int, char);//bishop of player//right bishop
char *** u_bishop(char *** pointer, int, char);//bishop of opponent//right bishop
bool bishopcheck_o1(char*** pointer ,int c ,int s, int bx, int by);//for player bishop checking 

int rows(int row);
int cols(char  col);

void status(char***);

//void mate()

int main() {
  start();
return 0;
}

void start() {
    
cout<<"\t\t\t\tWelcome to Chess Game\n";
    char quit='m';
    int x = 9, y = 8;
    char grid[9][9] = {
                      {'8','R','N','P','K','Q','S','T','O'},
                      {'7','.','.','.','.','.','.','.','.'},
                      {'6','.','.','.','.','.','.','.','.'},
                      {'5','.','.','.','.','.','.','.','.'},
                      {'4','.','.','.','.','.','.','.','.'},
                      {'3','.','.','.','.','.','.','.','.'},
                      {'2','.','.','.','.','.','.','.','.'},
                      {'1','r','n','b','k','q','s','t','o'},
                      {' ','A','B','C','D','E','F','G','H'}
    };
    char*** pointer = new char** [x];
    for (int i = 0; i < x; i++) {
        pointer[i] = new char* [y];
        for (int j = 0; j < x; j++) {
            pointer[i][j] = &grid[i][j];
        }
    }
    

    while (quit != 'x')//for player 
    {
        status(pointer);//shows the array each time

        player(pointer, x);//player
              status(pointer);
      opponent(pointer, x);//opponent function
         
    }







    // free the memory allocated for pointer
    for (int i = 0; i < x; i++) {
        delete[] pointer[i];
    }
    delete[] pointer;

}


void player(char*** pointer, int x)
{
    char ch;
    cout << "Symbols:\n";
    cout << "q for queen  , k for king , r for left  rook , b for bishop, n for left knight, o for right rook, t for right knight,s for right bishop (small alphabets for white)\n";
    cin >> ch;
    int choice = int(ch);
    switch (choice) {
    case 113:
        queen(pointer, x, ch);
        break;
    case 107: // k
        king(pointer, x, ch);
        break;
    case 114: //r
        rook(pointer, x, ch);
        break;
        case 111://o
          o_rook(pointer, x, ch);
              break;
    case 98://b
      bishopmoves(pointer, x, ch);
        break;
        case 115:
        r_bishop(pointer, x, ch);
        break;
      case 110://n
        knight(pointer, x, ch);
        break;
       
       case 116://t
        t_knight(pointer, x, ch);
        break;
        
      
       
    }
    
}
void opponent(char*** pointer, int x) {

    char ch;
    cout << "Symbols:\n";
    cout << "Q for queen  , K for king , R for left  rook , P left for bishop, N for knight, O for right rook,T for right Knight, S for right bishop (Large  alphabets for opponent)\n";
    cin >> ch;
    int choice = int(ch);
    switch (choice) {
    case 81://Q
        queen_o(pointer, x, ch);//done 
        break;
    case 75: // K
        king_o(pointer, x, ch);
        break;
    case 82: //R
        rook_o(pointer, x, ch);
        break;
         case 79://O
        r_rook(pointer, x, ch);
       break;
    case 80://P left bishop
      bishop_o(pointer, x, ch);
       break;
    case 78://N
        l_knight(pointer, x, ch);
        break;
    case 84://T
        r_knight(pointer, x, ch);
        break;
        
 
    }
   // return ch;

}

//function for queen
void queen(char*** pointer, int x, char y) {
  //  cout << "possible moves of queen\n";
cout << "where do you want to move your queen: ";
    char col;
    int row;
    cin >> col;
    cin >> row;
    int c, s;

    s = cols(col);
    c = rows(row);
    //for alphabets means for columns//final y
    //for integers means for rows//final x
    int initial_x, initial_y;
  
   for (int i = 0; i < x; i++) {
        for (int j = 1; j < x; j++) {
            if (*(pointer[i][j]) == 'q') {
              initial_x=i;
              initial_y=j;
               break;
            }
        }
        cout << "\n";
    }

     if( que1( pointer,c, s, initial_x, initial_y)){
      
           (*(pointer[initial_x][initial_y])) = '.';
           (*(pointer[c][s])) = 'q';
        
      
     }
     else 
      cout<<"invalid move\n";
}

void queen_o(char *** pointer, int x, char y){
cout << "where do you want to move your queen: ";
    char col;
    int row;
    cin >> col;
    cin >> row;
    int c, s;

    s = cols(col);//for alphabets means for columns//final y
    c = rows(row);//for integers means for rows//final x
    int initial_x, initial_y;
  
    // cout<<"s=="<<s<<"\n";
   for (int i = 0; i < x; i++) {
        for (int j = 1; j < x; j++) {
            if (*(pointer[i][j]) == 'Q') {
              initial_x=i;
              initial_y=j;
               break;
            }
        }
        cout << "\n";
    }
   
     if( que2( pointer,c, s, initial_x, initial_y)){
           (*(pointer[initial_x][initial_y])) = '.';
           (*(pointer[c][s])) = 'Q';
        
      
     }
     else 
      cout<<"invalid move\n";
    




}
bool que1(char *** pointer,int c, int s, int initial_x, int initial_y){
   bool x=0;
  if( checkingrook(initial_x, initial_y, c, s)||(bishopcheck_o( pointer , c,s, initial_x, initial_y))){
  if(((*(pointer[c][s]))!='k')&&((*(pointer[c][s]))!='r')&&((*(pointer[c][s]))!='n')&&((*(pointer[c][s]))!='s')&&((*(pointer[c][s]))!='t')&&((*(pointer[c][s]))!='o')){
     x=1;
     }
  }
  return x;
}
  bool que2(char *** pointer,int c, int s, int initial_x, int initial_y){
   bool x=0;
  if( checkingrook(initial_x, initial_y, c, s)||(bishopcheck_o( pointer , c,s, initial_x, initial_y))){
  if(((*(pointer[c][s]))!='K')&&((*(pointer[c][s]))!='R')&&((*(pointer[c][s]))!='N')&&((*(pointer[c][s]))!='S')&&((*(pointer[c][s]))!='T')&&((*(pointer[c][s]))!='O')){
     x=1;
     }
  }
   return x;
}

//function for king
void king(char*** pointer, int x, char y) //king of player
{
    cout << "where do you want to move your king: ";
    char col;
    int row;
    cin >> col;

    cin >> row;
    cout << "\n";
    int cx, cy;
    int c = rows(row);//rows
    int s = cols(col);//columns
  
    for (int i = 0; i < x; i++) {
        for (int j = 1; j < x; j++) {
            if ((*(pointer[i][j])) == 'k')//old coordinates of player king
            {
                cx = i;
                cy = j;
            }
            
             
     

        }
    }
   
    
    if (kingisvalid(cx, cy, c, s)) {
    //for player king
         if (((*(pointer[cx][cy])) == 'k')&&((*(pointer[cx][cy])) != 'q')&&((*(pointer[cx][cy])) != 'n')&&((*(pointer[cx][cy])) != 'r')&&((*(pointer[cx][cy])) != 'b')&&((*(pointer[cx][cy])) != 's')&&((*(pointer[cx][cy])) != 't')&&((*(pointer[cx][cy])) != 'o')){
        (*(pointer[c][s])) = 'k';
        (*(pointer[cx][cy])) = '.';
     }
       
    }
    
    else 
     cout << "invalid position\n";
    
    
}
//FUNCTION FOR CHECKING KING MOVE
bool kingisvalid(int& cx, int& cy, int c, int s) {
   bool r;
    int newx = abs(c - cx);
    int newy = abs(s - cy);

    if ((newx>1)&&(newy>1))
       r= 0;
     if((newx == 1) && (newy == 1))
        r= 1;
     return r;   
  }
  
  
//king of opponent
void king_o(char*** pointer, int x, char y)
{
    cout << "where do you want to move your king: ";
    char col;
    int row;
    cin >> col;

    cin >> row;
    cout << "\n";
    int cx, cy;
    int c = rows(row);//rows
    int s = cols(col);//columns
      cout<<"c="<<c<<"\n";
      cout<<"s="<<s<<"\n";
    for (int i = 0; i < x; i++) {
        for (int j = 1; j < x; j++) {
            if ((*(pointer[i][j])) == 'K')//old coordinates of opponent king
            {
                cx = i;
                cy = j;
            }
        }
    }
     cout<<"cx="<<cx<<"\n";
      cout<<"cy="<<cy<<"\n";
    
    if (kingisvalid(cx, cy, c, s)) {
    //for player king
         if (((*(pointer[cx][cy])) == 'k')&&((*(pointer[cx][cy])) != 'Q')&&((*(pointer[cx][cy])) != 'N')&&((*(pointer[cx][cy])) != 'R')&&((*(pointer[cx][cy])) != 'P')&&((*(pointer[cx][cy])) != 'S')&&((*(pointer[cx][cy])) != 'T')&&((*(pointer[cx][cy])) == 'O')){
        (*(pointer[c][s])) = 'K';
        (*(pointer[cx][cy])) = '.';
     }
      else 
      cout<<"invalid move\n";
    }
    
    else 
     cout << "invalid position\n";
}


//Function for rook of player
void rook(char*** pointer, int x, char y)//player rook//left rook
{
   cout << "Where do you want to move your rook: ";
    char col;
    int row;
    cin >> col;
    cin>> row;
   int s , c;
   
   s = cols(col);//for alphabets means for columns //final y
    c = rows(row);//for integers means for rows//final x
  
   int initial_x, initial_y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (*(pointer[i][j]) == 'r') {
               initial_x = i;//extracting row of existing coordinate
                initial_y = j;//extracting column of existing coordinate
                break;
            }
        }
      }
     

   
    if( checkingrook(initial_x, initial_y, c, s)){
        if (((*(pointer[c][s])) != 'q')&&((*(pointer[c][s])) != 'n')&&((*(pointer[c][s])) != 'k')&&((*(pointer[c][s])) != 'b')&&((*(pointer[c][s])) != 's')&&((*(pointer[c][s])) != 't')&&((*(pointer[c][s])) != 'o')){
       *(pointer[initial_x][initial_y])= '.';
       *(pointer[c][s])='r';
     
         }
       else 
       cout<<"invalid move\n";
     }
   else 
   cout<<"invalid move\n";
    
}
//rook of opponent
void rook_o(char*** pointer, int x, char y)//for player// right rook
{
    cout << "Where do you want to move your rook: ";
    char col;
    int row;
    cin >> col;
    cin>> row;
   int s , c;
   
   s = cols(col);//for alphabets means for columns //final y
    c = rows(row);//for integers means for rows//final x
  
   int initial_x, initial_y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (*(pointer[i][j]) == 'R') {
               initial_x = i;//extracting row of existing coordinate
                initial_y = j;//extracting column of existing coordinate
                break;
            }
        }}
     

   
    if( checkingrook(initial_x, initial_y, c, s)){
     if (((*(pointer[c][s])) != 'Q')&&((*(pointer[c][s])) != 'N')&&((*(pointer[c][s])) != 'K')&&((*(pointer[c][s])) != 'P')&&((*(pointer[c][s])) != 'S')&&((*(pointer[c][s])) != 'T')&&((*(pointer[c][s])) != 'O')){
    
       *(pointer[initial_x][initial_y])= '.';
       *(pointer[c][s])='R';
        }
        else 
        cout<<"invalid move\n";
      }
   else 
   cout<<"invalid move\n";

}

bool checkingrook(int initial_x,int initial_y,int  final_x,int final_y)//rook restrictions
{

    bool x;
    
     if(initial_x==final_x)
        
           x=1;
        
     if(initial_y==final_y)
         x=1;
      else 
       x=0;
       
    
  return x;
 }


int cols(char col)//"gives value of c"//Function returning the column value with respect to alphabetical order in Grid//
{
    int x=0;
    if (col == 65)//A
        x = 1;
    if (col == 66)//B
    {
        x = 2;
    }
    if (col == 67)//C
    {
        x = 3;
    }
    if (col == 68)//D
    {
        x = 4;
    }
    if (col == 69)//E
    {
        x = 5;
    }
    if (col == 70)//F
    {
        x = 6;
    }
    if (col == 71)//G
    {
        x = 7;
    }
    if (col == 72)//H
    {
        x = 8;
    }
    return x;
}
int rows(int row) {
    int x = 0;
    if(row==8)
    x=0;
    if(row==7)
    x=1;
    if(row==6)
       x=2;
    if (row == 5)
        x = 3;
    if (row == 4)
        x = 4;
    if (row == 3)
        x = 5;
    if (row == 2)
        x = 6;
    if (row == 1)
        x = 7;
    return x;
}


void status(char*** pointer) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            cout << (*(pointer[i][j])) << " ";

        }
        cout << "\n";
    }
    cout << "\n";
    cout << "press x to quit game\n";
}


// function to check if a given cell (x,y) is valid on the chessboard
bool isvalid(int x, int y)//related to queen
{
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}



void knight(char*** pointer, int x, char y) {
   

    cout << "Where do you want to move your knight: ";
    char col;
    int row;
    cin >> col >> row;

    int c, r;

    r = rows(row); //for rows
    c = cols(col);//for columns
                   

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (*(pointer[i][j]) == y) {
                (*(pointer[i][j])) = '.';
                (*(pointer[r][c])) = 'n';
            }
        }
        cout << "\n";
    }

    knightmoves(pointer, r, c);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cout << (*(pointer[i][j])) << " ";
        }
        cout << "\n";
    }
}

void knightmoves(char*** pointer, int r, int c) {
    int dr[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int dc[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    cout << "Possible moves:\n";
    for (int i = 0; i < 8; i++) {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (rr < 0 || rr > 7 || cc < 0 || cc > 7) {
            continue;
        }
       
    }
}
char*** bishop_o(char *** pointer, int row, char col)//opponent bishop
{
cout << "where do you want to move your bishop: ";
    
    cin >> col;


    cin >> row;


    int c, s;

    s = cols(col);//for alphabets means for columns
  //  c = rows(row);//for integers means for rows
     c=r(row); 
    int bx;//for new row
    int by;//for new col
         for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
           if((*(pointer[i][j])) == 'P'){ 
               // (*(pointer[i][j])) = '.';
              bx=i;
              by=j;
            }
        }
        cout << "\n";
    }

    
 if( bishopcheck_o( pointer , c,s, bx, by)){
                  if (((*(pointer[c][s])) != 'K')&&((*(pointer[c][s])) != 'Q')&&((*(pointer[c][s])) != 'N')&&((*(pointer[c][s])) != 'R')&&((*(pointer[c][s])) != 'S')&&((*(pointer[c][s])) != 'O')&&((*(pointer[c][s])) != 'T')){
                 
                   (*(pointer[bx][by])) = '.';
                   (*(pointer[c][s])) = 'P';
                   
                   }
                  else 
                  cout<<"Invalid move\n";
                }
            else
              cout<<"invalid move\n";
             
     
    return pointer;

   
}
bool bishopcheck_o(char*** pointer ,int c ,int s, int bx, int by)//check for opponent bishop
{
 bool t;
  float numerator, denominator;
      numerator=abs(c-bx);
      denominator=abs(s-by);
      cout<<" numerator="<< numerator<<"\n";
      cout<<"denominator="<<denominator<<"\n";
        if((denominator!=0)&&(numerator/denominator==1)&&(by!=0)){
       
        
        t=1;
         }
      
       else 
        t= 0;

return t;
}


bool bishopcheck_o1(char*** pointer ,int c ,int s, int bx, int by)//check for opponent bishop
{
 bool t;
  float numerator, denominator;
      numerator=abs(c-bx);
      denominator=abs(s-by);
      cout<<" numerator="<< numerator<<"\n";
      cout<<"denominator="<<denominator<<"\n";
        if((denominator!=0)&&(numerator/denominator==1)&&(by!=0)){
        t=1; 
         }
        else 
        t=0;

return t;
}



//bishop of player function
char*** bishopmoves(char*** pointer, int row, char col) //
{

   cout << "where do you want to move your bishop: ";
  
    cin >> col;


    cin >> row;
    int c, s;

    s = cols(col);//for alphabets means for columns
   // c = rows(row);//for integers means for rows
     c=r(row); 
    int bx;//for new row
    int by;//for new col
         for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
           if((*(pointer[i][j])) == 'b'){ 
               // (*(pointer[i][j])) = '.';
              bx=i;
              by=j;
            }
        }
        cout << "\n";
    }

          if( checkbishop( pointer , c,s, bx, by)){
           if (((*(pointer[c][s])) != 'k')&&((*(pointer[c][s])) != 'q')&&((*(pointer[c][s])) != 'n')&&((*(pointer[c][s])) != 'r')&&((*(pointer[c][s])) != 't')&&((*(pointer[c][s])) != 's')&&((*(pointer[c][s])) != 'o')){   
                 
                   (*(pointer[bx][by])) = '.';
                   (*(pointer[c][s])) = 'b';
                   }
                   else
                   cout<<"invalid move\n";
                   }
            else
              cout<<"invalid move\n";
             
     
    return pointer;
    }
   
    
  //restriction for bishop moves    
bool checkbishop(char*** pointer , int c, int s, int bx, int by){
     float numerator, denominator;
      numerator=abs(c-bx);
      denominator=abs(s-by);
     // cout<<" numerator="<< numerator<<"\n";
      //cout<<"denominator="<<denominator<<"\n";
        if((denominator!=0)&&(numerator/denominator==1)&&(by!=0))
           return 1;
              else 
                return 0;
     }
     
int r(int row){
  int x = 0;
    
    if (row==8)
        x=0;
    if (row==7)
        x=1;
    if (row==6)
        x=2;
    if (row==5)
        x=3;
    if (row==4)
        x=4;
    if (row==3)
        x=5;
    if (row==2)
        x=6;
    if (row==1)
        x=7;
     
    return x;
 } 
 
 bool que(char *** pointer, int){
    
    
    
 
 return 0;
 }
 


void r_rook(char*** pointer, int x, char y)//for opponent rook //right rook
{

 cout << "Where do you want to move your rook: ";
    char col;
    int row;
    cin >> col;
    cin>> row;
   int s , c;
   
   s = cols(col);//for alphabets means for columns //final y
    c = rows(row);//for integers means for rows//final x
  
   int initial_x, initial_y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (*(pointer[i][j]) == 'O') {
               initial_x = i;//extracting row of existing coordinate
                initial_y = j;//extracting column of existing coordinate
                break;
            }
        }
      }
    if( checkingrook(initial_x, initial_y, c, s)){
    if (((*(pointer[c][s])) != 'K')&&((*(pointer[c][s])) != 'Q')&&((*(pointer[c][s])) != 'N')&&((*(pointer[c][s])) != 'R')&&((*(pointer[c][s])) != 'B')&&((*(pointer[c][s])) != 'S')&&((*(pointer[c][s])) != 'T')&&((*(pointer[c][s])) != 'P')){
       *(pointer[initial_x][initial_y])= '.';
       *(pointer[c][s])='O';
        }
    else 
   cout<<"invalid move\n";
   
     }
   else 
   cout<<"invalid move\n";

}


void r_knight(char***pointer, int x, char y){
cout << "Where do you want to move your knight: ";
    char col;
    int row;
    cin >> col >> row;

    int c, r;

    r = rows(row);//rows
    c = cols(col);//cols

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (*(pointer[i][j]) == y) {
        if (((*(pointer[r][c])) != 'K')&&((*(pointer[r][c])) != 'Q')&&((*(pointer[r][c])) != 'N')&&((*(pointer[r][c])) != 'R')&&((*(pointer[r][c])) != 'P')&&((*(pointer[r][c])) != 'S')&&((*(pointer[r][c])) != 'O')){
                (*(pointer[i][j])) = '.';
                (*(pointer[r][c])) = 'T';
            }
            else 
            { 
            cout<<"Invalid move\n";
            break;
            }            
          }
        }
        cout << "\n";
    }

    knightmoves(pointer, r, c);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cout << (*(pointer[i][j])) << " ";
        }
        cout << "\n";
    }

}

void l_knight(char***pointer, int x, char y)//opponent left knight
{
cout << "Where do you want to move your knight: ";
    char col;
    int row;
    cin >> col >> row;

    int c, r;

    r = rows(row);
    c = cols(col);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (*(pointer[i][j]) == y) {
            if (((*(pointer[r][c])) != 'K')&&((*(pointer[r][c])) != 'Q')&&((*(pointer[r][c])) != 'S')&&((*(pointer[r][c])) != 'R')&&((*(pointer[r][c])) != 'P')&&((*(pointer[r][c])) != 'O')&&((*(pointer[r][c])) != 'T')){
            
                (*(pointer[i][j])) = '.';
                (*(pointer[r][c])) = 'N';
            }
            else 
              {cout<<"invalid move\n";
              break;
                    }             
          }
        }
        cout << "\n";
    }

   knightmoves(pointer, r, c);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cout << (*(pointer[i][j])) << " ";
        }
        cout << "\n";
    }

}



void t_knight(char*** pointer, int x, char y)//player knight of right side
{

cout << "Where do you want to move your knight: ";
    char col;
    int row;
    cin >> col >> row;

    int c, r;

    r = rows(row);
    c = cols(col);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (*(pointer[i][j]) == y) {
    if (((*(pointer[r][c])) != 'k')&&((*(pointer[r][c])) != 'q')&&((*(pointer[r][c])) != 'n')&&((*(pointer[r][c])) != 'r')&&((*(pointer[r][c])) != 'b')&&((*(pointer[r][c])) != 's')&&((*(pointer[r][c])) != 'o')){        
            
                (*(pointer[i][j])) = '.';
                (*(pointer[r][c])) = 't';
            }
            else {
             cout<<"invalid move\n";
              break;
              }
          }
        }
        cout << "\n";
     }

   
   
}


void o_rook(char*** pointer, int x, char y)//for player rook //right rook
{
cout << "Where do you want to move your rook: ";
    char col;
    int row;
    cin >> col;
    cin>> row;
   int s , c;
   
   s = cols(col);//for alphabets means for columns //final y
    c = rows(row);//for integers means for rows//final x
  
   int initial_x, initial_y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (*(pointer[i][j]) == 'o') {
               initial_x = i;//extracting row of existing coordinate
                initial_y = j;//extracting column of existing coordinate
                break;
            }
        }}
     

   
    if( checkingrook(initial_x, initial_y, c, s)){
    if (((*(pointer[c][s])) != 'k')&&((*(pointer[c][s])) != 'q')&&((*(pointer[c][s])) != 'n')&&((*(pointer[c][s])) != 'r')&&((*(pointer[c][s])) != 'b')&&((*(pointer[c][s])) != 's')&&((*(pointer[c][s])) != 't')){
       *(pointer[initial_x][initial_y])= '.';
       *(pointer[c][s])='o';
     }
     else 
     cout<<"invalid move\n";
     }
   else 
   cout<<"invalid move\n";

}


char *** r_bishop(char *** pointer, int, char)//bishop of opponent//right bishop
{

cout << "where do you want to move your bishop: ";
    char col;
    int row;
    cin >> col;


    cin >> row;


    int c, s;

    s = cols(col);//for alphabets means for columns
  
     c=r(row);// for row
    int bx;//for new row
    int by;//for new col
         for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
           if((*(pointer[i][j])) == 's'){ 
               // (*(pointer[i][j])) = '.';
              bx=i;
              by=j;
            }
        }
        cout << "\n";
    }

    
 if( bishopcheck_o1( pointer , c,s, bx, by)){
       if (((*(pointer[c][s])) != 'q')&&((*(pointer[c][s])) != 'n')&&((*(pointer[c][s])) != 'r')&&((*(pointer[c][s])) != 'b')&&((*(pointer[c][s])) != 'k')&&((*(pointer[c][s])) != 't')&&((*(pointer[c][s])) != 'o')){   
                 
                   (*(pointer[bx][by])) = '.';
                   (*(pointer[c][s])) = 's';
                   
                   }
                   else 
                   cout<<"invalid move\n";
              }
            else
              cout<<"invalid move\n";
    return pointer;
}
char *** u_bishop(char *** pointer, int, char)//bishop of opponent//right bishop
{
cout << "where do you want to move your bishop: ";
    char col;
    int row;
    cin >> col;
    cin >> row;
    int c, s;

    s = cols(col);//for alphabets means for columns
  //  c = rows(row);//for integers means for rows
     c=r(row); 
    int bx;//for new row
    int by;//for new col
         for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
           if((*(pointer[i][j])) == 'S'){ 
               // (*(pointer[i][j])) = '.';
              bx=i;
              by=j;
            }
        }
        cout << "\n";
    }
 if( bishopcheck_o( pointer , c,s, bx, by)){
          if (((*(pointer[c][s])) == 'K')&&((*(pointer[c][s])) != 'Q')&&((*(pointer[c][s])) != 'N')&&((*(pointer[c][s])) != 'R')&&((*(pointer[c][s])) != 'S')&&((*(pointer[c][s])) != 'T')&&((*(pointer[c][s])) == 'O')){
                 
                   (*(pointer[bx][by])) = '.';
                   (*(pointer[c][s])) = 'P';
                   
                   }
                   else
                   cout<<"invalid move\n";
                 }
            else
              cout<<"invalid move\n";
    return pointer;
}
