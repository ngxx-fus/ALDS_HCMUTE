#include<bits/stdc++.h>
using namespace std;
#define rep(i, begin, end) for( int i = (begin); i <= (end); i++)
#define rev(i, begin, end) for( int i = (begin); i >= (end); i--)

void merge_two_sequense(int *tmp_arr, 
                                                    int *left_arr_b, int *left_arr_e, 
                                                    int *right_arr_b, int *right_arr_e){//b: begin and e: end
    
    int   *p_tmp = tmp_arr, 
            *p_left = left_arr_b,
            *p_right =right_arr_b; 
    //merge left_arr and right_arr into tmp_arr
    while( p_left != left_arr_e && p_right != right_arr_e){
        if( *p_left < *p_right){
            *(p_tmp++) = *(p_left++);
        }else{
            *(p_tmp++) = *(p_right++);
        }
    }
    while( p_left != left_arr_e ) *(p_tmp++) = *(p_left++);
    while( p_right != right_arr_e ) *(p_tmp++) = *(p_right++);

    //move merged array in tmp_arr into {left_arr+right_arr}
    p_tmp = tmp_arr, 
    p_left = left_arr_b,
    p_right = right_arr_b;
    while( p_left != left_arr_e) {
        *p_left = *p_tmp;
        ++p_left;
        ++p_tmp;
    }
    while( p_right != right_arr_e){
        *p_right = *p_tmp;
        ++p_right;
        ++p_tmp;
    }
}

void devide_and_merge(int *tmp_arr, int *left, int *right){
    //sort range: [left, right)
    //size = 0 or size = 1
    if (right - left < 2) return;
    //size = 2
    if (right - left == 2){
        if( *left < *(right-1)) 
            return;
        else{
            int tmp_val = *left;
            *left = *(right-1);
            *(right-1) = tmp_val;
        }
    }
    //size >= 3
    int *mid = left + (right-left)/2;
    devide_and_merge(tmp_arr, left, mid);
    devide_and_merge(tmp_arr, mid, right);
    merge_two_sequense(tmp_arr, left, mid, mid, right);
}

void merge_sort(int *left, int *right){
    int *tmp_arr = new int[(right-left+1) + 4];//4 for padding :>
    devide_and_merge(tmp_arr, left, right);
    delete[] tmp_arr;
}

int32_t main(){
    int arr[] = {1,2,3,4, 1,2,3,4,0,0,0};
    int tmp[18];
    merge_sort(arr+2, arr+6);
    rep(i, 0, 10) cout << arr[i] << " ";   
return 0;
}

//arr + (arr+5)  ---->   0 1 2 3 4S