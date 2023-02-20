#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <iostream>
using namespace std;
//1. Составить программу, которая вставляет в список L новый элемент F за каждым вхождением элемента Е.
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

void Vivod(ND *ptr)
{
    cout<<"Содержимое списка: "<<endl;
    while (ptr!=NULL)
    {
        printf("\nval= %d",ptr->val);
        ptr=ptr->next;
    }
}

int main()
{

    int n, f, e;
    srand(time(0));
    ND *beg=NULL, *p;
    p=(ND *) malloc(sizeof(ND));
    p->val = 1+rand()%10;
    p->next = NULL;
    beg = p;
    cout<<"Сколько элементов будет в списке? "<<endl;
    cin>>n;
    Vvod(n, beg);
    Vivod(beg);
   cout<<endl;
    cout<<"Dobavit element F"<<endl;
    cin>>f;
     cout<<"Posle elementa E"<<endl;
    cin>>e;
    p=beg ;
    ND *temp;
    while (p->next!=NULL)
    {
        if (p->val==e)
        {
            temp=p;
            p= p->next;
            {
                temp->next = (ND *)malloc(sizeof(ND));
                temp = temp->next;
                temp->val = f;
                temp->next = p;
                if (p->val==e)
                {
                    temp=p;
                    p= p->next;
                    {
                        temp->next = (ND *)malloc(sizeof(ND));
                        temp = temp->next;
                        temp->val = f;
                        temp->next = p;
                    }
                }
            }
        }
        p=p->next;
    }
    if (p->next==NULL)
    {
        if (p->val==e)
        {
            {
                p->next = (ND *)malloc(sizeof(ND));
                p = p->next;
                p->val = f;
                p->next = NULL;
            }
        }
    }
    Vivod(beg);
    cout<<endl;
    return 0;
}
