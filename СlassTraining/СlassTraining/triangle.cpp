#include "StdAfx.h"
#include "triangle.h"
#include <iostream>
#include "cmath"
using namespace std;


	triangle::triangle(void)
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
	
	float triangle::angles()
	{
		float alpha;
		float betta;
		float gamma;
		alpha = acos((b*b+c*c-a*a)/(2*b*c));
		betta = acos((a*a+c*c-b*b)/(2*c*a));
		gamma = acos((b*b+a*a-c*c)/(2*b*a));
		cout<< "Angles: "<<alpha<<", "<<betta<<", "<<gamma<<".\n";
		return 0;

	}

	float* triangle:: getSides() 
	{
		float *sides=new float[3];
		sides[0]=a;
		sides[1]=b;
		sides[2]=c;	   
		return sides;
	};
	bool triangle::isValid()
	{
	
		if(a==0 || b==0 || c==0 || a+b<=c || a+c<=b || c+b<=a)
			 return false;
		else 
			return true;
	}


	void  triangle::printSidesValues()
	{
	    cout<<" sides of the triangle: ";
		for ( int i=0; i<3;i++)
		{
			if (i!=0)
			cout<<"-";
			cout<<getSides()[i];
		}
		cout<<"\n";
	}

	float triangle::mediumLine(char x)
    {
		if (x =='a')
		{
			return (getSides()[0])/2;
		}
		if (x =='b')
		{
			return (getSides()[1])/2;
		}
		if (x =='c')
		{
			return (getSides()[2])/2;
		}
	}
	void triangle::Increase( float p)
	{
		a=a+(a*p)/100.0;
		b=b+(b*p)/100.0;
		c=c+(c*p)/100.0;
		printSidesValues();
	}
	void triangle::Decrease(float p)
	{
		a=a-(a*p)/100.0;
		b=b-(b*p)/100.0;
		c=c-(c*p)/100.0;
		printSidesValues();
	}

	void triangle::type()

	{
		if(a*a+b*b==c*c || a*a+c*c==b*b || c*c+b*b==a*a)
			cout<<"right triangle\n";
		else
		{
			if(a*a+b*b<c*c || a*a+c*c<b*b || c*c+b*b<a*a)
				cout<<"blunt triangle\n";
			else
			{
				if(a*a+b*b>c*c || a*a+c*c>b*b || c*c+b*b>a*a)
					cout<<"sharp triangle\n";
			}
		}
		
	}