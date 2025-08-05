#include <stdio.h>

int main(){
    /*defining variables*/
    double a , b , c , error;
    scanf("%lf %lf %lf %lf", &a , &b , &c , &error);
    double max;

    /*finding the maximum of a & b & c*/
    if ((a>=b) && (a>=c)){
        max =a;
    }else if((b>=a) && (b>=c)){
        max =b;
    }else if((c>=a) && (c>=b)){
        max =c;
    }
    double ans = max*max;
    
    /*----------------------------------------*/
    if (((ans*ans*ans)+(a*ans*ans)+(b*ans)+c)>(-1)*error){
        while(((ans*ans*ans)+(a*ans*ans)+(b*ans)+c)>error){
            ans -= error;
        }
        printf("%lf\n" , ans);
    }else{
        printf("bedoon rishe");
    }  
    return 0;
} 