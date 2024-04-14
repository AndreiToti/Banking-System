int login(char *nume,char *prenume)
{
    FILE *p;
    char s[40];
    strcpy(s,nume);
    strcat(s," ");
    strcat(s,prenume);
    strcat(s,".txt");
    int ok=0;
    p=fopen(s,"r");
    char string[100];
    while(fgets(string,sizeof(string),p)!=NULL)
    {
        ok=1;
    }
    fclose(p);
    if(ok==1)
        return 1;
    else return 0;
}

void stergere_cont(char *nume,char *prenume)
{

    printf("Introduceti ibanul contului:");
    char *iban=(char*)malloc(33*sizeof(char));
    scanf("%s",iban);

    FILE *f;
    FILE *g;
    char s[40];
    strcpy(s,nume);
    strcat(s," ");
    strcat(s,prenume);
    strcat(s,".txt");

    char *string=(char*)malloc(33*sizeof(char));

    g= fopen("aditional.txt","w");
    f=fopen(s,"r");
    if (f == NULL) {
        printf("Fisierul nu poate fi accesat.");
    }
    else{
        int cont=-1;

        while(fgets(string,33*sizeof(char),f)!=NULL)
        {
            if(strstr(string,iban))
            {
                cont=2;
            }
            if(cont<0)
            {

                fprintf(g, "%s",string);

            }
            else cont--;

        }
    }
    fclose(g);
    fclose(f);

    FILE *y;
    y= fopen(s,"w");
    FILE *q;
    q = fopen("aditional.txt","r");

    while(fgets(string,33*sizeof(char),q)!=NULL)
    {
        fprintf(y,"%s",string);
    }
    free(string);
    fclose(q);
    fclose(y);

}
