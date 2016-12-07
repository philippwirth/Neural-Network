#include "NN_Matrix.h"
#include "NN_Layer.h"

#include <math.h>

/* Access functions */

int NN_Layer::getInputDim() 
{
	return this->inputDim;
}

int NN_Layer::getOutputDim() 
{
	return this->nNeurons;
}
	
NN_Matrix NN_Layer::getWeights() 
{
	return weights.copy();
}

void NN_Layer::setWeight(int i, int j, float v) 
{
	this->weights.set(i,j,v);
}

NN_Matrix NN_Layer::getOutput() 
{
	return this->output.copy();
}

/* Computations */
	
void NN_Layer::evaluate(NN_Matrix input) {

	if (this->useBias) {
		// create biased input TODO: move to NN_Matrix
		int biasedN = input.getN() + 1;
		NN_Matrix biasedInput(biasedN, 1);
		for (int i=0; i<biasedN-1; i++) {
			biasedInput.set(i, 0, input.get(i,0));
		}
		biasedInput.set(biasedN-1, 0, 1.0);	
		
		// compute output via matrix multiplication
		this->output = this->weights.multiply(biasedInput);
	} else {
		// compute output via matrix multiplication
		this->output = this->weights.multiply(input);
	}	

	// apply activation function TODO: move to NN_Matrix
	double f;
	for (int i=0; i<this->output.getN(); i++) {
		switch (this->actFun)
		{
			case arctan: 
				f = 1/(1 + exp(-this->output.get(i,0)));	
				break;
			default:
				f = this->output.get(i,0);
		};
		this->output.set(i,0, f);
	}
}
