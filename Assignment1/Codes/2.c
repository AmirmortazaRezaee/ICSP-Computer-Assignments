#include <stdio.h>

int main(){
    /*defining variables*/
    int days_num;
    int food_num;
    int calory_sum=0;
    scanf("%d", &days_num);
    /*determining the list of foods*/
    for(int i=1;i<=days_num;i++){
        scanf("%d",&food_num);
        switch (food_num)
        {
        case 1:
            calory_sum+=329;
            break;
        case 2:
            calory_sum+=127;
            break;
        case 3:
            calory_sum+=61;
            break;
        case 4:
            calory_sum+=83;
            break;
        case 5:
            calory_sum+=156;
            break;
        case 6:
            calory_sum+=296;
            break;
        case 7:
            calory_sum+=496;
            break;
        case 8:
            calory_sum+=73;
            break;
        case 9:
            calory_sum+=34;
            break;
        case 10:
            calory_sum+=16;
            break;
        }
    }
    /*finding the result*/
    if(calory_sum-(100*days_num)>0){
        printf("chagh");
    }else if( calory_sum -(100*days_num)==0){
        printf("bedoon taghir");
    }else{
        printf("laghar");
    }
}






