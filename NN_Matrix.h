#ifndef NN_MATRIX
#define NN_MATRIX

#include <iostream>

class NN_Matrix {

public:

	/* Constructor & Destructor */
	NN_Matrix() {}
	NN_Matrix(int _n, int _m) : n(_n), m(_m) {
		this->matrix = new float[n*m];
	}	
	~NN_Matrix();				


	/* Access functions */
	// value
	void set(int i, int j, float v);			// sets matrix[i,j] = v
	float get(int i, int j) const;				// returns matrix[i,j]

	// dimension
	void setDim(int _n, int _m);				// sets the dimension of the matrix to _n x _m
	int getN() {return n;};					// returns the number of rows of the matrix
	int getM() {return m;};					// returns the number of columns of the matrix

	// extend

	/* Computations */
	//void scale(float s);					// scales matrix by factor s
	NN_Matrix copy();					// creates a copy of the matrix
	NN_Matrix transpose();					// returns the transpose of the matrix
	NN_Matrix multiply(const NN_Matrix& other);		// result = this*other
	NN_Matrix pointwiseMultiply(const NN_Matrix& other); 	// pointwise multiply this*other

	/* print */
	void print() {

		for (int i=0; i<n; i++) {
			std::cout << "¦";
			for (int j=0; j<m; j++) {
				std::cout << matrix[i*m + j] << " ";
			}
			std::cout << "¦\n";
		}
	}

private:

	int n;		// n-dimension of an n x m matrix
	int m;		// m-dimension of an n x m matrix
	float* matrix;	

};

#endif
