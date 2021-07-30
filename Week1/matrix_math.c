#include <stdio.h>
#include <stdlib.h>
#include "cs50.h"
#include "myfunctions.h"

int main (void) {
    int size = get_int("Size of the square array: ");

    char *matrixAString = get_string("First matrix, in format 'a,b;c;d':\n");
    long A[size][size];
    m_parse(matrixAString, A, size);

    char *matrixBString = get_string("Second matrix, in format 'a,b;c;d':\n");
    long B[size][size];
    m_parse(matrixBString, B, size);

	// array for storing output
    long C[size][size];

    // get user input
    printf("I can do addition or multiplication of two %dx%d matricies\n",size,size);
    int option = get_int("Do you want me to (1) add or (2) multiply? ");

    // add or multiply depending on user input
    switch (option) {
        case 1:
            m_add(A, B, C, size);
            break;

        case 2:
            m_multiply(A, B, C, size);
            break;
    }

	// show input and output of calculation
	printf("Showing output\n");
    printf("First Matrix\n");
    m_print(A, size);
    printf("Second Matrix\n");
    m_print(B, size);
    printf("Resultant Matrix\n");
    m_print(C, size);

    return 0;
}
