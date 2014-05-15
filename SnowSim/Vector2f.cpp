#include "Vector2f.h"
#include <cmath>
#include <stdio.h>
#include "float.h"

//CONSTRUCTORS
Vector2f::Vector2f(){
	this->setPosition(0, 0);
}
Vector2f::Vector2f(float val){
	this->setPosition(val);
}
Vector2f::Vector2f(float x, float y){
	this->setPosition(x, y);
}
Vector2f::Vector2f(const Vector2f& orig) {
	this->setPosition(orig[0], orig[1]);
}
Vector2f::~Vector2f(){}

//OPERATIONS
void Vector2f::setPosition(float val){
	setPosition(val, val);
}
void Vector2f::setPosition(float x, float y){
	loc[0] = x;
	loc[1] = y;
}
void Vector2f::setPosition(const Vector2f &v){
	setPosition(v.loc[0], v.loc[1]);
}

void Vector2f::normalize(){
	*this /= this->length();
}
const float Vector2f::dot(const Vector2f &v) const{
	return v.loc[0]*loc[0] + v.loc[1]*loc[1];
}
const float Vector2f::sum() const{
	return loc[0] + loc[1];
}
const float Vector2f::product() const{
	return loc[0] * loc[1];
}
const float Vector2f::length() const{
	double sum = 0;
	for (int i=0; i<2; i++)
		sum += loc[i]*loc[i];
	return sqrt(sum);
}
const Matrix2f Vector2f::trans_product(const Vector2f& v) const{
	return Matrix2f(
		loc[0]*v.loc[0], loc[0]*v.loc[1],
		loc[1]*v.loc[0], loc[1]*v.loc[1]
	);
}

//OVERLOADS
//Array subscripts
float& Vector2f::operator[](int idx){
	return loc[idx];
}
const float& Vector2f::operator[](int idx) const{
	return loc[idx];
}

//SCALAR OVERLOADS
//Vector * Scalar
const Vector2f operator*(const float& c, const Vector2f& v){
	return Vector2f(v)*c;
}
const Vector2f Vector2f::operator*(const float& c) const{
	return Vector2f(*this) *= c;
}
Vector2f& Vector2f::operator*=(const float& c){
	loc[0] *= c;
	loc[1] *= c;
	return *this;
}
//Vector / Scalar
const Vector2f operator/(const float& c, const Vector2f& v){
	return Vector2f(v)/c;
}
const Vector2f Vector2f::operator/(const float& c) const{
	return Vector2f(*this) /= c;
}
Vector2f& Vector2f::operator/=(const float& c){
	loc[0] /= c;
	loc[1] /= c;
	return *this;
}
//Vector + Scalar
const Vector2f operator+(const float& c, const Vector2f& v){
	return Vector2f(v)+c;
}
const Vector2f Vector2f::operator+(const float& c) const{
	return Vector2f(*this) += c;
}
Vector2f& Vector2f::operator+=(const float& c){
	loc[0] += c;
	loc[1] += c;
	return *this;
}
//Vector - Scalar
const Vector2f operator-(const float& c, const Vector2f& v){
	return Vector2f(v)-c;
}
const Vector2f Vector2f::operator-(const float& c) const{
	return Vector2f(*this) -= c;
}
Vector2f& Vector2f::operator-=(const float& c){
	loc[0] -= c;
	loc[1] -= c;
	return *this;
}

//VECTOR OVERLOADS
//Vector / Vector (piecewise division)
const Vector2f Vector2f::operator/(const Vector2f& v) const{
	return Vector2f(*this) /= v;
}
Vector2f& Vector2f::operator/=(const Vector2f& v){
	loc[0] /= v.loc[0];
	loc[1] /= v.loc[1];
	return *this;
}
//Vector * Vector (dot product)
const Vector2f Vector2f::operator*(const Vector2f& v) const{
	return Vector2f(*this) *= v;
}
Vector2f& Vector2f::operator*=(const Vector2f& v){
	loc[0] *= v.loc[0];
	loc[1] *= v.loc[1];
	return *this;
}
//Vector ^ Vector (cross product)
const Vector2f Vector2f::operator^(const Vector2f& v) const{
	return Vector2f(*this) ^= v;
}
Vector2f& Vector2f::operator^=(const Vector2f& v){
	//TODO: this may be incorrect...
	float v1 = loc[0]*v.loc[1],
		  v2 = -loc[1]*v.loc[0];
	loc[0] = v1;
	loc[1] = v2;
	return *this;
}
//Vector + Vector
const Vector2f Vector2f::operator+(const Vector2f& v) const{
	return Vector2f(*this) += v;
}
Vector2f& Vector2f::operator+=(const Vector2f& v){
	loc[0] += v.loc[0];
	loc[1] += v.loc[1];
	return *this;
}
//Vector - Vector
const Vector2f Vector2f::operator-(const Vector2f& v) const{
	return Vector2f(*this) -= v;
}
Vector2f& Vector2f::operator-=(const Vector2f& v){
	loc[0] -= v.loc[0];
	loc[1] -= v.loc[1];
	return *this;
}
//Unary negation
const Vector2f Vector2f::operator-() const{
	return Vector2f(-loc[0], -loc[1]);
}