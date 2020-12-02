
/*
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 */


#ifndef COMMON_H
#define COMMON_H

static double ll_as_double(long long a) { return *(double*)&a; }
static long long double_as_ll(double a) { return *(long long*)&a; }

const double TWO_TO_53 = 9007199254740992.0;

const double LOG10_2[] __attribute__ ((aligned (64))) = {
3.0102999566398120e-01, 3.0102999566398120e-01, 3.0102999566398120e-01, 3.0102999566398120e-01,
3.0102999566398120e-01, 3.0102999566398120e-01, 3.0102999566398120e-01, 3.0102999566398120e-01
};

const double ONE_D[] __attribute__ ((aligned (64))) = {
1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
};

const unsigned long long ONE_I[] __attribute__ ((aligned (64))) = {
1ULL, 1ULL, 1ULL, 1ULL, 1ULL, 1ULL, 1ULL, 1ULL
};

const double THRESHOLD[]  __attribute__ ((aligned (64))) = {
0.75, 0.75, 0.75, 0.75, 0.75, 0.75, 0.75, 0.75
};

const unsigned long long MANTISSA_MASK[]  __attribute__ ((aligned (64))) = {
0xfffffffffffffULL, 0xfffffffffffffULL, 0xfffffffffffffULL, 0xfffffffffffffULL,
0xfffffffffffffULL, 0xfffffffffffffULL, 0xfffffffffffffULL, 0xfffffffffffffULL
};

const unsigned long long HALFIFIER[]  __attribute__ ((aligned (64))) = {
0x10000000000000ULL, 0x10000000000000ULL, 0x10000000000000ULL, 0x10000000000000ULL,
0x10000000000000ULL, 0x10000000000000ULL, 0x10000000000000ULL, 0x10000000000000ULL
};

const unsigned long long PINF[]  __attribute__ ((aligned (64))) = {
0x7ff0000000000000ULL, 0x7ff0000000000000ULL, 0x7ff0000000000000ULL, 0x7ff0000000000000ULL,
0x7ff0000000000000ULL, 0x7ff0000000000000ULL, 0x7ff0000000000000ULL, 0x7ff0000000000000ULL
};

const unsigned long long NINF[]  __attribute__ ((aligned (64))) = {
0xfff0000000000000ULL, 0xfff0000000000000ULL, 0xfff0000000000000ULL, 0xfff0000000000000ULL,
0xfff0000000000000ULL, 0xfff0000000000000ULL, 0xfff0000000000000ULL, 0xfff0000000000000ULL
};

const unsigned long long CANONICAL_NAN[]  __attribute__ ((aligned (64))) = {
0xfff8000000000000ULL, 0xfff8000000000000ULL, 0xfff8000000000000ULL, 0xfff8000000000000ULL,
0xfff8000000000000ULL, 0xfff8000000000000ULL, 0xfff8000000000000ULL, 0xfff8000000000000ULL
};

const double c0[] __attribute__ ((aligned (64))) = {
-3.9902972429474055e-03, -3.9902972429474055e-03, -3.9902972429474055e-03, -3.9902972429474055e-03,
-3.9902972429474055e-03, -3.9902972429474055e-03, -3.9902972429474055e-03, -3.9902972429474055e-03
};

