#include <stdio.h>


int main (){
    /*defining variables and getting them from the user*/
    int room_number;
    scanf("%d", &room_number);
    double jump_height;
    scanf("%lf", &jump_height);
    int area = (room_number%100);
    double min_height = (room_number/100)*2 + 1;
    double h=0 ;
    int n=1;
    double oter_heights = (jump_height/2);
    /*determining the jumping area*/
    if((1<=area)&&(area<=4)){
        printf("1\n");
    }else if((5<=area)&&(area<=8)){
        printf("2\n");
    }else if((9<=area)&&(area<=12)){
        printf("3\n");
    }else if((13<=area)&&(area<=16)){
        printf("4\n");
    }

  /*the algorithm to find the numbers of jumps*/
    while((jump_height+h)<min_height){
        h=n*oter_heights;
        n++;
    }
    printf("%d\n", n-1);
    

    return 0;
}