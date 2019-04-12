#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//LIST OF NAME (TEST CASE)
/*
Jarunee 
Leo 
Folk 
Tor 
Nabin 
Oat 
Zienan 
Pea 
Ern 
Wish 
Tata 
Ake 
Pete 
Kumpan
Yuan
Eye
Mine
Milla
Tian
Pakwhan 
Firn 
*/

using namespace std;

struct node{//structure NODE**
	char name[10];
	struct node *next;
};

void insert(struct node *head,char name[]);

void append(struct node *head,char name[]);

void printlist(struct node *head);

void del_name(struct node *head,char jaru[]);

void sort(struct node *head);

void swapname(struct node *a,struct node *b);

void insertafter(struct node *prev,char name[]);

void del(struct node *head,int num);

int main(){ //__________________________________________________________________________________________________//HERE MAIN!!
	char named[10];
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->next = NULL;
	cout << "ASK : INPUT NAME(S) APPEND [END input - stop]" <<endl;
	while(1){//APPEND PERSON
		cin >> named;
		if(strcmp(named,"stop")==0){
			break;
		}
		append(head,named);
	} 
	strcpy(named,"Jarunee");//ADD A PERSON NAMED JARUNEE
	append(head,named);
	cout << "------------LIST APPEND------------" <<endl <<"-------[JARUNEE WAS ADDED]---------" <<endl;
	printlist(head);//PRINT
	cout << "-----------------------------------" <<endl;
	cout << "- press [ENTER] to continue -" <<endl;
	getch();
	cout << "ASK : INPUT NAME(S) INSERT [END input - stop]" <<endl;
	while(1){//INSERT PERSON
		cin >> named;
		if(strcmp(named,"stop")==0){
			break;
		}
		insert(head,named);
	}
	cout << "-------------LIST INSERT-----------" <<endl;
	printlist(head);//PRINT
	cout << "-----------------------------------" <<endl;
	cout << "- press [ENTER] to continue -" <<endl;
	getch();
	char remove[10];
	cout << "ASK : INSERT NAME THAT YOU GONNA REMOVE? : ";
	cin >> remove;//INPUT ? th
	del_name(head,remove);//REMOVE ? th PERSON
	cout << "---LIST THAT REMOVED OF SOMEBODY---" <<endl;
	printlist(head);//PRINT
	cout << "-----------------------------------" <<endl;
	cout << "- press [ENTER] to continue -" <<endl;
	getch();
	del(head,1);//REMOVE FIRST PERSON
	del(head,INT_MAX);//REMOVE LAST PERSON
	cout << "LIST THAT REMOVED OF FIRST AND LAST" <<endl;
	printlist(head);//PRINT
	cout << "-----------------------------------" <<endl;
	cout << "- press [ENTER] to continue -" <<endl;
	getch();
	sort(head);//SORT PERSON
	cout << "---------LIST THAT SORTED----------" <<endl;
	printlist(head);//PRINT
	cout << "-----------------------------------" <<endl;
	cout << "- press [ENTER] to continue -" <<endl;
	getch();
	//---INSERT AFTER
	cout << "ASK : INPUT NAME(S) INSERTAFTER  [END input - stop]" <<endl;
	while(1){//INSERT PERSON
		cin >> named;
		if(strcmp(named,"stop")==0){
			break;
		}
		insertafter(head,named);
	}
	cout << "--------LIST INSERTAFTER-----------" <<endl;
	printlist(head);//PRINT
	cout << "-----------------------------------" <<endl;
	cout << "- press [ENTER] to end this process -" <<endl;
	getch();
	//---
}//_______________________________________________________________________________________________________________//MAIN AREA!!

void insert(struct node *head,char name[]){ //INSERT FROM TOP
	struct node *link = (struct node*)malloc(sizeof(struct node));
	strcpy(link->name,name);
	link->next = head->next;
	head->next = link;
}

void append(struct node *head,char name[]){ //APPEND = INSERT FROM BOTTOM
	struct node *box = (struct node *)malloc(sizeof(struct node));
	box->next = NULL;
	strcpy(box->name,name);
	while(head->next != NULL){
		head = head->next;
	}
	head->next = box;
}

void printlist(struct node *head){//PRINT LIST
	struct node *run;
	run = head->next;
	int i=1;
	while(run->next != NULL){
		cout << i << " " << run->name <<endl;
		run = run->next;
		i++;//COUNT
	}
	cout << i << " " << run->name <<endl;
}

void del_name(struct node *head,char jaru[]){//REMOVE BY INPUT name
	struct node *pre = head;
	head = head->next;
	while (strcmp(head->name,jaru)!=0 && head->next != NULL){
		pre = head;
		head = head->next;
	}
	pre->next=head->next;
	free(head);
}

void swapname(struct node *a,struct node *b){//THIS FN WILL USE IN FN-SORT
  char tmp[20];
  strcpy(tmp,a->name);
  strcpy(a->name,b->name);
  strcpy(b->name,tmp);
}

void sort(struct node *head){//SORT NAME A-Z
	struct node *temp ;
	struct node *pre ;
	int c = 1;
	while(c == 1){
	c = 0;
		for(temp = head->next->next,pre=head->next;temp != NULL;temp = temp ->next,pre = pre->next){
    		if(strcmp(temp->name,pre->name) <0) {
    			swapname(pre,temp);
    			c = 1;
    		}
		}
	}
}

void insertafter(struct node *head,char name[]){
	struct node *temp ;
	struct node *pre ;
	for(temp = head->next->next,pre=head->next;temp != NULL;temp = temp ->next,pre = pre->next){
   		if(strcmp(pre->name,name) < 0 && strcmp(temp->name,name) > 0) {
			struct node *nnew = (struct node *)malloc(sizeof(struct node));
			strcpy(nnew->name,name);
			nnew->next = pre->next;
			pre->next = nnew;
    	}
	}
}

void del(struct node *head,int num){//REMOVE BY INPUT INT
	struct node *pre = head;
	head = head->next;
	int i=0;
	while (i < num-1 && head->next != NULL){
		pre = head;
		head = head->next;
		i++;
	}
	pre->next=head->next;
	free(head);
}

//_________________________________________________________________________END THANK YOU_______** 
