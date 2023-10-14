#include <stdio.h>
#include <stdlib.h>
// const int max_length=200;
    int next_field(FILE *pfile, char *buffer, int max_length,int *count,int *next_pokemon);
    int Length(FILE *pfile);
    //void arrayfiller(,)
typedef struct pokemon{
        int Num;//0
        char Name[50];//1
        char Type_1[50];//2
        char Type_2[50];//3
        float Total;//4
        float Hp;//5
        float Attack;//6
        float Defense;//7
        float Sp_At;//8
        float Sp_Def;//9
        float Speed;//10
        int Generation;//11
        char Legendary[7];//12
        char Pokedex_Entry[200];//13

    }pokemon;
int main(){
    int *countptr;
    int* next_pokemonptr;
    int max_length=200;
    FILE * pfile;
    pfile = fopen("pokemon.csv","r");
pokemon arr [649];
int count =0;
int next_pokemon=0;
countptr=&count;
next_pokemonptr=&next_pokemon;

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
do{
finished=next_field(pfile,buffer,max_length,countptr,next_pokemonptr);
// arr[next_pokemon].[]=buffer;
if(count==0){sscanf(buffer,"%d",&arr[next_pokemon].Num);}
if(count==1){strcpy(arr[next_pokemon].Name, buffer);}
if(count==2){sscanf(buffer,"%d",&arr[next_pokemon].Type_1);}
if(count==3){sscanf(buffer,"%d",&arr[next_pokemon].Type_2);}
if(count==4){sscanf(buffer,"%d",&arr[next_pokemon].Total);}
if(count==5){sscanf(buffer,"%d",&arr[next_pokemon].Hp);}
if(count==6){sscanf(buffer,"%d",&arr[next_pokemon].Attack);}
if(count==7){sscanf(buffer,"%d",&arr[next_pokemon].Defense);}
if(count==8){sscanf(buffer,"%d",&arr[next_pokemon].Sp_At);}//spa
if(count==9){sscanf(buffer,"%d",&arr[next_pokemon].Sp_Def);}//spd
if(count==10){sscanf(buffer,"%d",&arr[next_pokemon].Speed);}//speed
if(count==11){sscanf(buffer,"%d",&arr[next_pokemon].Generation);}
if(count==12){strcpy(arr[next_pokemon].Legendary, buffer);}
if(count==13){strcpy(arr[next_pokemon].Pokedex_Entry, buffer);}



}while( !feof(pfile));

 printf("\n\n");
}

   
    int next_field(FILE *pfile, char *buffer, int max_length,int *count,int *next_pokemon){
       char c;
       int bool =0;
       int n=0;
       int f=0;
       for( int i = 0 ; i<=max_length;i++){
               c = fgetc(pfile);
               //TODO FIX THIS   
            if(c=='\"'&&bool==1){
                bool =0;//loop exited   FALSE OUT OF LOOP
                c = fgetc(pfile);

            }
            if(c=='\"'){
                bool =1;//loop entered TRUE IN LOOP
                c = fgetc(pfile);

            }








            if (c== ','&&bool==0){
                //
                 c='\0';
                buffer[i]=c;
               // printf("COMMA");

                return 0;// wanted
            }

            if(c==EOF||c=="\n"){
                buffer[i]="\0";
                return 1;   
                n=0;
                *next_pokemon++;        
            }
          *count=n++;
           buffer[i] = c;
        }   
    }