const double c1[] __attribute__ ((aligned (64))) = {
 1.4081442120452604e-02, 1.4081442120452604e-02, 1.4081442120452604e-02, 1.4081442120452604e-02,
 1.4081442120452604e-02, 1.4081442120452604e-02, 1.4081442120452604e-02, 1.4081442120452604e-02
};
const double c2[] __attribute__ ((aligned (64))) = {
-2.3672789854611846e-02, -2.3672789854611846e-02, -2.3672789854611846e-02, -2.3672789854611846e-02,
-2.3672789854611846e-02, -2.3672789854611846e-02, -2.3672789854611846e-02, -2.3672789854611846e-02
};
const double c3[] __attribute__ ((aligned (64))) = {
 2.7430685728900141e-02, 2.7430685728900141e-02, 2.7430685728900141e-02, 2.7430685728900141e-02,
 2.7430685728900141e-02, 2.7430685728900141e-02, 2.7430685728900141e-02, 2.7430685728900141e-02
};
const double c4[] __attribute__ ((aligned (64))) = {
-2.7935977036068853e-02, -2.7935977036068853e-02, -2.7935977036068853e-02, -2.7935977036068853e-02,
-2.7935977036068853e-02, -2.7935977036068853e-02, -2.7935977036068853e-02, -2.7935977036068853e-02
};
const double c5[] __attribute__ ((aligned (64))) = {
 2.8913989262316014e-02, 2.8913989262316014e-02, 2.8913989262316014e-02, 2.8913989262316014e-02,
 2.8913989262316014e-02, 2.8913989262316014e-02, 2.8913989262316014e-02, 2.8913989262316014e-02
};
const double c6[] __attribute__ ((aligned (64))) = {
-3.0925264020832541e-02, -3.0925264020832541e-02, -3.0925264020832541e-02, -3.0925264020832541e-02,
-3.0925264020832541e-02, -3.0925264020832541e-02, -3.0925264020832541e-02, -3.0925264020832541e-02
};
const double c7[] __attribute__ ((aligned (64))) = {
 3.3394250680337925e-02, 3.3394250680337925e-02, 3.3394250680337925e-02, 3.3394250680337925e-02,
 3.3394250680337925e-02, 3.3394250680337925e-02, 3.3394250680337925e-02, 3.3394250680337925e-02
};
const double c8[] __attribute__ ((aligned (64))) = {
-3.6196017360600602e-02, -3.6196017360600602e-02, -3.6196017360600602e-02, -3.6196017360600602e-02,
-3.6196017360600602e-02, -3.6196017360600602e-02, -3.6196017360600602e-02, -3.6196017360600602e-02
};
const double c9[] __attribute__ ((aligned (64))) = {
 3.9482521625171671e-02, 3.9482521625171671e-02, 3.9482521625171671e-02, 3.9482521625171671e-02,
 3.9482521625171671e-02, 3.9482521625171671e-02, 3.9482521625171671e-02, 3.9482521625171671e-02
};
const double c10[] __attribute__ ((aligned (64))) = {
-4.3429342257676216e-02, -4.3429342257676216e-02, -4.3429342257676216e-02, -4.3429342257676216e-02,
-4.3429342257676216e-02, -4.3429342257676216e-02, -4.3429342257676216e-02, -4.3429342257676216e-02
};
const double c11[] __attribute__ ((aligned (64))) = {
 4.8254896147627749e-02, 4.8254896147627749e-02,  4.8254896147627749e-02, 4.8254896147627749e-02,
 4.8254896147627749e-02, 4.8254896147627749e-02,  4.8254896147627749e-02, 4.8254896147627749e-02
};
const double c12[] __attribute__ ((aligned (64))) = {
-5.4286810715274331e-02, -5.4286810715274331e-02, -5.4286810715274331e-02, -5.4286810715274331e-02,
-5.4286810715274331e-02, -5.4286810715274331e-02, -5.4286810715274331e-02, -5.4286810715274331e-02
};
const double c13[] __attribute__ ((aligned (64))) = {
 6.2042069733283481e-02,  6.2042069733283481e-02,  6.2042069733283481e-02,  6.2042069733283481e-02,
 6.2042069733283481e-02,  6.2042069733283481e-02,  6.2042069733283481e-02,  6.2042069733283481e-02
};
const double c14[] __attribute__ ((aligned (64))) = {
-7.2382413666496184e-02, -7.2382413666496184e-02, -7.2382413666496184e-02, -7.2382413666496184e-02,
-7.2382413666496184e-02, -7.2382413666496184e-02, -7.2382413666496184e-02, -7.2382413666496184e-02
};
const double c15[] __attribute__ ((aligned (64))) = {
 8.6858896372479524e-02,  8.6858896372479524e-02,  8.6858896372479524e-02,  8.6858896372479524e-02,
 8.6858896372479524e-02,  8.6858896372479524e-02,  8.6858896372479524e-02,  8.6858896372479524e-02
};
const double c16[] __attribute__ ((aligned (64))) = {
-1.0857362047562141e-01, -1.0857362047562141e-01, -1.0857362047562141e-01, -1.0857362047562141e-01,
-1.0857362047562141e-01, -1.0857362047562141e-01, -1.0857362047562141e-01, -1.0857362047562141e-01
};
const double c17[] __attribute__ ((aligned (64))) = {
 1.4476482730111173e-01,  1.4476482730111173e-01,  1.4476482730111173e-01,  1.4476482730111173e-01,
 1.4476482730111173e-01,  1.4476482730111173e-01,  1.4476482730111173e-01,  1.4476482730111173e-01
};
const double c18[] __attribute__ ((aligned (64))) = {
-2.1714724095162635e-01, -2.1714724095162635e-01, -2.1714724095162635e-01, -2.1714724095162635e-01,
-2.1714724095162635e-01, -2.1714724095162635e-01, -2.1714724095162635e-01, -2.1714724095162635e-01
};
const double c19[] __attribute__ ((aligned (64))) = {
 4.3429448190325182e-01,  4.3429448190325182e-01,  4.3429448190325182e-01,  4.3429448190325182e-01,
 4.3429448190325182e-01,  4.3429448190325182e-01,  4.3429448190325182e-01,  4.3429448190325182e-01
};

#endif
