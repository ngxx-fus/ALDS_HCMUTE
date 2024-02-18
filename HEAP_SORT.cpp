#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class TYPE>
class my_heap{
    private:
    //--------------------------------------------------------------------
    template<typename T>  T get_max(T a, T b){return ((a>b)?a:b);}
    template<typename T>  T get_min(T a, T b){return ((a<b)?a:b);}
    template<typename T> void exchange(T &a, T &b){T tmp = a; a =b, b =tmp;}
    //--------------------------------------------------------------------
    // T is the place where heap is storaged
    vector<TYPE> T;
    // 0: max-heap and 1: min-heap
    bool mode;
    bool constructed;
    template<typename FIRST>FIRST compare(FIRST t){return t;}
    template<typename FIRST, typename ...Args>
    FIRST compare(FIRST first, Args ...args)
    {   FIRST res = first;
        if(mode == 0){
            res=get_max(res, compare(args...));
            return res;
        }
        res=get_min(res, compare(args...));
        return  res;
    }
    int parent( int i ){        return (i>>1);    }
    int left_child( int i ){        return (i<<1);    }
    int right_child( int i ){        return ((i<<1)+1);    }
    bool in_range(int i){        return (1 <= i && i <= (T.size()-1));    }

    //return true if the node at the index were "heapified", and vice versa.
    bool HEAPIFY(int i){
        if( !in_range(i) || size() < 2) return false;
        bool heapified = false;                      
        int l = left_child(i),
             r = right_child(i);
         //key is "largest" in max-heap and "smallest" in min-heap
        int key = i;
        if( in_range(l) && T[i] != compare(T[i], T[l]) ){
            key = l;
        }
        if( in_range(r) && T[key] !=  compare(T[key], T[r]) ){
            key = r;
        }
        if( key != i){
            heapified = true;
            exchange(T[i], T[key]);
            HEAPIFY(key);
        }
        return heapified;
    }

    bool BUILD_HEAP(){
        if(T.size() <= 1 ) return false;
        for(int i = size()/2; i >= 1; i--){
            HEAPIFY(i);
        }
        return true;
    }

    public:
    my_heap(){
        this->mode = false;//default for max-heap
        this->constructed = false;
        this->T.push_back(TYPE(-1));
    }
    my_heap(string mode){
        this->mode = ((mode=="max")?false:true);//default for max-heap
        this->constructed = false;
        this->T.push_back(TYPE(-1));
    }
    /*
    Build heap from vector<int> v,
    mode = "max" for max-heap
    mode = "min" for min-heap
    */
    my_heap(vector<TYPE> v, string mode = "max"){
        T.push_back(-1);//index 0 is not used!
        if(mode.compare("max") == 0) this->mode = 0;
        else this->mode = 1;
        for(auto val:v) this->insert(val);
        constructed = BUILD_HEAP();
    }
    unsigned int size(){
        return (T.empty()) ? 0 : (T.size()-1);
    }
    //mode 0  for max-heap
    //mode 1 for min-heap
    void set_mode(bool mode){
        if(this->mode != mode) constructed = false;
        this->mode = mode;
        constructed = BUILD_HEAP();
    }
    vector<TYPE> get_tree(){
        return vector<int>(T.begin()+1, T.end());
    }
    void insert(TYPE val){
        T.push_back(val);
        for( int index = parent(size()); index >=1; index = parent(index)){
            if(HEAPIFY(index) == false) break;
        }
    }
    TYPE top(){
        if( T.size() > 1)   return T.at(1);
        exit(-1);
        return -1;
    }
    void pop(){
        if(this->size()>=2){
            exchange(T.at(1), T.back() );
           T.pop_back();
            HEAPIFY(1);
        }else
            T.pop_back();
    }
    //Heap will be cleared after sort!
    vector<TYPE> get_sort(){
        vector<TYPE> v;
        while(this->size()) {
            v.push_back(this->top());
            this->pop();
        }
        return v;
    }
};

int main(){
    freopen("output.txt", "w", stdout);
    vector<int> v = {-54,3,21,5,-67,4,23,2,6,7};
    v = my_heap<int>(v).get_sort();
    for( auto p:v) cout << p << ' ';
}