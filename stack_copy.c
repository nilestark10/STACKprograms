#include<stdio.h>
#include<stdlib.h>

# define Max 5

typedef struct
{
    int data[Max];
    int top;
}STACK;

int push(STACK *s,int v)
{
    if(s->top==Max-1)
    {
        printf("OF");
        return 1;
    }
    else
    {
        s->top++;
        s->data[s->top]=v;
        return 0;
    }
}

int pop(STACK *s,int *k)
{
    if(s->top==-1)
    {
        printf("UF");
        return 1;
    }
    else
    {
        *k=s->data[s->top];
        s->top--;
        return 0;
    }

}

void copy(STACK *s1,STACK *s2)
{
    int m;
    STACK s;
    s.top=-1;
    for(int i=0;i<Max;i++)
       s.data[i]=0;
    while(s1->top!=-1)
    {
        pop(s1,&m);
        push(&s,m);
    }
    while(s.top!=-1)
    {
        pop(&s,&m);
        push(s2,m);
    }
    
}



int main()
{
    STACK s1;
    STACK s2;
    s1.top=-1;
    s2.top=-1;
    int m;

    for(int i=0;i<Max;i++)
       s1.data[i]=0;

    for(int i=0;i<Max;i++)
       s2.data[i]=0;
    push(&s1,10);
    push(&s1,5);
    push(&s1,6);
    push(&s1,7);
    push(&s1,8);

    for(int i=0;i<Max;i++)
    {
        printf("%d ",s1.data[i]);
    }
    printf("\n");
    copy(&s1,&s2);
    for(int i=0;i<Max;i++)
    {
        printf("%d ",s2.data[i]);
    }
    printf("\n");
    
    return 0;
}

