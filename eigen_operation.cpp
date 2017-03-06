/*************************************************************************
    > File Name: eigen_operation.cpp
    > Author: Tengyue MA
    > Mail: 1754187681@qq.com 
    > Created Time: 2017年03月05日 星期日 23时36分26秒
 ************************************************************************/

#include<iostream>
#include<eigen3/Eigen/Eigen>
using namespace Eigen;
using namespace std;

//向量的点积、叉积
void Vector_dot_cross();
//转置、伴随、行列式、逆矩阵
void Matrix_transpose_adjoint_determinant_inverse();
//计算特征值和特征向量
void Matrix_values();
//解线性方程
void Matrix_linearEquation();

//----------------------------------------------------------

//向量的点积、叉积
void Vector_dot_cross(){
	Vector3d v1(1, 2, 3);
	Vector3d v2(3, 2, 1);

	//点积的结果是个数
	cout << "v1.dot(v2) = " << v1.dot(v2) << endl;
	//叉积结果是个向量
	cout << "v1.cross(v2) = "  << endl << v1.cross(v2) << endl;
}

//转置、伴随、行列式、逆矩阵
void Matrix_transpose_adjoint_determinant_inverse(){
	Matrix3d matrix;
	matrix << 1, 6, 9,
			  4, 2, 7,
			  8, 5, 3;

	cout << "transpose:" << endl << matrix.transpose() << endl;
	cout << "adjoint:" << endl << matrix.adjoint() << endl;
	cout << "determinant:" << endl << matrix.determinant() << endl;
	cout << "inverse:" << endl << matrix.inverse() << endl;
}	

//计算特征值和特征向量
void Matrix_values(){
	Matrix3d a;
	a << 1, 2, 3,
		 4, 5, 6,
		 7, 8, 9;

	cout << "Here is the matrix A:" << endl << a << endl;
	SelfAdjointEigenSolver<Matrix3d> eigensolver(a);
	if (eigensolver.info() != Success)
		abort();
	cout << "values:" << endl << eigensolver.eigenvalues() << endl;
}

//解线性方程
void Matrix_linearEquation(){
	Matrix4d a;
	a << 2, -1, -1, 1,
		 1,  1,	-2,	1,
		 4, -6,	 2,-2,
		 3,  6, -9,	7;

	Vector4d b(2, 4, 4, 9);

	Vector4d x1 = a.colPivHouseholderQr().solve(b);
	Vector4d x2 = a.llt().solve(b);
	Vector4d x3 = a.ldlt().solve(b);

	cout << "x1:" << x1 << endl << "x2:" << x2 << endl << "x3:" << x3 << endl; 
}

int main(int argc, char ** argv){
	//向量的点积、叉积
	Vector_dot_cross();
	//转置、伴随、行列式、逆矩阵
	Matrix_transpose_adjoint_determinant_inverse();
	//计算特征值和特征向量
	Matrix_values();
	//解线性方程
	Matrix_linearEquation();
	
	return 0;
}
