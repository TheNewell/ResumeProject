#ifndef Perceptron_H_
#define Perceptron_H_

#include <Image.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
class Perceptron {

public:

	Perceptron (vector<Image> trainingFiles, int nVal);
	void epoch (int nVal);
	inline vector<float> getWeights() const {return weights;}
	inline float getIndexWeight(int index) const {return weights[index];}
	inline float getBias() const {return bias;}

private:

	int N;
	float bias;
	vector<Image> images;
	vector<float> weights;
	

};

#endif //Perceptron_H_