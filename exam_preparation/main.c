#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct an
{
    //30 ������� +1 ����������� ���� � +1 �� ����� ��� �� �����
    char owner_name[32];
    //7 ������� +1 �� ����������� + 1 �� ����� ��� �� �����
    char code[9];
    float price;
    //������ ������ �� ����� ���� � ��� ���� ������ �� ��������, ����� ������ �� ��������
}Animal;

//������ 1
Animal create_animal()
{
    //��������� ����������� � ��������� �������� �
    Animal p;
    printf("Enter name: ");
    fgets(p.owner_name,sizeof(p.owner_name),stdin);

    //������ ����� ��� �� ���� �� �������, ����� ����� � �������
    //��� � ����� �������� �� ���� "�������", ����� �� �� ������
    //��������:
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
    //��� �� ������ ������� �� �������� �� ������
    //������� ��� � � ����� ���� ���������� ��
    fgets(p.code,sizeof(p.code),stdin);
    //������ ������ ���� �������
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

    //�������� ��� ��� ��� �����, ����� ��� ������� �� ���������� �� ���������
    //��� ������ �� ��������� ��� ��������� ���������
    //��� �������� �����, ������ �������, �� � ����� ������ �� �� ���������
    //� ��� ��� ��������� �� �� �������� � ����� �����
    FILE * animals_file;
    if((animals_file=fopen("owner_taxes.txt", "w"))==NULL)
    {
        exit(1);
    }
    //��������� �������� �� �������� �������� ��� ����� � ����������� ���� � �������� ���� ������
    if(fprintf(animals_file,"%s, %.2f\n",p.owner_name, p.price)<0)
    {
        printf("Error writing!");
        fclose(animals_file);
        exit(1);
    }
    //��������� �����
    fclose(animals_file);
    //������� ��������������� ���������
    return p;
}

//������ 2
void animal_over_price(Animal * animals_array, int arrLen, float price)
{
    //������ �� ���������� �� �� ��� �������, �� ��� ��������/�� ��� ������� �� ����.
    int flag = 0;
    //��������� ���� ������� �� ����� � ������ ������� �� ��������, ��� ��������� �������� �������
    for(int i=0;i<arrLen;++i)
    {
        if(animals_array[i].price==price)
        {
            printf("%s - %s", animals_array[i].owner_name, animals_array[i].code);
            flag =1;
        }
    }
    //���������� ����� �� �� ������� ���� � ������� ����� �����
    if(flag==0)
    {
        printf("No info!");
    }
}

//������ 3
void read_from_binary_animal(float price)
{
    //�������� �������� ���� �� ������
    FILE * bin_file;
    if((bin_file=fopen("animalsBin.bin", "rb"))==NULL)
    {
        exit(1);
    }
    //��������� ������� ���������, ����� �� ���������� �� ��
    //������ ������������ �� �����
    Animal bin_animal;
    //����� ����� ������ ��� ����� �� �� ���� � ����������
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
    //��������� ������ �� ��� 1
    Animal * animal_array=(Animal*)malloc(2*sizeof(Animal));
    if(animal_array==NULL)
    {
        exit(1);
    }
    //��������� ������ �� ��� 1
    FILE * animals_file;
    if((animals_file=fopen("aniamlsText.txt", "w"))==NULL)
    {
        exit(1);
    }
    //fclose(animals_file);

    //��������� ��� ������� � �� ������ � �����
    animal_array[0]=create_animal();
    //���������� ���� �� �� �������� ������ �� ���������,
    //����� ������ �������� ���� ������ � ��
    fflush(stdin);
    animal_array[1]=create_animal();
    fclose(animals_file);

    //�������� ������� ���� �� ����� ������ � ������ �� �� ������ �� ������ �� �� ���� �� ���
    //���� � ���� ������
    if((animals_file=fopen("animalsBin.bin", "wb"))==NULL)
    {
        exit(1);
    }
    //��������� ��
    fwrite(&animal_array[0],sizeof(Animal),1,animals_file);
    fwrite(&animal_array[1],sizeof(Animal),1,animals_file);
    fclose(animals_file);
    //������ ���������� �������
    read_from_binary_animal(10);

    //��� �� ��������� ���� ������ �������� �� �� ���� �������
    //����� ������� ���������� �������� ��� ������ ����� ����;
    Animal * old_ptr = animal_array;
    //��������� ����������
    animal_array = (Animal*)realloc(animal_array,4*sizeof(Animal));
    //�������� �� ������� ��������� ��������
    if(animal_array==NULL)
    {
        animal_array=old_ptr;
    }
    free(animal_array);

    return 0;
}
