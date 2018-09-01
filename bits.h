/*
* ==========================================================================
* /File: bits.h /
* /Brief: Bitwise representation of an entity (data types) /
* /Creator: Leonid Artemev | Leartiz /
* /Date: 2018 /
* ==========================================================================
*/
#pragma once

// b - bit
// bits - bits

namespace bts
{
	struct Bit8
	{
		int b1 : 1;
		int b2 : 1;
		int b3 : 1;
		int b4 : 1;
		int b5 : 1;
		int b6 : 1;
		int b7 : 1;
		int b8 : 1;
	};

	struct Bit16
	{
		int b1 : 1;
		int b2 : 1;
		int b3 : 1;
		int b4 : 1;
		int b5 : 1;
		int b6 : 1;
		int b7 : 1;
		int b8 : 1;
		int b9 : 1;
		int b10 : 1;
		int b11 : 1;
		int b12 : 1;
		int b13 : 1;
		int b14 : 1;
		int b15 : 1;
		int b16 : 1;
	};

	struct Bit32
	{
		int b1 : 1;
		int b2 : 1;
		int b3 : 1;
		int b4 : 1;
		int b5 : 1;
		int b6 : 1;
		int b7 : 1;
		int b8 : 1;
		int b9 : 1;
		int b10 : 1;
		int b11 : 1;
		int b12 : 1;
		int b13 : 1;
		int b14 : 1;
		int b15 : 1;
		int b16 : 1;
		int b17 : 1;
		int b18 : 1;
		int b19 : 1;
		int b20 : 1;
		int b21 : 1;
		int b22 : 1;
		int b23 : 1;
		int b24 : 1;
		int b25 : 1;
		int b26 : 1;
		int b27 : 1;
		int b28 : 1;
		int b29 : 1;
		int b30 : 1;
		int b31 : 1;
		int b32 : 1;
	};

	// Bitwise representation of an entity (data types)
	// bool
	// char
	// short int
	// int
	// float
	// ...

	union Bitbool
	{
	public:
		Bitbool() { };
		bool bbool;
		Bit8 bits;
	};

	union Bitchar
	{
		char bchar;
		Bit8 bits;
	};

	union Bitshortint
	{
		short int bshortint;
		Bit16 bits;
	};

	union Bitint
	{
		int bint;
		Bit32 bits;
	};

	union Bitfloat
	{
		float bfloat;
		Bit32 bits;
	};

	// For char and int (private)
	union BitIntChar
	{
		int bint = 0;

		char bchar;
		Bit32 bits; // For char è int
	};

	void decode(BitIntChar);

	void decode(Bitchar);
	void decode(Bitint);
	void decode(Bitbool);
	void decode(Bitshortint);
	void decode(Bitfloat);
}