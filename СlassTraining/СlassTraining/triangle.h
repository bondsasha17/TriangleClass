#pragma once


 class triangle
{
private:
	 float a;
	 float b;
	 float c;
	
public:
	triangle(void);
	triangle::triangle( float, float, float);
	void setSides( float, float,  float);
	float* getSides();
	void printSidesValues();
	bool isValid();
	void Increase(float);
	void Decrease(float);
	float mediumLine(char);
	float angles();
	void type();
};

