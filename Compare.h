#ifndef Compare_H_
#define Compare_H_

#include <Histogram.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <math.h>


class Compare {

public:

 float Denominator(std::vector<float> normalizedOne, std::vector<float> normalizedTwo, float bias);
 float sumOfSquaredDifferences(std::vector<float> firstFile, std::vector<float> secondFile);

private:
 

};

#endif //Compare_H_