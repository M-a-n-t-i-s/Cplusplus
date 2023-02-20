#include <stdio.h>
#include <windows.h>
#include <time.h>
//Написать функцию, которая вычисляет среднее арифметическое элементов непустого списка.
typedef struct nd
{
    int val;
    struct nd * next;
} ND;

void Vvod(int t, ND *ptr)
{
    for (int i=1; i<t; i++)
    {
        ptr->next = (ND *)malloc(sizeof(ND));
        ptr=ptr->next;
        ptr->val = 1+rand()%10;
        ptr->next = NULL;
    }
}

void printlist(ND *ptr)
{
    printf("\nСодержимое списка: ");
    while (ptr!=NULL)
    {
        printf("\nval= %d",ptr->val);
        ptr=ptr->next;
    }
}

void perev(ND *ptr)
{
    if (ptr!=NULL)
    {
        perev(ptr->next);
        printf("\nval= %d",ptr->val);
    }
}

int main()
{
    system("chcp 1251 > nul");
    int n;
    srand(time(0));
    ND *beg=NULL, *p;
    p=(ND *) malloc(sizeof(ND));
    p->val = 1+rand()%10;
    p->next = NULL;
    beg = p;
    printf("Сколько элементов будет в списке? ");
    scanf("%d", &n);
    Vvod(n, beg);
    printlist(beg);
    printf("\n");
    printf("\nПеревернутый список: ");
    perev(beg);
    return 0;
}
