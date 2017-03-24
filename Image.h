#ifndef Image_H_
#define Image_H_

#include <Histogram.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
class Image {

public:

 Image (string fileName);
 void readImageFile(string fileName);
 void buildHistogram (vector<int> pixels, int imageSize);

//Accessors
	inline int getImageSize () const {return imageSize;}
	inline int getWidth () const {return width;}
	inline int getHeight () const {return height;}
	inline int getCategory () const {return category;}//Also retrieves value of N for PA8
	inline vector<int> getImageVector() {return pixels;}
	inline string getFileName () const {return fileName;}
	inline vector<float> getNormalized () const {return normalHistogram;}

//Vector values
	inline vector<float> getWholeNorm() {return histogram.getNormalized();}

//Index Values
	inline float getNormPixValues (int index) const {return pixels[index];}
	inline float getNormalValue (int index) const {return histogram.getNormalValue(index);}


private:
 Histogram histogram;
 string fileName;
 int imageSize, width, height, maxPixel;
 int category; //to store the value of class in the file name 
 vector<int> pixels;
 vector<float> normalHistogram;

};

#endif //Image_H_
