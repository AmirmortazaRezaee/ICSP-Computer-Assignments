int printer(int p1_printer_number,int p1_printer_symbol,int p2_printer_number,int p2_printer_symbol,int p3_printer_number,int p3_printer_symbol,
            int p4_printer_number,int p4_printer_symbol,int start_symbol, int start_number, int *player1_symbols , int *player1_numbers , int first_teams_score , int second_teams_score, int second_team_set, int first_team_set){
    
    /*this function prints the User Interface of the game*/
    printf("\t\t\t\t\tP3\n");
    printf("\t");
    for(int i=1;i<=65;i++){
        printf("-");
    }
    printf("\tTeam 1: %d | %d", first_teams_score , first_team_set);
    printf("\n");
    printf("\t|\t\t\t\t%c%2d       \t\t\t|", p3_printer_symbol+65 , p3_printer_number+1);
    printf("\n");
    for(int j=1;j<=7;j++){
        printf("\t|\t\t\t\t\t\t\t\t|\n");
    }
    printf("     P2 | %c%2d    \t\t\t\t\t\t    %c%2d | P4\n", p2_printer_symbol+65 , p2_printer_number+1, p4_printer_symbol+65 , p4_printer_number+1);
    for(int j=1;j<=7;j++){
        printf("\t|\t\t\t\t\t\t\t\t|\n");
    }
    printf("\t|\t\t\t\t%c%2d       \t\t\t|\n", p1_printer_symbol+65, p1_printer_number+1 );
    printf("\t");
    for(int i=1;i<=65;i++){
        printf("-");
    }
    printf("\tTeam 2: %d | %d", second_teams_score , second_team_set);
    printf("\n\t\t\t\t\tP1\n");
    printf("\t    ");
    for(int i=1;i<=56;i++){
        printf("-");
    }
    printf("\n     symbol |");
    for (int i=0;i<11;i++){
        printf(" ");
        printf("%c",(player1_symbols[i]+65) );
        printf("  |");
    }
    printf("\n");
    printf("\t    ");
    for(int i=1;i<=56;i++){
        printf("-");
    }
    printf("\n     number |");
    for (int i=0;i<11;i++){
        printf(" ");
        printf("%2d",player1_numbers[i]+1 );
        printf(" |");
    }
    printf("\n");
    printf("\t    ");
    for(int i=1;i<=56;i++){
        printf("-");
    }
    printf("\n\t      00   01   02   03   04   05   06   07   08   09   10\n\n\n");
}