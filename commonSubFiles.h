#ifndef  COMMON_SUBSTR
#define  COMMON_SUBSTR

#include <iostream>
#include <fstream>
#include <vector>

// Reference https://www.geeksforgeeks.org/longest-common-substring-dp-29/
// No fui a la clase, entonces probe varias cosas y finalmente encontre una forma recursiva de plantearlo
std::string lcs(std::string string_one, std::string string_two)
{
	// Find length of both the strings.
	int m = string_one.length();
	int n = string_two.length();

	int result = 0;
	int end;

	// Results matrix
	int len[2][n + 1];

	// Curren matrix row
	int currRow = 0;

	// For a particular value of i and j,
	// len[currRow][j] stores length of longest
	// common substring in string string_one[0..i] and string_two[0..j].
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
			{
	                len[currRow][j] = 0;
	            }
	            else if (string_one[i - 1] == string_two[j - 1])
			{
				len[currRow][j] = len[1 - currRow][j - 1] + 1;
				if (len[currRow][j] > result)
			      {
					result = len[currRow][j];
	                        end = i - 1;
	                  }
	            }
			else
			{
				len[currRow][j] = 0;
	            }
	        }

		currRow = 1 - currRow;
	}

	if (result == 0)  // no substring found
	{
		std::string non = "There is not a common largest substring between these two files\n";
	}

	std::cout << "End: " << end << "\n";
	std::cout << "Result: " << result << "\n";

	std::string string_to_return = "The largest common substring between these two files is " + string_one.substr(end - result + 1, result) + ". Starting from " + std::to_string(end-result) + " to " + std::to_string(end) + " in the first file string.\n";

	return string_to_return;
}

void findLargestSubstr(std::string file_one, std::string file_two)
{
	// First part of the code the strings are obtained
	std::ifstream infileOne(file_one); // read file_one
	std::string string_file_one; // string with all data from file one
	std::string aux_file_one;

	while (getline(infileOne, aux_file_one))
	{
		string_file_one += aux_file_one;
	}

	std::ifstream infileTwo(file_two); // read file_two
	std::string string_file_two; // string with all data from file two
	std::string aux_file_two;

	while (getline(infileTwo, aux_file_two))
	{
		string_file_two += aux_file_two;
	}

	std::string substr = lcs(string_file_one, string_file_two);
	std::cout << substr;

}

void solutionThirdProblem(std::vector<std::string> files)
{

	std::string greetings = "| --- Start searching for largest substring between files --- | \n";

	std::cout << greetings;

	std::string file_one = files[0];
	std::string file_two = files[1];

	std::cout << "File one: " << file_one << "\n";
	std::cout << "File two: " << file_two << "\n";

	findLargestSubstr(file_one, file_two); // passes file_name to read
}

#endif
