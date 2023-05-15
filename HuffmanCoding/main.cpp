#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <winbgim.h>

//Structures
typedef struct{
    char letter;
    float probability;
    int times;
    char *code;
} TNodo;


//Functions
void getMessage();
void countLetters();
void createNodes();
void orderNodes();
void printInf();

//Variables
char *message;          //Contains the message
char buffer [200];      //
char letters [27];
int numPLetter [27];
int numLetters;
TNodo * nodes;

int main (){

    getMessage();
    countLetters();
    createNodes();
    orderNodes();
    //printInf();

    //initwindow(600, 600, "Huffman Coding Tree");
    //getch();

    return 0;
}

void getMessage(){
    fflush(stdin);
    printf("Please, enter the message: ");
    fgets(buffer, 200, stdin);  //Got the message into buffer variable
    message = strdup(buffer);   //Copy buffer's value into message (but only filled spaces).
}

void countLetters(){
    int z = 0;
    int i;
    char * auxMSS = strdup(message);

    for(i = 0 ; message[i] != '\n'; i++){
        if(auxMSS[i] != '\n') {
            letters[z] = auxMSS[i] ;
            numPLetter[z] = 0;
            z++;
        }

        for(int j = 0; message[j] != '\n'; j++){
            if(letters[z-1] == auxMSS[j]){
                numPLetter[z-1]++;
                auxMSS[j] = '\n';
            }
        }
    }
    numLetters = z;
    letters[z] = '\n';
}

void createNodes(){

    nodes = (TNodo *) malloc(sizeof(TNodo) * numLetters);

    for(int i = 0; i < numLetters; i++){
        nodes[i].letter = letters[i];
        nodes[i].times = numPLetter[i];
        nodes[i].probability = (float) numPLetter[i] / ( strlen(message) - 1);
    }
}

void orderNodes(){
    TNodo aux;

    for(int i = 0; i < numLetters; i++){
        for(int j = 0; j < numLetters; j++){
            if(nodes[i].probability > nodes[j].probability){
                aux = nodes[j];
                nodes[j] = nodes[i];
                nodes[i] = aux;
            }
        }
    }
}

void printInf(){
    printf("LETTER              TIMES              PROBABILITY              CODE\n");
    for(int i = 0; i < numLetters; i++){
        printf("%c              %d              %f              \n", nodes[i].letter, nodes[i].times, nodes[i].probability);
    }
}

//ANITA LAVA LA TINA









