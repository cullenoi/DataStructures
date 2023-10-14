#include<stdio.h>
#include<stdlib.h>
#include <string.h> //for strcpy and strcmp
#include <ctype.h>  //for isalnum

// NB: this skeleton is here to help you - ignore anything that does not help you
// There are a lot of others (and better!) ways of doing this

// note this sekeleton uses a global variable. It therefore will only work with 
// one hashtable, of the size set. In general global variables should be avoided
// as their global scope makes it very challenging to see where they are updated 
// (as it can be anywhere!), and don't work well when several threads/programs
// update them at the same time (concurency), amongst others problems.
// Having said that, they can make coding a bit easier, so that's why we are using 
// one here. If you can, try using a hashTable as a variable, passing it as a 
// parameter to functions!



#define MAX_STRING_SIZE 20 //max length of a string
#define ARRAY_SIZE 59  //best be prime

typedef struct Element Element;
struct Element{
    char* data;
	int count;
    int collision;
};

Element* hashTable[ARRAY_SIZE]={NULL};

 int hash_function(char* s){
    int hash = 0;
	const int  m = 1e9 + 7;
	long R_pow = 1;
	int weight=1102;
	int weight2=3101;

    int R=31;
    while(*s){
		if(s=='o'||s=='O')*s=*s*weight;
		if(s=='M'||s=='m')*s=*s*weight2;

        hash = (hash + (*s*R_pow));
        s++;
	R_pow=(R_pow*R)%m;

    }
    return (abs(hash % ARRAY_SIZE));
 }
// int hash_function(char* s){
//     int hash = 0;
//     int R=29;
//     while(*s){
//         hash = (R*hash + *s);
//         s++;
//     }
//     return (abs(hash % ARRAY_SIZE));
// }
// int hash_function(char* s){
//     const int p = 29, m = 1e2 + 7;
//     int hash = 0;
//     long p_pow = 1;
//     for(int i = 0; i < MAX_STRING_SIZE; i++) {
//         hash = (hash + (s[i] - 'a' + 1) * p_pow) % m;
//         p_pow = (p_pow * p) % m;
// 		    }
//     return abs(hash%ARRAY_SIZE);
// }

Element* createNewElement(char* name){
    // TODO
	Element* newElement=(Element*)malloc(sizeof(Element));//(Element) before malloc stops malloc returing void* instead returns 
	//a non void address
	newElement->data=(char*)malloc(sizeof(char)*MAX_STRING_SIZE);
	strcpy(newElement->data,name);
	//printf("DEBUG CHECK 1 GOOD!\n");
    // you might want to use the function strcpy from the string package here!
    return newElement;
}


// returns the element with name name or NULL if the element is not present
Element* search (char* name){
//Element* newperson_ptr = createNewElement(name);

    //TODO Basic version wont iterate down the array yet just to test idea..
	int key = hash_function(name);
	int start=key;

if(hashTable[key]==NULL){
//	printf("nothing here yet stored here man\n");
	//nothing has yet to be stored here...
	return NULL;
}
	while(hashTable[key]!=NULL){//if not name and not null we know its now data...
	if(strcmp(hashTable[key]->data,name)==0){
//		printf("Hey Bai we're yer man!\n");
		return hashTable[key];
		}
        // if(i>ARRAY_SIZE){
        //     printf("no space\n");
        //     return NULL;
        // }
        key++;

    if(key==ARRAY_SIZE)key=0;
	// if(key==start)return NULL;
    // key++;
	// if(key==start)break;
	
		
           
	// 		if(key==start){
	// //		printf("Not anywhere to be seen!\n") ;
	// 		return NULL;
	// 		}
	 }
    if( hashTable[key]==NULL) return NULL; //if the next iteration of i = null not stored there/....

	}	

// assuming that no element of key name is in the list (use search first!), add element at the correct place in the list
// NB: it would be more efficient for search to return the index where it should be stored directly, but aiming for simplicity here!
void insert(char* name){
   // TODO
//    Element newperson;
//    newperson.ElementAddress=createNewElement(name);
//    newperson=*(newperson.ElementAddress);
Element* newperson_ptr = createNewElement(name);
//    newperson.ElementAddress=NULL;
int col=0;
int key=0;
int start=0;

   	if(search(newperson_ptr->data)!=NULL){
	//	printf("name already stored ...\n");
	return;//TODO ADD OR INCREMENT HERE...
	}
	
//	printf("Sticking it in Baii\n");
	key= hash_function(name);
	start=key;
	if(hashTable[key]==NULL){
	hashTable[key]=newperson_ptr;
//        printf("key=%d\n",key);
	//printf("1 Name Stored==%s\n",newperson_ptr->data);
	//SHOULD EQUAL NEWELEMENT (GENERATE ONE HERTE)
    return;
	}
	while(hashTable[key]!=NULL){
        key++;
        col++;
        newperson_ptr->collision=col;
      if(key==ARRAY_SIZE)key=0;
	  if(key==start)return;
	}	
		hashTable[key]=newperson_ptr;
		// printf("2 Name Stored==%s\n",newperson_ptr->data);//keep iterating down the array till it is found.
    return;
	}

