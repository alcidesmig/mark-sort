/* 
 * File:   main.c
 * Author: alcidesmig
 *
 * Created on 29 de Julho de 2019, 22:12
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define NUMERICAL_RANGE 1000
#define NUM_VALUES 1000
#define NUM_LOOPS 1000

void markSort(int * vector, int * output) {
    for (int i = 0; i < NUMERICAL_RANGE; i++) {
        vector++;
        while (*(vector) > 0) {
            *(output++) = i + 1;
            *(vector) -= 1;
        }
    }
}

int * receive_and_sort(int * vector_values, int n) {

    int * vector_appeared = (int *) calloc(NUMERICAL_RANGE, sizeof (int));

    for (int i = 0; i < n; i++) {
        vector_appeared[*(vector_values + i)]++;
    }

    int * output = (int *) malloc(n * sizeof (int));
    int * backup = output;

    markSort(vector_appeared, output);

    return backup;

}

int * read_and_sort(int n) {

    int * vector_values = (int *) malloc(n * sizeof (int));
    int * vector_appeared = (int *) calloc(NUMERICAL_RANGE, sizeof (int));

    for (int i = 0; i < n; i++) {
        scanf("%d", (vector_values + i));
        vector_appeared[*(vector_values + i)]++;
    }

    int * output = (int *) malloc(n * sizeof (int));
    int * backup = output;

    markSort(vector_appeared, output);

    return backup;
}

int partition(int a[], int p, int r);
void quickSort(int a[], int p, int r);

long runMarkSort(int * values) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    int * response = receive_and_sort(values, NUM_VALUES);
    gettimeofday(&end, NULL);
    long time_spent = (((end.tv_sec - start.tv_sec) * 1000000) + end.tv_usec) - (start.tv_usec);
    return time_spent;
}

long runQuickSort(int * values) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    quickSort(values, 0, NUM_VALUES - 1);
    gettimeofday(&end, NULL);
    long time_spent = (((end.tv_sec - start.tv_sec) * 1000000) + end.tv_usec) - (start.tv_usec);
    return time_spent;
}

int main() {
    srand(time(NULL));
    FILE * fp = fopen("all_values.txt", "w");
    int * values = (int *) malloc(NUM_VALUES * sizeof (int));
    long mark_sum = 0, quick_sum = 0;
    long iteration_mark = 0, iteration_quick = 0;
    for (int j = 0; j < NUM_LOOPS; j++) {
        for (int i = 0; i < NUM_VALUES; i++) {
            *(values + i) = rand() % NUMERICAL_RANGE;
        }
        iteration_mark = runMarkSort(values);
        iteration_quick = runQuickSort(values);
        mark_sum += iteration_mark;
        quick_sum += iteration_quick;
        fprintf(fp, "markSort: %3ld quickSort: %3ld\n", iteration_mark, iteration_quick);
    }
    fclose(fp);
    fp = fopen("media.txt", "w");
    fprintf(fp, "markSort: %3ld\nquickSort: %3ld\n", mark_sum / NUM_LOOPS, quick_sum / NUM_LOOPS);
    fclose(fp);
    return 0;
}

/*
    QuickSort Wikipedia code 
 */
int partition(int a[], int p, int r) {
    int x = a[r];
    int j = p - 1;
    for (int i = p; i < r; i++) {

        if (x >= a[i]) { // changed (x <= a[i]) to (x >= a[i]) for reverse False
            j = j + 1;
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    a[r] = a[j + 1];
    a[j + 1] = x;

    return (j + 1);
}

void quickSort(int a[], int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}
