#include <Dataset.h>
#include <iostream>

using std::cerr;
using std::endl;
using std::istringstream;
using std::cout;


int main(int argc, char* argv[]) 
{
	try {

		 Dataset runProgram;
		 int k;
		

		if (argc != 4) {					
			cerr << "Incorrect arguements, Please enter an Executable and 3 arguements." << endl;
			return -1;
		}

		istringstream kArg(argv[3]); 		//stores value of K (In PA8 k value will represent number N)***
		//istringstream sortArg(argv[3]); 	//stores type of sort algorithim option(int)***

		if (!(kArg >> k)) {								
			cerr << "Incorrect 3rd arguement, needs to be a positive integer" << endl;
			return -1;
		}
		//Code removed for PA8***
		// if (!(sortArg >> sortOption)) {   
		// 	cerr << "Incorrect 4th arguement, needs to be integer value between 1-4." << endl;
		// 	return -1;
		// }	

		//Code Removed for PA8***
		// if (sortOption < 1 || sortOption > 4) { 
		// 	cerr << "Incorrect 4th arguement, needs to be integer value between 1-4." << endl;
		// 	return -1;
		// }

		// runProgram.buildClusters(argv[1], k, sortOption);***
		
		// runProgram.compareClusters(k, sortOption);***

		runProgram.trainPerceptrons(argv[1]);
		runProgram.buildClusters(argv[2], k);


	}

	catch (int error) { //will print an error base on where the programs throws a values. values corrilate to error location.

		cout<< "error # " << error << ": ";

		switch (error) {
			case 1: cerr<<"Please run Executable file with one .txt file, the number of desired clusters, and your sorting option (1, 2, 3) are valid options. \n"; break;
			case 2: cerr<<"Text file contain values outside of 0-255 \n"; break;
			case 3: cerr<<"Nonexsistant .txt file inputed\n"; break;
			case 4: cerr<<"Image Files should only contain int values \n"; break;
			case 5: cerr<<"Please imput two image files with .pgm extensions\n"; break;
			case 6: cerr<<"Improper .pgm format, please start file with P2 followed by width, then height, and then Max pixel size\n"; break;
			case 7: cerr<<"Number of Pixels does not match given Image size\n"; break;
			case 8: cerr<<"Image Height and Width not equal, Two images cannot be compared\n"; break;
			case 9: cerr<<"Input a file with 2 or more image file names\n"; break;
			case 10: cerr<<"Only input files that are 128 X 128\n"; break;
			case 11: cerr<<"second arguements need to be greater than 0 and less than total files being clustered\n"; break;
			case 21: cerr<<"Histogram could not be built\n"; break;

			default: cerr<<"Unkown error has occured\n";
		}

		return -1;
	}



return 0;
}