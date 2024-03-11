#include<iostream>
#include<vector>
#include<random>
#include<time.h>

using namespace std;
#define rep(i, begin, end) for( int i = (begin); i <= (end); i++)
#define rev(i, begin, end) for( int i = (begin); i >= (end); i--)
#define max_(a,b) ((a>b)?a:b)
#define min_(a,b) ((a>b)?b:a)

template<typename T>
void exchange(T &a, T &b){ T tmp = a; a = b; b = tmp;}

template<typename T>
T random_pivot(T p, T r){
    unsigned int _size = r-p;
    if( _size <= 2  ) return r-1;
    srand(time(0));
    unsigned int _delta = rand()%_size;
    exchange(*(p+_delta), *(r-1));
    return r-1;
}

template<typename T>
T partition(T p, T r){
    if( (r-p) <= 1 ) return r; 
    if( (r-p) == 2){
        if( *p < *(r-1) ) return (r-1);
        else{
            exchange(*p, *(r-1));
            return p;
        }
    }
    T i = r;//r as NULL
    T pivot = random_pivot(p, r);
    for( T j = p; j != pivot && i != pivot; j++){
        if( *j <= *pivot){
            if(i == r){
                i = p;
            }else{
                ++i;
            }
            exchange(*i, *j);
        }
    }
    if( i == r){
        exchange(*p, *pivot);
        return (pivot=p);
    }
    exchange(*(++i), *pivot);
    return (pivot = i);
}

//aviable sort range: [begin_, end_)
template<typename T>
void quick_sort(T begin_, T end_){
    T pivot = partition(begin_, end_);
    if( pivot == end_ ) return;
    for( T tmp = begin_; tmp != end_; tmp++)        cout << *tmp << ' ';    cout << '\n';
    quick_sort(begin_, pivot);
    quick_sort(pivot+1, end_);
}

int main(){
    vector<int> v = {1,4,5,2,3,-1,4,10,6,8,7,5,5, -11, -19, -3, 8, 10,13,-17};
    quick_sort(v.begin(), v.end());  
    for(auto p:v) printf("%-4d", p);
return 0;
}