#include <Compare.h>

using namespace std;


float Compare::Denominator (vector<float> histogramOne, vector<float> histogramTwo, float bias) {

	vector<float> finalHistogram;
	float finalValue = 0;
	for (int i = 0; i < 64; i++) {
		finalHistogram.push_back(min(histogramOne[i],histogramTwo[i])); //code for PA3 to find minimum of 2 normalized vectors
	}
	for (int i = 0; i < 64; i++) {
		finalValue += finalHistogram[i];
	}
	return finalValue;
}

float Compare::sumOfSquaredDifferences(vector<float> firstFile, vector<float> secondFile) {

	vector<float> finalSquaredDifference;
	float sumOfSquaredDifferences = 0;
	//cout << "Inside sumOfSquaredDifferences-----------------------------------------------" << endl;
	for (int i = 0; i < (int)firstFile.size(); i++) {
		finalSquaredDifference.push_back(pow((firstFile[i] - secondFile[i]),2));
		//cout << finalSquaredDifference[i] << " : ";
	}
	//cout << "\n-------------------------------------------------------"<< endl;
	for (int i = 0; i < (int)finalSquaredDifference.size(); i++) {
		sumOfSquaredDifferences += finalSquaredDifference[i];
	}
	//cout << "Output from Compare Class -- sumOfSquaredDifferences value: " << sumOfSquaredDifferences << endl;
	return sumOfSquaredDifferences;
}

