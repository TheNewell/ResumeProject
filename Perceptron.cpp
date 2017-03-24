#include <Perceptron.h>
#include <iostream>
#include <string>


using namespace std;


Perceptron::Perceptron (vector<Image> trainingFiles, int nVal) {

	N = nVal;
	//fileNames = masterFile;

	weights.resize(64,0);
	bias = 0;
	images = trainingFiles;
	epoch(N);
}

void Perceptron::epoch (int nVal) {

	float y;
	int d, N = nVal;


	for (int i = 0; i < 100; i++) {
		for (int image = 0; image < (int) images.size(); image++) {
			//cout << ": Sample Name= " << images[image].getFileName() << " ---------------" << endl;

			if (N == images[image].getCategory()) { d = 1; }
			else { d = -1; }
			//cout << "nVal = " << N << ":: d = " << d << endl;
			y = 0;

			for (int weight = 0; weight < (int) weights.size(); weight++) {

				y += (images[image].getNormalValue(weight)*weights[weight]);

			}
			y += bias;
			//cout << "Checking value of y: " << y << endl;
			for (int update = 0; update < (int) weights.size(); update++) {

				weights[update] = (weights[update] + ((d - y)*images[image].getNormalValue(update)));
				
			}

			bias = (bias + (d - y));
		}
	}
		//cout << "Checking value of Bias: " << bias << endl;
	// for (int print = 0; print < 64; print++) {

	// 	cout << weights[print] << " ";

	// 	if (print == 63) {
	// 		cout << bias << "\n" << endl;
	// 	}
	// }	

}


