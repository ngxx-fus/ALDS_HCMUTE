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

//T is an iterator or pointer
//pivot is the end element of original sequence.
//Aviable sort range : [p, r)
template<typename T>
T partition(T p, T r){
    //invalid range when the sequense empty or
    //- have only one element (r-p == 0 is true)
    //- either p or r is nullptr 
    //- have only one  element! (r-p == 1 is true)
    //based case:
    if( (r-p) <= 1 ) return r; 
    if( (r-p) == 2)
        if( *p<*(r-1) ) return (r-1);
        else{
            exchange(*p, *(r-1));
            return p;
        }
    //initializing
    T i = r;//r as null :>
    //random
    T pivot = r-1;
    //the range of the greater than pivot elements  
    // is (i, j)
    for( T j = p; j != pivot && i != pivot; j++){
        if( *j <= *pivot){
            if(i == r){
                i = j;
            }else{
                ++i;
                exchange(*i, *j);
            }
        }
    }
    //Now, the range of the greater than pivot elements 
    //is (i, j]. onsist of j!  j is the true index of the of the pivot.
    //If (i, j] is not invalid, then the last step
    //is exchange(*i, *pivot). 
    //Call that case is "normal case"!

    //if the range (i, j] is invalid ranged such as:
    // i == r (r as null :>) then the true of the index of pivot is p :> 
    // because the pivot is the mininum element of original sequence.
    // in this case, the last step is set i = p and exchange(*i, *pivot)
    // (note: i = pivot-1 = j  ;>)

    // i == j then then the true of the index of pivot is pivot (r-1) :> 
    // because the pivot is the maxinum element of original sequence
    // Such as "normal case", the last step is increase i by add 1, and exchange(*i, *pivot)
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
    vector<int> v = {1,4,5,2,3,-1,4,10,6,8,7,5,5};
    quick_sort(v.begin(), v.end());  
    for(auto p:v) printf("%-3d", p);
return 0;
}