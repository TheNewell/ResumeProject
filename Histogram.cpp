#include <Histogram.h>
#include <cmath>
#include <math.h>

using namespace std;


//Take entire picture and normalize the entire thing
void Histogram::normalizeHistogram (vector<int> values, float imageSize) {


	int groupValue;
	histogram.resize(64,0);

	for (int count = 0; count < (int)values.size(); ++count) {
		groupValue = floor(values[count]/4);
		histogram[groupValue] += 1;
	}
	for (int i = 0; i < 64; i++) {
		normalHistogram.push_back(histogram[i]/imageSize);
	}
}









