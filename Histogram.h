#ifndef HISTOGRAM_H_
#define HISTOGRAM_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Histogram {

public:

	void normalizeHistogram (vector<int> sortedHistogram, float fileSize);

//Setters

//Accessors
	inline vector<int> getHistogram () const {return histogram;}
	inline vector<float> getNormalized () const {return normalHistogram;}
	
//Accesors to Avg histograms
	inline float getNormalValue (int index) const {return normalHistogram[index];}


private:
	string fileName;
	vector<int> normPixValues;
	vector<int> histogram; //vector of all pixels in the 64 bins

	//Value for normalizing the whole picture
	vector<float> normalHistogram;

	
	
	
};



#endif //HISTOGRAM_H_