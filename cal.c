/*Matrix Calculator For Sqaure Matrices. Still a work in progress. Dev by Udam Liyanage*/
#include <stdio.h>
#include <stdbool.h>

#define s 2

//Global Variable Declaration
int m1[s][s], m2[s][s], res[s][s]; //M1 and M2 are 2X2 Square Matrices. Res stores the result derived from the operatins performed on the matrices.
char placeholder[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}, mName[10];
//Function Declarations
void initialiseArray(int t[s][s]);
void inputArray(int t[s][s], char mName[10]); //Function to add data into the array.
void displayArray(int disArray[s][s]); //Function to display the array (matrices)
void matrixAddition();
void matrixSubtraction();
void scalarMultiplication();
void matrixMultiplication();

int main(){
 int choice;
 bool run = true;

 while(run == true){
   printf("Welcome to the Matrix Calculator. Please select your choice to proceed\n1.Matrix Addtion\n2.Matrix Subtraction\n3.Scalar Multiplication\n4.Matrix Multiplication\n5.Quit");
   printf("\nChoice: ");
   scanf("%d", &choice);
   if(choice>5 || choice<0){
     printf("\nIllegal Choice Made\n");
   }
   else if(choice == 5){
     run = false;
     printf("Thank you for using the Matrix Calculator. Have a nice day");
   }
   else{
     switch(choice){
       case 1: matrixAddition();
       break;

       case 2: matrixSubtraction();
       break;

       case 3: scalarMultiplication();
       break;

       case 4: matrixMultiplication();
       break;
     }
   }
 }
 return 0;
}

void matrixMultiplication(){
  int x, y;
  printf("\nYou've chosen matrix multiplication. You can perform multiplication on two 2X2 square matrices, namely p and q\n");
  initialiseArray(m1);
  initialiseArray(m2);
  initialiseArray(res);
  inputArray(m1, "Matrix p");
  inputArray(m2, "Matrix q");
  res[0][0] = (m1[0][0]*m2[0][0]) + (m1[0][1]*m2[1][0]);
  res[0][1] = (m1[0][0]*m2[0][1]) + (m1[0][1]*m2[1][1]);
  res[1][0] = (m1[1][0]*m2[0][0]) + (m1[1][1]*m2[1][0]);
  res[1][1] = (m1[1][0]*m2[0][1]) + (m1[1][1]*m2[1][1]);

  displayArray(res);
}

void scalarMultiplication(){
  int k, x, y;
  printf("\nYou've chosen scalar multiplication. You can perform scalar multiplication on a 2X2 matrix with the constant k as the scalar.");
  printf("\n Result of scalar multiplication = kXP");
  printf("\nPlease input the value for k (constant): ");
  scanf("%d", &k);
  initialiseArray(m1);
  initialiseArray(m2);
  initialiseArray(res);
  inputArray(m1, "Matrix p");
  for(x=0;x<2;x++){
    for(y=0;y<2;y++){
      res[x][y] = k*m1[x][y];
    }
  }
  printf("\nkP = \n");
  displayArray(res);
}

void matrixSubtraction(){
  int x, y;
  printf("\nYou've chosen matrix subtraction. You can perform addition on two 2X2 square matrices, namely p and q\n");
  initialiseArray(m1);
  initialiseArray(m2);
  initialiseArray(res);
  inputArray(m1, "Matrix p");
  inputArray(m2, "Matrix q");
  for(x=0;x<2;x++){
    for(y=0;y<2;y++){
      res[x][y] = m1[x][y]-m2[x][y];
    }
  }
  printf("p + q = \n");
  displayArray(res);
}

void matrixAddition(){
  int x, y;
  printf("\nYou've chosen matrix addition. You can perform addition on two 2X2 square matrices, namely p and q\n");
  initialiseArray(m1);
  initialiseArray(m2);
  initialiseArray(res);
  inputArray(m1, "Matrix p");
  inputArray(m2, "Matrix q");
  for(x=0;x<2;x++){
    for(y=0;y<2;y++){
      res[x][y] = m1[x][y]+m2[x][y];
    }
  }
  printf("p + q = \n");
  displayArray(res);
}

void inputArray(int t[s][s], char mName[10]){
 int v1, v2, v3, v4, x, y;
 printf("Input values for %s", mName);
 if(mName == "Matrix p"){ //Instance where Matrix is P.
   printf("\np = a b\n    c d\n");
   printf("Input value for %c: ", placeholder[0]);
   scanf("%d", &v1);
   printf("Input value for %c: ", placeholder[1]);
   scanf("%d", &v2);
   printf("Input value for %c: ", placeholder[2]);
   scanf("%d", &v3);
   printf("Input value for %c: ", placeholder[3]);
   scanf("%d", &v4);
   t[0][0] = v1;
   t[0][1] = v2;
   t[1][0] = v3;
   t[1][1] = v4;
 }
 else{ //Or else  data is entered to Matrix q.
   printf("\nq = e f\n    g h\n");
   printf("Input value for %c: ", placeholder[4]);
   scanf("%d", &v1);
   printf("Input value for %c: ", placeholder[5]);
   scanf("%d", &v2);
   printf("Input value for %c: ", placeholder[6]);
   scanf("%d", &v3);
   printf("Input value for %c: ", placeholder[7]);
   scanf("%d", &v4);
   t[0][0] = v1;
   t[0][1] = v2;
   t[1][0] = v3;
   t[1][1] = v4;
 }
}

void displayArray(int disArray[s][s]){
 int x, y;
 for(x=0; x<2; x++){
   for(y=0; y<2; y++){
     printf("%d ", disArray[x][y]);
   }
   printf("\n");
 }
}

void initialiseArray(int t[s][s]){
  int x, y;
  for(x=0;x<2;x++){
    for(y=0;y<2;y++){
      t[s][s] = 0;
    }
  }
}

