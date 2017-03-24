#include <Dataset.h>

using namespace std;


void Dataset::trainPerceptrons (string masterFile) {

  
  bool classTracker = false;
	vector<string> fileNames =  readMasterFile(masterFile);

  //Build Vector of images 
  for (int i = 0; i < (int) fileNames.size() ; i++ ) { 

    Image *temp = new Image(fileNames[i]);
    training.push_back(*temp);
    if (i > 0) {
      for (int j = 0; j < (int) classNumbers.size(); j++) {
        if (training[i].getCategory() == classNumbers[j]) //If the class# is already stored it wont store another one. 
          classTracker = true;
      }
      if (classTracker == false)
        classNumbers.push_back(training[i].getCategory()); //Stores the class# in a vector to know how many perceptrons to make
    }
    classTracker = false; //resets class tracker
    delete temp;
  }

  int N;
  for (int i = 0; i < (int) classNumbers.size(); i++) {
    N = classNumbers[i];
  	Perceptron *perceptron = new Perceptron(training, N); //N is the class# to build the perceptron with
  	//perceptron -> epoch(N);
    pTrons.push_back(*perceptron);

  }

  // for (int i = 0; i < (int) classNumbers.size(); i++) {
  //   cout << i << " stored class: " << classNumbers[i] << endl;
  // }


}



vector<string> Dataset::readMasterFile (string masterFile) {

  string names;
  ifstream namesFile (masterFile);
  vector<string> fileNames;

  if (namesFile.is_open()) {
    while (namesFile >> names) {
      
      //if (!names.empty())
      fileNames.push_back(names);
      //namesFile >> skipws;
    }

    
    namesFile.close();
  }
  else throw 3; //Throws error if it cannot open master file
  return fileNames;
}
void Dataset::buildClusters (string masterFile, int kVal) {

	int k = kVal;

	vector<string> fileNames = readMasterFile(masterFile);

  if (fileNames.size() < 2) {throw 9;} //Throws error if there are not 2 files in master file***
  if (k < 1 || k > (int) fileNames.size()) {throw 11;}//Throws error if clusters desired in < 1 or > total images

	for (int i = 0; i < (int) fileNames.size(); i++) {

		Cluster *temp = new Cluster(fileNames[i]);
		clusters.push_back(*temp);
		delete temp;
    //cout << "Cluster Catagory: " << clusters[i].getCategory() << endl;
	}

  compareClusters(k);

}

void Dataset::compareClusters (int kVal) {

	int k = kVal;

	//cout<<"Comparing clusters---------------------"<<endl;


	if ((int) clusters.size() == k) {
		//cout<<"K = Total clusters: Going to print"<<endl;
			for (int i = 0; i < (int) clusters.size(); i++){

				clusters[i].calculateAvg();
				//clusters[i].printClusters();
			}
	}
	else {

		//Compare compare;
		float similarity, tempVal; //bias;
		int clusterOne = 0, clusterTwo = 0, tempOne, tempTwo;
    double score, denomI, denomJ, denominator;


		while ((int) clusters.size() != k) {
			similarity = 0;

//First two for loops interate through the clusters to compare similarities 
			for (int i = 0; i < (int) clusters.size(); i++) {
				tempOne = i;

				for (int j = i+1; j < (int) clusters.size(); j++) {
					tempTwo = j;
					//tempVal = compare.compareHistograms(clusters[tempOne].getClusterAvg(), clusters[tempTwo].getClusterAvg());
          tempVal = 0;

//Last two for loops build the similarity values by taking the sum of the clusters*allperceptron measures 
          for (int c = 0; c < (int) classNumbers.size(); c++) {
           // bias = pTrons[c].getBias();
            for (int w = 0; w < 64; w++) {
              denomI = ((pTrons[c].getIndexWeight(w) * clusters[i].getClusterIndex(w)));
              denomJ = ((pTrons[c].getIndexWeight(w) * clusters[j].getClusterIndex(w)));
              denominator = (denomI - denomJ + .001);
              //cout << denomI << " - " << denomJ << " == " << denominator << endl; 
            }
            score = (1/(pow(denominator, 2)));
            //cout << "Score is Equal to: " << score << endl;
            tempVal = tempVal + score;
            score = 0;
          }

					if (tempVal > similarity) {
						//cout << "similarity: " << tempVal << " comparing files: " << tempOne << " & " << tempTwo << endl;
						similarity = tempVal;
						clusterOne = tempOne;
						clusterTwo = tempTwo;
					}
				}
			}
			for (int i = 0; i < clusters[clusterTwo].getNumHistograms(); i++) { 
				clusters[clusterOne].addImage(clusters[clusterTwo].getImage(i));
			}
			clusters[clusterOne].calculateAvg();
			clusters.erase(clusters.begin()+clusterTwo);
		}
		
		for (int i = 0; i < (int) clusters.size(); i++) { 
			clusters[i].printClusters();
			
		}
	}

  }
