#include<stdio.h>

#define abs(x) (x<0.0?(-1.0)*(x):(x))

static unsigned  int steps_count = 0;

double sqrt_(const double y, const double delta=0.0001f){
    double res;
    //processing:
    for(double rev = y/2; abs(rev*rev - y) > delta ; res = rev){
        steps_count++;
        rev = 0.5*(rev+y/rev);
    }
    return res;
}

int main(){
    double y = 12981235.124, delta = 0.0001;
    printf("# delta = %lf \n# sqrt(%lf) = %lf\n", delta, y, sqrt_(y, delta));
    printf("steps: %d", steps_count);
}
