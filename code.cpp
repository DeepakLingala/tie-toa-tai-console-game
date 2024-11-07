#include <iostream>
#include <ctime>
#include <random>
using namespace std;

char board[9];
void reset_board();
void show_board();
void get_X_player_choice();                  
void get_O_player_choice();
void get_Computer_choice(); 
int count_board(char symbol);
char check_Winner();
void Computer_VS_Player();
void Player_VS_Player();
void print_welcome_message();
void print_game_mode_message();

int main() {
    int mode;
    print_welcome_message();
    
    while (true) {
        reset_board();
        print_game_mode_message();
        cin >> mode;
        switch (mode) {
        case 1:
            Computer_VS_Player();
            break;
        case 2:
            Player_VS_Player();
            break;
        default:
            cout << "Warning! Please select a valid game mode." << endl;
        }

        cout << "Do you want to play again? (Y/N): ";
        char play_again;
        cin >> play_again;
        if (play_again != 'y' && play_again != 'Y') {
            cout << "Thanks for playing! See You Again!" << endl;
            break;
        }
    }
     
    return 0;
}

void print_welcome_message() {
    cout << "==================================" << endl;
    cout << "    Welcome to Tic-Tac-Toe Game   " << endl;
    cout << "==================================" << endl << endl;
}

void print_game_mode_message() {
    cout << " ----->1. Computer VS Player. <----- " << endl;
    cout << " ----->2. Player VS Player. <----- " << endl;
    cout << " ----->>> Select Any Game Mode. <<<----- " << endl;
}

void reset_board() {
    for(int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
}

void Computer_VS_Player(){
    string player_name;
    cout << "Enter Your Name: ";
    cin >> player_name;
    while (true) {
        show_board();
        if(count_board('X') == count_board('O')) {
            cout << player_name << "'s Turn." << endl;
            get_X_player_choice();
        }
        else {
            get_Computer_choice();
        }
        char winner = check_Winner();
        if(winner == 'X'){
          show_board();
          cout << player_name << " Won the Game. " << endl;
          break;
        }
        else if(winner == 'O'){
          show_board();
          cout << "Computer Won the Game. " << endl;
          break;
        }
        else if(winner == 'D') {
            show_board();
            cout << "Game is Draw. " << endl;
            break;
        }
    }
}

void get_Computer_choice(){
    srand(time(0));
    int choice;
    do {
        choice = rand() % 9;
    } while(board[choice] != ' ');
    board[choice] = 'O';
}

void get_X_player_choice() {
    while(true) {
        cout << "Select Your Position (1 - 9): ";
        int choice;
        cin >> choice;
        choice--;
        if(choice < 0 || choice > 8) {
            cout << "Please Select Your Choice From (1 - 9)." << endl;
        }
        else if(board[choice] != ' ') {
            cout << "Please Select An Empty Position." << endl;
        }
        else {
            board[choice] = 'X';
            break;
        }
    }
}

void get_O_player_choice() {
    while(true) {
        cout << "Select Your Position (1 - 9): ";
        int choice;
        cin >> choice;
        choice--;
        if(choice < 0 || choice > 8) {
            cout << "Please Select Your Choice From (1 - 9)." << endl;
        }
        else if(board[choice] != ' ') {
            cout << "Please Select An Empty Position." << endl;
        }
        else {
            board[choice] = 'O';
            break;
        }
    }
}

void Player_VS_Player(){
    string X_Player_name, O_Player_name;
    cout << "Enter the X Player Name: ";
    cin >> X_Player_name;
    cout << "Enter the O Player Name: ";
    cin >> O_Player_name;
    while(true) {
        show_board();
        if(count_board('X') == count_board('O')) {
            cout << X_Player_name << "'s Turn. " << endl;
            get_X_player_choice();
        } else {
            cout << O_Player_name << "'s Turn." << endl;
            get_O_player_choice();
        }
        char winner = check_Winner();
        if(winner == 'X') {
            show_board();
            cout << X_Player_name << " Won The Game. " << endl;
            break;
        } else if(winner == 'O') {
            show_board();
            cout << O_Player_name << " Won The Game. " << endl;
            break; 
        } else if(winner == 'D') {
            show_board();
            cout << "Game is Draw." << endl;
            break;
        }
    }
}

int count_board(char symbol){
    int total = 0;
    for(int i = 0; i < 9; i++) {
        if(board[i] == symbol)
            total += 1;
    }
    return total;
}

char check_Winner(){
    //checking winner in horizontal
    if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
        return board[0];
    if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        return board[3];
    if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        return board[6];
    //checking winner in vertical/column
    if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
        return board[0];
    if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        return board[1];
    if(board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
        return board[2];
    //checking winner in diagonal
    if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
        return board[0];
    if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        return board[2];

    if(count_board('X') + count_board('O') < 9)
        return 'C';
    else
        return 'D';
}

void show_board() {
    cout << endl;
    cout << "     |     |     " << endl;   
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
    cout << "     |     |     " << endl;
    cout << endl;
}
