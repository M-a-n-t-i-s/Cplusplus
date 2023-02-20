#include <stdio.h>
#include <windows.h>
#include <time.h>
//—формировать список целых чисел и удалить из него все четные.
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
        ptr->val = 1 + rand()%10;
        ptr->next = NULL;
    }
}

void printlist(ND *ptr)
{
    printf("\n—одержимое списка: ");
    while (ptr!=NULL)
    {
        printf("\nval=%d",ptr->val);
        ptr=ptr->next;
    }
}

int main()
{
    system("chcp 1251 > nul");
    int n;
    srand(time(0));
    ND *beg=NULL, *p;
    p=(ND *) malloc(sizeof(ND));
    p->val = 1+ rand()%6;
    p->next = NULL;
    beg = p;
    printf("—колько элементов будет в списке? ");
    scanf("%d", &n);
    Vvod(n, beg);
    printlist(beg);
    printf("\n");
    p=beg;
    ND *temp;
    while (beg->val % 2 == 0)
    {
        p = beg;
        beg = beg->next;
        free(p);
    }
    p=beg;
    while (p->next != NULL )
    {
        temp=p;
        p=p->next;
        if (p->val % 2 == 0)
        {
            temp->next = p->next;
            free(p);
            p=temp;
        }
    }
    printlist(beg);
    printf("\n");
    return 0;
}
