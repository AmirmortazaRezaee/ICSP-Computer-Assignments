int pn_plays(int playern[4][11], int pn_return ,  int start_symbol, int bakhshnameh_decimal, int *pn_printer_number_pointer , int  *pn_printer_symbol_pointer){
    /*this function choose a card to play with regarding the rules of the project*/
    int min_num=11;
    int min_sym=4;

    switch (pn_return){
    case 1:
        for(int i=10;i>=0;i--){
            if(playern[start_symbol][i]==1){
                *pn_printer_number_pointer=i;
                *pn_printer_symbol_pointer=start_symbol;
                playern[start_symbol][i]=0;
                break;
            }
        }
        break;
    case 2:
        for(int i=10;i>=0;i--){
            if(playern[bakhshnameh_decimal-65][i]==1){
                *pn_printer_number_pointer=i;
                *pn_printer_symbol_pointer=bakhshnameh_decimal-65;
                playern[bakhshnameh_decimal-65][i]=0;
                break;
            }
        }
        break;
    case 3:
        for(int i=0;i<4;i++){
            for(int j=0;j<11;j++){
                if(playern[i][j]==1){
                    if(j<min_num){
                        min_num=j;
                        min_sym=i;
                    }
                }
            }
        }
        *pn_printer_number_pointer=min_num;
        *pn_printer_symbol_pointer=min_sym;
        playern[min_sym][min_num]=0;
        break;
    
    default:
        break;
    }
}