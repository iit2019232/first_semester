


#include<stdio.h>
#include<stdlib.h>
#include"source_file.h"
#include<string.h>

int main(){

//Welcomes the customer (Starting interface of the program)   
welcome();

//Waits for user to type return key
getchar();

//Details of various coffee types (stored in struct array)
coffee cof[7] = {{1, "Flat White", 250}, {2, "Caffe Mocha", 230}, {3, "Cappuccino", 200}, 
                {4, "Americano", 185}, {5, "PO French Press", 195}, {6, "Espresso", 175},
                {7, "Hot Chocolate", 160}};


int final_price = 0;

//Quantities of coffee types are stored in their respective flags
int flag[7] = {0, 0, 0, 0, 0, 0, 0};

//User charcter input
char trigger;

select_coffee: printf("Type in the coffee number to select it: \n\n");
int cof_selected = 0;
int quantity = 0;


printf("Sr-> Coffee Type       ->Price\n\n");
//Prints out all the coffee types and their details (MENU CARD)
for(int i = 0; i < 7; i++){
    printf("%d -> %s", cof[i].num, cof[i].name);
    for(int m = 0; m < 18 - strlen(cof[i].name); m++)printf(" ");
    printf("->%d\n\n", cof[i].price);
}

scanf("%d", &cof_selected);
newline(2);
printf("You have selected: %s", cof[cof_selected - 1].name);
newline(2);
printf("How many of %s do you desire to order: ", cof[cof_selected - 1].name);
newline(1);
scanf("%d", &quantity);
flag[cof_selected - 1] += quantity;
newline(1);
printf("Congratulations, You have added %d %s to your cart!", quantity, cof[cof_selected - 1].name);

//Label where user decides what to do next, where to edit, finalize or add items to current order
ultimate_selection: newline(3);
printf("To edit your current order, press E!\n\nTo add items to your order, press A!\n\nTo finalize your order, press F!\n");
scanf("%c", &trigger); //Extra scanf command is added during debugging to debug an issue
scanf("%c", &trigger);
newline(3);

bold_line();
//Label in which user decides to edit his/her order
edit_mode: if(trigger == 'E'||trigger == 'e'){
    printf("Edit Mode:\n");
    underline(9);
    for(int i = 0; i < 7; i++){
        if(flag[i] == 0) continue;
        else {printf("%d -> %s", cof[i].num, cof[i].name);
              for(int m = 0; m < 18 - strlen(cof[i].name); m++)printf(" ");
              printf("Quantity-> %d\n", flag[i]);}}
    
    printf("Enter Coffee No. that you wish to drop: \n");
    scanf("%d", &cof_selected);
    newline(2);
    printf("How many of %s do you wish to remove: ", cof[cof_selected - 1].name);
    scanf("%d", &quantity);
    int temp = flag[cof_selected - 1];
    flag[cof_selected - 1] -= quantity;
    
    //This is done to keep the quantity of oredered coffees in greater or equal to zero
    if(flag[cof_selected - 1] < 0){
        printf("Sorry, Invalid!\n\n");
        flag[cof_selected - 1] = temp;
        goto edit_mode;
    }
    newline(1);
    printf("You have successfully removed %d %s from your cart!\n", quantity, cof[cof_selected - 1].name);
    goto ultimate_selection;}

//Loops back to the add coffees section
if(trigger == 'A'||trigger == 'a'){
    printf("Select Mode:\n");
    underline(11);
    goto select_coffee;}

//Label in which user finalizes his/her order
if(trigger == 'F'||trigger == 'f'){
    printf("Are you sure that you want to finalize the order of: \n\n");
    for(int i = 0; i < 7; i++){
        if(flag[i] == 0) continue;
        else {printf("%d -> %s", cof[i].num, cof[i].name);
              for(int m = 0; m < 18 - strlen(cof[i].name); m++)printf(" ");
              printf("Quantity-> %d\n\n", flag[i]);}}
    newline(2);
    
    //Calculating and returning final amount to be paid by the user
    final_price = 0;
    for(int i = 0; i < 7; i++){
        final_price += (flag[i]*(cof[i].price));
    }
    
    final_select: printf("Your total will be - Rs. %d\n", final_price);
    underline(29);
    printf("\nType Y for YES, Type N for NO\n");
    scanf("%c", &trigger); //Extra scanf command is added during debugging to debug an issue
    scanf("%c", &trigger);
    
    //Loops back if the user changes his/her mind.
    if(trigger == 'N'||trigger == 'n'){
        goto ultimate_selection;
    }
    
    //If the user confirms his/her order
    else if(trigger == 'Y'||trigger == 'y'){
        single_line();
        printf("Amount of Rs.%d has been debited from your debit card!\nThank you for choosing ROSE\'s Coffee Machine!\n", final_price);
        bold_line();
        printf("Please collect your order of: \n\n");
        for(int i = 0; i < 7; i++){
        if(flag[i] == 0) continue;
        else {printf("# %s", cof[i].name);
              for(int m = 0; m < 18 - strlen(cof[i].name); m++)printf(" ");
              printf("Quantity-> %d\n\n", flag[i]);}}
        bold_line();
    }
    //incase the user types something other that 'Y' or 'N'
    else {
        printf("\nSorry, Invalid!\n");
        goto final_select;
    }}
    
     //incase the user types something other that 'A', 'E' or 'F'
    else {
        printf("\nSorry, Invalid!\n");
        goto ultimate_selection;
    }




return 0;}


