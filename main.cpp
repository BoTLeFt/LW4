#include <stdlib.h>
#include <iostream>
#include <cmath>

class Number //Абстрактный класс, т.к. чистые виртуальные функции
{
protected:
	float value;
public:
	Number(float v)
	{
		value = v;
	}
	virtual float GetAbs() = 0;
	virtual void Print() = 0;
};

class Float : public Number //Наследник от абстрактного класс
{
public:
	Float (float v):Number(v)
	{
	}
	float GetAbs() override
	{
		return abs(value);
	}
	void Print() override
	{
		std::cout << "Value " << value << " Absolute: " << GetAbs();
	}
};
class Complexity : public Float //Наследник от наследника абстрактного класса
{
	float imagine;
public:
	Complexity(float v, float i):Float(v)
	{
		imagine = i;
	}
	float GetAbs()
	{
		return sqrt(value*value + imagine * imagine);
	}
	void Print()
	{
		Float::Print();
		std::cout << " Imagine: " << imagine;
	}
};

int main()
{
	Float Pi(3.14);
	Float E(-2.87);
	Complexity Complex(3, 4);
	Complexity Comp(5, 12);
	Number *p[] = {&Pi, &E, &Complex, &Comp};
	for(int i=0; i<4; i++)
	{
		p[i]->Print();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}