#ifndef NN_NEURALNETWORK
#define NN_NEURALNETWORK

#include "NN_Matrix.h"
#include "NN_Layer.h"
#include <vector>
#include <stdlib.h>

#define USEBIAS 1	// USEBIAS 1 adds a bias input to each layer
#define ACTFUN 1	// TODO: add more activation functions (0 = linear, 1 = sigmoidal)

class NN_NeuralNetwork {

	public:
		/* Constructor & Destructor */
		NN_NeuralNetwork() {};
		NN_NeuralNetwork(int _nLayers, int* _layerDims) : nLayers(_nLayers) {
			
			// initialize layers
			this->nWeights = 0;
			for (int i=1; i<nLayers+1; i++) {
				NN_Layer currLayer(_layerDims[i], _layerDims[i-1], ACTFUN, USEBIAS);
				layers.push_back(currLayer);
				this->nWeights += (_layerDims[i-1]+USEBIAS) * _layerDims[i];
			}
			
			// initialize weights
			srand48(time(0));
			setWeightsRandom();

			// set input and output dimension
			this->inputDimension = _layerDims[0];
			this->outputDimension = _layerDims[nLayers];
		}

		~NN_NeuralNetwork() {}


		/* Access Functions */
		int getInputDimension();		// returns the input dimension of the nn
		int getOutputDimension();		// returns the output dimension of the nn

		int getNumberOfWeights();		// returns the number of weights used by the nn
		void getWeights(float* _weights); 	// returns the weights used by the nn
		void setWeights(float* _weights);	// sets the weights of the nn to _weights
		void setWeightsRandom();		// sets the weights of the nn randomly in [0,1]

		void getOutput(float* _output);		// returns the output computed by the nn

		/* Computations */
		void evaluate(float* input);		// evaluates the nn on an input

	private:
		int inputDimension, outputDimension;
		int nWeights;
		int nLayers;
		std::vector<NN_Layer> layers;
};

#endif
