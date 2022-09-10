/*
|------------------------------|
   Program by github/justNeto
|------------------------------|
*/

// Include headers and libraries
#include <iostream>
#include <fstream>
#include <chrono>

bool debug;

void setDebug()
{
	std::string ans;
	std::cout << "\n::- [Activate debug mode]: 1 - yes | 0 - no (default)\n";

	while (true)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::fflush(stdin);

    		std::getline(std::cin, ans);

		if (ans == "1")
		{
			std::cout << "| --- [ Activating debug mode ] --- | \n";
			debug = true;

			break;
		}
		else if (ans == "0")
		{
			std::cout << "| --- [ No debug mode ] --- | \n";
			debug = false;

			break;
		}
		else if (ans == "")
		{
			std::cout << "| --- [ No debug mode ] --- | \n";
			debug = false;

			break;
		}
		else
		{
			std::cout << "Please select an appropiate answer. Press enter to try again.";
		}
	}
}

void genPattern(int pattern_length, std::string name)
{
	std::ofstream file;
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::srand(seed); // sets seed

	int max_val = 16; // size of the gen_word dictionary
	char gen_word[max_val] = {'A', 'B', 'C', 'D', 'E', 'F', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	file.open(name);

	for (int i = 0; i < pattern_length; i++)
	{
		int select_char = (std::rand() % max_val);

		if (debug) std::cout << "Random index: " << select_char << "\n";

		if ((gen_word[select_char] == '\n') && (debug))
		{
			std::cout << "Value in dict: New line made \n";
		}
		else if (debug)
		{
			std::cout << "Value in dict: [" << gen_word[select_char] << "]\n";
		}

		file << gen_word[select_char];
	}

	file.close();
}

void genText(int text_length, std::string name)
{
	std::ofstream file;
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::srand(seed); // sets seed

	int max_val = 17; // size of the gen_word dictionary
	char gen_word[max_val] = {'A', 'B', 'C', 'D', 'E', 'F', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\n'};

	file.open(name);

	for (int i = 0; i < text_length; i++)
	{
		int select_char = (std::rand() % max_val);

		if (debug) std::cout << "Random index: " << select_char << "\n";

		if ((gen_word[select_char] == '\n') && (debug))
		{
			std::cout << "Value in dict: New line made \n";
		}
		else if (debug)
		{
			std::cout << "Value in dict: [" << gen_word[select_char] << "]\n";
		}

		file << gen_word[select_char];
	}

	file.close();
}

// Main function
int main()
{
	int length;

	std::cout << "Length of the documents randomly generated documents\n";

	while (true)
	{

		if (!(std::cin >> length))
		{
			std::cout << "Error. Please enter an int number.\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');

			continue;
		}

		break;

	}

	setDebug(); // setting debug

	genText(length, "transmision1.txt");
	genText(length, "transmision2.txt");
	genPattern(10, "mcode1.txt");
	genPattern(10, "mcode2.txt");
	genPattern(10, "mcode3.txt");
}
