/*
* ==========================================================================
* /File: Source.cpp /
* /Brief: Logic Grammar ( ... ) / Parser Logical Expressions /
* /Creator: Leonid Artemev | Leartiz /
* /Date: 2018 /
* ==========================================================================
*/
#include <iostream>
#include <cstdlib>
#include <stdexcept> // runtime_error
#include <string>
#include <vector>
#include <conio.h>
#include <ctype.h>
#include <Windows.h>

#include "bits.h"
#include "variable.h"

// Operators: | or, & and, ^ exclusive or, ~ addition (bitwise), ! logical inversion
// Operator ! is a prefix unary
// If all the bits 0 then 1, else 0
// Operator ~ is a prefix unary
// Addition (bitwise inversion), that is 1 -> 0, and 0 -> 1

void verification(); // Main processing cycle
void instruction();
void error(std::string s); // Error
void pass_string(); // If the exception to pass

// Returns a character (the result of bitwise operations)
int statement();
int expression(); // '|'
int definition(); // Definition (input of variables)
int term(); // '^'
int subterm(); // '&'
int primary(); // An object

std::string read_name(); // Reads the name
						 // Name of the variable letters and numbers (beginning with a letter)

std::vector<var::VarInt> varint(0); // Storage of variables (user input)
// Appeal to the vector / private cases
int get_vbci(std::string name); // Getting from the vector
bool is_declared(std::string name); // Check for the presence of a variable in the vector with name
void set_vbci(std::string name, int in); // Edit value
void define_name(std::string name, int in); // Defining a variable name

int main()
{
	//
	// Can check
	//bts::Bitchar btestch;
	//btestch.bchar = ' . . . '; // Expression
	//bts::decode(btestch);
	//

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::cout << "LogicGrammar - 0.1 \n\n";

	instruction();
	verification();

	system("PAUSE"); // Or replace with _getche();
	return 0;
}

void verification()
{
	const std::string promt = "> ";
	const std::string result = "= ";

	// For result and output
	const char exit = 'x';
	const char end = '=';
	const std::string endstr = "="; // For an error (processing)

	while (std::cin)
	{

	bts::BitIntChar bres;

	char check_ch = 0;
	int res = 0; // For work with Char and Int
	
		try
		{
			std::cout << promt;
			std::cin >> check_ch;
			while (check_ch == end)
				std::cin >> check_ch;
			if (check_ch == exit)
				break;
			std::cin.putback(check_ch);

			// Grammar
			res = statement();

			std::cin >> check_ch;
			if (check_ch != end)
				error("Expected \'" + endstr + "\'\n"
					"/possibly an invalid operator\n"
					"/possibly a large number!");

			// If there is more than one expression on the line promt
			std::cout << "\b\b\b";
			std::cout << "Answer: \n";
			std::cout << result << res << std::endl; // Whole (Int)

			bres.bint = res;
			std::cout << result;
			bts::decode(bres); // Binary

			std::cout << std::endl;
			std::cin.clear();

		}
		catch (std::runtime_error & ex)
		{
			std::cerr << "Exception: " << ex.what() << std::endl << std::endl;
			pass_string();
		}
		catch (...)
		{
			std::cerr << "Exception!" << std::endl << std::endl;
			pass_string();
		}
	}
}

void pass_string()
{
	int some = 0;
	//std::cin.putback(' '); // Since there are sometimes exceptions with completed expressions
	some = std::cin.get();
	// Possible stops (-1 only in an exception)
	while (some != ';' && some != '=' && some != '\n' && some != '\0' && some != -1)
		some = std::cin.get();

	std::cin.clear();
}

int statement()
{
	// def - definition
	// ass - assigning an existing
	const std::string def = "let";
	const std::string ass = "change";
	const std::string clear = "cls";

	int res = 0;

	//act - act def ass (and so on)
	std::string act = "";
	std::cin >> act; // Until the space

	if (act == clear)
	{
		system("CLS");
		instruction();
		std::cin.putback('='); // As cls
	}
	else if (act != def && act != ass)
	{
		// putback - string
		for (int i = act.length() - 1; i >= 0; --i)
			std::cin.putback(act[i]);

		act = "";

		res = expression();
	}
	else
	{
		// putback - string
		for (int i = act.length() - 1; i >= 0; --i)
			std::cin.putback(act[i]);
		
		act = "";

		res = definition();
	}
	return res;
}

std::string read_name()
{
	std::string name = "";
	char ch = 0;

	do
	{
		std::cin.get(ch);
	} while (ch == ' ');
	if (!isalpha(ch))
		error("The variable name must begin with a letter!");
	while (isalnum(ch)) // Number or letter
	{
		name += ch;
		std::cin.get(ch);
	}
	std::cin.putback(ch);
	return name;
}

