#ifndef Dataset_H_
#define Dataset_H_

#include <Histogram.h>
#include <Cluster.h>
#include <Image.h>
#include <Compare.h>
#include <Perceptron.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <math.h>


class Dataset {

public:

 inline Dataset () {}; 
  void trainPerceptrons (string masterFile);
  std::vector<string> readMasterFile(string masterFile);
  void buildClusters (string masterFile, int kVal);
  void compareClusters(int kVal);
 
private:
 	std::vector<Cluster> clusters;
	std::vector<Image> training;
	std::vector<Perceptron> pTrons; //perceptron classes in same order as classNumbers
	std::vector<int> classNumbers; //used to track the order of classes stored in perceptron vector

};

#endif //Dataset_H_