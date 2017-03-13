// —lassTraining.cpp: „Î‡‚Ì˚È Ù‡ÈÎ ÔÓÂÍÚ‡.

#include "stdafx.h"
#include "triangle.h"
#include <iostream>
#include "math.h"

using namespace System;
using namespace std;

void  printSidesValues(triangle trg)
	{
	    cout<<" sides of the triangle: ";
		for ( int i=0; i<3;i++)
		{
			if (i!=0)
			cout<<"-";
			cout<<trg.getSides(i);
		}
		cout<<"\n";
	}


int main(array<System::String ^> ^args)
{
	//int n;
    //cout<<"How many tiangles do you  want to create?\n";
	//cin>>n;
	int n=3;
	triangle *arrayTriangle;
	arrayTriangle = new triangle[n];
	
	/*for ( int i=0; i<n;i++)
	{
		 float a;
		 float b;
		 float c;
		cout<<"Enter the triangle sides\n";
		bool flag=true;
		
		while (flag)
		{	
			cin>>a>>b>>c;
			arrayTriangle[i].setSides(a,b,c);
		    flag=!arrayTriangle[i].isValid();
			if(flag==true)
			cout<<"This triangle dosen't exist. Enter the triangle sides again \n";
		}
		arrayTriangle[i].setSides(a,b,c);
		
		
			
}*/ 
	   arrayTriangle[0].setSides(1,1,1);
	   arrayTriangle[1].setSides(5,4,3);
	   arrayTriangle[2].setSides(9,5,5);

	for ( int i=0; i<n;i++)
	{
		cout<<"Triangle "<<i+1;
		printSidesValues(arrayTriangle[i]);
	}

	select:
	int selectedT;
	cout<<"Choose a triangle (1, 2 or 3)\n";
	cin >> selectedT;
	if (selectedT != 1 && selectedT != 2 && selectedT != 3)
	{
		cout<<"Enter 1, 2 or 3 to select a triangle\n";
		goto select;
	}

	action:
	cout<<"Choose an action:\n";
	cout<<"1 - Increase(percent)\n";
	cout<<"2 - Decrease(percent)\n";
	cout<<"3 - Medium line\n";
	cout<<"4 - Calculate angles\n";
	cout<<"5 - Get triangles' type\n";
	int selectedA;
	cin >> selectedA;
	if (selectedA != 1 && selectedA != 2 && selectedA != 3 && selectedA != 4 && selectedA != 5)
	{
		cout<<"Enter 1, 2, 3, 4 or 5 to select an action\n";
		goto action;
	}

	if (selectedA == 1)
	{
		float percent;
		cin >> percent;
		arrayTriangle[selectedT-1].Increase(percent);
		printSidesValues(arrayTriangle[selectedT-1]);
	} else if (selectedA == 2)
	{
		float percent;
		cout << "Enter persent \n";
		cin >> percent;
		arrayTriangle[selectedT-1].Decrease(percent);
		printSidesValues(arrayTriangle[selectedT-1]);
	} else if (selectedA == 3)
	{
		char side;
		cout << "Pick the triangle side (a, b or c) \n";
		cin >> side;
		cout<<arrayTriangle[selectedT-1].mediumLine(side)<<"\n";
	} else if (selectedA == 4)
	{
		for(int i=0; i<3;i++)
		{
			cout<<arrayTriangle[selectedT-1].angles(i)<<"\n";
		}
	} else if (selectedA == 5)
	{
		if (arrayTriangle[selectedT-1].type()==1)
		{
			cout<<"right triangle\n";
		}
		else
		{ 
			if(arrayTriangle[selectedT-1].type()==2)
			{
				cout<<"blunt triangle\n";
			}
			else 
			{
				cout<<"sharp triangle\n";
			}
		}
	}

	char tryAgain;
	cout << "Try again? (y/n)";
	cin >> tryAgain;
	if (tryAgain == 'y')
		goto select;

	/*cout<<"Medium line is "<<arrayTriangle[0].mediumLine('a')<<"\n";
	arrayTriangle[0].Increase(50);
	cout<<"Incresing ";
	arrayTriangle[0].printSidesValues();
	
	arrayTriangle[0].Decrease(50);
	cout<<"Dicresing ";
	arrayTriangle[0].printSidesValues();
	arrayTriangle[0].type();
	arrayTriangle[0].angles();*/

	
	system("pause");
    return 0;
}
