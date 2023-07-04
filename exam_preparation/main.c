#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct an
{
    //30 символа +1 терминираща нула и +1 за новия ред от фгетс
    char owner_name[32];
    //7 символа +1 за терминираща + 1 за новия ред от фгетс
    char code[9];
    float price;
    //Единия символ за фгетс може и без него зависи от логиката, която искате да прложите
}Animal;

//Задача 1
Animal create_animal()
{
    //Създавате структурата и попълвате полетата и
    Animal p;
    printf("Enter name: ");
    fgets(p.owner_name,sizeof(p.owner_name),stdin);

    //Махаме новия ред от края на стринга, който фгетс е оставил
    //има и други варианти за тази "маневра", стига да ги знаете
    //Например:
    //p.owner_name[strlen(p.owner_name)-1]='\0';
    for(int i=0; i<32;++i)
    {
        if(p.owner_name[i]=='\n')
        {
            p.owner_name[i]='\0';
            break;
        }
    }

    printf("Enter code: ");
    //ТУК НИ ЛИПСВА ФУНКЦИЯ ЗА ПРОВЕРКА НА ФОРМТА
    //нАПИСАЛ СЪМ Я В ДРУИЯ ФАЙЛ ПОГЛЕДНЕТЕ ГО
    fgets(p.code,sizeof(p.code),stdin);
    //Същата логика като горната
    for(int i=0; i<8;++i)
    {
        if(p.code[i]=='\n')
        {
            p.code[i]='\0';
            break;
        }
    }
    //p.code[strlen(p.code)-1]='\0';
    printf("Enter price: ");
    scanf("%f", &p.price);

    //Отваряте нов фйл или същия, който сте създали за съхранение на животните
    //Вие трябва да прецените как разбирате условието
    //Ако изберете същия, имайте предвид, че в мейна трябва да го затворите
    //и тук във функцията да го отворите в режим апенд
    FILE * animals_file;
    if((animals_file=fopen("owner_taxes.txt", "w"))==NULL)
    {
        exit(1);
    }
    //Записваме желаното от задачата стрингче във файла и проверяваме дали е записано като хората
    if(fprintf(animals_file,"%s, %.2f\n",p.owner_name, p.price)<0)
    {
        printf("Error writing!");
        fclose(animals_file);
        exit(1);
    }
    //Затваряме файла
    fclose(animals_file);
    //Връщаме новосъздадената структура
    return p;
}

//Задача 2
void animal_over_price(Animal * animals_array, int arrLen, float price)
{
    //Флагът го използваме за да сме сигурни, че сме намерили/не сме каквото се иска.
    int flag = 0;
    //Обикаляме през дадения ни масив и правим нужната ни проверка, ако условието отговаря принтим
    for(int i=0;i<arrLen;++i)
    {
        if(animals_array[i].price==price)
        {
            printf("%s - %s", animals_array[i].owner_name, animals_array[i].code);
            flag =1;
        }
    }
    //Използваме флага за да прверим дали е намерен такъв запис
    if(flag==0)
    {
        printf("No info!");
    }
}

//Задача 3
void read_from_binary_animal(float price)
{
    //Отваряме бинарния файл за четене
    FILE * bin_file;
    if((bin_file=fopen("animalsBin.bin", "rb"))==NULL)
    {
        exit(1);
    }
    //Създаваме буферна структура, която ще използваме за да
    //пълним информацията от файла
    Animal bin_animal;
    //Четем файла докато има какво да се чете и принтираме
    while(fread(&bin_animal,sizeof(Animal),1,bin_file)==1)
    {
        if(bin_animal.price>=price)
        {
            printf("Bin Owner Name: %s\n", bin_animal.owner_name);
            printf("Bin Code: %s\n", bin_animal.code);
            printf("Bin Price: %.2f\n", bin_animal.price);
        }
    }
    fclose(bin_file);
}


int main()
{
    //Създаваме масива от зад 1
    Animal * animal_array=(Animal*)malloc(2*sizeof(Animal));
    if(animal_array==NULL)
    {
        exit(1);
    }
    //Създаваме файлът от зад 1
    FILE * animals_file;
    if((animals_file=fopen("aniamlsText.txt", "w"))==NULL)
    {
        exit(1);
    }
    //fclose(animals_file);

    //Създаваме две животни и ги пълнив в мсива
    animal_array[0]=create_animal();
    //Използваме флъш за да изчистим буфера на конзолата,
    //сканф оставя спейсове нови редове и тн
    fflush(stdin);
    animal_array[1]=create_animal();
    fclose(animals_file);

    //Отваряме бинарен файл за запис идеята е просто да ви покажа че работи не се иска от вас
    //Поне в тази задача
    if((animals_file=fopen("animalsBin.bin", "wb"))==NULL)
    {
        exit(1);
    }
    //Попълваме го
    fwrite(&animal_array[0],sizeof(Animal),1,animals_file);
    fwrite(&animal_array[1],sizeof(Animal),1,animals_file);
    fclose(animals_file);
    //Викаме последната функция
    read_from_binary_animal(10);

    //Как би изглеждал един реалок показвам го по ваше желание
    //Пазим старата референция случайно ако реалко върне нълл;
    Animal * old_ptr = animal_array;
    //Променяме големината
    animal_array = (Animal*)realloc(animal_array,4*sizeof(Animal));
    //Проверка за успешно променена големина
    if(animal_array==NULL)
    {
        animal_array=old_ptr;
    }
    free(animal_array);

    return 0;
}
