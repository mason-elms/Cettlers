#ifndef BOARD_HELPER_H_
#define BOARD_HELPER_H_

#include "types.h"

// Gah... Mersenne Twister PRNG *sigh* there is existing pure c for this buuuuut I'm gonna try to do this myself
// C code provided in paper linked here: chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/ARTICLES/mt.pdf Appendix C
// I don't need quite that degree of size and I may want this to run on smaller machines... need to understand it to move to 16bit though lol. later!
#define N 624
#define M 397
#define MATRIX_A 0x9908b0df
#define UPPER_MASK 0x80000000
#define LOWER_MASK 0x7fffffff
#define MASK_B 0x9d2c5680
#define MASK_C 0xefc60000

static uint_32 mt[N];
static int mti = N+1;

void sgenrand( uint_32 seed)
{
    mt[0] = seed & 0xffffffff;
    for (mti = 1; mti < N; mti++) {
        mt[mti] = 69069 * mt[mti-1] & 0xffffffff;
    }
}

uint_32 genrand()
{
    uint_32 y;
    static uint_32 mag_01[2] = {0x0, MATRIX_A};
    if (mti >= N) {
        int kk;

        if (mti == N+1) {
            sgenrand(3797);
        }

        for (kk = 0; kk < N-M; kk++) {
            y = (mt[kk] & UPPER_MASK) | (mt[kk+1] & LOWER_MASK);
            mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag_01[y & 0x1];
        }

        for (; kk < N; kk++) {
            y = (mt[kk] & UPPER_MASK) | (mt[kk+1] & LOWER_MASK);
            mt[kk] = mt[kk + (M-N)] ^ (y >> 1) ^ mag_01[y & 0x1];
        }

        y = (mt[N-1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
        mt[N-1] = mt[M-1] ^ (y >> 1) ^ mag_01[y & 0x1];

        mti = 0;
    }

    y = mt[mti++];

    y ^= (y >> 11);
    y ^= (y << 7) & MASK_B;
    y ^= (y << 15) & MASK_C;
    y ^= (y >> 18);

    return y;
}

uint_32 biased_int_mul_bounded_rand(uint_32(*functionPointer)(void) , uint_32 range)
{
    //making this a function pointer in case I wanna use something else later. Unecessary? perhaps.
    uint_32 rand = functionPointer();
    uint_64 loooooong =  (uint_64) rand * (uint_64)range;
    return loooooong >> 32;
}

void swap_in_place_int(uint_32 *arr, uint_32 idx1, uint_32 idx2)
{
    uint_32 tmp1 = *(arr+idx1);
    *(arr+idx1) = *(arr+idx2);
    *(arr+idx2) = tmp1;
}

void fisher_yates_shuffle(uint_32 *permutation, uint_32 n)
{
    uint_32 i;
    for (i = 0; i < n-2; i++) {
        uint_32 j = i + biased_int_mul_bounded_rand(&genrand, n-i);
        swap_in_place_int(permutation, i, j);
    }

}
#endif