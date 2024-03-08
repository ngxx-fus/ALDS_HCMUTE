#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include <stdbool.h>
#include <float.h>
#include <limits.h>
#include <math.h>

typedef unsigned long long uint64;
typedef unsigned int uint32;
#define floor64(x) ((unsigned long long)(x))
#define floor32(x) ((unsigned int)(x))
#define rep64(i, a, b) for( unsigned long long i = (a); i <= (b); ++i)
#define rep32(i, a, b) for( unsigned int i = (a); i <= (b); ++i)

time_t b, e;

int main(){
    b = clock();
    //---------------- begin of code -------------------
    uint64 ans=0; 
    uint64 n = 20llu;
    
    uint32 max_size_v = 2*floor32(sqrt(n))+1+4;
    uint32 v_size = 0;
    uint64* V = (uint64*)malloc( max_size_v*sizeof(uint64));
    if( V == NULL ) {printf("Cannot allocate memory!\n"); return(0);}
    rep64(k, 1, floor64(sqrt(n))+1)  V[v_size++] = floor64(n/k);
    do { V[v_size] = V[v_size-1]-1; } while(V[v_size++] != 0);

    uint64* S = (uint64*)malloc( n*sizeof(uint64));
    if( S == NULL ) {free(V); printf("Cannot allocate memory!\n"); return(0);} 
    rep32(i, 0, v_size-1) S[ V[i] ] = V[i] * (V[i]+1) / 2 - 1;

    rep64( p, 2llu, floor64(sqrt(n))+1){
        if( S[p] > S[p-1] ){
            uint64 sum_primes = S[p-1];
            uint64 p_squared = p*p;
            rep32(i, 0, v_size-1){
                if( V[i] < p_squared ) break;
                S[V[i]] -= p * (S[V[i] / p] - sum_primes);
            }
        }
    }
    ans = S[n];

    free(V);
    free(S);
    //---------------- end of code -------------------
    e = clock();
    printf("res: %llu\n", ans);
    printf("time: %0.9f", 1.0f*(e-b)/CLOCKS_PER_SEC);
}