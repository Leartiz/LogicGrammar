/*
* ==========================================================================
* /File: bits.cpp /
* /Brief: Functions decode ( ... ) /
* /Creator: Leonid Artemev | Leartiz /
* /Date: 2018 /
* ==========================================================================
*/
#include "bits.h"
#include <stdio.h>


// Improve?

void bts::decode(Bitbool bbool) // Accepts an object
{
	if (bbool.bits.b8) printf("1");
	else printf("0");
	if (bbool.bits.b7) printf("1");
	else printf("0");
	if (bbool.bits.b6) printf("1");
	else printf("0");
	if (bbool.bits.b5) printf("1");
	else printf("0");
	if (bbool.bits.b4) printf("1");
	else printf("0");
	if (bbool.bits.b3) printf("1");
	else printf("0");
	if (bbool.bits.b2) printf("1");
	else printf("0");
	if (bbool.bits.b1) printf("1");
	else printf("0");

	printf("\n");
}

void bts::decode(Bitchar bchar) // Accepts an object
{
	if (bchar.bits.b8) printf("1");
	else printf("0");
	if (bchar.bits.b7) printf("1");
	else printf("0");
	if (bchar.bits.b6) printf("1");
	else printf("0");
	if (bchar.bits.b5) printf("1");
	else printf("0");
	if (bchar.bits.b4) printf("1");
	else printf("0");
	if (bchar.bits.b3) printf("1");
	else printf("0");
	if (bchar.bits.b2) printf("1");
	else printf("0");
	if (bchar.bits.b1) printf("1");
	else printf("0");

	printf("\n");
}

void bts::decode(Bitshortint bshortint) // Accepts an object
{
	if (bshortint.bits.b16) printf("1");
	else printf("0");
	if (bshortint.bits.b15) printf("1");
	else printf("0");
	if (bshortint.bits.b14) printf("1");
	else printf("0");
	if (bshortint.bits.b13) printf("1");
	else printf("0");
	if (bshortint.bits.b12) printf("1");
	else printf("0");
	if (bshortint.bits.b11) printf("1");
	else printf("0");
	if (bshortint.bits.b10) printf("1");
	else printf("0");
	if (bshortint.bits.b9) printf("1");
	else printf("0");

	printf(" ");

	if (bshortint.bits.b8) printf("1");
	else printf("0");
	if (bshortint.bits.b7) printf("1");
	else printf("0");
	if (bshortint.bits.b6) printf("1");
	else printf("0");
	if (bshortint.bits.b5) printf("1");
	else printf("0");
	if (bshortint.bits.b4) printf("1");
	else printf("0");
	if (bshortint.bits.b3) printf("1");
	else printf("0");
	if (bshortint.bits.b2) printf("1");
	else printf("0");
	if (bshortint.bits.b1) printf("1");
	else printf("0");

	printf("\n");
}

// Œ√Œ
void bts::decode(Bitint bint) // Accepts an object
{
	if (bint.bits.b32) printf("1");
	else printf("0");
	if (bint.bits.b31) printf("1");
	else printf("0");
	if (bint.bits.b30) printf("1");
	else printf("0");
	if (bint.bits.b29) printf("1");
	else printf("0");
	if (bint.bits.b28) printf("1");
	else printf("0");
	if (bint.bits.b27) printf("1");
	else printf("0");
	if (bint.bits.b26) printf("1");
	else printf("0");
	if (bint.bits.b25) printf("1");
	else printf("0");

	printf(" ");

	if (bint.bits.b24) printf("1");
	else printf("0");
	if (bint.bits.b23) printf("1");
	else printf("0");
	if (bint.bits.b22) printf("1");
	else printf("0");
	if (bint.bits.b21) printf("1");
	else printf("0");
	if (bint.bits.b20) printf("1");
	else printf("0");
	if (bint.bits.b19) printf("1");
	else printf("0");
	if (bint.bits.b18) printf("1");
	else printf("0");
	if (bint.bits.b17) printf("1");
	else printf("0");

	printf(" ");

	if (bint.bits.b16) printf("1");
	else printf("0");
	if (bint.bits.b15) printf("1");
	else printf("0");
	if (bint.bits.b14) printf("1");
	else printf("0");
	if (bint.bits.b13) printf("1");
	else printf("0");
	if (bint.bits.b12) printf("1");
	else printf("0");
	if (bint.bits.b11) printf("1");
	else printf("0");
	if (bint.bits.b10) printf("1");
	else printf("0");
	if (bint.bits.b9) printf("1");
	else printf("0");

	printf(" ");

	if (bint.bits.b8) printf("1");
	else printf("0");
	if (bint.bits.b7) printf("1");
	else printf("0");
	if (bint.bits.b6) printf("1");
	else printf("0");
	if (bint.bits.b5) printf("1");
	else printf("0");
	if (bint.bits.b4) printf("1");
	else printf("0");
	if (bint.bits.b3) printf("1");
	else printf("0");
	if (bint.bits.b2) printf("1");
	else printf("0");
	if (bint.bits.b1) printf("1");
	else printf("0");

	printf("\n");
}


