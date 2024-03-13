#include<stdio.h>

#define abs(x) (x<0.0?(-1.0)*(x):(x))

static unsigned  steps_count = 0;

double sqrt_(const double y, const double delta=0.0001f){
    if(y < 0 ) return -1;
    double l = 0.0f, r = y/2.0f;
    double res = 0.0;
    //processing:
    for(double mid = (l+r)/2.0f; abs(mid*mid - y) > delta ;  mid = (l+r)/2.0f){
        steps_count++;
        if( mid*mid - y > delta ) r = mid-delta;
        else  /*  if(mid*mid - y < delta ) */ l = mid+delta;
        res=mid;
    }
    return res;
}

int main(){
    double y = 12981235.124, delta = 0.0001;
    printf("# delta = %lf \n# sqrt(%lf) = %lf\n", delta, y, sqrt_(y, delta));
    printf("steps: %d", steps_count);
}


/*
sqrt(y) = x
Thì ta biết rằng x nằm trong đoạn [0, y]
Ta sẽ mô hình hoá khoảng chứa nghiệm x là đoạn [L,R].
Gọi: 
    x_final là nghiệm chính xác(giả định nó tồn tại để lập luận), 
    x_mid là nghiệm cần tìm, mang tính chất xấp xỉ x_final. 
    delta = | x_mid^2 - y | là độ chính xác.

Ứng dụng tìm kím nhị phân:
-> Ta giả sử nghiệm ở chính giữa đoạn [L,R].  
Tức x_mid = (L+R)/2, xét ba trường hợp sau:
        TH1:                  | x_mid^2 - y | <= delta  (Trường hợp ưu tiên xét)
                Như vậy nghiệm của bài toán là x_mid.
        TH2:
                                x_mid^2 - y  > delta
                Giá trị của x_mid lớn hơn x_final nhiều,
                Nên ta sẽ loại bỏ khoảng [x_mid, R] 
                Và tiếp tục thực hiện lại các thao thác 
                trên đoạn [L, x_mid-delta].
        TH3:
                                x_mid^2 - y  < delta
                Giá trị của x_mid nhỏ x_final hơn nhiều,
                Nên ta sẽ loại bỏ khoảng [x_mid, R] 
                Và tiếp tục thực hiện lại các thao thác 
                trên đoạn [L, x_mid-delta].
Trường hợp TH2, TH3 được lặp lại tới khi nào tìm được 1 nghiệm thoả
| x_mid^2 - y | <= delta.
delta càng bé thì thuật toán chạy càng lâu!
*/