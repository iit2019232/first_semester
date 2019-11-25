

#include<stdio.h>
#include<stdlib.h>
#include"source_file.h"

//Prints out a bold line (Needed for the functioning of welcome function)
void bold_line(void){
    for(int i = 0; i < 70; i++)
    printf("=");
    printf("\n");
}

//Prints out a single line (Needed for the functioning of welcome function)
void single_line(void){
    for(int i = 0; i < 70; i++)
    printf("-");
    printf("\n");
}

//Used for padding (Designing)
void spacing1(int n, char c){
   for(int i = 0; i < (35-n/2); i++)
   printf("%c", c);
}

//Used for padding (Designing)
void spacing2(int n, char c){
   for(int i = 0; i < (35-n/2); i++)
   printf("%c", c);
   printf("\n");
}

//Used for underlining (Designing)
void underline(int n){
   for(int i = 0; i < n; i++)
   printf("-");
   printf("\n");
}

//Used to get to "n" new lines (Designing)
void newline(int n){
   for(int i = 0; i < n; i++)
   printf("\n");
}

//Welcomes the customer (Starting interface of the program)
void welcome(void){
 newline(4);
 bold_line();
 newline(2);
 spacing1(38, ' ');
 printf("* Welcome to ROSE\'s Coffee Machine! *");
 spacing2(38, ' ');
 spacing1(38, ' ');
 underline(38);
 spacing2(38, ' ');
 newline(6);
 single_line();
 spacing1(36, ' ');
 printf("Everything gets better with coffee!");
 spacing2(36, ' ');
 bold_line();
 printf("\nPress return/enter key to get the ROSE\'s Coffee Machine MENU CARD...");
 newline(2);
}



