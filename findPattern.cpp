#include "genTxtFiles.h"
#include <vector>

bool verbose;

void prtVersion()
{
	std::cout << "1.2.0\n";
}

void prtHelp()
{
	std::cout << "Usage: findPattern [OPTIONS] ... [FILE] ... \n\n";

	std::cout << "Finds a certain pattern on a file and points at the index it can be found.\n\n";
	std::cout << "Use the following options for searching patterns in files.\n";
      std::cout << "  -f, --file						search this file for the pattern. Can specify multiple files.\n";
      std::cout << "  -p, --pattern						file with the pattern. Can specify multiple patterns.\n";
      std::cout << "  -v, --verbose						prints the program specifics in runtime.\n";
      std::cout << "  -s, --simulate					creates three random files in current directory and searches for two random patterns.\n\n";

	std::cout << "Use the following options for generating test random files and patterns.\n";
	std::cout << "  -gf, --generate-files					generate a given number of random files of a given length.  They will be named accordingly.\n";
	std::cout << "  -gp, --generate-patterns				generate a given number of random patterns of a given length. They will be named accordingly.\n\n";

	std::cout << "  -h, --help						shows this help menu and exit.\n";
      std::cout << "  --version						displays current version of script.\n";
}

// Argc: number of arguments including the program name
// Argv: the vector in char ** format
int main(int argc, char ** argv)
{
	// Vectors to save the names of the files and patterns the program will later use
	std::vector<std::string> files; // existing files
	std::vector<std::string> patterns; // existing patterns
	std::vector<std::string> gen_files; // create files
	std::vector<std::string> gen_patterns; // create patterns

	// Opts
	bool file_opt = false;
	bool pattern_opt = false;
	bool gen_file_opt = false;
	bool gen_pattern_opt = false;

	// Control vars
	bool patterns_inputed = false;
	bool patterns_generated = false;
	bool files_generated = false;
	bool files_inputed = false;

	bool simulation = false; // inputting patterns

	if (argc == 1) // no opts passed, program was just executed
	{
		prtHelp();
		exit(1);
	}

	int aux = 1;

	while (aux != argc)
	{
		if ((file_opt == true) && (files_inputed == false))  // if file_opt active and files_inputed still false
		{
			// New opt in argv[aux] detected
			if (argv[aux][0] == '-')
			{
				files_inputed = true; // can no longer add into this opt
				continue;
			}

			files.push_back(argv[aux]);
			aux++;

			continue;
		}

		if ((pattern_opt == true) && (patterns_inputed == false))  // if file_opt active and files_inputed still false
		{
			if (argv[aux][0] == '-')
			{
				patterns_inputed = true; // can no longer add into this opt
				continue;
			}

			patterns.push_back(argv[aux]);
			aux++;

			continue;
		}

		if ((gen_file_opt == true) && (files_generated == false))  // if file_opt active and files_inputed still false
		{
			if (argv[aux][0] == '-')
			{
				files_generated = true;
				continue;
			}

			gen_files.push_back(argv[aux]);
			aux++;

			continue;
		}

		if ((gen_pattern_opt == true) && (patterns_generated == false))  // if file_opt active and files_inputed still false
		{
			if (argv[aux][0] == '-')
			{
				patterns_generated = true;
				continue;
			}

			gen_patterns.push_back(argv[aux]);
			aux++;

			continue;
		}

		// Generate new files of random characters
		if ((argv[aux] == std::string("-gf")) || (argv[aux] == std::string("--generate-files")))
	      {
			gen_file_opt = true; // selects the option to work with
			aux++;
			continue;
	      }

		// Generate new files of random patterns
		if ((argv[aux] == std::string("-gp")) || (argv[aux] == std::string("--generate-patterns")))
	      {
			gen_pattern_opt = true; // selects the option to work with
			aux++;
			continue;
	      }

		// Use files to solve the problems
		if ((argv[aux] == std::string("-f")) || (argv[aux] == std::string("--file")))
	      {
	            file_opt = true;
			aux++;
		      continue;
	      }

		// Use patterns to solve the problems
	      if ((argv[aux] == std::string("-p")) || (argv[aux] == std::string("--pattern"))) // if file options selected
	      {
		      pattern_opt = false; // selects the option to work with
			aux++;
		      continue;
	      }

		// Start simulation mode
		if ((argv[aux] == std::string("-s")) || (argv[aux] == std::string("--simulate")))
	      {
			simulation = true; //automatically ignore any other commands and go straight to simulation
			aux++;
			break;
	      }

		// Activate verbose mode
	      if ((argv[aux] == std::string("-v")) || (argv[aux] == std::string("--verbose"))) // if file options selected
	      {
			verbose = true;
			aux++;
			continue;
	      }

		// Show current version of proyect
	      if (argv[aux] == std::string ("--version")) // if file options selected
	      {
			prtVersion();
		      exit(0);
	      }

	      if ((argv[aux] == std::string ("-h")) || (argv[aux] == std::string("--help"))) // if file options selected
	      {
			prtHelp();
			exit(0);
	      }

	      // If not entering a file then some erros has been made
	      std::cout << "Invalid option. Try findPattern -h or findPattern --help for more information.\n";
		exit(1);
	}

	if (simulation == true)
	{
		if (verbose) std::cout << "| --- [Simulation mode activated] --- | \n";
		if (verbose) std::cout << "In simulation mode, default values will be used for file length and pattern length.\n";

		if (verbose) std::cout << "::- Creating files\n";

		genText(20000, "transmission1.txt");
		genText(20000, "transmission2.txt");
		genPattern(5, "mcode1.txt");
		genPattern(5, "mcode2.txt");
		genPattern(5, "mcode3.txt");

		if (verbose) std::cout << "::- Files created\n";

		// Once the files are created, the solutions for the three problems will run

		if (verbose) std::cout << "::- Solution for the first problem:\n";
		// Solution one

		if (verbose) std::cout << "::- Solution for the second problem:\n";
		// Solution two

		if (verbose) std::cout << "::- Solution for the third problem:\n";
		// Solution three

		if (verbose) std::cout << "::- Simulation mode terminated.\n";
		exit(0);
	}

	if (gen_file_opt)
	{
		if (verbose)
		{
			if (gen_files.empty())
			{
				std::cout << "\n::-Missing arguments. Try findPattern -h or findPattern --help for more information. \n";
			}
			else
			{
				std::cout << "\n::-Will generate this files: \n";

				for (auto const &names : gen_files)
				{
					std::cout << names << "\n";
				}
			}
		}
	}

	if (file_opt)
	{
		if (verbose)
		{
			if (files.empty())
			{
				std::cout << "\n::-Missing arguments. Try findPattern -h or findPattern --help for more information. \n";
			}
			else
			{
				std::cout << "\n::-Will use this files to find a solution: \n";

				for (auto const &names : files)
				{
					std::cout << names << "\n";
				}
			}


		}
	}

	if (gen_pattern_opt)
	{
		if (verbose)
		{
			if (gen_patterns.empty())
			{
				std::cout << "\n::-Missing arguments. Try findPattern -h or findPattern --help for more information. \n";
			}
			else
			{
				std::cout << "\n::-Will generate this patterns: \n";

				for (auto const &names : gen_patterns)
				{
					std::cout << names << "\n";
				}
			}

		}
	}

	if (pattern_opt)
	{
		if (verbose)
		{
			if (patterns.empty())
			{
				std::cout << "\n::-Missing arguments. Try findPattern -h or findPattern --help for more information. \n";
			}
			else
			{
				std::cout << "\n::-Will use this patterns to find solution: \n";

				for (auto const &names : patterns)
				{
					std::cout << names << "\n";
				}
			}
		}
	}
}