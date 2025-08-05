int zeroer (int player1[4][11],int player2[4][11],int player3[4][11],int player4[4][11]){
    /*this function puts the values of all the indexes of all players arrays equal to 0*/
        for(int i=0;i<4;i++){
            for(int j=0;j<11;j++){
                player1[i][j]=0;
                player2[i][j]=0;
                player3[i][j]=0;
                player4[i][j]=0;
        }
    }
}