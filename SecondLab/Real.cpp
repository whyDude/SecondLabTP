#include "Real.h"
#include <iostream>
using namespace std;
Real::Real() : numb(0.0){}
Real::Real(float num)
{
	numb = num;
}

Real::~Real() {}
Real::Real(const Real& real_copy)
{
	this->numb = real_copy.numb;
}

Real& Real::operator= (float r)
{
	set_num(r);
	return *this;
}

//Real& Real::operator= (const Real& r)
//{
//	if (this == &r) //проерка на самоприсваивание
//		return *this;
//	numb = r.numb;
//	return *this;
//}

Real& Real :: operator --() 
{
	numb -= 0.1;
	return *this;
}
Real& Real:: operator ++()
{
	numb += 0.5;
	return *this;
}

Real& operator ++(Real& r, int) {
	Real temp(r);
	r.numb += 2.5;
	return temp;
}

Real& operator --(Real& r, int) {
	Real temp(r);
	r.numb -= 0.2;
	return temp;
}

void Real::set_num(float &value) { numb = value; }
void Real::print() { cout << numb << endl; }
float Real::get_num() 
{
	return this->numb;
}