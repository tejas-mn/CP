#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
for (i=0;i<strlen(str);i++)
{
    if (str[i]!="*")
    {
        push(str[i]);
    }
    else{
        pop();
    }
}
*/

///////////////////
#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5
int top,s[10],item;
void push()
{
if(top==STACK_SIZE-1)
{
printf("stack full\n");
return;
}
top=top+1;
s[top]=item;
}
int pop()
{
int item_deleted;
if(top==-1) return 0;
item_deleted=s[top--];
return item_deleted;
}
void display()
{
int i;
if(top==-1)
{
printf("stack is empty\n");
return;
}
printf("contents of the stack\n");
for(i=top;i>=0;i--)
{
printf("%d\n",s[i]);
}
}

int main()
{
int choice;
top=-1;
char str[10];
str[10]="EAS*Y*QUE";
for (int k=0;k<strlen(str);k++)
{
    printf("%c",str[k]);
if (str[k]!="*"){
    item=str[k];
    push();
}
else
{
    item=pop();
    if(item==-1)
printf("stack is empty\n");
else
printf("item deleted =%d\n",item);
}
}
}



