//Code by Alex
#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

double getRegression(vector <double> a, vector <double> b, int n)
{	double c;
	double sum_X = 0, sum_Y = 0, sum_XY = 0;
    double squareSum_X = 0, squareSum_Y = 0;
	
	cout << "X-Data Values\tY-Data Values " << endl; 

for(int i = 0; i<a.size(); i++){
		sum_X = sum_X + a[i];

        sum_Y = sum_Y + b[i];

        sum_XY = sum_XY + (a[i] * b[i]);

        squareSum_X = squareSum_X + (a[i] * a[i]);
        squareSum_Y = squareSum_Y +( b[i] * b[i]);
	
		cout << "  " << a[i];
		cout << "\t\t    " << b[i] << endl; 
		
 }
		  cout << endl;

    
    double numeratorA = (sum_Y*squareSum_X)-(sum_X*sum_XY);
    double denominator = (n/2)*(squareSum_X)-pow(sum_X,2);

    double numeratorB = (n/2)*(sum_XY)-(sum_X*sum_Y);


    double value1 = numeratorA/denominator;
    double value2 = numeratorB/denominator;


    cout << "The line equation of the regression  is y = " << value2 <<" + " << value1 << "x" << endl<< endl;

}

double getCoefficient(vector <double> a, vector <double> b, int n)
{double c;
	double sum_X = 0, sum_Y = 0, sum_XY = 0;
    double squareSum_X = 0, squareSum_Y = 0;
	
	cout << "X-Data Values\tY-Data Values " << endl; 

for(int i = 0; i<a.size(); i++){
		sum_X = sum_X + a[i];

        sum_Y = sum_Y + b[i];

        sum_XY = sum_XY + (a[i] * b[i]);

        squareSum_X = squareSum_X + (a[i] * a[i]);
        squareSum_Y = squareSum_Y +( b[i] * b[i]);
	
		cout << "  " << a[i];
	
		cout << "\t\t    " << b[i] << endl; 
		
 }

    double numerator = (((n/2) * sum_XY) - (sum_X * sum_Y));
    double denominator = sqrt((((n/2) * squareSum_X) - (sum_X * sum_X) ) * (((n/2) * squareSum_Y )- (sum_Y * sum_Y)));
    double corr = numerator/denominator;
    double corr2 = pow(corr,2);

    cout << "The Correlation Coefficient = " << corr << endl;
    cout << "Coefficient of Determination = " << corr2 << endl<< endl;
}

double getLocation( vector <double> data,int n){
    double y, median, mode, counter, counter1;
    for(int i = 0; i<n; i++){y = y + data[i];}

    cout << "The mean is " << y/n << endl;

    sort(data.begin(),data.end());

    if (n % 2 != 0)
        median = data[n / 2];
    else{
        median = (data[(n - 1) / 2] + data[n / 2]) / 2.0;}

    cout <<"The median is " << median << endl;

    for(int z = 0; z<n; z++){
        counter = count (data.begin(), data.end(), data[z]);
        if(counter1 < counter){counter1 = counter; mode = data[z];}}


    if(counter1 == 1){ cout << "There is no mode" << endl;}
    else{cout <<"The mode is " << mode << endl;}

    cout << "The data's minimum is "<< data.front() << endl;
    cout << "The data's maximum is "<< data.back() << endl << endl;

}

double getVariance( vector <double> data,int n){
    int option1, option2;
    double xa, xb, y, var, sd;

start:
cout << "[1] Random Sample Variance" << endl << "[2] Sample Variance" << endl << "[3]Population Variance"<< endl;
cout << "Enter your choice: ";
cin >> option1;
cout << endl;

switch (option1){
        case 1:{

        for(int i = 0; i < n; i++){y = y + data[i];}
        xa = y*y;

        for(int i = 0; i<n; i++){ xb = xb +pow(data[i],2);}
        var = (((n*xb))-xa)/(n*(n-1));
        sd = pow(var, 0.5);
        cout << "The random sample variance is "<< var<<endl;
        cout << "The random sample standard deviation is "<<sd<<endl<< endl;
        break;
    }
    case 2:{
        for(int i = 0; i < n; i++){y = y + data[i];}
        xa = y/n;

        for(int i = 0; i < n; i++){xb = xb + pow((data[i] - xa),2);}
        var = xb/(n-1);

        sd = pow(var, 0.5);
        cout << "The sample variance is "<< var<<endl;
        cout << "The sample standard deviation is "<<sd<<endl<< endl;
    }

case 3:{
    for(int i = 0; i < n; i++){y = y + data[i];}
        xa = y/n;

        for(int i = 0; i < n; i++){xb = xb + pow((data[i] - xa),2);}
        var = xb/(n);

        sd = pow(var, 0.5);
        cout << "The population variance is "<< var<<endl;
        cout << "The population standard deviation is "<<sd<<endl<< endl;
}

defualt:  cout << "Invalid Answer. Try again." << endl<< endl; goto start;
}
}

