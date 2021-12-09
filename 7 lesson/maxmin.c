#include "maxmin.h"

#ifndef MAX
#define MAX(a,b) ((a)>(b)?a:b)
#endif
#ifndef MIN
#define MIN(a,b) ((a)<(b)?a:b)
#endif

pair MaxMin(int A[], int L, int H){
    pair ret1, ret2, ret;

    if(L == H){
        ret.max = A[L];
        ret.min = A[L];
    } else if(L == H - 1){
        if(A[L] < A[H]){
            ret.max = A[H];
            ret.min = A[L];
        } else{
            ret.max = A[L];
            ret.min = A[H];
        }
    } else{
        int middle = (H + L)/2;

        ret1 = MaxMin(A, L, middle);
        ret2 = MaxMin(A, middle + 1, H);

        if(ret1.max > ret2.max){
            ret.max = ret1.max;
        } else{
            ret.max = ret2.max;
        }
        if(ret1.min < ret2.min){
            ret.min = ret1.min;
        } else{
            ret.min = ret2.min;
        }
    }

	/*pair ret;

    int max = A[0], min = A[0];
    for(int i = 0; i <= H; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    for(int i = 0; i <= H; i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    ret.min = min;
    ret.max = max;*/
    
	return ret;
}
