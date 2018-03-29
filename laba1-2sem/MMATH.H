/*******************************************************************
Библиотека многократной арифметики MMATH v. 1.12 (12 августа 1996 г.)
(С) АО "ИИТ" (г. Харьков)
  Файл MMATH.H
*************************************************************************/

#ifndef __MMATH_H32VC
#define __MMATH_H32VC

#include "mdef.h"

#define m_len(X) ((int)X[0])
        // Длина X в блоках

#define m_ifzero(X) ((X)[0]==1 && (X)[1] == 0)
        // X==0 ?

#define m_odd(X) ((X)[1] % 2 == 1)
        // X - нечетное ?
#define m_msb(X) (X[(int)X[0]])
        // Возвращает старший блок числа X

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------*/
// Арифметические операции
void m_add ( M_LONG x, M_LONG y, M_LONG z );
// z := x + y

int m_cmp ( M_LONG x, M_LONG y );
// Возвращает -1, если X < Y
// Возвращает 0, если  X ==Y
// Возвращает 1, если  X > Y

void m_div ( M_LONG x, M_LONG y, M_LONG z, M_LONG m );
// Деление x на y
// z - частное
// m - остаток

void m_div1 ( M_LONG x, DIGIT y, M_LONG z, DIGIT *m );
// Деление x на y, если длина y = 1
// z - частное
// m - остаток

void m_egcd ( M_LONG x, M_LONG y, M_LONG gcd, M_LONG a );
// gcd:= НОД ( x, y )
// Если gcd == 1, то a:=(1/x) mod y

int m_inv ( M_LONG x, M_LONG m, M_LONG y );
// y := x^-1 ( mod m )
// (Вычисление обратного элемента в поле)
// Возвращаемое значение:
//      0 - если обратный элемент существует
//    1 - если не существует

DIGIT m_inv1 ( DIGIT x );
// Вычисление x^-1 ( mod 2^32 )

void m_mul ( M_LONG x, M_LONG y, M_LONG z );
// z := x * y
// !!! &z != &x, &z != &y  ( т.е. z не может размещаться по
//              одному адресу с x или y )

#define m_mulmod(x,y,m,z) \
        { \
        DIGIT tmpVarm1[M_MAXSIZE*2+2]; \
        M_LONG tmpVarm2; \
        m_mul ( x, y, tmpVarm1 ); \
        m_div ( tmpVarm1, m, tmpVarm2, z ); }
// z := x * y % m

#define m_sqrmod(x,m,z) \
        { \
        DIGIT tmpVarm1[M_MAXSIZE*2+2]; \
        M_LONG tmpVarm2; \
        m_sqr ( x, tmpVarm1 ); \
        m_div ( tmpVarm1, m, tmpVarm2, z ); }
// z := x * x % m

#define m_mod(x,y,m) \
        { \
        M_LONG tmpVarm2; \
        m_div ( x,y,tmpVarm2,m); }
// m := x % y

void m_blockpowmod (M_LONG x, M_LONG y,
                        M_LONG m,
                        M_LONG z           );

void m_blockmontpowmod (M_LONG x, M_LONG y,
                        M_LONG m,
                        M_LONG z           );
// Возведение в степень блочным методом по Монтгомери

void m_blockmontpowmod2 (M_LONG x, M_LONG y,
                       M_LONG a, M_LONG b,
                       M_LONG m,
                       M_LONG z           );

void m_sqr ( M_LONG x, M_LONG y );
// y = x^2
// !!! &x != &y

void m_sub ( M_LONG x, M_LONG y, M_LONG z );
// z := x - y

void m_copy ( M_LONG y, M_LONG x );
// y := x

/*---------------------------------------------------------------*/
 void m_error ( int code );

int m_bitcount ( M_LONG x );
// Возвращает точную длину x в битах

int m_firstbit ( M_LONG x );
// Возвращает номер старшего бита в старшем блоке x

int m_getbit ( M_LONG x, int k );
// Возвращает k-й бит числа x

void m_setbit ( M_LONG x, int k );
// Устанавливает k-й бит числа x в 1

void m_shl ( M_LONG x, char nbits );
// x <<= nbits(nbits<32)

void m_shr ( M_LONG x, char nbits );
// x >>= nbits(nbits<32)

void m_normalize ( M_LONG x );
// Удаление нулей, стоящих в начале x

void m_rand ( M_LONG x, int len );
// Генерирует случайное число длиной len

void m_zero ( M_LONG x, int len );
// Устанавливает длину x в len и заполняет его нулями

#ifdef __cplusplus
}
#endif

#endif

