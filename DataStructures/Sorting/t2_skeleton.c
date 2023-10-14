#include <stdio.h> 
#include "t2.h"

int number_comparisons = 0;
int number_swaps = 0;

void selectionSort(int arr[], int size) 
{ 
  int buffer=0;
  int small =0;
  for(int i=0;i<size-1;i++){
    small=i;
    for(int j=i+1;j<size;j++){
    number_comparisons++;
      if(arr[j] < arr[i]){
        small = j;
        buffer =arr[i];
        arr[i] = arr[small];
        arr[small] = buffer;
        //SWAP
        number_swaps++;
      }
      
    }

  }
  //TODO
  return;
} 

void insertionSort(int arr[], int size) 
{ 
  //TODO
for(int i=0; i<size-1;i++){
  for(int j=i+1;j>0;j--){
    number_comparisons++;
   int buf= arr[j];
    if(arr[j-1]>arr[j]){
    // int buf=arr[j];
    arr[j]=arr[j-1];//SWAP
    arr[j-1]=buf;
    number_swaps++;
  }
    else {
      //arr[j-1]=buf;
      break;
    }
  }

}
return; 
}

void quickSort2(int arr[],int p,int r);

int partition(int *arr,int start,int end);



void quickSort(int arr[],int size) //hhh
{ 
  int r=size;
  int p = 0;
   quickSort2( arr ,p, r); 
   return;
}

int partition(int *arr,int start,int end){
if(start==end)return start;//case 1 TRIVIAL
int x=end;
int piv=arr[x];//find last value in array
int high=end;//will be definded.....
int buf =0;//check his slides to solve!
int low=start-1;

for(;;){
  do{
    low++;
    number_comparisons++;
  }while(arr[low]<piv);
  do{
    high--;
    number_comparisons++;
    if(start==high)break;
  }while(arr[high]>piv);
if(low>high||low==high){
  buf=arr[low];
  arr[low]=arr[end];//SWAP!!! but also change pivots position
  arr[end]=buf;
  number_swaps++;
  return low;
}
 buf=arr[low];
    arr[low]=arr[high];//SWAP!!!
    arr[high]=buf;
    number_swaps++;

}
}
  
//   while(arr[right]>arr[piv]){
//     right++;
//   }
//   if(arr[left]>piv&&arr[right]<arr[piv]){
//     arr[left]=buf;
//     arr[left]=arr[right];//SWAP!!!
//     arr[right]=buf;
//   }
//   if(left>right||left==right){
//   piv_pos=right;
//   arr[left]=buf;
//   arr[left]=arr[piv];//SWAP!!! but also change pivots position
//   arr[piv]=buf;
//   return piv_pos;
// }




void quickSort2(int arr[],int p,int r)
{
  int q=0;
 if(p<r){
      q=partition(arr,p,r);
      quickSort2(arr,p,q-1);
      quickSort2(arr,q+1,r);

    }
  return;
// gcc -Wall t1_skeleton.c t2_skeleton.c t3_test.c -o t3
}