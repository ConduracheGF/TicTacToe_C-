#include<iostream>
#include<ctime>
#include "header.h"
using namespace std;

void Grafica_TicTac(char *spatiu){
    cout << '\n';
    cout << "     |     |     "<< '\n';
    cout << "  " <<spatiu[0]<< "  |  " <<spatiu[1]<< "  |  " <<spatiu[2]<< "  " << '\n';
    cout << "_____|_____|_____"<< '\n';
    cout << "     |     |     "<< '\n';
    cout << "  " <<spatiu[3]<< "  |  " <<spatiu[4]<< "  |  " <<spatiu[5]<< "  " << '\n';
    cout << "_____|_____|_____"<< '\n';
    cout << "     |     |     "<< '\n';
    cout << "  " <<spatiu[6]<< "  |  " <<spatiu[7]<< "  |  " <<spatiu[8]<< "  " << '\n';
    cout << "     |     |     "<< '\n';
    cout << '\n';
}
void Move_Player_1(char *spatiu, char player_1){
    int nr;
    do{
        cout << "Plaseaza un loc pentru X in intervalul (1-9)";
        cin >> nr;
        nr--;
        if(spatiu[nr] == ' '){
            spatiu[nr] = player_1;
            break;
        }

    }while(nr > 0 || !nr < 8);
}
void Move_Player_2(char *spatiu,char player_2){
    int nr;
    srand(time(0));

    while(true){
        nr = rand() % 9;
        if(spatiu[nr]==' '){
            spatiu[nr] = player_2;
            break;
        }
    }
}
bool castigator(char *spatiu,char player_1, char player_2){ 
    if((spatiu[0] != ' ') && (spatiu[0] == spatiu[1]) && (spatiu[1] == spatiu[2])){
        spatiu[0] == player_1 ? cout<<"AI CASTIGAT\n" : cout<<"AI PIERDUT\n";
    }
    else if((spatiu[3] != ' ') && (spatiu[3] == spatiu[4]) && (spatiu[4] == spatiu[5])){
        spatiu[3] == player_1 ? cout<<"AI CASTIGAT\n" : cout<<"AI PIERDUT\n";
    }
    else if((spatiu[6] != ' ') && (spatiu[6] == spatiu[7]) && (spatiu[7] == spatiu[8])){
        spatiu[6] == player_1 ? cout<<"AI CASTIGAT\n" : cout<<"AI PIERDUT\n";
    }
    else if((spatiu[0] != ' ') && (spatiu[0] == spatiu[3]) && (spatiu[3] == spatiu[6])){
        spatiu[0] == player_1 ? cout<<"AI CASTIGAT\n" : cout<<"AI PIERDUT\n";
    }
    else if((spatiu[1] != ' ') && (spatiu[1] == spatiu[4]) && (spatiu[4] == spatiu[7])){
        spatiu[1] == player_1 ? cout<<"AI CASTIGAT\n" : cout<<"AI PIERDUT\n";
    }
    else if((spatiu[2] != ' ') && (spatiu[2] == spatiu[5]) && (spatiu[5] == spatiu[8])){
        spatiu[6] == player_1 ? cout<<"AI CASTIGAT\n" : cout<<"AI PIERDUT\n";
    }
    else if((spatiu[0] != ' ') && (spatiu[0] == spatiu[4]) && (spatiu[4] == spatiu[8])){
        spatiu[0] == player_1 ? cout<<"AI CASTIGAT\n" : cout<<"AI PIERDUT\n";
    }
    else if((spatiu[2] != ' ') && (spatiu[2] == spatiu[4]) && (spatiu[4] == spatiu[6])){
        spatiu[2] == player_1 ? cout<<"AI CASTIGAT\n" : cout<<"AI PIERDUT\n";
    }
    else{
        return false;
    }
    return true;
}
bool verif_Tie(char *spatiu){
    for(int i = 0; i < 9; i++){
        if(spatiu[i] == ' '){
            return false;
        }
    }
    cout<<"IT'S TIE!\n";
    return true;
}

int main()
{
    char spatiu[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',};
    char player_1 = 'X';
    char player_2 = 'O';
    bool joci = true;

    Grafica_TicTac(spatiu);
    while (joci)
    {
        Move_Player_1(spatiu,player_1);
        Grafica_TicTac(spatiu);
        if(castigator(spatiu,player_1,player_2)){
            joci = false;
            break;
        }
        else if(verif_Tie(spatiu)){
            joci = false;
            break;
        }
        Move_Player_2(spatiu,player_2);
        Grafica_TicTac(spatiu);
        if(castigator(spatiu,player_1,player_2)){
            joci = false;
            break;
        }
        else if(verif_Tie(spatiu)){
            joci = false;
            break;
        }
    }
    cout<<"Thanks for playing";
    return 0;
}
