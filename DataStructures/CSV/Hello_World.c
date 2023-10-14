#include <stdio.h> 
int main(){
int age;
char name[]={'1','2','5','\0','f'};
    sscanf(name,"%d",&age);
    printf("AGE = %d\n",age);

    
}