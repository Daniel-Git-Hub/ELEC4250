#include "myfunctions.h"
#include <stdio.h>
#include <stdlib.h>

void m_add(void *pointerA, void *pointerB, void *pointerResult, int size) {
    long (*A)[size] = pointerA;
    long (*B)[size] = pointerB;
    long (*result)[size] = pointerResult;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void m_multiply(void *pointerA, void *pointerB, void *pointerResult, int size) {
    long (*A)[size] = pointerA;
    long (*B)[size] = pointerB;
    long (*result)[size] = pointerResult;    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            result[i][j] = 0;
            for(int k = 0; k < size; k++){
                result[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void m_parse(char *m_string, void *pointerResult, int size){
    long (*result)[size] = pointerResult;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            result[i][j] = strtol(m_string, &m_string, 10);
            m_string++;
        }
    }
}


void m_print(void *pointerA, int size){
    long (*A)[size] = pointerA;
    for (int i = 0; i < size; i++) {
        printf("[ ");
        for (int j = 0; j < size; j++) {
            printf("%ld ",A[i][j]);
        }
        printf("]\n");
    } 
}

