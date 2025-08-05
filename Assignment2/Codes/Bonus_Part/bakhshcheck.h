int bakhshcheck(char bakshnameh, int player1[4][11]){
    /*this function checks if user enters the correct value for bakhshnameh or not*/
    if (bakshnameh=='A'){
        for(int i=0;i<11;i++){
            if (player1[0][i]==1){
                return 0;
            }
        }
        return 1;
    }
    if (bakshnameh=='B'){
        for(int i=0;i<11;i++){
            if (player1[1][i]==1){
                return 0;
            }
        }
        return 1;
    }
    if (bakshnameh=='C'){
        for(int i=0;i<11;i++){
            if (player1[2][i]==1){
                return 0;
            }
        }
        return 1;
    }
    if (bakshnameh=='D'){
        for(int i=0;i<11;i++){
            if (player1[3][i]==1){
                return 0;
            }
        }
        return 1;
    }

}