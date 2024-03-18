#include<bits/stdc++.h>
using namespace std;
#define rep(i, begin, end) for( int i = (begin); i <= (end); i++)
#define rev(i, begin, end) for( int i = (begin); i >= (end); i--)
#define max_(a,b) ((a>b)?a:b)
#define min_(a,b) ((a>b)?b:a)



namespace user_def{
    template<typename T> class stack;
};
template<typename T> class user_def::stack{
private:
    uint32_t size_;
    uint32_t limited_size_ ;
    class iter{
        iter* next;
        iter* prev;
        T key;
    public:
        iter(T key){
            next = nullptr;
            prev = nullptr;
            this->key = key;
        }
        T &_key(){
            return key;
        }
        void new_next(T key){
            next = new iter(key);
        }
        void new_prev(T key){
            prev = new iter(key);
        }
        iter* &next_pointer(){
            return next;
        }
        iter* &prev_pointer(){
            return prev;
        }
        void del_next(iter* &it = nullptr){
            if( it == nullptr ) return;
            if( it->next_pointer() != nullptr )
                del_next(it->next_pointer());
            delete it;
            it = nullptr;
        }
        void del_prev(iter* &it = nullptr){
            if( it == nullptr ) return;
            it->prev_pointer();
            if( it->prev_pointer() != nullptr )
                del_prev(it->next_pointer());
            delete it;
            it = nullptr;
        }
    } *root;
public:
    stack(){
        this->root = nullptr;
        this->size_ = 0;
        this->limited_size_ = (+1000000000LLU)/sizeof(T);
    }
    //push an element
    void push(T key){
        if(size_ > limited_size_ ){
            cout << "Cannot push the element!";
            cout << "(The size of stack is limited at: ";
            cout << limited_size_ << "!)\n";
        }
        if(size_ == 0){
            root = new iter(key);
        }else{
            root->new_next(key);
            iter *tmp = root->next_pointer();
            tmp->prev_pointer() = root;
            root = tmp;
        }
        ++size_;
    }
    void pop(){
        if(size_ == 0) return;
        if(size_ == 1){
            size_ = 0;
            delete root;
            return;
        }
        root = root->prev_pointer();
        root->del_next(root->next_pointer());
        
        --size_;
    }
    //get size_
    uint32_t size(){
        return size_;
    }
    //get size_
    uint32_t max_size(){
        return limited_size_;
    }
    //access to top term
    T& top(){
        return root->_key();
    }
    bool empty(){
        return (size()==0lu);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("out.txt","w",stdout);
    user_def::stack<int> st;
    cout << "Max size: " << st.max_size() << "\n";
    srand(time(0));
    rep(i,1,10) {
        int t = rand()%100;
        st.push(t);
        cout << t << "\n";
    }
    cout << "Current size: " << st.size() << "\n";
    cout << "\n\nPop and show\n\n" << "\n";
    while(!st.empty()){
        cout << st.top() << '\n';
        st.pop(); 
    }
return 0;
}
