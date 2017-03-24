PA10: Image.o Histogram.o Perceptron.o Dataset.o main.o Cluster.o Compare.o
	g++ -Wall -O3 -I. *.o -o PA10

Image.o: Image.cpp Image.h
	g++ -Wall -O3 -I. -c Image.cpp

Histogram.o: Histogram.cpp Histogram.h
	g++ -Wall -O3 -I. -c Histogram.cpp

Cluster.o: Cluster.cpp Cluster.h
	g++ -Wall -O3 -I. -c Cluster.cpp

Compare.o: Compare.cpp Compare.h
	g++ -Wall -O3 -I. -c Compare.cpp

Dataset.o: Dataset.cpp Dataset.h
	g++ -Wall -O3 -I. -c Dataset.cpp

Perceptron.o: Perceptron.cpp Perceptron.h
	g++ -Wall -O3 -I. -c Perceptron.cpp

main.o: main.cpp Histogram.h Image.h Perceptron.h #Cluster.h Compare.h Dataset.h
	g++ -Wall -O3 -I. -c main.cpp

clean:
	rm *.o PA10
