#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
char lab[20][20],opc[20][20],opr[20][20];
}s;


int main(){
    FILE *f1,*f2;
    s s1;
    char ch[50];
    char c[300]="";
    char *token, *token1;
    //char tok[100][20];
    int n=0,i;//,m=0;
    f1=fopen("f1.txt","r");
    f2=fopen("f2.txt","w");
    do{
        fgets(ch,50,f1);

        token1 = strtok(ch,"\n");
        while( token1 != NULL )
        {
            //strcpy(tok[n]," ");
            //n+=1;
            printf("%s\n\n\n",token1);

            strcat(c,token1);
            strcat(c,"_");
            token1 = strtok(NULL, "\n");
        }

    }while(!feof(f1));
    printf("%s\n",c);
    printf("%d\n\n",strlen(c));

    token = strtok(c,"_");
    while( token != NULL )
    {
        //strcpy(tok[n]," ");
        //n+=1;
        strcpy(s1.lab[n],token);
        token = strtok(NULL, "_-");


        strcpy(s1.opc[n],token);
        token = strtok(NULL, "_-");

        strcpy(s1.opr[n],token);
        token = strtok(NULL, "_-");

        n=n+1;
    }
    for(i=0;i<n;i++){
        printf("%s %s %s\n",s1.lab[i],s1.opc[i],s1.opr[i]);
        fprintf(f2,"%s %s %s\n",s1.lab[i],s1.opc[i],s1.opr[i]);
    }
    printf("\nlabels\n");
    for(i=0;i<n;i++){
        printf("%s\n",s1.lab[i]);
    }

    printf("\n\n\nopcodes\n");
    for(i=0;i<n;i++){
        printf("%s\n",s1.opc[i]);
    }

    printf("\n\n\noperand\n");
    for(i=0;i<n;i++){
        printf("%s\n",s1.opr[i]);
    }
    fclose(f1);
    return 0;
}