int main (){
    int counter = 0;
    double num, num1;
    int option1, option, option2, option3;
    string name, name1;
    vector<double>data,a,b;

    cout << "Welcome to Sir Lui's Calculator" << endl << endl << "NOTE: Do NOT input WORDS if you don't want it to crash" << endl << endl;

  	startE:
    cout << "[1] Single Set of Data" << endl << "[2] X-Y Data Set" << endl;
    cout << "Enter your choice: "; cin >> option; cout << endl << endl;

    switch (option){

        case 1:{
        
		startG:
		
		cout << "Enter filename of X-data: "; cin >> name; cout <<endl;

        name=name+".txt";

        ifstream file (name.c_str());
        	if (!file.is_open()) { cerr << "There was a problem opening the input file!\n"; cout << endl; goto startG; }

        	while (!file.eof()) { file>>num; data.push_back(num);
        	counter++;}

       startC:
        	cout << "[1] Find Variance" << endl << "[2] Find Location Measures" << endl << "Enter your choice: " ;
        	cin >> option1;
        	cout << endl;
            switch(option1){
            	case 1:{getVariance(data,counter); break;}
            	case 2:{getLocation(data,counter); break;}
            	default: goto startC; 
        	}
        break;
        }

        case 2:{
        	startD:
        		
			cout << "Are the X-Y data separated in different files? \n [1]YES \n [2]NO \n" << "Enter your choice: " ; cin >> option3;
        
        	switch(option3){
				case 2:{		
        			cout << "Enter filename of X-Y-data: "; cin >> name; cout << endl;
        			name=name+".txt";
        			ifstream file (name.c_str());
        				if (!file.is_open()) { cerr << "There was a problem opening the input file!\n"; goto startD;}
        				while (!file.eof()) { file>>num; data.push_back(num);
        				counter++;
        				}
        			for(int i =0; i<counter; i++){
        			double num = data[i];
        			if(i%2==0){a.push_back(num);}
        			else{b.push_back(num);}
            		}
      			break;
				}	
      		
			  	case 1:{ 
				
        			cout << "Enter filename of X-data: "; cin >> name; cout << endl;
        			name=name+".txt";
        			ifstream file (name.c_str());
        				if (!file.is_open()) { cerr << "There was a problem opening the input file!\n"; goto startD;}
        				while (!file.eof()) { file>>num; a.push_back(num);
        				counter++;
        				}
        			file.close();
        
					cout << "Enter filename of Y-data: "; cin >> name1; cout << endl;
        			name1=name1+".txt";
        			ifstream file1 (name1.c_str());
        			if (!file1.is_open()) { cerr << "There was a problem opening the input file!\n"; goto startD;}
        			while (!file1.eof()) { file1>>num1; b.push_back(num1);
        			counter++;
        			}

      			break;
				}
				
				default: goto startD;
			}
        
			if(a.size() == b.size()){
			  startA:
        	cout << "[1] Find Coefficient of Determination" << endl << "[2] Find Linear Regression" << endl << "Enter your choice: " ;
        	cin >> option1;
        	cout << endl;

         	switch(option1){
            	case 1:{getCoefficient(a,b,counter); break;}
            	case 2:{getRegression(a,b,counter); break;}
            	default: goto startA;}
        	}

        	else{cout << "Enter an even amount of X-Y values" << endl << endl; 
			goto startD;}

        		break;}

       			default: cout << "Invalid Answer. Try again." << endl<< endl; goto startE;

    }
    
   
   
    
     startF:
	cout << "Do you want to use the calculator again? \n [1] YES \n [2] NO" << endl << "Enter your choice: " ;
	cin >> option2;
    cout << endl;
    
    switch(option2){
		case 1:
    	cout << endl<< endl;
    	goto startE;
		break;
	
		case 2:
		cout << "Program Ended";
		break;
	
		default: goto startF;
    }


    
}
