#include <stdio.h>

int main()
{
    int n;
    printf("enter n");
scanf("%d", &n);

for (int i=0; i < 2*n-1; i++){  
    if (i < n){
       
        for (int j=0; j < i; j++){
            printf("%d ", n-j);
        }
       
        for (int k=2*(n-i)-1; k > 0; k--){
            printf("%d ", n-i);
        }
      
        for (int l=0; l < i; l++){
            printf("%d ", n-i+l+1);
        }
        printf("\n");
    } else {
       
        for (int j=0; j < 2*n-i-1; j++){
            printf("%d ", n-j);
        }
    
        for (int k=2*(i-n)+2; k > 0; k--){
            printf("%d ", i-n+2);
        }
        
        for (int l=0; l < 2*n-i-2 ; l++){
            printf("%d ", i-n+l+3);
        }
        printf("\n");
    }

}


    return 0;
}
