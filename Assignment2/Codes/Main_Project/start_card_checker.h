int start_card_checker(int choose , int *player1_numbers){
    /*this function checks if the user enters a valid card to play or not */
    if((choose>10)||(choose<0)|| (player1_numbers[choose]== -1)){
        return 1;
    }
    return 0;
}