#include <stdio.h>

void swap_float(float* a, float* b){
    float c = *a;
    *a = *b;
    *b = c;}

void swap_int(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;}

void row_multiply(float a[4][3], int row, float constant){
   for(int i = 0; i < 3; i++)
   a[row][i] *= constant;
}

void row_addition(float a[4][3], int row1, int row2, float constant){
    for(int i = 0; i < 3; i++)
    a[row1][i] += a[row2][i]*constant;
}

int main(void) {
    int f,j,i;
	float a[4][3];
    le_input: printf("\nEnter the 4x3 matrix: \n");
	for(int i=0;i<4;i++)
	for(int j=0;j<3;j++)
	scanf("%f",&a[i][j]);
	
    int countlead[4]={0};
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]==0)
			countlead[i]++;
			else break;
		}
	}

    for (i = 0; i < 3; i++)    
       for (j = 0; j < 3-i; j++)  
        if (countlead[j] > countlead[j+1]){ 
              swap_int(&countlead[j], &countlead[j+1]);
              for(int m = 0; m < 3; m++)
              swap_float(&a[j][m], &a[j+1][m]);}
   
    if(a[0][0]!=0){
        row_multiply(a, 0, (1/a[0][0]));
        for(int i = 1; i < 4; i++)
        if(a[i][0]!=0)
        row_addition(a, i, 0, (-a[i][0]));}

    else if(a[0][1]!=0){
        row_multiply(a, 0, (1/a[0][1]));
        for(int i = 1; i < 4; i++)
        if(a[i][1]!=0)
        row_addition(a, i, 0, (-a[i][1]));}

    else if(a[0][2]!=0){
        row_multiply(a, 0, (1/a[0][2]));
        for(int i = 1; i < 4; i++)
        if(a[i][2]!=0)
        row_addition(a, i, 0, (-a[i][2]));}

    
    for(int i = 1; i < 4; i++)
        if(a[i][1]!=0){
            swap_float(&a[i][1], &a[1][1]);
            swap_float(&a[i][2], &a[1][2]);
        }
  

    if(a[1][1]!=0){
        row_multiply(a, 1, (1/a[1][1]));
        for(int i = 0; i < 4; i++)
        if(a[i][1]!=0&&i!=1)
        row_addition(a, i, 1, (-a[i][1]));}

    if(a[1][1]==0)
       if((a[1][2]!=0)||(a[2][2]!=0)||(a[3][2]!=0)){
        a[0][2] = 0;
        a[1][2] = 1;
        a[2][2] = 0; 
        a[3][2] = 0;}   
        
 
    if(a[2][2]!=0||a[3][2]!=0){
        a[0][2]=0;
        a[1][2]=0;
        a[2][2]=1;             
        a[3][2]=0;}
       
    
    for(int i=0;i<4;i++)
	for(int j=0;j<3;j++){
        if((a[i][j] < 0.005)&&(a[i][j]>-0.005))
        a[i][j] = 0;
    }
   
    printf("\n\nRow reduced echelon form of the given matrix is: \n");	
    for(int i=0;i<4;i++){
	for(int j=0;j<3;j++)
	printf("%.2f  ",a[i][j]);
	printf("\n");
    }
    
    int flag = 0, rank = 0;
    for(int i=0;i<4;i++){
    flag = 0;
	for(int j=0;j<3;j++)
    if(a[i][j]!=0)flag++;
    if(flag!=0)rank++;
    }

    printf("\nRank of the given matrix is: %d\n\n\n", rank);
    
    goto le_input;
} 