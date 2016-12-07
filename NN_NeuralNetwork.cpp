#include <stdlib.h>

#include "NN_NeuralNetwork.h"

/* returns the input dimension of the nn */
int NN_NeuralNetwork::getInputDimension()
{
	return this->inputDimension;
}

/* returns the output dimension of the nn */
int NN_NeuralNetwork::getOutputDimension()
{
	return this->outputDimension;
}

/* returns the total number of weights of the nn */
int NN_NeuralNetwork::getNumberOfWeights()
{
	return this->nWeights;
}

/* returns all weights used by the nn */
void NN_NeuralNetwork::getWeights(float* _weights) 
{	
	// collect weights of all layers
	int weightIndex = 0;
	for (int i=0; i<nLayers; i++) {
		// iterate over the weight matrix to collect weights
		for (int j=0; j<layers[i].getInputDim(); j++) {
			for (int k=0; k<layers[i].getOutputDim(); k++) {
				_weights[weightIndex] = layers[i].getWeights().get(j,k);
				weightIndex += 1;
			}
		}
	}
}

/* sets the weigths of the nn to _weights */
void NN_NeuralNetwork::setWeights(float* _weights) 
{	
	// set weights of all lyers
	int weightIndex = 0;
	for (int i=0; i<nLayers; i++) {
		// iterate over the weight matrix to set weights
		for (int j=0; j<layers[i].getOutputDim(); j++) {
			for (int k=0; k<layers[i].getInputDim(); k++) {
				layers[i].setWeight(j,k, _weights[weightIndex]);
				weightIndex += 1;
			}
		}
	}
}

/* initializes the weights of the nn randomly in [0,1] */
void NN_NeuralNetwork::setWeightsRandom() 
{
	for (int i=0; i<nLayers; i++) {
		for (int j=0; j<layers[i].getOutputDim(); j++) {
			for (int k=0; k<layers[i].getInputDim(); k++) {
				layers[i].setWeight(j,k, drand48());
			}
		}
	}
}

/* stores the output of the nn in _output */
void NN_NeuralNetwork::getOutput(float* _output) {
	for (int i=0; i<this->outputDimension; i++) {
		_output[i] = layers[nLayers-1].getOutput().get(i,0);
	}
}

/* evaluates the nn on a given _input */
void NN_NeuralNetwork::evaluate(float* _input) {

	// create NN_Matrix to store input
	NN_Matrix input(this->inputDimension, 1);
	for (int i=0; i<this->inputDimension; i++) {
		input.set(i,0, _input[i]);
	}
	
	// propagate input
	NN_Matrix temp;
	layers[0].evaluate(input);	

	for (int i=1; i<nLayers; i++) {
		temp = layers[i-1].getOutput();
		layers[i].evaluate(temp);
	}
}