void addOrIncrement(char* name){//CHANGing this to try to include an element so count can be brought.
    //TODO
    int i=0;
    int key=0;

	 key=hash_function(name);
	int start=key;
	int x=0;
	//HOW MANY OCCUPANCIES WILL ALSO NEED TO BE MENTIODED BUT DIFFERENT FUNCTION.
	if(search(name)!=NULL){
    while(strcmp(hashTable[key]->data,name)!=0){
				key++;
		if(key==ARRAY_SIZE)key=0;
		// if(key==start)break;
	}
        x= hashTable[key]->count;
		x++;
		hashTable[key]->count=x;
  		//printf("added+1\n");

		return;
	}
	else//not in the array
	insert(name);
        x++;
		hashTable[key]->count=x;
	return;
}

// prints the number of occurences, or 0 if not in the file
void printStats(){
    float percentage =0;
    float capacity=ARRAY_SIZE;
    int numterms=0;
    int col_count=0;
    for(int i=0;i<ARRAY_SIZE;i++){
        if(hashTable[i]!=NULL){
            numterms++;
            col_count=col_count+hashTable[i]->collision;
        }

    }
    float numterms2=numterms;//gets around / operand forLOAD
    percentage = numterms2/capacity;
    printf(" Capacity   :%d\n",ARRAY_SIZE);
    printf(" Num Term   :%d\n",numterms);
    printf(" Collisions :%d\n",col_count);
    printf(" Load       :%.2f%c\n",percentage,37);
    return;
    }

// }
// }
// function from the assignment 0
// Reads strings of alpha numeric characters from input file. Truncates strings which are too long to string_max-1
void next_token ( char *buf, FILE *f, int string_max ) {
	// start by skipping any characters we're not interested in
	buf[0] = fgetc(f);
	while ( !isalnum(buf[0]) && !feof(f) ) { buf[0] = fgetc(f); }
	// read string of alphanumeric characters
	int i=1;
	for (;;) {
		buf[i] = fgetc(f);                // get next character from file
		if( !isalnum(buf[i])&&buf[i]!= ' ' ) { break; } // only load letters and numbers
		if( feof(f) ) { break; }          // file ended?
		if( i < (string_max-1) ) { ++i; } // truncate strings that are too long
	}
	buf[i] = '\0'; // NULL terminate the string
}


//  Reads the contents of a file and adds them to the hash table - returns 1 if file was successfully read and 0 if not.
int load_file ( char *fname ) {
    //printf("///////////////////////////////////////\n");
	FILE *f;
	char buf[MAX_STRING_SIZE];

	// boiler plate code to ensure we can open the file
	f = fopen(fname, "r");	
	if (!f) { 
		printf("Unable to open %s\n", fname);
		return 0; 
	}
	
	// read until the end of the file
	while ( !feof(f) ) {
		next_token(buf, f, MAX_STRING_SIZE);
		addOrIncrement( buf);                           //here you call your function from above!
	}

	// always remember to close your file stream
	fclose(f);

	return 1;
}

int main(){
char* quit ="quit";
int initcheck=50;//arbritary value!=1||0.
char* inputname;
inputname=(char*)malloc(sizeof(char)*MAX_STRING_SIZE);
//char inputname[MAX_STRING_SIZE];
initcheck=load_file("names.csv");
if ((initcheck==0))
{
    printf("File loading failed try again\n");
    return 0;
}
if(initcheck==1){
    printf("File names.csv loaded\n");
    printStats();
    printf("Enter term to get frequency or type \"quit\" to escape\n");
    while(strcmp(inputname,quit)!=0){
    // printf(">>> ");
scanf(" %[^\n]%*c", inputname);    //fgets(inputname,MAX_STRING_SIZE,stdin);

    if(strcmp(inputname,quit)==0){
        return 0;
    }

    Element* check=search(inputname);
    if(check==NULL){
        //printf("%s not in table\n",inputname);
        printf(">>> %s - 0 \n",inputname);
    }else if(check!=NULL){
        int key1=0;

        
        int k=check->count;       
    printf(">>> %s - %d \n",inputname,k);
    }
 }
}

    //then move on to addOrIncrement TICK
    //only then worry about loading the file TICK
    //and later again about an interactive interface
    
    return 0;
}