//Tik tak toe//
//Md Sadi AL HUDA//
//Binarybeast004//

#include <iostream>
#include <stdlib.h>   //header for clc command
using namespace std; 

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; //Global Array decleaaration
char turn='X';
int row,column;
bool draw = false;

void displayboard(){ //Funchion for display
    int choice;
    
   system("cls");
   // system("Color 0A");
   
    cout <<"\n\n Tik   Tak   Toe"<<endl;
    cout <<"\n player1 [X] \n player2 [O]"<<endl;
    cout <<"\t\t     |     |     \n";
    cout <<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
    cout <<"\t\t_____|_____|_____\n";
    cout <<"\t\t     |     |     \n";
    cout <<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
    cout <<"\t\t_____|_____|_____\n";
    cout <<"\t\t     |     |     \n";
    cout <<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
    cout <<"\t\t     |     |     \n";
}
    

    
void player_turn(){ //function fro turn
    int choice;
    if (turn == 'X')
    cout<<"\n\tplayer1 [X] turn:"<<endl;
    if (turn == 'O')
    cout<<"\n\tplayer2 [O] turn:"<<endl;

    cin>>choice; 

    
    switch(choice){  //switch case statement for place decleaaration
        case 1: row=0; column=0;break;
        case 2: row=0; column=1;break;
        case 3: row=0; column=2;break;
        case 4: row=1; column=0;break;
        case 5: row=1; column=1;break;
        case 6: row=1; column=2;break;
        case 7: row=2; column=0;break;
        case 8: row=2; column=1;break;
        case 9: row=2; column=2;break;
       
       default:
       cout<<"Invalid choice\n"<<endl;
    }
    if (turn == 'X' && board[row][column]!='X' && board[row][column]!='O'){
        board[row][column]='X';
        turn ='O';
    }
    else if(turn =='O' && board[row][column]!='X' && board[row][column]!='O'){
        board[row][column]='O';
        turn='X';
    }
    else{
        cout<<" Box already Filled"<<endl;
        player_turn();
    }
    }
    
    bool gameover(){
        //game over function to stop ending
       //cheak win         //bool for true datatype
       for(int i=0; i<3; i++ )
       if (board[i][0]==board[i][1] && board[i][0]==board[i][2]||board[0][i]==board[1][i] && board[0][i]==board[2][i])
       return false;
       
       //if there is any box not filled
       for (int i=0; i<3; i++)
       for (int j=0; j<3; j++)
       if (board[i][j] !='X' && board[i][j]!='O')
       return true;
       //draw
       draw = true;
       return false;
    }
    
    
   

    
int main(){  //main function
    bool cheak=gameover();
    while(cheak)
    {   // loop for display again 
    displayboard();
    player_turn();
    gameover();
    }
    
    if (turn == 'X' && draw==false)
    cout <<" player2 [O] Wins !! Congratulations"<<endl;
    else if (turn == 'O' && draw==false)
    cout <<" player1 [X] Wins !! Congratulations"<<endl;
    else
    cout<<"Game Draw !!"<<endl;
   
}





