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

void print_array(int [], int);
void sort_array(int [], int);
void merge_arrays(int [],int , int [], int , int []);
int compare_int( const void* a, const void* b);


int main() {
    
    int first_size = SIZE / 2;
    int second_size = SIZE - first_size;
    sort_array(list, first_size);  // sort the first half of the array
    sort_array(list + first_size + 1, second_size);  // sort the second half of the array
    
    // Testing the array sorting
    printf("Printing first array \n");
    print_array(list, first_size);
    printf("\n\n Printing second array \n");
    print_array(list + first_size + 1, second_size);
    
    // Testing array merging
    merge_arrays(list, first_size, list + first_size + 1, second_size, result);
    printf("\n\n Merged Array \n");
    print_array(result, SIZE);
    
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

void merge_arrays(int a[], int m, int b[], int n, int sorted[]) {
    int i, j, k;
    
    j = k = 0;
    
    for (i = 0; i < m + n;) {
        if (j < m && k < n) {
            if (a[j] < b[k]) {
                sorted[i] = a[j];
                j++;
            }
            else {
                sorted[i] = b[k];
                k++;
            }
            i++;
        }
        else if (j == m) {
            for (; i < m + n;) {
                sorted[i] = b[k];
                k++;
                i++;
            }
        }
        else {
            for (; i < m + n;) {
                sorted[i] = a[j];
                j++;
                i++;
            }
        }
    }
}

void print_array(int array[], int len) {
    for (int i=0; i<len; i++)
        printf("%d \n", array[i]);
}