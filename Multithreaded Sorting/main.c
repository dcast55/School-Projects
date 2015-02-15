//
//  main.c
//  Multithreaded Sorting
//
//  Created by Daniel Castellucci on 2/16/15.
//  Copyright (c) 2015 Daniel Castellucci. All rights reserved.
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define NUMBER_OF_THREADS 3

int list[SIZE] = {7,12,19,3,18,4,2,6,15,8};
int result[SIZE];

void print_array(int array[], int len);
void sort_array(int array[], int len);
void merge_arrays(int dest[], int src1[], int src1_len, int src2[], int src2_len);
int compare_int( const void* a, const void* b);


int main() {
    
    int first_size = SIZE / 2;
    int second_size = SIZE - first_size;
    sort_array(list, first_size);  // sort the first half of the array
    sort_array(list + first_size + 1, second_size);  // sort the second half of the array
//    merge_arrays(result, list, first_size, list + first_size + 1, second_size);
    
    printf("Printing first array \n");
    print_array(list, first_size);
    printf("\n\n Printing second array \n");
    print_array(list + first_size + 1, second_size);

    
    return 0;
}

void sort_array(int array[], int len) {
    qsort(array, len, sizeof(int), compare_int);
}

int compare_int( const void* a, const void* b)
{
    if( *(int*)a == *(int*)b ) return 0;
    return *(int*)a < *(int*)b ? -1 : 1;
}

void print_array(int array[], int len) {
    for (int i=0; i<len; i++)
        printf("%d \n", array[i]);
}