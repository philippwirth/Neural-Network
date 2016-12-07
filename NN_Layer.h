#ifndef NN_LAYER
#define NN_LAYER

#include "NN_Matrix.h"

enum activationFunction {linear, arctan};

class NN_Layer
{

public:
	/* Constructor & Destructor */
	NN_Layer() {}
	NN_Layer(int _nNeurons, int _inputDim, int _actFun, int bias) : nNeurons(_nNeurons), inputDim(_inputDim+bias), weights(_nNeurons, _inputDim+bias), output(_nNeurons,1) {
		
		// set activation function
		switch (_actFun) {
			case 1:
				this->actFun = arctan;
				break;
			default:
				this->actFun = linear;
		};

		// set bias
		switch (bias) {
			case 0:
				this->useBias = false;
				break;
			default: 
				this->useBias = true;
		};
	}

	/* Access functions */
	int getInputDim();			// returns the input dimension of the layer
	int getOutputDim();			// returns the output dimension of the layer

		
	NN_Matrix getWeights();			// returns the weights of the layer
	void setWeight(int i, int j, float v);	// sets a weight at i,j in the weight matrix to v 

	NN_Matrix getOutput();			// returns the output of the layer

	/* Computations */	
	void evaluate(NN_Matrix input);		// evaluates the layer on a given input

	//TODO: backpropagation

private:

	int nNeurons, inputDim;
	NN_Matrix weights;
	NN_Matrix output;
	activationFunction actFun;
	bool useBias;
};

#endif
