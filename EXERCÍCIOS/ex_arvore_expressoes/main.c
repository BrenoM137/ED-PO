#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char stack[100];
int top = -1;

struct no
{
    int info;
    struct no* esq;
    struct no* dir;
};

typedef struct no No;

No* new_node(int x);
void destruct(No*root);
void remove_spaces(char* s);
void push(char x);
char pop();
int priority(char x);

//-----------------MAIN-------------------------
int main()
{
    int count = 0;
    char exp[100];
    char *e, x;

    fgets(exp, 100, stdin);
    remove_spaces(exp);
    printf("\n");
    e = exp;
    //printf("%s", e);

    while(*e != '\0')
    {
        if(isalnum(*e))
        {
            printf("%c",*e);
        }
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
            {
                printf("%c", x);
            }

        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }

    while(top != -1)
    {
        printf("%c",pop());
    }
    return 0;
}
//-----------------MAIN-------------------------

No* new_node(int x)
{
    No *p;
    p = malloc(sizeof(No));
    p->info = x;
    p->esq = NULL;
    p->dir = NULL;

    return p;
}

void destruct(No*root)
{
    if(root != NULL)
    {
        destruct(root->dir);
        destruct(root->esq);
        free(root);
    }
}

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

void remove_spaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}