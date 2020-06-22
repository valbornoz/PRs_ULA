#include "stdio.h"

main(){
    int edad;

        printf("introdusca la edad: ");
        scanf("%i",&edad);

    if((edad>=0)&&((edad<=2)){
    printf("la edad correspode a un bebe \n");
     }
    else
    if((edad>=3)&&((edad<=12)){
    printf("la edad correspode a un niño \n");
     }
    else
    if((edad>=13)&&((edad<=17)){
    printf("la edad correspode a un adolescente \n");
     }
    else
    if((edad>=18)&&((edad<=64)){
    printf("la edad correspode a un adulto \n");
     }
    else
    if((edad>=65)&&((edad<=105)){
    printf("la edad correspode a un anciano \n");
     }
    else
    printf("edad fuera de rango \n");
   }
   return 0;
}

