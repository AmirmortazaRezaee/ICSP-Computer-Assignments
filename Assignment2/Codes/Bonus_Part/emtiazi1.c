#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include"bakhshcheck.h"
#include "bakhshnameh_existance_check.h"
#include "card_giver_first_round.h"
#include "card_giver_second_round.h"
#include "card_giver_third_round.h"
#include "play_check.h"
#include "pn_plays.h"
#include "pn_starts.h"
#include "print_values_refresher.h"
#include "printer.h"
#include "score_calculator.h"
#include "start_card_checker.h"
#include "zeroer.h"

void shuffle_card(int* card);


int main(){
    printf("\n\t\t\t\t**WELCOME TO MY PROJECT**\n\t\t\t\t    $$HOPE YOU WIN$$\n\n\n");
    int first_team_set=0, second_team_set=0;
    while((first_team_set<5)&&(second_team_set<5)){
        /*variables declaration*/
        int card[44];
        int player1[4][11], player2[4][11], player3[4][11],player4[4][11];
        int player1_symbols[11], player1_numbers[11];
        int start_number, start_symbol; /*the number an the symbol of the each round's starting card*/
        int *start_number_pointer=&start_number;
        int *start_symbol_pointer=&start_symbol;
        
        int p1_printer_number=-1 , p1_printer_symbol=-20 , p2_printer_number=-1 , p2_printer_symbol=-20 ,
            p3_printer_number=-1 , p3_printer_symbol=-20 , p4_printer_number=-1 , p4_printer_symbol=-20 ;

        int *p1_printer_number_pointer=&p1_printer_number , *p1_printer_symbol_pointer=&p1_printer_symbol ,
            *p2_printer_number_pointer=&p2_printer_number , *p2_printer_symbol_pointer=&p2_printer_symbol , 
            *p3_printer_number_pointer=&p3_printer_number , *p3_printer_symbol_pointer=&p3_printer_symbol , 
            *p4_printer_number_pointer=&p4_printer_number , *p4_printer_symbol_pointer=&p4_printer_symbol ;

        int p2_return , p3_return , p4_return;
        int choose;
        
        char bakhshnameh;

        int first_teams_score=0 , second_teams_score=0;
        //int first_team_set=0, second_team_set=0;
        int *first_teams_score_pointer=&first_teams_score , *second_teams_score_pointer=&second_teams_score;
        int starter; /*a variable to determines the player who should start each round*/
        int *starter_pointer=&starter;
        int bakhshnameh_decimal;

    
        for(int i=0;i<11;i++){
        player1_numbers[i]=0;
        player1_symbols[i]= -20;
        }
        starter=1;
        /*shufling cards*/
        zeroer(player1,player2,player3,player4);
        shuffle_card(card);
        system("cls");
        
        /*shuffling first 5 cards*/
        card_giver_first_round( player1, player1_symbols, player1_numbers ,player2,player3,player4,card);
        printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol, p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score , second_team_set, first_team_set);

        /*getting bakhshnameh symbol from user*/
        printf("please select bakhshnameh:\n");
        do{
            scanf("%c", &bakhshnameh);
            if(bakhshcheck(bakhshnameh, player1)){
               // printf("invalid input, try again:\n");
                scanf("%c", &bakhshnameh);
            }
        } while (bakhshcheck(bakhshnameh, player1));
        bakhshnameh_decimal=bakhshnameh;


        /*shuffling second 4 cards*/
        card_giver_second_round(player1, player1_symbols, player1_numbers ,player2,player3,player4,card);
        system("cls");
        printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol, p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score, second_team_set, first_team_set);
        
        printf("please press ENTER to continue:\n");
        getch();
        /*shuffling last 2 cards*/
        card_giver_third_round(player1, player1_symbols, player1_numbers ,player2,player3,player4,card);
        system("cls");
        printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol, p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);
    
        /*********GAME STARTS*********/
        
        while((first_teams_score<6)&&(second_teams_score<6)){

            switch (starter){
                case 1: /*the condition in which, the first player (user) should start the game*/
                    printf("You should start this round!! please choose a card:\n");
                    scanf("%d", &choose);
                    do{
                        if(start_card_checker(choose, player1_numbers)){
                            printf("invalid input, try again:\n");
                            scanf("%d", &choose);
                        }
                    } while (start_card_checker(choose , player1_numbers));

                    start_number = player1_numbers[choose];
                    start_symbol = player1_symbols[choose];
                    p1_printer_number = player1_numbers[choose];
                    p1_printer_symbol = player1_symbols[choose];
                    player1_numbers[choose]=-1;
                    player1_symbols[choose]= -20;
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol, p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score, second_team_set, first_team_set);

                    printf("\nIt's not your turn! please press ENTER to continue:\n");
                    getch();

                    if (play_check(player2, start_symbol)){
                        p2_return=1;
                    }else{
                        if(bakhshnameh_existance_check(player2, bakhshnameh)){
                            p2_return=2;
                        }else{
                            p2_return=3;
                        }
                    }
                    /*if the player has a symbol of start card, the return value will be 1, else if the player has a symbol of bakhshnameh,
                    the return value will be 2, and if the player has none of them, the return value will be 3*/
                    pn_plays(player2,p2_return ,start_symbol,bakhshnameh_decimal,p2_printer_number_pointer , p2_printer_symbol_pointer);
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol, p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);
                    
                    printf("\nIt's not your turn! please press ENTER to continue:\n");
                    getch();

                    if (play_check(player3, start_symbol)){
                        p3_return=1;
                    }else{
                        if(bakhshnameh_existance_check(player3, bakhshnameh)){
                            p3_return=2;
                        }else{
                            p3_return=3;
                        }
                    }

                    pn_plays(player3,p3_return ,start_symbol,bakhshnameh_decimal,p3_printer_number_pointer , p3_printer_symbol_pointer);
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol, p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);

                    printf("\nIt's not your turn! please press ENTER to continue:\n");
                    getch();
                    
                    if (play_check(player4, start_symbol)){
                        p4_return=1;
                    }else{
                        if(bakhshnameh_existance_check(player4, bakhshnameh)){
                            p4_return=2;
                        }else{
                            p4_return=3;
                        }
                    }

                    pn_plays(player4,p4_return ,start_symbol,bakhshnameh_decimal,p4_printer_number_pointer , p4_printer_symbol_pointer);
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol, p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);

                    printf("please press ENTER to update the results!\n");
                    getch();

                    

                    score_calculator(first_teams_score_pointer ,second_teams_score_pointer ,start_symbol ,p1_printer_number ,p1_printer_symbol ,p2_printer_number 
                    ,p2_printer_symbol ,p3_printer_number,p3_printer_symbol ,p4_printer_number ,p4_printer_symbol ,starter_pointer ,bakhshnameh_decimal);
                    
                    /*deleting all the cards on the game board*/
                    print_values_refresher(p1_printer_number_pointer, p1_printer_symbol_pointer);
                    print_values_refresher(p2_printer_number_pointer, p2_printer_symbol_pointer);
                    print_values_refresher(p3_printer_number_pointer, p3_printer_symbol_pointer);
                    print_values_refresher(p4_printer_number_pointer, p4_printer_symbol_pointer);
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);

                    
                    break;
                
                case 2: /*the condition in which, the second player should start the game*/
                    
                    printf("\nplayer 2 should start this round!! , please press ENTER to continue:\n");
                    getch();
                    pn_starts(player2, bakhshnameh_decimal , p2_printer_number_pointer, p2_printer_symbol_pointer,start_number_pointer,start_symbol_pointer);
                    start_number = p2_printer_number;
                    start_symbol = p2_printer_symbol;
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);
                    printf("\nIt's not your turn! please press ENTER to continue:\n");
                    getch();

                    if (play_check(player3, start_symbol)){
                        p3_return=1;
                    }else{
                        if(bakhshnameh_existance_check(player3, bakhshnameh)){
                            p3_return=2;
                        }else{
                            p3_return=3;
                        }
                    }

                    pn_plays(player3,p3_return ,start_symbol,bakhshnameh_decimal,p3_printer_number_pointer , p3_printer_symbol_pointer);
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);
                    printf("\nIt's not your turn! please press ENTER to continue:\n");
                    getch();

                    if (play_check(player4, start_symbol)){
                        p4_return=1;
                    }else{
                        if(bakhshnameh_existance_check(player4, bakhshnameh)){
                            p4_return=2;
                        }else{
                            p4_return=3;
                        }
                    }

                    pn_plays(player4,p4_return ,start_symbol,bakhshnameh_decimal,p4_printer_number_pointer , p4_printer_symbol_pointer);
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);
                    
                    printf("\nIt's your turn!\nplease choose a card:\n");
                    scanf("%d", &choose);
                    do{
                        if(start_card_checker(choose , player1_numbers)){
                            printf("invalid input, try again:\n");
                            scanf("%d", &choose);
                        }
                    } while (start_card_checker(choose , player1_numbers));
                    p1_printer_number = player1_numbers[choose];
                    p1_printer_symbol = player1_symbols[choose];
                    player1_numbers[choose]=-1;
                    player1_symbols[choose]= -20;
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);

                    printf("please press ENTER to update the results!\n");
                    getch();
                    score_calculator(first_teams_score_pointer ,second_teams_score_pointer ,start_symbol ,p1_printer_number ,p1_printer_symbol ,p2_printer_number 
                    ,p2_printer_symbol ,p3_printer_number,p3_printer_symbol ,p4_printer_number ,p4_printer_symbol ,starter_pointer ,bakhshnameh_decimal);

                    /*deleting all the cards on the game board*/
                    print_values_refresher(p1_printer_number_pointer, p1_printer_symbol_pointer);
                    print_values_refresher(p2_printer_number_pointer, p2_printer_symbol_pointer);
                    print_values_refresher(p3_printer_number_pointer, p3_printer_symbol_pointer);
                    print_values_refresher(p4_printer_number_pointer, p4_printer_symbol_pointer);
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);
                    break;
                    
                case 3: /*the condition in which, the third player should start the game*/
                
                    printf("\nplayer 3 should start this round!! , please press ENTER to continue: \n");
                    getch();
                    pn_starts(player3, bakhshnameh_decimal , p3_printer_number_pointer, p3_printer_symbol_pointer ,start_number_pointer,start_symbol_pointer);
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);
                    printf("\nIt's not your turn!,please press ENTER to continue:\n");
                    getch();

                    if (play_check(player4, start_symbol)){
                        p4_return=1;
                    }else{
                        if(bakhshnameh_existance_check(player4, bakhshnameh)){
                            p4_return=2;
                        }else{
                            p4_return=3;
                        }
                    }

                    pn_plays(player4,p4_return ,start_symbol,bakhshnameh_decimal,p4_printer_number_pointer , p4_printer_symbol_pointer);
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);
                    
                    printf("\nIt's your turn!\nplease choose a card:\n");
                    scanf("%d", &choose);
                    do{
                        if(start_card_checker(choose , player1_numbers)){
                            printf("invalid input, try again:\n");
                            scanf("%d", &choose);
                        }
                    } while (start_card_checker(choose , player1_numbers));
                    p1_printer_number = player1_numbers[choose];
                    p1_printer_symbol = player1_symbols[choose];
                    player1_numbers[choose]=-1;
                    player1_symbols[choose]= -20;
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);

                    printf("It's not your turn!\nplease press ENTER to continue\n");
                    getch();

                    if (play_check(player2, start_symbol)){
                        p2_return=1;
                    }else{
                        if(bakhshnameh_existance_check(player2, bakhshnameh)){
                            p2_return=2;
                        }else{
                            p2_return=3;
                        }
                    }
                    pn_plays(player2,p2_return ,start_symbol,bakhshnameh_decimal,p2_printer_number_pointer , p2_printer_symbol_pointer);
                    start_number = p2_printer_number;
                    start_symbol = p2_printer_symbol;
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);

                    printf("please press ENTER to update the results!\n");
                    getch();

                    score_calculator(first_teams_score_pointer ,second_teams_score_pointer ,start_symbol ,p1_printer_number ,p1_printer_symbol ,p2_printer_number 
                    ,p2_printer_symbol ,p3_printer_number,p3_printer_symbol ,p4_printer_number ,p4_printer_symbol ,starter_pointer ,bakhshnameh_decimal);

                    /*deleting all the cards on the game board*/
                    print_values_refresher(p1_printer_number_pointer, p1_printer_symbol_pointer);
                    print_values_refresher(p2_printer_number_pointer, p2_printer_symbol_pointer);
                    print_values_refresher(p3_printer_number_pointer, p3_printer_symbol_pointer);
                    print_values_refresher(p4_printer_number_pointer, p4_printer_symbol_pointer);
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);
                    break;

                case 4:  /*the condition in which, the fourth player should start the game*/
                    
                    printf("\nplayer 4 should start this round!! , please press ENTER to continue: \n");
                    getch();
                    pn_starts(player4, bakhshnameh_decimal , p4_printer_number_pointer, p4_printer_symbol_pointer, start_number_pointer,start_symbol_pointer);
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);
                    
                    printf("\nIt's your turn!\nplease choose a card:\n");
                    scanf("%d", &choose);
                    do{
                        if(start_card_checker(choose , player1_numbers)){
                            printf("invalid input, try again:\n");
                            scanf("%d", &choose);
                        }
                    } while (start_card_checker(choose , player1_numbers));
                    p1_printer_number = player1_numbers[choose];
                    p1_printer_symbol = player1_symbols[choose];
                    player1_numbers[choose]=-1;
                    player1_symbols[choose]= -20;
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);

                    printf("It's not your turn! ,please press ENTER to continue:\n");
                    getch();

                    if (play_check(player2, start_symbol)){
                        p2_return=1;
                    }else{
                        if(bakhshnameh_existance_check(player2, bakhshnameh)){
                            p2_return=2;
                        }else{
                            p2_return=3;
                        }
                    }
                    pn_plays(player2,p2_return ,start_symbol,bakhshnameh_decimal,p2_printer_number_pointer , p2_printer_symbol_pointer);
                    start_number = p2_printer_number;
                    start_symbol = p2_printer_symbol;
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);

                    printf("It's not your turn! ,please press ENTER to continue:\n");
                    getch();

                    if (play_check(player3, start_symbol)){
                        p3_return=1;
                    }else{
                        if(bakhshnameh_existance_check(player3, bakhshnameh)){
                            p3_return=2;
                        }else{
                            p3_return=3;
                        }
                    }

                    pn_plays(player3,p3_return ,start_symbol,bakhshnameh_decimal,p3_printer_number_pointer , p3_printer_symbol_pointer);
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);

                    printf("please press ENTER to update the results!\n");
                    getch();

                    score_calculator(first_teams_score_pointer ,second_teams_score_pointer ,start_symbol ,p1_printer_number ,p1_printer_symbol ,p2_printer_number 
                    ,p2_printer_symbol ,p3_printer_number,p3_printer_symbol ,p4_printer_number ,p4_printer_symbol ,starter_pointer ,bakhshnameh_decimal);

                    /*deleting all the cards on the game board*/
                    print_values_refresher(p1_printer_number_pointer, p1_printer_symbol_pointer);
                    print_values_refresher(p2_printer_number_pointer, p2_printer_symbol_pointer);
                    print_values_refresher(p3_printer_number_pointer, p3_printer_symbol_pointer);
                    print_values_refresher(p4_printer_number_pointer, p4_printer_symbol_pointer);
                    system("cls");
                    printer(p1_printer_number, p1_printer_symbol, p2_printer_number, p2_printer_symbol, p3_printer_number, p3_printer_symbol,
                    p4_printer_number, p4_printer_symbol,start_symbol, start_number,player1_symbols, player1_numbers , first_teams_score, second_teams_score,second_team_set, first_team_set);
                    break;

                default:
                    break;

            }
            

            /*printing the last result*/
            if(first_teams_score==6){
                printf("\n\t***\n FIRST TEAM WINS THE ROUND!! \n\t***\n");
                getch();
            }else if(second_teams_score==6){
                printf("\n\t***\n SECOND TEAM WINS THE ROUND!! \n\t***\n");
                getch();
            }
        }
        if(first_teams_score>second_teams_score){
            first_team_set++;
        }else{
            second_team_set++;
        }
        if((first_teams_score==6)&&(second_teams_score==0)){
            first_team_set++;
        }else if((second_teams_score==6)&&(first_teams_score==0)){
            second_team_set++;
        }
    }
    if(first_team_set==5){
                printf("\n*******************\n FIRST TEAM WINS!! \n*******************\n");
                getch();
            }else if(second_team_set==5){
                printf("\n********************\n SECOND TEAM WINS!! \n********************\n");
                getch();
            }
    return 0;
}
    

    void shuffle_card(int* card) {
    int i, r, temp;
    for (temp = 0, i = 0; temp < 44; i++, temp++)
        card[temp] = i;
    srand(time(NULL));
    for (i = 43; i > 0; i--) {
        r = rand() % i;
        temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
}