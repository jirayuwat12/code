#include <iostream>
#include <conio.h>
using namespace std;

typedef struct stack{
  char oper;
  stack *next;
}stack;

bool empty(stack *e){
  if(e->next == NULL) return true;
  else return false;
}

char pop(stack *s){
  char rt;
  stack *tmp=s->next;
  s->next = s->next->next;
  rt = tmp->oper;
  free(tmp);
  return rt;
}

bool push(stack *s,char inp){
  stack *tmp = (stack *)malloc(sizeof(stack));
  tmp->oper = inp;
  tmp->next = s->next;
  s->next = tmp;
  return true;
}

char top(stack *s){
  return s->next->oper;
}
void showstack(stack *s){
    while (!empty(s)) cout<<pop(s);
}
int main(){
  stack *bftop = (stack *)malloc(sizeof(stack));
  bftop->next = NULL;
  cout<<"Equation :";
  char inp[10];
  int i=0;
  cin>>inp;
  cout<<"Postfix  :";
  while (inp[i]!='\0') {
    char bfoper = ' ';
    if(!empty(bftop)) bfoper = top(bftop);
    if((inp[i] == '+' || inp[i] =='-' || inp[i]=='*' ||inp[i]=='/')){
      if((bfoper != ' ')&&(inp[i] =='+' || inp[i]=='-')){
        cout<<pop(bftop);
      }
      push(bftop,inp[i]);
    }
    else{
      cout<<inp[i];
    }
    i++;
  }
  showstack(bftop);
}
