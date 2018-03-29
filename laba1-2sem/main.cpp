#include <iostream>
#include "MMATH.H"

#pragma comment (lib, "mmath32m.lib")

int main(){
M_LONG P = { 16, 0x6f18544d, 0xedb374f5, 0xffbc3bcc, 0x7249bb52,
0xb09152ec, 0x9551dc2c, 0x7f6e2853, 0xa4dba914,
0xa9bd6e9b, 0x70cd54ce, 0x31fe7bd3, 0xcc61f6d2,
0x5d45c7fc, 0x11a20acc, 0x39b8708c, 0x9df3ef1d },
Q = { 16, 0xab74d85d, 0x8e352852, 0xf440ab72, 0x790f53f3,
0xb51fbad0, 0x10555a11, 0xd79b004c, 0x90ca7e6c,
0x8bcca0b1, 0xba0262f8, 0xc2e3603d, 0x52e68e5e,
0xb4a22921, 0xa234ee79, 0x5ae28905, 0xf5fe50db };

M_LONG H = {1,4};

M_LONG N, E, D, C, FN, M1;
m_mul(P, Q, N);
P[1] = P[1] - 1;
Q[1] = Q[1] - 1;
m_mul(P, Q, FN);
m_rand(E, FN[0] - 1);
E[1] |= 1;

while (m_inv(E, FN, D) || m_cmp(E, D) == 0)
{
m_add(E, H, E);
}

m_blockpowmod(H, E, N, C);
m_blockpowmod(C,D,N,M1);
int a = m_cmp(H, M1);

if (a != 0)
  std::cout << "crash" << std::endl;
else
  std::cout << "done" << std::endl;



return 0;

}
