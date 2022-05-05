#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {

        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap( & arr[min_idx], & arr[i]);
    }
}

int main() {
    int *inp, i, j;
    FILE *input, *output;
    float total;
    clock_t start, end;

    input = fopen("input.txt", "w");
    output = fopen("output.txt", "w");
    for (i = 10000; i <= 50000; i = i + 10000) {
        inp = (int *)(malloc(i *sizeof(int)));
        printf("\nFor n = %d\n", i);
        //write i numbers of randam values from 0 to i in input file
        for (j = 0; j < i; j++) {
            fprintf(input, "%d  ", rand() % i);
        }
        fclose(input);
        input = fopen("input.txt", "r");
        //read the i numbers of random values and store them in array of int
        for (j = 0; j < i; j++) {
            fscanf(input, "%d", & inp[j]);
        }


        start = clock();
        selectionSort(inp, i);
        end = clock();
        total = (float)(end - start) / CLOCKS_PER_SEC;
        for (j = 0; j < i; j++) {
            fprintf(output, "%d ", inp[j]);
        }
        printf("Selection sort total time : %f\n\n", total);
    }
    fclose(input);
    fclose(output);
    return 0;
}