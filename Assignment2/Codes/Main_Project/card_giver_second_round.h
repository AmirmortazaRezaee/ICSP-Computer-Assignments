int card_giver_second_round(int player1[4][11],int *player1_symbols , int *player1_numbers,int player2[4][11],int player3[4][11],int player4[4][11] , int *card){
    /*this function gives each players second 4 cards*/
    for(int i=20;i<24;i++){
        player1[(card[i]/11)][(card[i]%11)] =1;
        player1_symbols[i-15]=(card[i]/11);
        player1_numbers[i-15]=(card[i]%11);
    }
    for(int i=24;i<28;i++){
        player2[(card[i]/11)][(card[i]%11)] =1;
    }
    for(int i=28;i<32;i++){
        player3[(card[i]/11)][(card[i]%11)] =1;
    }
    for(int i=32;i<36;i++){
        player4[(card[i]/11)][(card[i]%11)] =1;
    }
}