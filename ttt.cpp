#include <iostream>
#include "ttt_functions.hpp"

int main() {
    
    greet();
    draw();
    int count = 0;

    while(count < 10){

        if(take_turn()){
            update_board();
            if(!filled_up()){
                if(!is_winner()){
                    change_player();    
                } else {
                    break;
                }
            } else {
                break;
            }
        } else {
            std::cout << "\nGame Over!\n";
            return 0;
        }
        count++;
        
    }

    end_game();

    return 0;
}