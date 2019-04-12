#include <bits/stdc++.h>
using namespace std;

int main(){
	 double a,b,c;  
    do  
    {  
        scanf("%lf %lf",&a,&b);  
    }  
    while(a<=0||b<=0);  
  
    c = (a * a) + (b * b);  
    printf("%lf",sqrt(c));  
  
}
