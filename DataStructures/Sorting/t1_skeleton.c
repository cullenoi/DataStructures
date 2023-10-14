#include "t1.h"
#include <stdio.h>
#include <stdlib.h>
void fill_ascending(int *array, int size)
{
for(int k=0;k<size;k++){
 *(array+k)=k;
}
return;
}
//Fills the array with descending numbers, starting from size-1
void fill_descending(int *array, int size)
{
for(int k=0;k<size;k++){
 *(array+k)=(size-k)-1;
}
 return;
}

//Fills the array with uniform numbers.
void fill_uniform(int *array, int size)
{
    int randNum=0;
for(int k=0;k<size;k++){
randNum=rand()%size;
 *(array+k)=randNum;
}
    int uniform=array[0];
    for(int i=0;i<size;i++){
        array[i]=uniform;
    }
    return;
}

//Fills the array with random numbers within 0 and size-1. Duplicates are allowed.
void fill_with_duplicates(int *array, int size)
{
    for(int i=0;i<size;i++){
        *(array+i)=(rand()%(size-1));
    }
    return;
}


//Fills the array with unique numbers between 0 and size-1 in a shuffled order. Duplicates are not allowed.
void fill_without_duplicates(int *array, int size)
{
  int buffer=0;
  fill_ascending(array,size);
   for(int i=0; i<size;i++){
    int num =(rand()%(size-1));//generate a number to randomly swap values with and do this for the whole array
    buffer = array[i];//!SWAP!
    array[i]=array[num];
    array[num]=buffer;
   }
 return;
            
}
void printArray(int* arr, int size){
  int i;
  for(i=0; i<size;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  return;
}
//gcc -Wall t1_skeleton.c t1_test_skeleton.c -o t1
