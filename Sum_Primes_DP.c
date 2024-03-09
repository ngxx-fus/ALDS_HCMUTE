/*
Name: Sum primes from 2 to N (N=1e9)
Author: Nguyen Thanh Phu
Programming language: C - version: C17
Reference algorithm from:  Lucy_Hedgehog  (https://projecteuler.net/thread=10;page=5)
*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <math.h>

time_t b, e;
unsigned long long called = 0;

//---------------- begin of external code -------------------
typedef unsigned long long uint64;
typedef unsigned int uint32;
#define floor64(x) ((unsigned long long)(x))
#define rep64(i, a, b) for( unsigned long long i = (a); i <= (b); ++i)
#define rep32(i, a, b) for( unsigned int i = (a); i <= (b); ++i)

#define S(x) Data[(index_at_(x, V, v_size))]
uint32 index_at_(uint64 key, uint64* arr, uint32 arr_size) {
    //range [l, r] in V 
    ++called;
    uint64* mid, * l = arr, * r = arr + arr_size - 1;
    while (r - l >= 0) {
        if (r - l == 0) if (*l == key) return l - arr; else return arr_size;
        mid = l + (r - l) / 2;
        if (*mid == key) {
            //found the index
            return mid - arr;
        }
        if (*mid < key) r = mid - 1;
        else  l = mid + 1;
    }
    return arr_size;
}
//---------------- end  of external code -------------------

int main() {
    b = clock();
    //---------------- begin of code -------------------
    uint64 ans = 0;
    uint64 n = 1e9;

    if(n < 2) {printf("Invalid input!\n"); return 0;}
    //4 : reservation
    uint32 max_size_v = 2 * floor(sqrt(n)) + 1 + 4;
    //not total of the program!
    uint32 v_size = 0;

    //initializing V array (consist of reservation  elements )
    //V contain 2*sqrt(N)+1 terms that we need to check, 
    //not N terms!
    uint64* V = (uint64*)malloc(max_size_v * sizeof(uint64));
    //if allocation is failed -> exit
    if (V == NULL) { printf("Cannot allocate memory - V!\n"); return(0); }
    //Computing value for V array
    rep64(k, 1, floor64(sqrt(n)) + 1)  V[v_size++] = floor64(n / k);
    do { V[v_size] = V[v_size - 1] - 1; } while (V[v_size++] != 0);

    //Initializing Data array (consist of reservation elements )
    uint64* Data = (uint64*)malloc(max_size_v * sizeof(uint64));
    //if allocation is failed -> exit
    if (Data == NULL) { free(V); printf("Cannot allocate memory - Data!\n"); return(0); }

    //Computing the initail value for each S[v],  v in V.
    rep32(i, 0, v_size - 1) Data[i] = V[i] * (V[i] + 1) / 2 - 1;

    rep64(p, 2llu, floor64(sqrt(n)) + 1) {
        uint64 sum_primes_curr = S(p);
        uint64 sum_primes_prev = S(p - 1);
        uint64 p_squared = p * p;
        if (sum_primes_curr > sum_primes_prev) { //p is prime
        //removing the multiples of p 
        //Ex:p^2, p^2+p, p^2+2p, ..., V[i]
            rep32(i, 0, v_size-1) {
                if (V[i] < p_squared) break; // for all p < sqrt(V[i])
                Data[i] -= p * (S(V[i] / p) - sum_primes_prev);
            }
        }
    }
    ans = Data[0];

    free(V);
    free(Data);

    //---------------- end of code -------------------
    e = clock();
    printf("V,Data array size: \n> %u\n", max_size_v);
    printf("Mem using by V, Data array (calc):  \n> %u(Bytes)\n", 2*max_size_v*8+300);
    printf("No. of call to \"index_at_\": \n> %llu\n", called);
    printf("Total exe time: \n> %0.9f (s)\n", 1.0f * (e - b) / CLOCKS_PER_SEC);
    printf("Result: \n> %llu\n", ans);
}
