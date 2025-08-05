int pn_starts(int playern[4][11] ,int bakhshnameh_decimal , int *pn_printer_number_pointer , int  *pn_printer_symbol_pointer , int *start_number_pointer,int *start_symbol_pointer ){
    /*this function choose a card to start the round with regarding the rules of the project*/
    int max_num=-1;
    int max_sym=-1;
    int max_num_bakhsh =-1;
    switch (bakhshnameh_decimal-65){
        case 0:
            for(int i=1;i<4;i++){
                for(int j=10;j>=0;j--){
                    if(playern[i][j]==1){
                        if(j>max_num){
                            max_num=j;
                            max_sym=i;
                        }
                    }
                }
            }
            for(int k=10;k>=0;k--){
                if(playern[0][k]==1){
                    if(k>max_num_bakhsh){
                        max_num_bakhsh=k;
                    }
                }
            }
            if(max_num!= -1){
                *pn_printer_number_pointer=max_num;
                *pn_printer_symbol_pointer=max_sym;
                *start_number_pointer=max_num;
                *start_symbol_pointer=max_sym;
                playern[max_sym][max_num]=0;
            }else{
                *pn_printer_number_pointer=max_num_bakhsh;
                *pn_printer_symbol_pointer=0;
                *start_number_pointer=max_num_bakhsh;
                *start_symbol_pointer=0;
                playern[0][max_num_bakhsh]=0;
            }
            break;
        case 1:
            for(int i=10;i>=0;i--){
                if(playern[0][i]==1){
                    if(i>max_num){
                        max_num=i;
                        max_sym=1;
                    }
                }
            }
            for(int j=2;j<4;j++){
                for(int k=10;k>=0;k--){
                    if(playern[j][k]==1){
                        if(k>max_num){
                            max_num=k;
                            max_sym=j;
                        }
                    }
                }
            }
            for(int t=10;t>=0;t--){
                if(playern[1][t]==1){
                    if(t>max_num_bakhsh){
                        max_num_bakhsh=t;
                    }
                }
            }
            if(max_num!= -1){
                *pn_printer_number_pointer=max_num;
                *pn_printer_symbol_pointer=max_sym;
                *start_number_pointer=max_num;
                *start_symbol_pointer=max_sym;
                playern[max_sym][max_num]=0;
            }else{
                *pn_printer_number_pointer=max_num_bakhsh;
                *pn_printer_symbol_pointer=1;
                *start_number_pointer=max_num_bakhsh;
                *start_symbol_pointer=1;
                playern[1][max_num_bakhsh]=0;
            }
            break;
        case 2:
            for(int i=0;i<2;i++){
                for(int j=10;j>=0;j--){
                    if(playern[i][j]==1){
                        if(j>max_num){
                            max_num=j;
                            max_sym=i;
                        }
                    }
                }
            }
            for(int k=10;k>=0;k--){
                if(playern[3][k]==1){
                    if(k>max_num){
                        max_num=k;
                        max_sym=3;
                    }
                }
            }
            for(int t=10;t>=0;t--){
                if(playern[2][t]==1){
                    if(t>max_num_bakhsh){
                        max_num_bakhsh=t;
                    }
                }
            }
            if(max_num!= -1){
                *pn_printer_number_pointer=max_num;
                *pn_printer_symbol_pointer=max_sym;
                *start_number_pointer=max_num;
                *start_symbol_pointer=max_sym;
                playern[max_sym][max_num]=0;
            }else{
                *pn_printer_number_pointer=max_num_bakhsh;
                *pn_printer_symbol_pointer=2;
                *start_number_pointer=max_num_bakhsh;
                *start_symbol_pointer=2;
                playern[2][max_num_bakhsh]=0;
            }
            break;
        case 3:
            for(int i=0;i<3;i++){
                for(int j=10;j>=0;j--){
                    if(playern[i][j]==1){
                        if(j>max_num){
                            max_num=j;
                            max_sym=i;
                        }
                    }
                }
            }
            for(int k=10;k>=0;k--){
                if(playern[3][k]==1){
                    if(k>max_num_bakhsh){
                        max_num_bakhsh=k;
                    }
                }
            }
            if(max_num!= -1){
                *pn_printer_number_pointer=max_num;
                *pn_printer_symbol_pointer=max_sym;
                *start_number_pointer=max_num;
                *start_symbol_pointer=max_sym;
                playern[max_sym][max_num]=0;
            }else{
                *pn_printer_number_pointer=max_num_bakhsh;
                *pn_printer_symbol_pointer=3;
                *start_number_pointer=max_num_bakhsh;
                *start_symbol_pointer=3;
                playern[3][max_num_bakhsh]=0;
            }
            break;
        default:
            break;
    }
}