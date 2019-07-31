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

int * runMarkSort(int * values) {
    return receive_and_sort(values, NUM_VALUES);
}

int main() {
    srand(time(NULL));
    int * values = (int *) malloc(NUM_VALUES * sizeof (int));
    for (int j = 0; j < NUM_LOOPS; j++) {
        for (int i = 0; i < NUM_VALUES; i++) {
            *(values + i) = rand() % NUMERICAL_RANGE;
        }
        runMarkSort(values);
    }
    return 0;
}