// For definition used "let"
int definition()
{
	// def - definition
	// ass - assigning an existing
	const std::string def = "let";
	const std::string ass = "change";

	const char end = ';'; // If the assignment / definition
	const std::string endstr = ";"; // For error

	int res = 0;

	char check_ch = 0;

	std::string act = "";
	std::cin >> act; // Until the space

	std::string name = ""; // Now the name of the variable

	name = read_name();

	std::cin >> check_ch;

	if (check_ch != '=') // Assignment operator
		error("Assignment operator \"=\" not found!");

	else // Not necessarily because the exception
	{
		res = expression(); // In any case, know the right side for the assignment statement

		std::cin >> check_ch;
		if (check_ch != end)
			error("Expected \'" + endstr + "\'");

		if (act == def)
			// Definition a name and value and adding to a vector varchar
			define_name(name, res);
		else // act == ass
			set_vbci(name, res);
	}
	std::cin.putback('='); // That is Definition / assignment and verification in verification()

	return res;
}

// Works with symbols and variables
int expression()
{
	int res = term();
	char op = 0;
	std::cin >> op;
	if (op != '|')
	{
		std::cin.putback(op);
		return res;
	}
	else 
	{
		return res | expression();
	}
	return res;
}

int term()
{
	int res = subterm();
	char op = 0;
	std::cin >> op;
	if (op != '^')
	{
		std::cin.putback(op);
		return res;
	}
	else
	{
		return res ^ term();
	}
}

int subterm()
{
	int res = primary(); //  Char or name or number
	char op = 0;
	std::cin >> op;
	if (op != '&')
	{
		std::cin.putback(op);
		return res;
	}
	else
	{
		return res & subterm();
	}
}

int primary()
{
	// If there is more than one expression on the line promt
	std::cout << "\b\b\b";

	bts::BitIntChar bres;

	char check_ch = 0; // ch for reading everything and checking and further converting to int

	int res = 0;

	char bord = 0; // 
	char unarych = 0; // Unary operation, if 0 then was not
	std::string name = "";

	// Processing of the unary operation
	std::cin >> unarych; // As a "border" and possibly a unary operation
	// Other unary operations are possible (add and below)
	switch (unarych) 
	{
	case '~': case '!':
		break;
	default:
		std::cin.putback(unarych);
		break;
	}

	std::cin >> bord;
	// You can reorder
	// If the symbol
	if (bord == '\'')
	{
		std::cin >> check_ch; // Some character in '' (SYMBOL ONLY ONE)
		std::cin >> bord;

		if (bord != '\'')
			error("\' \' not found (usually right / maybe not a character)!");

		bres.bint = int(check_ch); // Since the symbol representation
		std::cout << int(check_ch) << " = ";
		bts::decode(bres);

		res = int(check_ch);
	}
	// Borders
	else if (bord == '(')
	{
		res = expression();

		std::cin >> bord;
		if (bord != ')')
			error("\')\' not found!");
	}
	// if name
	else
	{
		std::cin.putback(bord);

		std::cin >> check_ch;
		// If number (unary operations)
		if (check_ch == '+' || check_ch == '-' || isdigit(check_ch))
		{
			std::cin.putback(check_ch);

			std::cin >> res;

			bres.bint = res;
			std::cout << res << " = ";
			bts::decode(bres);
		}
		// If name
		else
		{
			std::cin.putback(check_ch);

			name = read_name();
			if (!is_declared(name))
				error(name + " " + "not determined!"); // Also checking in get_char()

			res = get_vbci(name); // From the vector get the number

			bres.bint = res;
			std::cout << res << " = ";
			bts::decode(bres);
		}
	}

	// Processing of unary operations for all
	switch (unarych)
	{
	case '~':
		return ~res;
		break;
	case '!':
		return !res;
		break;
	default:
		return res; // Return value
		break;
	}

}

// To work with std::vector<VarChar> varchar
// Checking in the functions! (processing of input values)
int get_vbci(std::string name)
{
	for (int i = 0; i < varint.size(); ++i)
		if (varint[i].name == name)
			return varint[i].vint;
	error("get_char: undefined variable!");
}

void set_vbci(std::string name, int in)
{
	for (int i = 0; i < varint.size(); ++i)
		if (varint[i].name == name)
		{
			varint[i].vint = in;
			return;
		}
	error("set_char: undefined variable!");
}

bool is_declared(std::string name)
{
	for (int i = 0; i < varint.size(); ++i)
		if (varint[i].name == name)
			return true;
	return false;
}

void define_name(std::string name, int in)
{
	if (is_declared(name))
		error(name + " " + "definition twice!");

	varint.push_back(var::VarInt(name, in));
	return;
}
//

void instruction()
{
	std::cout << "\trules: \n";
	std::cout << "End of expression - '=' (no definition / no assignment) \n";
	std::cout << "The symbol in '...' \n";

	std::cout << "Defining a variable \"let\" < name > = < expression > ; \n"; 
	std::cout << "Assigning a Variable Value \"change\" < name > = < expression > ; \n";

	std::cout << "Clear Screen - cls \n";

	std::cout << "Exit - x \n";
	std::cout << std::endl;
}

void error(std::string s)
{
	throw std::runtime_error(s);
}