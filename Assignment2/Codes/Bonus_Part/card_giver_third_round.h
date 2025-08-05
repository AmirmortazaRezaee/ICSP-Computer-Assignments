int card_giver_third_round(int player1[4][11],int *player1_symbols , int *player1_numbers,int player2[4][11],int player3[4][11],int player4[4][11] , int *card){
    /*this function gives each players slast 2 cards*/
    for(int i=36;i<38;i++){
        player1[(card[i]/11)][(card[i]%11)] =1;
        player1_symbols[i-27]=(card[i]/11);
        player1_numbers[i-27]=(card[i]%11);
    }
    for(int i=38;i<40;i++){
        player2[(card[i]/11)][(card[i]%11)] =1;
    }
    for(int i=40;i<42;i++){
        player3[(card[i]/11)][(card[i]%11)] =1;
    }
    for(int i=42;i<44;i++){
        player4[(card[i]/11)][(card[i]%11)] =1;
    }
}