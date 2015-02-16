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
void *passtoSort(void *params);
void quicksort(int x[10],int first,int last);
void *passtoMerge(void *params);
void merge_arrays(int a[], int m, int b[], int n, int result[]);


typedef struct {
    int sublist[5];
    int start;
    int end;
} parameters;

typedef struct {
    int mergesub1[5];
    int mergesub2[5];
} merge_args;


int main() {
    
    pthread_t thread[NUMBER_OF_THREADS];
    
    printf("Initial unsorted array: \n");
    for (int i=0; i<SIZE; i++)
        printf("%d\n", list[i]);
    
    // Establish first sorting array
    parameters *data1 = (parameters *) malloc(sizeof(parameters));
    data1->start = 0;
    data1->end = (SIZE/2);
    for (int i=0; i<data1->end; i++)
        data1->sublist[i]=list[i];
    pthread_create(&thread[0], NULL, passtoSort, data1);
//    pthread_join(thread[0], NULL);
//    passtoSort(data1);
    
    // Establish second sorting array
    parameters *data2 = (parameters *) malloc(sizeof(parameters));
    data2->start = SIZE/2;
    data2->end = SIZE;
    int counter = 0;
    for (int i = data2->start; i < data2->end; i++) {
        data2->sublist[counter]=list[i];
        counter++;
    }
    pthread_create(&thread[1], NULL, passtoSort, data2);
//    pthread_join(thread[1], NULL);
//    passtoSort(data2);
    
    // Wait for sorting to complete
    for (int i=0; i<NUMBER_OF_THREADS-1; i++)
        pthread_join(thread[i], NULL);
    
    // Merge the two arrays
    merge_args *mergesub = (merge_args *) malloc(sizeof(merge_args));
    for (int i=0; i<5; i++) {
        mergesub->mergesub1[i]=data1->sublist[i];
        mergesub->mergesub2[i]=data2->sublist[i];
    }
    pthread_create(&thread[2], NULL, passtoMerge, mergesub);
    pthread_join(thread[2], NULL);
    
    // Print the final array
    printf("Final sorted and merged array: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%d\n", result[i]);

    return 0;
}

// Function to accept arguments from newly created thread and pass proper arguments to the quicksort algorithm
void *passtoSort(void *params) {
    printf("Starting new thread, sorting... \n");
    parameters* p = (parameters *)params;
    int x[5], first=0, last=5;
    for (int i = 0; i < 5; i++) {
        x[i] = p->sublist[i];
        //printf("Received array is: %d\n", x[i]);
        }
    
    quicksort(x, first, last);
    
    for(int z = 0; z < 5; z++) {
        p->sublist[z] = x[z];
        //printf("The sorted array is: %d\n", p->sublist[z]);
    }
    printf("Sort completed \n");

    pthread_exit(0);
}

// Quicksort to sort arrays in ascending order
void quicksort(int x[5], int first, int last) {
    int pivot,j,temp,i;
    
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        
        while(i<j){
            while(x[i]<=x[pivot]&&i<last)
                i++;
            while(x[j]>x[pivot])
                j--;
            if(i<j){
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
        
        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;
        quicksort(x,first,j-1);
        quicksort(x,j+1,last);
    }
}

// Accept arguments from newly created thread and pass proper arguments to merge function
void *passtoMerge(void* params) {
    printf("Starting new thread, merging... \n");
    merge_args* p = (merge_args *)params;
    int x[5], y[5];
    for (int i = 0; i < 5; i++) {
        x[i] = p->mergesub1[i];
        y[i] = p->mergesub2[i];
    }
    
    merge_arrays(x, 5, y, 5, result);
    
    pthread_exit(0);
}

// Take the two sorted sublists and merge them into the final sorted array in ascending order
void merge_arrays(int a[], int m, int b[], int n, int result[]) {
    int i, j, k;
    
    j = k = 0;
    
    for (i = 0; i < m + n;) {
        if (j < m && k < n) {
            if (a[j] < b[k]) {
                result[i] = a[j];
                j++;
            }
            else {
                result[i] = b[k];
                k++;
            }
            i++;
        }
        else if (j == m) {
            for (; i < m + n;) {
                result[i] = b[k];
                k++;
                i++;
            }
        }
        else {
            for (; i < m + n;) {
                result[i] = a[j];
                j++;
                i++;
            }
        }
    }
}