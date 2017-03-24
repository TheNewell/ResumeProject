#include <Image.h>
#include <iostream>
#include <string>

using namespace std;

Image::Image (string file):histogram() {
  
  //cout<<"In Image Constructor"<<endl;
  fileName = file;
  string delimiter = "_";
  string token = file.substr(5, file.find(delimiter));
  istringstream(token) >> category;
  //cout << "Checking value of category: " << category << endl;


    readImageFile(file);
    buildHistogram(pixels, imageSize);
  

  //find group number of image here
}

void Image::readImageFile (string filename) {

  int number;
  string fileStart;
  char c;
  imageSize = 0;
  ifstream imageFile (filename);

  if (imageFile.is_open()) {
      imageFile.get(c);
      fileStart = c;

      if ( fileStart != "P" ) throw 6;
      imageFile.get(c);
      fileStart.push_back(c);

      if ( fileStart.compare("P2")) throw 6;
      imageFile >> width;
      imageFile >> height;
      imageFile >> maxPixel;

      if (width != 128 || height != 128) throw 10; //makes sure file is 128 X 128
      while (!imageFile.eof()) {
        if (imageFile >> skipws >> number) {
          if (number < 0 || number > maxPixel) {throw 2;} //Checks if numbers in file are outside 0-255

          pixels.push_back(number);
        }
        else {throw 4;} //Checks if values are ints, if not will throw an error for any charecter thats not a number
        imageFile >> ws; //Clears the white space at the end of a file
        imageSize++;
      }
      if (width*height != imageSize) throw 7; //checks to make sure the numer of pixels given matches the width*height
      imageFile.close();
    }
    else throw 3; //Not able to open file
}

void Image::buildHistogram (vector<int> pixels, int imageSize) {

    histogram.normalizeHistogram(pixels, imageSize);
  

}

