#include <Cluster.h>

using namespace std;

Cluster::Cluster (string imageName):image(imageName) {
	
	//cout<<"		In Cluster Constructor"<<endl;
	clusterImages.push_back(image);
	//cout<<"Name of new Image: "<< image.getFileName() <<endl;
	calculateAvg();
}

void Cluster::calculateAvg () {


	float temp;

	if (!clusterAvg.empty())
		clusterAvg.clear();

	for (int i = 0; i < 64; i++) {
		temp = 0;
		clusterAvg.push_back(0);
		for (int j = 0; j < (int) clusterImages.size(); j++) {
			temp += clusterImages[j].getNormalValue(i);
		}
		clusterAvg[i] = temp/(int) clusterImages.size();
	}
	
}

void Cluster::printClusters () {

	for (int i = 0; i < (int) clusterImages.size(); i++) {

		//cout<<"Printing clusters from printClusters" << endl;

		cout << clusterImages[i].getFileName() << " ";

		// for (int j = 0; j < 64; j++){
		// 	cout << clusterAvg[j] << ":";
		// }
	}

	cout << "\n" << endl;
}
