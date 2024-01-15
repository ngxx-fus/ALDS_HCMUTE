#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define rep(i, begin, end) for( int i = (begin); i <= (end); i++)
#define rev(i, begin, end) for( int i = (begin); i >= (end); i--)
#define rand_in(min, max) (rand()%(max-min)+min)

void insertion_sort(int *arr, int size_ ){
    if( size_ < 2 ) return;
    for(int i = 1; i < size_; i++){
        int key = arr[i];
        int  j = i - 1;
        while( j > 0 && arr[j] > key ){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

int32_t main(){
    int arr[] = {1,6,5,4,2,5,6,7,8,5,3,2};
    int size_ =  sizeof(arr)/sizeof(int);
    insertion_sort(arr, size_);
    rep(i, 0, size_-1){
        cout << arr[i] << " ";
    }
return 0;
}