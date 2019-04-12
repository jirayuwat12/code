#include <iostream>

void swap_pointer(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
void swap_ref(int &a,int &b){
	int t =a;
	a = b;
	b = t;
}

int main(){
	int a=10;
	int b=20;
	swap_ref(a,b);
	std::cout<<"a:"<<a<<std::endl<<"b:"<<b;
}
