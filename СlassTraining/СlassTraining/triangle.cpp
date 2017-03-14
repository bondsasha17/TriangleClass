#include "StdAfx.h"
#include "triangle.h"
#include <iostream>
#include "cmath"
using namespace std;


	triangle::triangle()
	{
	}
	triangle::triangle( float _a,  float _b, float _c)
	{
		setSides(_a, _b, _c);
	}

	void triangle:: setSides( float _a,  float _b, float _c) 
	 { 
			a=_a;
			b=_b;
			c=_c;
	 }

	
	float  triangle::angles(int i)
	{
		switch(i) {
		case 0: return acos((b*b+c*c-a*a)/(2*b*c));
		case 1: return acos((a*a+c*c-b*b)/(2*c*a));
		case 2: return acos((b*b+a*a-c*c)/(2*b*a));

		}
	}
	void triangle::angles(float* angles)
	{
		angles[0]= acos((b*b+c*c-a*a)/(2*b*c));
		angles[1]= acos((a*a+c*c-b*b)/(2*c*a));
		angles[2]= acos((b*b+a*a-c*c)/(2*b*a));
	}

	float  triangle::getSides(int i)
	{
		switch(i) {
		case 0: return a;
		case 1: return b;
		case 2: return c;

		}
	}

	void triangle:: getSides(float* sides) 
	{
		
		sides[0]=a;
		sides[1]=b;
		sides[2]=c;	   
		
	};
	bool triangle::isValid()
	{
	
		if(a<=0 || b<=0 || c<=0 || a+b<=c || a+c<=b || c+b<=a)
			 return false;
		else 
			return true;
	}


	float triangle::mediumLine(char x)
    {
		if (x =='a')
		{
			return (a)/2;
		}
		if (x =='b')
		{
			return (b)/2;
		}
		if (x =='c')
		{
			return (c)/2;
		}
	}
	void triangle::Increase( float p)
	{
		a=a+(a*p)/100.0;
		b=b+(b*p)/100.0;
		c=c+(c*p)/100.0;
		
	}
	void triangle::Decrease(float p)
	{
		a=a-(a*p)/100.0;
		b=b-(b*p)/100.0;
		c=c-(c*p)/100.0;
		
	}

	int triangle::type()

	{
		if(a*a+b*b==c*c || a*a+c*c==b*b || c*c+b*b==a*a)
			return TRIANGLE_90 ;//прямоугольный
		else
		{
			if(a*a+b*b<c*c || a*a+c*c<b*b || c*c+b*b<a*a)
				return TRIANGLE_B;//blunt triangle;
			else
			{
				if(a*a+b*b>c*c || a*a+c*c>b*b || c*c+b*b>a*a)
					return TRIANGLE_S;// #
			}
		}
		
	}