#include "stdio.h"

 main(){

    int vr[5], v1[5], v2[5], i;
    
       for(i=0;i<5;i++){
           printf("introduzca elemento %i del primer vector: ",i+1);
          scanf("%i",&v1[i]);
         }
       for(i=0;i<5;i++){
           printf("introduzca elemento %i del segundo vector: ",i+1);
          scanf("%i",&v2[i]);
         }


      for(i=0; i<5; i++){
       vr[i]=v1[i]+v2[i];
      printf("%i ",vr[i]);
  }
        printf("\n");
}
