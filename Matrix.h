#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

/*
 * ²�檺�x�}�ۥ[�M�ۭ�
 */
 
class Matrix {
private:
	double ** data;			// �@�ӤG����double�x�}
	int row;			// �x�sdata�@���X��row
	int col;			// �x�sdata�@���X��col
	void setUp(int, int);		// utility function, �]�wrow�Mcol����
	
	static int count;

public:
	Matrix();			// default constructor, ���򳣤���, �Ndata�s�J2*2���O0����
	Matrix(int, int);		// constructor, �u�]�w�j�p, ��ƹw�]��0
	Matrix(int, int, double [],int);// constructor, �N�ǤJ���@���}�C��s���G���}�C��Jdata��
	Matrix(const Matrix &);		// copy constructor
	~Matrix();			// destructor, �M�zdata

	void setData(int, int, double);	// �]�w��(r,c)��mdata����

	int getRow() const;		// �^��private member: row
	int getCol() const;		// �^��private member: col
	double getData(int, int) const;	// ����x�}(r,c)��m����

	
	static int getCount();
	
	Matrix add(const Matrix &);		// �x�}�ۥ[, �^�Ǭۥ[�᪺�x�}
	Matrix multiply(const Matrix &);	// �x�}�ۭ�, �^�Ǭۭ��ᤧ�x�}
	Matrix transpose();	// �x�}��m, �^����m�᪺�x�}
    
	void displayData() {	// �N�o�ӯx�}����ƦL�X�� (�����ק�)
		for (int i = 0;i<row; i++) {
			for (int j = 0;j<col; j++) {
					cout<<data[i][j]<<"\t";
    			}
			cout<<""<<endl;
		}
	}
	
	
	friend Matrix operator+(Matrix&, const Matrix&);
	Matrix operator+(const double&);
	Matrix& operator=(const Matrix&);
	Matrix& operator+=(const Matrix&);
	Matrix operator++(int);
	friend Matrix operator*(Matrix&, const Matrix&);
	Matrix operator()();
	bool operator==(const Matrix&);
	friend ostream& operator<<(ostream&, const Matrix&);
	friend istream& operator>>(istream&, Matrix&);
};

#endif
