#include "stdafx.h"
#include <mmath.h>
#include <iostream>
#include <intrin.h>

int _tmain()
{
	M_LONG P = {16,	0x6f18544d,0xedb374f5,0xffbc3bcc,0x7249bb52, 
					0xb09152ec,0x9551dc2c,0x7f6e2853,0xa4dba914, 
					0xa9bd6e9b,0x70cd54ce,0x31fe7bd3,0xcc61f6d2, 
					0x5d45c7fc,0x11a20acc,0x39b8708c,0x9df3ef1d}; 


	M_LONG x, a;
	m_rand(x, P[0]-1);
	m_rand(a, P[0]-1);

	M_LONG m;
	m_rand(m, P[0]-1);
	int L = 1000;
	int Lk = 50;
	
	M_LONG z, z1, z2, z3, z4, z5,y_i, b_i;
	
	unsigned _int64 tic1,tic2,tic_m1,tic_m2,tic_m_m1=999999999999,tic_m_m2=999999999999,s1=0, s2=0;

	for (int i=0;i<L;i++)
	{
		
		m_rand(y_i, P[0]-1);
		m_rand(b_i, P[0]-1);
		for(int i_1=0;i_1<Lk;i_1++)
		{
			tic1 = __rdtsc();
			m_blockmontpowmod2(x,y_i,a,b_i,m,z);
			tic2 = __rdtsc();
			tic_m1 = tic2-tic1;
			//---------------------------------
			tic1 = __rdtsc();
			m_blockmontpowmod(x,y_i,m,z1);
			m_blockmontpowmod(a,b_i,m,z2);
			m_mul(z1,z2,z3);
			m_div(z3,m,z4,z5);
			tic2 = __rdtsc();
			tic_m2 = tic2-tic1;
			//----------------------------------
			tic_m_m1=(tic_m_m1>tic_m1)?tic_m1:tic_m_m1;
			tic_m_m2=(tic_m_m2>tic_m2)?tic_m2:tic_m_m2;
		}
		s1+=tic_m_m1;
		s2+=tic_m_m2;
		tic_m_m1=999999999999;
		tic_m_m2=999999999999;
	}
	std::cout<<s1/L<<"\t"<<s2/L<<"\n";

	return 0;
}

