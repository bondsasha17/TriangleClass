#pragma once


 class triangle
{
private:
	 float a;
	 float b;
	 float c;
	 
	
public:
	
	triangle();
	triangle( float, float, float);
	void setSides( float, float,  float);
	void getSides(float*);
	float getSides(int);
	bool isValid();
	void Increase(float);
	void Decrease(float);
	float mediumLine(char);
	void angles(float* );
	float angles(int);
	int type();
};

