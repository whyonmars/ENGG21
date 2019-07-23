#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
double findMode(vector<double> datavec)//function in finding the mode
{
  int data, counter, num, max = 0, modes = 0;
  vector<int> repeat;
  vector<int> mode;

  for (int a = 0; a < datavec.size(); a++)//goes through each element of datavec
  {
    counter = 0;
    num = datavec[a];
    for(int b = a; b < datavec.size(); b++)
    {
      if (num == datavec[b])
      {
        counter++;
      }
    }
    repeat.push_back(counter);
  }
  for (int c = 0; c < repeat.size(); c++)//loops for the most number of occurences
  {
    if (repeat[c] > max)
    {
      max = repeat[c]; //updates  the most max when a number greater than current max is found
    }
  }
  for (int d = 0; d < repeat.size(); d++)
  {
    if (max == repeat[d])
    {
      modes++;
      mode.push_back(datavec[d]);
    }
  }
  if (mode.size() == 1)//conditions in checking the number of modes
  {
    cout << "The mode is: " << mode[0];
  }
  else if (mode.size() > 1)
  {
    cout << "The modes are: ";
    for (int a = 0; a < mode.size(); a++)
    {
      cout << mode[a] << " ";
    }
  }
  else
  {
    cout << "There is no mode";
  }
  cout << endl;
  //be sure to clear variables--
}

double getRegression(vector <double> a, vector <double> b, vector <double> datavec)
{
  int n=datavec.size();
  double sum_X = 0, sum_Y = 0, sum_XY = 0;
  double squareSum_X = 0, squareSum_Y = 0;

  cout <<endl<<"X-Data Values\tY-Data Values\t   Residuals " << endl;

  for (int i = 0; i < n/2; i++)
  {
    sum_X = sum_X + a[i];

    sum_Y = sum_Y + b[i];

    sum_XY = sum_XY + (a[i] * b[i]);
    squareSum_X = squareSum_X + (a[i] * a[i]);
    squareSum_Y = squareSum_Y +( b[i] * b[i]);
  }

  double numeratorA = (sum_Y*squareSum_X)-(sum_X*sum_XY);
  double denominator = (n/2)*(squareSum_X)-pow(sum_X,2);

  double numeratorB = (n/2)*(sum_XY)-(sum_X*sum_Y);


  double value1 = numeratorA/denominator;
  double value2 = numeratorB/denominator;


  for (int i = 0; i < n/2; i++)
  {
    cout << "  " << a[i];
    cout << "\t\t    " << b[i];
    cout << "\t\t    "<<value1*a[i]+value2 << endl;
  }
    cout << endl<<"The line equation of the regression  is y = " << value1 <<" x " << "+" <<value2 << endl;
}

double getCoefficient(vector <double> a, vector <double> b, vector <double> datavec)
{
  int n=datavec.size();
  double sum_X = 0, sum_Y = 0, sum_XY = 0;
  double squareSum_X = 0, squareSum_Y = 0;

  for (int i = 0; i < n/2; i++)
  {
    sum_X = sum_X + a[i];
    sum_Y = sum_Y + b[i];
    sum_XY = sum_XY + (a[i] * b[i]);

    squareSum_X = squareSum_X + (a[i] * a[i]);
    squareSum_Y = squareSum_Y +( b[i] * b[i]);
  }

  double numerator = (((n/2) * sum_XY) - (sum_X * sum_Y));
  double denominator = sqrt((((n/2) * squareSum_X) - (sum_X * sum_X) ) * (((n/2) * squareSum_Y )- (sum_Y * sum_Y)));
  double corr = numerator/denominator;
  double corr2 = pow(corr,2);

  cout << "The Correlation Coefficient = " << corr << endl;
  cout << "Coefficient of Determination = " << corr2 << endl;
}

double getMeasuresOfLocation(vector<double> datavec)
{
  int n=datavec.size();
  double y,z,median, mode, counter,counter1;
  cout << "Data Values: ";

  //Mean
  for(int i = 0; i<n; i++)
  {
    y = y + datavec[i];
    cout <<"  " << datavec[i];
  }
  cout<<endl<<"Mean: "<<y/n<<endl;

  //Median
  sort(datavec.begin(),datavec.end()); //Arranges the data
  if (n % 2 != 0)
  {
    median = datavec[n / 2];
  }
  else
  {
    median = (datavec[(n - 1) / 2] + datavec[n / 2]) / 2.0;
  }
  cout <<"The median is " << median << endl;

  //Mode
  findMode(datavec);

  //Maximum_and_Minimum
  cout << "The data's minimum is "<< datavec.front() << endl;
  cout << "The data's maximum is "<< datavec.back() << endl;
}

