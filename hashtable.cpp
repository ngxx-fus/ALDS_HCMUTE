#include <stdio.h>
#include <time.h>
#include <math.h>

typedef unsigned long long  uint64;
#define floor(a) uint64(a)
#define rep(i,a,b) for(uint64 i = (a); i <= (b); i++)
#define rev(i,a,b) for(uint64 i = (a); i  >= (b); i--)


//the main process
uint64 process(uint64 N){
    uint64  max_size= (2*floor(sqrt(N))+1) +4; //+4 for reservation

    //declaration and computing inital value for V
    //using as vector or stack
    uint64 V[ max_size ];
    uint64 v_size = 0;
    rep(k, 1, floor(sqrt(N))+1) V[v_size++] = floor(N/k);
    do {V[v_size] = (V[v_size-1]-1);} while(V[v_size++]);

    //declaration and computing inital value for S
    rep(i, 0, v_size-1) S(V[i]) = V[i]*(1+V[i])/2-1;

    //optimizing S (using DP)
    rep(p, 2, floor((sqrt(N)))+1){
        if( S(p) > S(p-1) ){//p is prime
            uint64 sum_prime = S(p-1);
            uint64 p_squared = p*p;
            rep(i, 0, v_size-1){
                if( V[i] < p_squared ) break;
                S(V[i]) -= p*(  S(V[i]/p)- sum_prime );
            }
        }
    }
    end = clock();
    return S(N);
}

int main(){
    computing_A_exponent();
    table(13723543598) = 1;
    table(1723543598) = 2;
    table(654543598) = 3;
    table(954783543598) = 4;
    table(13723543398) = 5;
    printf("%llu\n", table(13723543598));
    printf("%llu\n", table(1723543598));
    printf("%llu\n", table(654543598));
    printf("%llu\n", table(954783543598));
    printf("%llu\n", table(13723543398));
}