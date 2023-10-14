#include <stdio.h>
#include <stdlib.h>

    int next_field(FILE *pfile, char *buffer, int max_length);
        int Length(FILE *pfile);

int main(int argc, char *argv[]){
    FILE * pfile;
    if(argc>1){
        pfile=fopen(argv[1],"r");
        
    }else{
        pfile=fopen("EX.csv","r");
    }
     

    int max_length= 200;
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

do{
finished=next_field(pfile,buffer,max_length);
 if(record==1){
 printf("%s \n",buffer);
 }
if(finished==0){
printf(" \n");
 }
 if(finished==1){
    printf("\n\n");
    record =1;
 }
}while( !feof(pfile));

 return 0;
}

   
    int next_field(FILE *pfile, char *buffer, int max_length){
       char c;
       int bool =0;
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

            if(c==EOF||c=='\n'){
                buffer[i]='\0';
                return 1;           
            }
          
           buffer[i] = c;
        }   
    }