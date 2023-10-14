//#include "t1.h"
//#include "t2.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define ARRAY_SIZE 18624//REDUCE BY 1 IN A SECOND  
#define STRING_SIZE 100


typedef struct IGN IGN;
struct IGN {
    char title[STRING_SIZE];//0
    char platform[STRING_SIZE];//1
    int score;//2 
    int year;//3

};


int partition(IGN *arr,int start,int end);

void quickSort2(IGN arr[],int p,int r); 

void quickSort(IGN arr[],int size) //sorts this array by popularity.....
{ 
  int r=size;
  int p = 0;
   quickSort2( arr ,p, r); 
   return;
}

int partition(IGN *arr,int start,int end){
if(start==end)return start;//case 1 TRIVIAL
int piv=arr[end].score;//find last value in array
int high=end;//will be definded.....
IGN* buf; 
buf= (IGN*)malloc(sizeof(IGN));//check his slides to solve!
int low=start-1;

for(;;){
  do{
    low++;
  }while(arr[low].score<piv);
  do{
    high--;
    if(start==high)break;
  }while(arr[high].score>piv);
if(low>high||low==high){
  *buf=arr[low];
  arr[low]=arr[end];//SWAP!!! but also change pivots position
  arr[end]=*buf;
  return low;
}
 *buf=arr[low];
    arr[low]=arr[high];//SWAP!!!
    arr[high]=*buf;
}
}


void quickSort2(IGN arr[],int p,int r)
{
  int q=0;
 if(p<r){
      q=partition(arr,p,r);
      quickSort2(arr,p,q-1);
      quickSort2(arr,q+1,r);

    }
  return;

}


///////////////////////////////////////////////////////////////////////////////////////////////

//TASK 4 STUFF//
///////////////////////////////////////////////////////////////////////////////////////////////////////

    IGN arr[ARRAY_SIZE];
    

 int next_field(FILE *pfile, char *buffer, int max_length,int count){
       char c;
       int bool =0;
       for( int i = 0 ; i<max_length;i++){
               c = fgetc(pfile);
               //TODO FIX THIS   

            // if(c=='"'&&bool==1){
            // //   buffer[i] = c;
            //     bool =0;//loop exited   FALSE OUT OF LOOP
            //    c = fgetc(pfile);
            // }
            if(c=='"'){
                c = fgetc(pfile);
                if(bool==0)bool =1;//loop entered TRUE IN LOOP
                else bool=0;
           }

            if (c== ','&&bool==0){
                //
                 c='\0';
                buffer[i]=c;
               // printf("COMMA");

                return 0;// wanted
            }

            if(c==EOF||c=='\n'){
                buffer[i]='\0';
                return 1;           
            }
          
           buffer[i] = c;
        }   
    }
void printStatsBottom(){
   int count =1;
   int score=0;
   int year=0;
   int i=ARRAY_SIZE;
while(count<11){
    
    score=arr[i].score;
    year=arr[i].year;
    printf("Number %d = :\n",count);
    printf("Title %s = \n",arr[i].title);
    printf("Platform %s = \n",arr[i].platform);
    printf("Score %d = \n",score);
    printf("Year %d = \n",year);
    printf("--------------------\n");
    i--;
        count++;

    
}
return;
}

int main(int argc, char *argv[]){
    FILE * pfile;
    // IGN arr[18626];
    int max_length=200;
    int pos=0;
    if(argc>1){
        pfile=fopen(argv[1],"r");
        
    }else{
        pfile=fopen("t4_ign.csv","r");
    }
     

    // int max_length= 200;
    char *buffer;
    buffer=malloc(max_length*sizeof(char));
    if(buffer==NULL){
        printf("Error with array here!");
    }

        // buffer=(char*)malloc(2000);
        //buffer[max_length];
    int finished=4;//arbiturary value != being used.
// printf("Enter Array Length\n");
//     scanf("%d",&max_length);
int record=0;
int count=0;
pos=0;
do{
        finished=next_field(pfile,buffer,max_length,count);//Clearing first line
        count++;
        if(4==count)pos=1;
    }while(pos==0);
    //buffer=NULL;
    pos=0;
    count=0;
do{
    
    if(count==0){
        finished=next_field(pfile,buffer,max_length,count);
        strcpy(arr[pos].title, buffer);
         printf("%s ,",buffer);
        count++;
    }
    if(count==1){
        finished=next_field(pfile,buffer,max_length,count);
         printf("%s ,",buffer);
        strcpy(arr[pos].platform, buffer);
        count++;
    }
    if(count==2){
        finished=next_field(pfile,buffer,max_length,count);
         printf("%s ,",buffer);
        arr[pos].score=atoi( buffer);
        count++;
    }
    if(count==3){
        finished=next_field(pfile,buffer,max_length,count);
         printf("%s \n",buffer);
         arr[pos].year=atoi( buffer);        count=0;
    }
    pos++;

}while( !feof(pfile));
 printf("all loaded\n");

quickSort(arr,ARRAY_SIZE);

 printStatsBottom();

 return 0;
}
