/*******************************************************************************
*   Author: Rahul Adhikari                                                      *
*   Description: A simple matrix class capable of scalar multiplication,        *
*                matrix addition, matrix multiplication                         *
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "main.h"
#include "ctype.h"


int main(void){

    int matrixA[10][10]; // initialized at 10 just to have it initialized
    int matrixB[10][10];
    int rowA, colA;
    int rowB, colB;
    int operation;//used in swtich statements
    char again = 'Y';
    int scalar = 0;
    int add = 1;
    int sub = -1;

    while (again == 'Y'){


        //this is the operation menu just type A, B, C or D to calculate
        printf("\nOperation Menu\n");
        printf("\t1. Add\n");
        printf("\t2. Subtract\n");
        printf("\t3. Scalar Multiply\n");
        printf("\t4. Multiply two matrices\n");
        printf("\t5. Exit\n");
        printf("Enter yout choice: ");
        scanf(" %d", &operation);


        switch (operation){

        case 1:
            printf("\nEnter the #rows and #cols for matrix A: ");
            scanf("%d%d", &rowA, &colA);

            printf("Enter the #rows and #cols for matrix B: ");
            scanf("%d%d", &rowB, &colB);

            while ((rowA != rowB) && (colA != colB)){
                printf("\nMatrices must be the same size\n");
                printf("\nEnter the #rows and #cols for matrix A: ");
                scanf("%d%d", &rowA, &colA);

                printf("Enter the #rows and #cols for matrix B: ");
                scanf("%d%d", &rowB, &colB);

            }


            printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); // with the %d we remember the user the dimentions of the array
            read(matrixA, rowA, colA);
            printf("\n\t\tMatrix A\n\n");
            print(matrixA, rowA, colA);


            printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB); // with the %d we remember the user the dimentions of the array
            read(matrixB, rowB, colB);
            printf("\n\t\tMatrix B\n\n");
            print(matrixB, rowB, colB);


            printf("\nThe Sum of matrixA + matrixB is : \n");
            AddSub(matrixA, matrixB, rowA, colA, add);

            break;

        case 2:

            printf("\nEnter the #rows and #cols for matrix A: ");
            scanf("%d%d", &rowA, &colA);

            printf("Enter the #rows and #cols for matrix B: ");
            scanf("%d%d", &rowB, &colB);

            while ((rowA != rowB) && (colA != colB)){
                printf("\nMatrices must be the same size\n");
                printf("\nEnter the #rows and #cols for matrix A: ");
                scanf("%d%d", &rowA, &colA);

                printf("Enter the #rows and #cols for matrix B: ");
                scanf("%d%d", &rowB, &colB);
            }

            printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); // with the %d we remember the user the dimentions of the array
            read(matrixA, rowA, colA);
            printf("\n\tMatrix A\n");
            print(matrixA, rowA, colA);

            printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB); // with the %d we remember the user the dimentions of the array
            read(matrixB, rowB, colB);
            printf("\n\tMatrix B\n");
            print(matrixB, rowB, colB);

            printf("\nThe difference between matrixA - matrixB is : \n");
            AddSub(matrixA, matrixB, rowA, colA, sub);
            break;

        case 3:

            printf("\nEnter the scalar: ");
            scanf("%d", &scalar);
            printf("\nThe scalar is: %d ", scalar);


            printf("\nEnter the #rows and #cols for matrix A: ");
            scanf("%d%d", &rowA, &colA);

            printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); // with the %d we remember the user the dimentions of the array
            read(matrixA, rowA, colA);
            printf("\n\t\tMatrix A\n\n");
            print(matrixA, rowA, colA);

            printf("\nThe scalar multiplication between matrixA * %d is: \n", scalar);
            ScalarMultiply(matrixA, scalar, rowA, colA);

            break;

        case 4:
            //when mulotiplying arrays matrixA colum # has to equal matrixB row #
            printf("\nEnter the #rows and #cols for matrix A: ");
            scanf("%d%d", &rowA, &colA);

            printf("Enter the #rows and #cols for matrix B: ");
            scanf("%d%d", &rowB, &colB);

            // Column of first matrix should be equal to column of second matrix and
            while (colA != rowB)
            {
                printf("\n\nError! column of first matrix not equal to row of second.\n\n");
                printf("\nEnter the #rows and #cols for matrix A: ");
                scanf("%d%d", &rowA, &colA);

                printf("Enter the #rows and #cols for matrix B: ");
                scanf("%d%d", &rowB, &colB);
            }

            // Storing elements of first matrix.
            printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); // with the %d we remember the user the dimentions of the array
            read(matrixA, rowA, colA);
            printf("\n\t\tMatrix A\n\n");
            print(matrixA, rowA, colA);

            // Storing elements of second matrix.
            printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB); // with the %d we remember the user the dimentions of the array
            read(matrixB, rowB, colB);
            printf("\n\t\tMatrix A\n\n");
            print(matrixB, rowB, colB);

            //multiplyng arrays
            Multiply(matrixA, matrixB, rowA, colA, colB);

            break;

        case 5:
            break;
        default:
            printf("\nIncorrect option! Please choose a number 1-4.");
            break;
        }

        printf("\n\nDo you want to calculate again? Y/N\n");
        scanf(" %c", &again);
        again = toupper(again);
    }
    printf("\n\nGoodbye!\n\n");

    return 0;
}


//User Defined Function Definition
void read(int array[10][10], int rows, int colums)
{
    int i, j;
    for (i = 0; i < rows; i++){
        printf("\t%d entries for row %d: ", colums, i + 1);
        for (j = 0; j < colums; j++){
            scanf("%d", &array[i][j]);
        }
    }

    return;
}

void print(int array[10][10], int rows, int colums)
{
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < colums; j++){
            printf("\t%d", array[i][j]);
        }
        printf("\n");
    }
}


void AddSub(int arrayone[10][10], int arraytwo[10][10], int rows, int colums, int mul)
{
    int i, j;
    int sumM[10][10];
    int scaM[10][10];
    for (i = 0; i < rows; i++){
        for (j = 0; j < colums; j++){
            scaM[i][j] = mul * arraytwo[i][j];
            }
        }


    for (i = 0; i < rows; i++){
        for (j = 0; j < colums; j++){
            sumM[i][j] = arrayone[i][j] + scaM[i][j];
            printf("\t%d", sumM[i][j]);
        }
        printf("\n");
    }
}


void ScalarMultiply(int array[10][10], int scalar, int rows, int colums){
    int i, j;
    int scaM[10][10];
    for (i = 0; i < rows; i++){
        for (j = 0; j < colums; j++){
            scaM[i][j] = scalar * array[i][j];
            printf("%d\t", scaM[i][j]);
        }
        printf("\n");
    }

}

void Multiply(int arrayone[10][10], int arraytwo[10][10], int rowsA, int columsA,int columsB)
{
    int i, j, k;
    int mulM[10][10];

    // Initializing all elements of result matrix to 0
    for (i = 0; i<rowsA; ++i)
        for (j = 0; j<columsB; ++j)
        {
            mulM[i][j] = 0;
        }

    // Multiplying matrices a and b and
    // storing result in result matrix
    for (i = 0; i<rowsA; ++i)
        for (j = 0; j<columsB; ++j)
            for (k = 0; k<columsA; ++k)
            {
                mulM[i][j] += arrayone[i][k] * arraytwo[k][j];
            }
    printf("\nOutput Matrix:\n");
    for (i = 0; i<rowsA; ++i)
        for (j = 0; j<columsB; ++j)
        {
            printf("\t%d ", mulM[i][j]);
            if (j == columsB - 1)
                printf("\n\n");
        }
}
/*******************************************************************************
*                                 THE END                                      *
*******************************************************************************/