#ifndef Cluster_H_
#define Cluster_H_

#include <Image.h>
#include <Compare.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <math.h>

using std::vector;
using std::string;

class Cluster {

public:

 Cluster(string imageName);
 void printClusters();
 //void mergeClusters(Cluster firstCluster, Cluster secondCluster);
 void calculateAvg();
 //float compareClusters (std::vector<float>, std::vector<float>);
 
	inline float getClusterIndex (int index) const {return clusterAvg[index];}
	inline int getNumHistograms () {return (int) clusterImages.size();}
	inline Image getImage (int index) {return clusterImages[index];}
	inline void addImage(Image newImage) {clusterImages.push_back(newImage);}

	inline int getNumImages () const {return clusterImages.size();}
	inline int getCategory () const {return image.getCategory();}




private:
 vector<float> clusterAvg;
 Image image;
 vector<Image> clusterImages;




};

#endif //Cluster_H_
