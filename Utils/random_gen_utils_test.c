#include "random_gen_utils.h"
#include <stdio.h>

#define RANGE_SIZE 19
#define MAX_IDX 18
int main(int argc, char* argv[])
{
    int range = 18;
    sgenrand(1477);

    //arr to count uniform vals:
    uint_16 uniform_counts[RANGE_SIZE] = {0};

    printf("-------- UNIFORM GENERATION --------\n");
    uint_32(*mt_func)() = &genrand;
    uint_32 oob_ctr = 0;

    for (int j = 0; j<10000; j++) {
        uint_32 uniform = biased_int_mul_bounded_rand(mt_func, RANGE_SIZE);
        uniform_counts[uniform]++;
        if (uniform > MAX_IDX) {
            oob_ctr++;
        }
    }

    for (uint_16 i = 0; i< RANGE_SIZE; i++ ) {
        printf("%u: %u\n", i, uniform_counts[i]);
    }

    printf("Num out of bounds: %lu\n", oob_ctr);
    printf("--------------------------------------\n\n");
    printf("-------- FISHER YATES ---------\n");

    uint_32 permutation_arr[RANGE_SIZE];
    printf("[");
    for ( uint_16 k = 0; k < RANGE_SIZE; k++) {
        permutation_arr[k] = k;
        printf("%u ", k);
    }
    printf("]\n");

    sgenrand(88);

    fisher_yates_shuffle(permutation_arr, RANGE_SIZE);



    printf("[");
    for ( uint_16 l = 0; l < RANGE_SIZE; l++) {
        printf("%lu ", permutation_arr[l]);
    }
    printf("]\n");

    return 0;

}