double getSampleVariance(vector<double> datavec)
{
  int n=datavec.size();
  double sumSquared=0;
  double sumANDsquared=0;
  double SAvariance;

  for(int i=0; i<datavec.size();i++)
  {
    sumSquared=sumSquared+datavec[i]*datavec[i];
    sumANDsquared=datavec[i]+sumANDsquared;
  }
  sumANDsquared=sumANDsquared*sumANDsquared;
  SAvariance=(n*sumSquared-sumANDsquared)/(n*(n-1));
  cout<<"Variance of the Data is: "<<SAvariance<<endl;
  cout<<"Standard Deviation is: "<<sqrt(SAvariance)<<endl;
}

double getPopulationVariance(vector<double> datavec)
{
  int n=datavec.size();
  double sumSquared=0;
  double sumANDsquared=0;
  double POPvariance;

  for(int i=0; i<datavec.size();i++)
  {
    sumSquared=sumSquared+datavec[i]*datavec[i];
    sumANDsquared=datavec[i]+sumANDsquared;
  }
  sumANDsquared=sumANDsquared*sumANDsquared;
  POPvariance=(n*sumSquared-sumANDsquared)/(n*(n));
  cout<<"Variance of the Data is: "<<POPvariance<<endl;
  cout<<"Standard Deviation is: "<<sqrt(POPvariance)<<endl;
}


int main()
{
  vector<double> datavec,a,b,q,w;
  double data;
  int choice,choice1,choice2,choice4;
  string name,name1,name2,name3;

  startE:
  cout<<"Choose: [1] Univariate Data, [2] Bivariate Data: ";
  cin>>choice;

  switch (choice)
  {
    case 1:
    {
      startG:
      cout<< endl<< "Enter the filename of the univariate data: ";
      cin>>name;
      name=name+".txt";
      ifstream file (name.c_str());
      if (!file.is_open())
      {
        cout << "Sorry, the file can't be open";
        goto startG;
      }
      else
      {
        while (file >> data)
        {
          datavec.push_back(data);
        }
      }

      cout<<"Is the data a [1]sample or [2]population: ";
      cin>>choice1;

      switch(choice1)
      {
        case 1:
          getMeasuresOfLocation(datavec);
          getSampleVariance(datavec);
          break;
        case 2:
          getMeasuresOfLocation(datavec);
          getPopulationVariance(datavec);
          break;
      }
      break;
    }
    case 2:
    {
      cout<<"X-Y Data is in [1]One File, [2]Separate File: ";
      cin>>choice2;

      switch(choice2)
      {
        case 1:
        {
          startH:
          cout<< "Enter the filename of the bivariate data: ";
          cin>>name1;
          name1=name1+".txt";

          ifstream file (name1.c_str());
          if (!file.is_open())
          {
            cout << "There was a problem opening the input file!\n";
            goto startH;
          }
          while (file>>data)
          {
            datavec.push_back(data);
          }
          for(int i =0; i<datavec.size(); i++)
          {
            double data= datavec[i];
            if(i%2==0)
            {
              a.push_back(data);
            }
            else
            {
              b.push_back(data);
            }
          }
          getRegression(a,b,datavec);
          getCoefficient(a,b,datavec);
          break;
        }
        case 2:
        {
          startJ:
          cout << "Enter filename of X-data: ";
          cin >> name1;
          name1=name1+".txt";

          ifstream file (name1.c_str());
          if (!file.is_open())
          {
            cout<< "There was a problem opening the input file!\n";
            goto startJ;
          }
          while (file >> data)
          {
            q.push_back(data);
          }
          startK:
          cout << "Enter filename of Y-data: ";
          cin >> name2;
          name2=name2+".txt";
          ifstream file1 (name2.c_str());

          if (!file1.is_open())
          {
            cout << "There was a problem opening the input file!\n";
                        goto startK;
          }
          while (file1 >> data)
          {
            w.push_back(data);
          }

          for (int v = 0; v < ((q.size())+(w.size())); v++)
          {
            datavec.push_back(0);
          }
          for (int z = 0; z < datavec.size(); z+=2)
          {
            datavec[z] = q[z/2];
            datavec[z+1] = w[z/2];
          }

          for(int i =0; i<datavec.size(); i++)
          {
            double data= datavec[i];

            if(i%2==0)
            {
              a.push_back(data);
            }
            else
            {
              b.push_back(data);
            }
          }
          getRegression(a,b,datavec);
          getCoefficient(a,b,datavec);
          break;
        }
      }
        break;
    }
      default: goto startE;
    }
    startF:
    cout << endl<<"---Do you want to use the calculator again?--- \n [1] YES \n [2] NO" << endl << "Enter your choice: " ;
    cin >> choice4;
    cout << endl;

    switch(choice4)
    {
      case 1:
      {
        cout << endl<< endl;
        goto startE;
        break;
      }
      case 2:
      {
        cout << "Program Ended";
        break;
      }
      default: goto startF;
    }
}

