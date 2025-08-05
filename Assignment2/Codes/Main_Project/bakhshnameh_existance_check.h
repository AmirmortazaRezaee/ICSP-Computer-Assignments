int bakhshnameh_existance_check(int playern[4][11], char bakhshnameh){
    /*this function checks if the n-th player has a symbol of bakhshnameh between its cards*/
    for(int i=0;i<11;i++){
        if (playern[bakhshnameh-65][i]==1){
            return 1;
        }else if(playern[bakhshnameh-65][i]==0 && i==10){
            return 0;
        }
    }
}