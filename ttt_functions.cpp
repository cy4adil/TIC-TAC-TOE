#include <iostream>
#include <vector>

std::vector<char> board = {'1','2','3','4','5','6','7','8','9'};
int player = 1;
int player_turn;
int winner = 0;
int filled = 0;

void greet() {
    std::cout << "\n\n==================\n";
    std::cout << " TIC TAC TOE GAME\n";
    std::cout << "==================\n\n";
    
    std::cout << "\n\nStart:\n\n";
}

void draw() {
    
    
    
    std::cout << "     |     |      \n";

    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    std::cout << "     |     |      \n";

    std::cout << "\n";
}

void change_player() {
    if(player == 1) {
        player = 2;
    } else {
        player = 1;
    }
}

void set_position(int input, int player_check) {
    if(input == 1){
        if(player_check == 1) {
            board[0] = 'X';
        } else{
            board[0] = 'O';
        }
    } else if (input == 2){
        if(player_check == 1) {
            board[1] = 'X';
        } else{
            board[1] = 'O';
        }
    } else if (input == 3){
        if(player_check == 1) {
            board[2] = 'X';
        } else{
            board[2] = 'O';
        }
    } else if(input == 4){
        if(player_check == 1) {
            board[3] = 'X';
        } else{
            board[3] = 'O';
        }
    } else if (input == 5) {
        if(player_check == 1) {
            board[4] = 'X';
        } else{
            board[4] = 'O';
        }
    } else if (input == 6) {
        if(player_check == 1) {
            board[5] = 'X';
        } else{
            board[5] = 'O';
        }
    } else if (input == 7) {
        if(player_check == 1) {
            board[6] = 'X';
        } else{
            board[6] = 'O';
        }
    } else if (input == 8) {
        if(player_check == 1) {
            board[7] = 'X';
        } else{
            board[7] = 'O';
        }
    } else if (input == 9) {
        if(player_check == 1) {
            board[8] = 'X';
        } else{
            board[8] = 'O';
        }
    } else {
        std::cout << "Invalid Option selected!\n";
    }
}

bool take_turn() {
    
    int loop_count = 0;
    std::cout << "Player " << player << ", enter a box number to take your turn please: ";
    // This loop will check if user has selected a valid box number or not
    while (loop_count < 5){
        std::cin >> player_turn;
        if(player_turn == 1 || player_turn == 2 || player_turn == 3 || player_turn == 4 || player_turn == 5 || player_turn == 6 || player_turn == 7 || player_turn == 8 || player_turn == 9) {
            if(board[player_turn - 1] == 'X' || board[player_turn - 1] == 'O'){
                std::cout << "\nPlcae is already occuppied\n";
                std::cout << "Select a valid box number: ";
                continue;
            } else {
                set_position(player_turn, player);
            }
            return true;
        } else { 
            std::cout << "No box number selected!\n";
            std::cout << "Player " << player << ", enter a box number to take your turn please: ";
        }
        loop_count++;
    }
    return false;
}

void update_board() {
    draw();
}

bool is_winner() {
    if(board[0] == board[1] && board[0] == board[2]){
        if(board[0] == 'X') {
            winner = 1;
        } else {
            winner = 2;
        }
        return true;
    } if (board[3] == board[4] && board[3] == board[5]) {
        if(board[3] == 'X') {
            winner = 1;
        } else {
            winner = 2;
        }
        return true;
    } if (board[6] == board[7] && board[6] == board[8]) {
        if(board[6] == 'X') {
            winner = 1;
        } else {
            winner = 2;
        }
        return true;
    } if (board[0] == board[3] && board[0] == board[6]) {
        if(board[0] == 'X') {
            winner = 1;
        } else {
            winner = 2;
        }
        return true;
    } if (board[1] == board[4] && board[1] == board[7]) {
        if(board[1] == 'X') {
            winner = 1;
        } else {
            winner = 2;
        }
        return true;
    } if(board[2] == board[5] && board[2] == board[8]) {
        if(board[2] == 'X') {
            winner = 1;
        } else {
            winner = 2;
        }
        return true;
    } if (board[0] == board[4] && board[0] == board[8]) {
        if(board[0] == 'X') {
            winner = 1;
        } else {
            winner = 2;
        }
        return true;
    } if (board[2] == board[4] && board[2] == board[6]){
        if(board[2] == 'X') {
            winner = 1;
        } else {
            winner = 2;
        }
        return true;
    }
    return false;
    
}

bool filled_up () {
    if(board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4' && board[4] != '5' && board[5] != '6' && board[6] != '7' && board[7] != '8' && board[8] != '9') {
        filled = 1;
        return true;
    } else {
        return false;
    }
}

void end_game() {
    std::cout << "\n==================================================\n";
    if(filled == 1) {
        std::cout << "There is a tie between player 1 and player 2\n";
    } else if (winner == 1 || winner == 2 ){
        std::cout << "  Congratulations Player " << winner << ", You won the game\n";
    } else {
        std::cout << "Game Overflow!\n";
    }
    std::cout << "==================================================\n";
}