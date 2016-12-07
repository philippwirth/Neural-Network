#include "NN_Matrix.h"


/* sets matrix[i,j] = v */
void NN_Matrix::set(int i, int j, float v) {
	matrix[i*m + j] = v;
}

/* returns matrix[i,j] */
float NN_Matrix::get(int i, int j) const {
	return matrix[i*m + j];
}

/* returns a copy of the matrix */
NN_Matrix NN_Matrix::copy() {
	
	NN_Matrix result(this->n, this->m);
	for (int i=0; i<this->n; i++) {
		for (int j=0; j<this->m; j++) {
			result.set(i,j,get(i,j));
		}
	}

	return result;
}

/* returns the transpose of the matrix */
NN_Matrix NN_Matrix::transpose() {

	NN_Matrix result(this->m, this->n);
	for (int i=0; i<this->n; i++) {
		for (int j = 0; j<this->m; j++) {
			result.set(j, i, get(i,j));
		}
	}

	return result;
}

/* performs pointwise multiplication of two matrices */
NN_Matrix NN_Matrix::pointwiseMultiply(const NN_Matrix& other) {

	NN_Matrix result(this->n, this->m);

	for (int i=0; i<this->n; i++) {
		for (int j=0; j<this->m; j++) {
			result.set(i, j,  get(i,j) * other.get(i,j));
		}
	}

	return result;
}

/* performs the multiplication result = this*other */
NN_Matrix NN_Matrix::multiply(const NN_Matrix& other) {

	int resn = this->n;
	int resm = other.m;

	NN_Matrix result(resn, resm);
	
	for (int i=0; i<this->n; i++) {
		for (int j=0; j<other.m; j++) {
			float temp = 0;
			for (int k=0; k<this->m; k++) {
				temp += get(i, k) * other.get(k, j); 
			}
			result.set(i,j, temp);
		}
	}

	return result;
}
