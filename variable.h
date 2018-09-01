/*
* ==========================================================================
* /File: variable.h /
* /Brief: Variable and name /
* /Creator: Leonid Artemev | Leartiz /
* /Date: 2018 /
* ==========================================================================
*/
#pragma once
#include <string>

#include "bits.h"

namespace var
{
	struct VarChar
	{
		std::string name;
		char vchar;
		VarChar() { };
		VarChar(std::string name_, char c)
			: name{ name_ }, vchar{ c } { };
	};
	
	// By cd
	struct VarInt
	{
		std::string name;
		int vint;
		VarInt() { };
		VarInt(std::string name_, int i)
			: name{ name_ }, vint{ i } { };
	};

	// Use bits.h
	struct VarBitCharInt
	{
		std::string name;
		bts::BitIntChar bintchar;

		VarBitCharInt() { };

		VarBitCharInt(std::string name_, int in)
			: name{ name_ }, bintchar{ in } { };

		VarBitCharInt(std::string name_, char ch)
			: name{ name_ }, bintchar{ ch } { };
	};
}


