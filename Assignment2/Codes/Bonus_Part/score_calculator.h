int score_calculator(int *first_teams_score_pointer , int *second_teams_score_pointer , int start_symbol ,int p1_printer_number ,int p1_printer_symbol ,int p2_printer_number ,int p2_printer_symbol ,
       int p3_printer_number,int p3_printer_symbol ,int p4_printer_number ,int p4_printer_symbol , int *starter_pointer,int bakhshnameh_decimal ){
        int bakhsh1=0 , bakhsh2=0, bakhsh3=0, bakhsh4=0 , bakhsh_sum=0, sym1=0,sym2=0,sym3=0,sym4=0;

        /*this function checks playing conditions and calculates scores with regarding the rules of the project*/

        /*first situation: all the symbols are same*/
        if((p1_printer_symbol==p2_printer_symbol)&&(p2_printer_symbol==p3_printer_symbol)&&(p3_printer_symbol==p4_printer_symbol)){
            if(((p1_printer_number>p2_printer_number)&&(p1_printer_number>p4_printer_number))||((p3_printer_number>p2_printer_number)&&(p3_printer_number>p4_printer_number))){
                *first_teams_score_pointer +=1;
                if(p1_printer_number>p3_printer_number){
                    *starter_pointer=1;
                }else{
                    *starter_pointer=3;
                }
            }else{
                *second_teams_score_pointer +=1;
                if(p2_printer_number>p4_printer_number){
                    *starter_pointer=2;
                }else{
                    *starter_pointer=4;
                }
            }    
        }else{
            if (p1_printer_symbol==bakhshnameh_decimal-65){
                bakhsh1++;
            }
            if (p2_printer_symbol==bakhshnameh_decimal-65){
                bakhsh2++;
            }
            if (p3_printer_symbol==bakhshnameh_decimal-65){
                bakhsh3++;
            }
            if (p4_printer_symbol==bakhshnameh_decimal-65){
                bakhsh4++;
            }
            bakhsh_sum= bakhsh1+bakhsh2+bakhsh3+bakhsh4;
            
            /*second situation: all the symbols are not same and there is no bakhshnameh symbol on the board*/
            switch (bakhsh_sum){
                case 0:
                    if(p1_printer_symbol==start_symbol){
                        sym1++;
                    }
                    if(p2_printer_symbol==start_symbol){
                        sym2++;
                    }
                    if(p3_printer_symbol==start_symbol){
                        sym3++;
                    }
                    if(p4_printer_symbol==start_symbol){
                        sym4++;
                    }
                    switch (sym1+sym2+sym3+sym4){
                        case 1:
                            if((*starter_pointer==1)||(*starter_pointer==3)){
                                *first_teams_score_pointer+=1;
                            }else{
                                *second_teams_score_pointer+=1;
                            }
                        case 2:
                            if((sym1==1)&&(sym2==1)){
                                if(p1_printer_number>p2_printer_number){
                                    *first_teams_score_pointer +=1;
                                    *starter_pointer=1;
                                }else{
                                    *second_teams_score_pointer +=1;
                                    *starter_pointer=2;
                                }
                                }else if((sym1==1)&&(sym3==1)){
                                    *first_teams_score_pointer +=1;
                                    if(p1_printer_number>p3_printer_number){
                                        *starter_pointer=1;
                                    }else{
                                        *starter_pointer=3;
                                    }
                                }else if((sym1==1)&&(sym4==1)){
                                    if(p1_printer_number>p4_printer_number){
                                        *first_teams_score_pointer +=1;
                                        *starter_pointer=1;
                                    }else{
                                        *second_teams_score_pointer +=1;
                                        *starter_pointer=4;
                                    }
                                }else if((sym2==1)&&(sym3==1)){
                                    if(p3_printer_number>p2_printer_number){
                                        *first_teams_score_pointer +=1;
                                        *starter_pointer=3;
                                    }else{
                                        *second_teams_score_pointer +=1;
                                        *starter_pointer=2;
                                    }
                                }else if((sym4==1)&&(sym2==1)){
                                    *second_teams_score_pointer +=1;
                                    if(p4_printer_number>p2_printer_number){
                                        *starter_pointer=4;
                                    }else{                                      
                                        *starter_pointer=2;
                                    }
                                }else if((sym3==1)&&(sym4==1)){
                                    if(p3_printer_number>p4_printer_number){
                                        *first_teams_score_pointer +=1;
                                        *starter_pointer=3;
                                    }else{
                                        *second_teams_score_pointer +=1;
                                        *starter_pointer=4;
                                    }
                                }
                            break;

                        case 3:
                            if((sym1==1) && (sym2==1) && (sym3==1)){
                                if((p1_printer_number>p2_printer_number)&&(p1_printer_number>p3_printer_number)){
                                    *first_teams_score_pointer +=1;
                                    *starter_pointer=1;
                                }else if((p3_printer_number>p2_printer_number)&&(p3_printer_number>p1_printer_number)){
                                    *first_teams_score_pointer +=1;
                                    *starter_pointer=3;
                                }else if((p2_printer_number>p1_printer_number)&&(p2_printer_number>p3_printer_number)){
                                    *second_teams_score_pointer +=1;
                                    *starter_pointer=2;
                                }
                            } else if((sym1==1) && (sym2==1) && (sym4==1)){
                                if((p1_printer_number>p2_printer_number)&&(p1_printer_number>p4_printer_number)){
                                    *first_teams_score_pointer +=1;
                                    *starter_pointer=1;
                                }else if((p2_printer_number>p1_printer_number)&&(p2_printer_number>p4_printer_number)){
                                    *second_teams_score_pointer +=1;
                                    *starter_pointer=2;
                                }else if((p4_printer_number>p1_printer_number)&&(p4_printer_number>p2_printer_number)){
                                    *second_teams_score_pointer +=1;
                                    *starter_pointer=4;
                                }
                            }else if((sym1==1) && (sym3==1) && (sym4==1)){
                                if((p1_printer_number>p3_printer_number)&&(p1_printer_number>p4_printer_number)){
                                    *first_teams_score_pointer +=1;
                                    *starter_pointer=1;
                                }else if((p3_printer_number>p1_printer_number)&&(p3_printer_number>p4_printer_number)){
                                    *first_teams_score_pointer +=1;
                                    *starter_pointer=3;
                                }else if((p4_printer_number>p1_printer_number)&&(p4_printer_number>p3_printer_number)){
                                    *second_teams_score_pointer +=1;
                                    *starter_pointer=4;
                                }
                            }else if((sym2==1) && (sym3==1) && (sym4==1)){
                                if((p2_printer_number>p3_printer_number)&&(p2_printer_number>p4_printer_number)){
                                    *second_teams_score_pointer +=1;
                                    *starter_pointer=2;
                                }else if((p3_printer_number>p2_printer_number)&&(p3_printer_number>p4_printer_number)){
                                    *first_teams_score_pointer +=1;
                                    *starter_pointer=3;
                                }else if((p4_printer_number>p2_printer_number)&&(p4_printer_number>p3_printer_number)){
                                    *second_teams_score_pointer +=1;
                                    *starter_pointer=4;
                                }
                            }
                            break;
                        case 4:
                            if((p1_printer_number>p2_printer_number)&&(p1_printer_number>p3_printer_number)&&(p1_printer_number>p4_printer_number)){
                                *first_teams_score_pointer +=1;
                                *starter_pointer=1;
                            }else if((p2_printer_number>p1_printer_number)&&(p2_printer_number>p3_printer_number)&&(p2_printer_number>p4_printer_number)){
                                *second_teams_score_pointer +=1;
                                *starter_pointer=2;
                            }else if((p3_printer_number>p1_printer_number)&&(p3_printer_number>p2_printer_number)&&(p3_printer_number>p4_printer_number)){
                                *first_teams_score_pointer +=1;
                                *starter_pointer=3;
                            }else if((p4_printer_number>p1_printer_number)&&(p4_printer_number>p2_printer_number)&&(p4_printer_number>p3_printer_number)){
                                *second_teams_score_pointer +=1;
                                *starter_pointer=4;
                            }
                            break;
                        default:
                            break;
                        
                    }
                    break;
                
                case 1:
                    if(bakhsh1==1){
                        *first_teams_score_pointer +=1;
                        *starter_pointer=1;
                    }else if(bakhsh3==1){
                        *first_teams_score_pointer +=1;
                        *starter_pointer=3;
                    }else if(bakhsh2==1){
                        *second_teams_score_pointer +=1;
                        *starter_pointer=2;
                    }else if(bakhsh4==1){
                        *second_teams_score_pointer +=1;
                        *starter_pointer=4;
                    }
                    break;
                case 2:
                    if(bakhsh1==1 && bakhsh2==1){
                        if(p1_printer_number > p2_printer_number){
                            *first_teams_score_pointer +=1;
                            *starter_pointer=1;
                        }else{
                            *second_teams_score_pointer +=1;
                            *starter_pointer=2;
                        }
                    }else if(bakhsh1==1 && bakhsh3==1){
                        *first_teams_score_pointer +=1;
                        if(p1_printer_number > p3_printer_number){
                            *starter_pointer=1;
                        }else{
                            *starter_pointer=3;
                        }
                    }else if(bakhsh1==1 && bakhsh4==1){
                        if(p1_printer_number > p4_printer_number){
                            *first_teams_score_pointer +=1;
                            *starter_pointer=1;
                        }else{
                            *second_teams_score_pointer +=1;
                            *starter_pointer=4;
                        }
                    }else if(bakhsh2==1 && bakhsh3==1){
                        if(p3_printer_number > p2_printer_number){
                            *first_teams_score_pointer +=1;
                            *starter_pointer=3;
                        }else{
                            *second_teams_score_pointer +=1;
                            *starter_pointer=2;
                        }
                    }else if(bakhsh2==1 && bakhsh4==1){
                        *second_teams_score_pointer +=1;
                        if(p2_printer_number > p4_printer_number){
                            *starter_pointer=2;
                        }else{
                            *starter_pointer=4;
                        }
                    }else if(bakhsh3==1 && bakhsh4==1){
                        if(p3_printer_number > p4_printer_number){
                            *first_teams_score_pointer +=1;
                            *starter_pointer=3;
                        }else{
                            *second_teams_score_pointer +=1;
                            *starter_pointer=4;
                        }
                    }
                    break;
                
                case 3:
                    if ((bakhsh1==1)&&(bakhsh2==1)&&(bakhsh3==1)){
                        if((p1_printer_number>p2_printer_number)&& (p1_printer_number>p3_printer_number)){
                            *first_teams_score_pointer +=1;
                            *starter_pointer=1;
                        }else if((p3_printer_number>p2_printer_number)&& (p3_printer_number>p1_printer_number)){
                            *first_teams_score_pointer +=1;
                            *starter_pointer=3;
                        }else if((p2_printer_number>p1_printer_number)&& (p2_printer_number>p3_printer_number)){
                            *second_teams_score_pointer +=1;
                            *starter_pointer=2;
                        }
                    }else if ((bakhsh1==1)&&(bakhsh2==1)&&(bakhsh4==1)){
                        if((p1_printer_number>p2_printer_number)&& (p1_printer_number>p4_printer_number)){
                            *first_teams_score_pointer +=1;
                            *starter_pointer=1;
                        }else if((p2_printer_number>p1_printer_number)&& (p2_printer_number>p4_printer_number)){
                            *second_teams_score_pointer +=1;
                            *starter_pointer=2;
                        }else if((p4_printer_number>p1_printer_number)&& (p4_printer_number>p2_printer_number)){
                            *second_teams_score_pointer +=1;
                            *starter_pointer=4;
                        }
                    }else if ((bakhsh1==1)&&(bakhsh3==1)&&(bakhsh4==1)){
                        if((p1_printer_number>p3_printer_number)&& (p1_printer_number>p4_printer_number)){
                            *first_teams_score_pointer +=1;
                            *starter_pointer=1;
                        }else if((p3_printer_number>p1_printer_number)&& (p3_printer_number>p4_printer_number)){
                            *first_teams_score_pointer +=1;
                            *starter_pointer=3;
                        }else if((p4_printer_number>p1_printer_number)&& (p4_printer_number>p3_printer_number)){
                            *second_teams_score_pointer +=1;
                            *starter_pointer=4;
                        }
                    }else if ((bakhsh2==1)&&(bakhsh3==1)&&(bakhsh4==1)){
                        if((p2_printer_number>p3_printer_number)&& (p2_printer_number>p4_printer_number)){
                            *second_teams_score_pointer +=1;
                            *starter_pointer=2;
                        }else if((p3_printer_number>p2_printer_number)&& (p3_printer_number>p4_printer_number)){
                            *first_teams_score_pointer +=1;
                            *starter_pointer=3;
                        }else if((p4_printer_number>p2_printer_number)&& (p4_printer_number>p3_printer_number)){
                            *second_teams_score_pointer +=1;
                            *starter_pointer=4;
                        }
                    }
                    break;


                default:
                    break;
            }
        }
    }