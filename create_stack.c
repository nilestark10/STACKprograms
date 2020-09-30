#include<stdio.h>
#include<stdlib.h>

# define Max 5

typedef struct
{
    int data[Max];
    int top1;
    int top2;
}STACK;

int push(STACK *s,int v,int p)
{   
    int count=0;
    if(p==0)
    {
      if (s->top1 == s->top2 - 1)
        {
            printf("OverFlow");
            return 1;
        }
        else
        {
           s->top1++;
           s->data[s->top1]=v;
           count++;
           return 0;
        }
        
    }

    if(p==1)
    {
        
         if (s->top2 == s->top1 + 1)
        {
            printf("OverFlow");
            return 1;
        }
        else
        {
           s->top2--;
           s->data[s->top2]=v;
           count++;
           return 0;
        }
    }
}


int pop(STACK *s,int *k,int p)
{   
    if(p==0)
    {
        if(s->top1==-1)
        {
            printf("UnderFlow");
            return 1;
        }
        else
        {
           s->data[s->top1]=0;
           s->top1--;
           return 0;
        }

    }
    if(p==1)
    {
         if(s->top2==Max)
        {
            printf("UnderFlow");
            return 1;
        }
        else
        {
           s->data[s->top2]=0;
           s->top2++;
           return 0;
        }
        
    }   

}

int main()
{
    STACK s1;
    s1.top1=-1;
    s1.top2=Max;
    int m;
    for(int i=0;i<Max;i++)
        s1.data[i]=0;

    push(&s1,10,0);
    push(&s1,5,1);
    push(&s1,2,0);
    push(&s1,3,1);
    push(&s1,4,0);

    for(int i=0;i<Max;i++)
    {
        printf("%d ",s1.data[i]);
    }

    pop(&s1,&m,1);
    pop(&s1,&m,1);
    pop(&s1,&m,0);
    pop(&s1,&m,0);
    pop(&s1,&m,0);

    printf("\n");

    for(int i = 0; i < Max; i++)
    {
        printf("%d  ", s1.data[i]);
    }

    return 0;
}
