#include <stdio.h>
#include <stdlib.h>

struct Members{
    char ownerName[30];
    char chipNum[10];
    float price;
};

void printMembersInTextFile(){
    struct Members m1;
    char firstName[30];
    char lastName[30];

    scanf("%s",&firstName);
    scanf("%s",&lastName);

    strcat(m1.ownerName,firstName);
    strcat(m1.ownerName," ");
    strcat(m1.ownerName,lastName);

    scanf("%s",&m1.chipNum);
    scanf("%f",&m1.price);

    struct Members member[3];
    member[0]= m1;

    FILE *fp;

    fp=fopen("animalText.txt","w");
    if(fp==NULL){
        printf("ERROR!");
        exit(1);
    }

    fprintf(fp,"%s,%.2f",member[0].ownerName,member[0].price);

    fclose(fp);

}

int main(){
    printMembersInTextFile();

    return 0;
}


