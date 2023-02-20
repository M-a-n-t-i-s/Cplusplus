#include <stdio.h>
#include <windows.h>
#include <time.h>


typedef struct nd
{
    string val;
    struct nd * next;
} ND;

void Vvod(int t, ND *ptr)
{ string c;
    for (int i=1; i<t; i++)
    {
        ptr->next = (ND *)malloc(sizeof(ND));
        ptr=ptr->next;
        cout<<"Vvedite stroku"<<endl;
        getline (cin, c);
        ptr->val =c;
        ptr->next = NULL;
    }
}

void printlist(ND *ptr)
{ FILE *f = fopen("filn.txt", "wt+");
int a=0,b=7;


    printf("\nsoderzhimoe spiska: ");
    while (ptr!=NULL)
    {
        printf("\nval= %d",ptr->val);
        fseek(f,a,SEEK_SET);
        fprintf(f, "%s", ptr->val);
        fseek(f,b,SEEK_SET);
        fprintf(f, "%s", ptr->val);
        ptr=ptr->next;
        a++;
        b--;
    }


fclose(f) ;
}


void sr(ND *ptr)


int main()
{

    int n;
    srand(time(0));
    ND *beg=NULL, *end=NULL, *p;
    p=(ND *) malloc(sizeof(ND));
    p->val = 1+rand()%10;
    p->next = NULL;
    beg = p;
    printf(" Kolichestvo elementov 4 ");
    n=4;
    Vvod(n, beg);
    printlist(beg);
    printf("\n");
    sr(beg);
    printf("\n");
    return 0;
}
