using namespace std;
#ifndef VECTOR_H
#define VECTOR_H
#pragma once
#include <iostream>
#include "Point.h"
#include <vector>
#include <queue>
#include <string>

class Vector : public Point
{
public:
	double n1;
	double n2;
	double n3;
	Point A;
	Point B;
	double get_vector_n1();
	double get_vector_n2();
	double get_vector_n3();
	Point get_vector_A();
	Point get_vector_B();
	void set_vector_n1(double N1);
	void set_vector_n2(double N2);
	void set_vector_n3(double N3);
	void set_vector_A(Point a);
	void set_vector_B(Point b);
	Vector(std::queue<std::string> cmds);
	Vector(double X, double Y, double Z);
	Vector(Point x, Point y);
	Vector();
	double get_vector_length();
	bool is_vector_null();
	bool is_vector_null(int x, int y, int z);
	double vector_direction_by_pts();
	vector<double> get_direction_by_nums();
	void print_direction();
	bool is_parallel(Vector v);
	double operator*(const Vector& v); //Returns the scalar product of 2 vectors
	bool is_vector_perpendicullar(const Vector& v);
	Vector operator+(const Vector& v);
	Vector operator-(const Vector& v);
	double operator()(const Vector& v1, const Vector v2);
	friend Vector operator*(double num, const Vector& v); // Multiplies vector by a real number
	friend Vector operator^(const Vector& v1, const Vector& v2); // Multiplies two vectors
	string get_data();
	std::ostream& ins(std::ostream&) const;
	std::istream& ext(std::istream&);
};

#endif 