// The whole part?
void bts::decode(Bitfloat bfloat)
{
	if (bfloat.bits.b32) printf("1");
	else printf("0");
	if (bfloat.bits.b31) printf("1");
	else printf("0");
	if (bfloat.bits.b30) printf("1");
	else printf("0");
	if (bfloat.bits.b29) printf("1");
	else printf("0");
	if (bfloat.bits.b28) printf("1");
	else printf("0");
	if (bfloat.bits.b27) printf("1");
	else printf("0");
	if (bfloat.bits.b26) printf("1");
	else printf("0");
	if (bfloat.bits.b25) printf("1");
	else printf("0");

	printf(" ");

	if (bfloat.bits.b24) printf("1");
	else printf("0");
	if (bfloat.bits.b23) printf("1");
	else printf("0");
	if (bfloat.bits.b22) printf("1");
	else printf("0");
	if (bfloat.bits.b21) printf("1");
	else printf("0");
	if (bfloat.bits.b20) printf("1");
	else printf("0");
	if (bfloat.bits.b19) printf("1");
	else printf("0");
	if (bfloat.bits.b18) printf("1");
	else printf("0");
	if (bfloat.bits.b17) printf("1");
	else printf("0");

	printf(" ");

	if (bfloat.bits.b16) printf("1");
	else printf("0");
	if (bfloat.bits.b15) printf("1");
	else printf("0");
	if (bfloat.bits.b14) printf("1");
	else printf("0");
	if (bfloat.bits.b13) printf("1");
	else printf("0");
	if (bfloat.bits.b12) printf("1");
	else printf("0");
	if (bfloat.bits.b11) printf("1");
	else printf("0");
	if (bfloat.bits.b10) printf("1");
	else printf("0");
	if (bfloat.bits.b9) printf("1");
	else printf("0");

	printf(" ");

	if (bfloat.bits.b8) printf("1");
	else printf("0");
	if (bfloat.bits.b7) printf("1");
	else printf("0");
	if (bfloat.bits.b6) printf("1");
	else printf("0");
	if (bfloat.bits.b5) printf("1");
	else printf("0");
	if (bfloat.bits.b4) printf("1");
	else printf("0");
	if (bfloat.bits.b3) printf("1");
	else printf("0");
	if (bfloat.bits.b2) printf("1");
	else printf("0");
	if (bfloat.bits.b1) printf("1");
	else printf("0");

	printf("\n");
}

void bts::decode(BitIntChar bintchar)
{
	if (bintchar.bits.b32) printf("1");
	else printf("0");
	if (bintchar.bits.b31) printf("1");
	else printf("0");
	if (bintchar.bits.b30) printf("1");
	else printf("0");
	if (bintchar.bits.b29) printf("1");
	else printf("0");
	if (bintchar.bits.b28) printf("1");
	else printf("0");
	if (bintchar.bits.b27) printf("1");
	else printf("0");
	if (bintchar.bits.b26) printf("1");
	else printf("0");
	if (bintchar.bits.b25) printf("1");
	else printf("0");

	printf(" ");

	if (bintchar.bits.b24) printf("1");
	else printf("0");
	if (bintchar.bits.b23) printf("1");
	else printf("0");
	if (bintchar.bits.b22) printf("1");
	else printf("0");
	if (bintchar.bits.b21) printf("1");
	else printf("0");
	if (bintchar.bits.b20) printf("1");
	else printf("0");
	if (bintchar.bits.b19) printf("1");
	else printf("0");
	if (bintchar.bits.b18) printf("1");
	else printf("0");
	if (bintchar.bits.b17) printf("1");
	else printf("0");

	printf(" ");

	if (bintchar.bits.b16) printf("1");
	else printf("0");
	if (bintchar.bits.b15) printf("1");
	else printf("0");
	if (bintchar.bits.b14) printf("1");
	else printf("0");
	if (bintchar.bits.b13) printf("1");
	else printf("0");
	if (bintchar.bits.b12) printf("1");
	else printf("0");
	if (bintchar.bits.b11) printf("1");
	else printf("0");
	if (bintchar.bits.b10) printf("1");
	else printf("0");
	if (bintchar.bits.b9) printf("1");
	else printf("0");

	printf(" ");

	if (bintchar.bits.b8) printf("1");
	else printf("0");
	if (bintchar.bits.b7) printf("1");
	else printf("0");
	if (bintchar.bits.b6) printf("1");
	else printf("0");
	if (bintchar.bits.b5) printf("1");
	else printf("0");
	if (bintchar.bits.b4) printf("1");
	else printf("0");
	if (bintchar.bits.b3) printf("1");
	else printf("0");
	if (bintchar.bits.b2) printf("1");
	else printf("0");
	if (bintchar.bits.b1) printf("1");
	else printf("0");

	printf("\n");
}
