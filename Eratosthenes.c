/*
Name: Sum primes from 2 to N (N=1e9)
Author: Nguyen Thanh Phu
Programming language: C - version: C17
Reference algorithm from:  The sieve of Eratosthenes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include <stdbool.h>
#include <float.h>
#include <limits.h>

typedef unsigned long long uint64;
time_t b, e;
uint64 called = 0;

int main(){
    b = clock();
    //---------------- begin of code -------------------
    uint64 ans=0;
    uint64 n = 1000000000llu;
    bool *is_prime = (bool*) (malloc(n));
    memset(is_prime, 1, n);

    for(uint64 p = 2; p <= n; p++){
        if( is_prime[p] == false )continue;
        ans += p;
        uint64 multiple_of_p = p*p;
        while( multiple_of_p <= n ){
            ++called; // counting
            is_prime[ multiple_of_p ] = false;
            multiple_of_p += p;
        }
        while(is_prime[n]==false) --n;
    }
    free(is_prime);
    //---------------- end of code -------------------
    e = clock();
    printf("No. of call to \"is_prime[...]\": \n> %llu\n", called);
    printf("Total exe time: \n> %0.9f (s)\n", 1.0f * (e - b) / CLOCKS_PER_SEC);
    printf("Result: \n> %llu\n", ans);
}