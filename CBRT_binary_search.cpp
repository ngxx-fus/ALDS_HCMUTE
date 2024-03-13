#include<stdio.h>

#define abs(x) (x<0.0?(-1.0)*(x):(x))

static unsigned  steps_count = 0;

double cbrt_(const double y, const double delta=0.0001f){
    if(y < 0 ) return -1;
    double l = 0.0f, r = y/2.0f;
    double res = 0.0;
    //processing:
    for(double mid = (l+r)/2.0f; abs(mid*mid*mid - y) > delta ;  mid = (l+r)/2.0f){
        steps_count++;
        if( mid*mid*mid - y > delta ) r = mid-delta;
        else  /*  if(mid*mid - y < delta ) */ l = mid+delta;
        res=mid;
    }
    return res;
}

int main(){
    double y = 298897.0001, delta = 0.0001;
    printf("# delta = %lf \n# sqrt(%lf) = %lf\n", delta, y, cbrt_(y, delta));
    printf("steps: %d", steps_count);
}

