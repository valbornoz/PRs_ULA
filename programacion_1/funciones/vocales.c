#include "stdio.h"

    char voc(char p[]){
              int j=0,h=0;

      for(j<20; p[j]!='\0'; j++){
             if((p[j]=='a')||(p[j]=='e')||(p[j]=='i')||(p[j]=='o')||(p[j]=='u')||(p[j]=='A')||(p[j]=='E')||(p[j]=='I')||(p[j]=='O')||(p[j]=='U'))
                      h++;
                  
          }
                   return h;
     }

    void main(){
           char p[20];
           int h;

                  printf("introduzca una palabra: \n");
                  scanf("%s",p);

      h=voc(p);

                printf("la palabra tiene %i vocales\n",h);
}
