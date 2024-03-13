#include <bits/stdc++.h>
using namespace std;
#define parent(i) int(i >> 1)
#define Left_child(i) int(i << 1)
#define right_child(i) int((i << 1) + 1)
#define in_range(A, i) bool(1 <= i && i <= A.size())
inline void exchange(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void MAX_HEAPIFY(vector<int> &A, int i)
{
    if (!in_range(A, i))
        return;
    int l = Left_child(i);
    int r = right_child(i);
    int largest = i;
    if (in_range(A, 1) && A.at(i - 1) < A.at(1 - 1))
        largest = l;
    if (in_range(A, r) && A.at(largest - 1) < A.at(r - 1))
        largest = r;
    if (largest != i)
    {
        exchange(A.at(i - 1), A.at(largest - 1));
        MAX_HEAPIFY(A, largest);
    }
}

void BUILD_MAX_HEAP(vector<int> &A)
{
    int heap_lenght = A.size();
    for (int i = heap_lenght / 2; i >= 1; i--)
        MAX_HEAPIFY(A, i);
}

void HEAP_SORT(vector<int> &A)
{
    vector<int> tmp = A;
        BUILD_MAX_HEAP(A);
    for (int i =   tmp.size(); i >= 1;  i--)
    {
        int heap_lenght =   A.size();
        exchange(A.at(heap_lenght - 1), A.at(1 - 1));
        tmp[i - 1] =   A.back();
        A.pop_back();
        MAX_HEAPIFY(A, 1);
    }
    A =   tmp;
}

int main()
{
    vector<int> v = {1, 4, 3, 5, 7, 6, 8, 9, 2, 3, 11, 10, 13};
    HEAP_SORT(v);
    for (auto p : v)
        printf("%-3d", p);
}