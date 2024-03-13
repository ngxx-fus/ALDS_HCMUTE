#include<bits/stdc++.h>
using namespace std;


int get_max(int a, int b){
    return (a>b)?a:b;
}
int get_min(int a, int b){
    return (a<b)?a:b;
}
int compare(){
    return 0;
}
template< typename T, typename First, typename... Args>
int compare(T mode, First first, Args ... args){
    int res = first;
    if(mode == 0){
        res=get_max(res, compare(args...));
    }
        res=get_min(res, compare(args...));
    return res; 
}

int main()
{
    cout << compare(0,2,3,4,5,-8,10, 43) << "\n";
}