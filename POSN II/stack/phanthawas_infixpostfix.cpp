#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
struct stack
{
  char op;
  struct stack *next;
};
char top(struct stack *top)
{
  struct stack *pnew = (struct stack *)malloc(sizeof(struct stack));
  pnew = top->next;
  return pnew->op;
}
void push(struct stack *top,char input)
{
  struct stack *pnew = (struct stack *)malloc(sizeof(struct stack));
  pnew->op = input;
  pnew->next = top->next;
  top->next = pnew;
}
void pop(struct stack *top)
{
  struct stack *pre = top;
  top = top->next;
  pre->next = top->next;
  free(top);
}
int value(char c)
{
    if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

void itop(string s)
{
    struct stack *eq = (struct stack *)malloc(sizeof(struct stack));
    push(eq,'!');
    int l = s.length();
    char n;
    string ns;
    for(int i = 0; i < l; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
        {
        ns += s[i];
        }
        else
        {
          n=top(eq);
            while(n != '!' && value(s[i]) <= value(top(eq)))
            {
              n=top(eq);
                char c = top(eq);
                pop(eq);
                ns += c;
            }
            push(eq,s[i]);
        }
    }
    while(top(eq) != '!')
    {
        char c = top(eq);
        pop(eq);
        ns += c;
    }
    cout << ns << endl;
}
int main()
{
    string eq;
    cout << "Insert equation : ";
    cin >> eq;
    itop(eq);
    return 0;
}
