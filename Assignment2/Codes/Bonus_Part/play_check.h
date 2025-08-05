int play_check(int playern[4][11] , int start_symbol){
    /*this function checks if the n-th player has a card with the same symbol of start card's symbol or not*/
    for(int i=0;i<11;i++){
        if (playern[start_symbol][i]==1){
            return 1;
        }else if(playern[start_symbol][i]==0 && i ==10){
            return 0;
        }
    }
}