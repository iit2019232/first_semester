


#ifndef SOURCE_FILE
#define SOURCE_FILE

void bold_line(void); //Prints out a bold line (Needed for the functioning of welcome function)
void single_line(void); //Prints out a single line (Needed for the functioning of welcome function)
void spacing1(int, char); //Used for padding (Designing)
void spacing2(int, char); //Used for padding (Designing)
void underline(int); //Used for underlining (Designing)
void newline(int); //Used to get to "n" new lines (Designing)
void welcome(void); //Welcomes the customer (Starting interface of the program)

//This struct will store the details of each type of coffee
struct coffee{
    int num;
    char name[30];
    int price;
};

//This is done to avoid typing "struct" keyword again and again
typedef struct coffee coffee;




#endif


