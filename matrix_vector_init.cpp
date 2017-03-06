/*************************************************************************
    > File Name: matrix_vector_init.cpp
    > Author: Tengyue MA
    > Mail: 1754187681@qq.com 
    > Created Time: 2017年03月05日 星期日 23时10分18秒
 ************************************************************************/

#include<iostream>
#include<eigen3/Eigen/Eigen>
using namespace Eigen;
using namespace std;

int main(int argc, char ** argv){
	//MatrixXd（double类型） MatrixXf（float类型）
	MatrixXf matrix1(3, 3); //动态矩阵，建立3行3列
	MatrixXd matrix2(4, 3); //4行3列，依此类推

	Vector3d vector1; //静态数组，不用指定行或者列
	
	/* 初始化 */
	Matrix4d matrix = Matrix4d::Random();
	matrix1 = MatrixXf::Zero(3, 3); //用0矩阵初始化,要指定行列数
	matrix2 = MatrixXd::Identity(4, 3); //用单位矩阵初始化
	vector1 = Vector3d::Zero(); //静态的，不用指定行列数

	matrix1 << 1, 2, 3,  //也可以以这种方式初始化
			   4, 5, 6,
			   7, 8, 9;

	//向量初始化，与矩阵类似
	Vector3d vector2(1, 2, 3);
	VectorXf vectorx(2);

	//print matrix & vector
	cout << "matrix = " << endl << matrix << endl;
	cout << "matrix1 = " << endl << matrix1 << endl;
	cout << "matrix2 = " << endl << matrix2 << endl;
	cout << "vector1 = " << endl << vector1 << endl;
	cout << "vector2 = " << endl << vector2 << endl;
	cout << "vectorx = " << endl << vectorx << endl;

	return 0;
}
