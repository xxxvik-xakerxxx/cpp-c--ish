#include <iostream>
#include "./libs/MMATH.H"

void stepleft(M_LONG X, M_LONG K, M_LONG N, M_LONG M){
    M_LONG  Y,Z;
    unsigned int S = K[K[0]];
    int i;
    for(i=31; i>0; i--){
        if (S & (1<<i)) break;
        if (i==0){
            i=31;
            S= K[0]=1;
        }
        else {
            i--;
            S=K[0];
        }
        m_copy(M,X);
        for( ; S>0; S--){
            for( ; i>0; i--){
                m_sqr(M,Y);
                m_div(Y,N,Z,M);
                if(K[S] & (1<<i)){
                    m_mul(M,X,Y);
                    m_div(Y,N,Z,M);

                }
            }
            
        }
        i=31;
    }
}

int main(){
    

    return 0;
}