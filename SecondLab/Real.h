#pragma once

class Real
{
private:
	float numb;
public:
	Real();
	explicit Real(float value);
	~Real();
	Real(const Real& real_copy);
	void set_num(float& num);
	float get_num();
	Real& operator=(float r); 
	//Real& operator=(const Real& r);
	Real& operator --(); //префиксная форма
	friend Real& operator --(Real& r, int); //постфиксная форма
	Real& operator ++(); //префиксная форма
	friend Real& operator ++(Real& r, int); //постфиксная форма
	void print();
};
