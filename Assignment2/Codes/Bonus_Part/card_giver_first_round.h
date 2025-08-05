int card_giver_first_round(int player1[4][11],int *player1_symbols , int *player1_numbers,int player2[4][11],int player3[4][11],int player4[4][11] , int *card){
    /*this function gives each players first 5 cards*/
    for(int i=0;i<5;i++){
        player1[(card[i]/11)][(card[i]%11)] =1;
        player1_symbols[i]=(card[i]/11);
        player1_numbers[i]=(card[i]%11);
    }
    for(int i=5;i<10;i++){
        player2[(card[i]/11)][(card[i]%11)] =1;
    }
    for(int i=10;i<15;i++){
        player3[(card[i]/11)][(card[i]%11)] =1;
    }
    for(int i=15;i<20;i++){
        player4[(card[i]/11)][(card[i]%11)] =1;
    }
}