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
	Real& operator --(); //���������� �����
	friend Real& operator --(Real& r, int); //����������� �����
	Real& operator ++(); //���������� �����
	friend Real& operator ++(Real& r, int); //����������� �����
	void print();
};
