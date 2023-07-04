#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct an
{
    char owner_name[32];
    char code[8];
    double price;
}Animal;

int check_code(char *code)
{
    if(code[0]<'A' || code[0]>'Z')
    {
        return 0;
    }
    for(int i=1;i<6;++i)
    {
        if(code[i]<'0' || code[i]>'9')
        {
            return 0;
        }
    }
    if(code[6]<'A' || code[6]>'Z')
    {
        return 0;
    }
    return 1;
}

Animal get_animal_from_user()
{
    Animal p;
    printf("Enter name: ");
    fgets(p.owner_name,sizeof(p.owner_name),stdin);
    p.owner_name[strlen(p.owner_name)-1]='\0';
    do
    {
        printf("Enter code: ");
        scanf("%s",p.code);
    }while(check_code(p.code)==0);
    printf("Enter price: ");
    scanf("%lf", &p.price);

    FILE * an_file;
    if((an_file=fopen("owner_taxes.txt","a"))==NULL)
    {
        exit(1);
    }

    if(fprintf(an_file,"%s, %.2lf\n",p.owner_name, p.price)<0)
    {
        printf("Error writing!");
        fclose(an_file);
        exit(1);
    }
    fclose(an_file);

    return p;
}

void price_check(Animal * animals, int arrLen, double price)
{
    int flag=0;
    for(int i=0;i<arrLen;++i)
    {
        if(animals[i].price==price)
        {
            printf("%s - %s",animals[i].owner_name,animals[i].code);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("Not found!");
    }
}

void bin_read_animal(double price)
{
    FILE * bin_file;
    if((bin_file=fopen("animalsBin.bin","rb"))==NULL)
    {
        exit(1);
    }
    Animal buff;
    while(fread(&buff, sizeof(Animal), 1, bin_file)==1)
    {
        if(buff.price>=price)
        {
            printf("Bin Owner Name: %s\n", buff.owner_name);
            printf("Bin Code: %s\n", buff.code);
            printf("Bin Price: %.2f\n", buff.price);
        }
    }
    fclose(bin_file);

}


int main()
{
    Animal* animals_array = (Animal*)malloc(sizeof(Animal));
    if(animals_array==NULL)
    {
        exit(10);
    }
    FILE* animals_file;
    if((animals_file=fopen("animalsText.txt","w"))==NULL)
    {
        exit(1);
    }
    animals_array[0]=get_animal_from_user();
    price_check(animals_array,1,10);
    bin_read_animal(10);

    fclose(animals_file);
    free(animals_array);
    return 0;
}
