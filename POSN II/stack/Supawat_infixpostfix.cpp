#include <iostream>
#include <stdlib.h>

using namespace std;

struct stack{
	char sign;
	struct stack *next;
};

struct stack *head = (struct stack *)malloc(sizeof(struct stack));

void push(char input){
	struct stack *ch = (struct stack *)malloc(sizeof(struct stack));
	ch->sign = input;
	ch->next = head->next;
	head->next = ch;
}


char pop(struct stack *head){
	char n = head->next->sign;
	head->next=head->next->next;
	free(head->next);
	return n;
}

int main(){
	string input;
	head->next = NULL ;
	//LET'S BEGIN
	cout << "INSERT EQUATION : ";
	cin >> input ;
	for(int i = 0;input[i]!='\0';i++){	
		if(input[i] == '+' || input[i] == '-'){
			cout << pop(head);
		}
		else if(input[i] == '*' || input[i] == '/'){
			
		}
		head = head->next;//NOT FINISHED
	}
	
	
}
