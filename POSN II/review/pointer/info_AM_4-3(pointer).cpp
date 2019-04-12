#include <bits/stdc++.h>

using namespace std;

void swap_int(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void swap_char(char *a,char *b){
    char t = *a;
    *a = *b;
    *b = t;
}
void sort_int(int len,int *a){
    int ck=1;
    while(ck){
        ck=0;
        for(int i =1;i<len;i++){
            if(*(a+i)<*(a+i-1)) {
                swap_int(a+i,a+i-1);
                ck++;
            }
        }
    }
}
void back_cout(char *a,int len){
    for(len--;len>=0;len--){
        cout<<*(a+len);
    }
}
void back_ref(char *a,int len){
    int i;len--;
    for(i = len;i>=len/2;i--){
        swap_char((a+i),(a+(len-i)));
    }
}

int main()
{
  int i,a[100];
//set value
  //normal
  for(i=0;i<100;i++) a[i] =0;
  //better way : memset(pointer,value,amount)
  memset(a,1,100);
//copy value
  //better way : memcpy(destination,original,amonut)
  int b[50];
  memcpy(b,a,sizeof(int)*50);
//mem allocaion : #include <stdlib.h>
  int *c;
  c = (int *)malloc(sizeof(int));
  //must to do
  free(c);
  c = (int *)malloc(sizeof(int)*2);
//struct
    struct student {
      int id;
      char name[50];
      int age;
    };
    struct student t;
    t.id = 2659;
    strcpy(t.name,"Jirayuwat");
    t.age = 15;

    struct student s[5];
    for(i=0;i<5;i++){
      cout<<"Enter id:";
      cin>>s[i].id;
      cout<<"Enter name:";
      cin>>s[i].name;
    }
    cout<<"=========LIST NAME========="<<endl;
    for(i=0;i<5;i++){
      cout<<i+1<<" name:"<<s[i].name<<endl<<i+1<<" id:"<<s[i].id<<endl;
    }

}
