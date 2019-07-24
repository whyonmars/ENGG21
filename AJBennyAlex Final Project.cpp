#include <fstream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
string Header()
{
  cout << "ENGG11 CMD Stat[Version 4.0]" << endl;
  cout << "CMD Basic Statistics Software\n";
  cout << "----------------------------------------" << endl;
  cout << "| Univariate\n";
  cout << "| ---Mead\n";
  cout << "| ---Median\n";
  cout << "| ---Mode\n";
  cout << "| ---Population//Sample Standard Deviation\n";
  cout << "| ---Variance\n";
  cout << "| ---Max Value\n";
  cout << "| ---Min Value\n";
  cout << "| Bivariate\n";
  cout << "| ---Correlation Coefficient\n";
  cout << "| ---Coefficient of Determination\n";
  cout << "| ---Statistics of Least Square Fit Residuals\n";
  cout << "| ---Line Equation of the Regression\n";
  cout << "----------------------------------------" << endl;
  cout << "Commands: [command] \n";
  cout << "[.] - exit\n";
  cout << "----------------------------------------" << endl;
}
string export1(); //Univariate;
string export2(); //Multivariate
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
}

double getRegression(vector <double> a, vector <double> b, vector <double> datavec)
{
  int n=datavec.size();
  double sum_X = 0, sum_Y = 0, sum_XY = 0;
  double squareSum_X = 0, squareSum_Y = 0;

  cout << endl << "---------------------Linear Regression---------------------"<< endl;
  cout <<endl<<"X-Data Values\tY-Data Values\t   Residuals \t          SSE\t       SST " << endl;

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
    cout << "\t\t    "<<value2*a[i]+value1;
    cout << "\t\t    "<<(b[i]-(value2*a[i]+value1))*(b[i]-(value2*a[i]+value1));
    cout << "\t\t    "<<(b[i]-(n/sum_Y))*(b[i]-(n/sum_Y))<< endl; ///Need to fix
  }
    cout << endl<<"The line equation of the regression  is y = " << value2 <<" x " << "+" <<value1 << endl;
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

  cout << "The Correlation Coefficient (r) = " << corr << endl;
  cout << "Coefficient of Determination (r^2) = " << corr2 << endl;
}

double getMeasuresOfLocation(vector<double> datavec)
{
  int n=datavec.size();
  double y,z,median, mode, counter,counter1;
  cout << "----------------------------------------" << endl;
  cout << "Data Values: ";

  //Mean
  for(int i = 0; i<n; i++)
  {
    y = y + datavec[i];
    cout << " " << datavec[i];
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

double getSampleVariance(vector<double> datavec) //Sample Variance
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
  cout << "----------------------------------------" << endl;
}

double getPopulationVariance(vector<double> datavec) //Population Variance
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
  cout << "----------------------------------------" << endl;
}


int main()
{
  system("title CMD Stat");
  vector<double> datavec,a,b,q,w;
  double data;
  char choice,choice1,choice2,choice4;
  int countX = 0, countY = 0,countXY = 0;
  string name,name1,name2,name3;

  startE:
  Header();
  cout << "\nSelect Number of Data Variables:\n[1] Univariate Data: \n";
  cout << "[2] Bivariate Data: \n";
  cout << "Stat:|> ";
  //give global command options
  cin >> choice;

  switch (choice)
  {
    case '1': //Univariate
    {
      startG:
      cout<< endl<< "\nEnter the filename of the univariate data: \n";
      cout << "Stat:|Univariate> ";
      cin>>name;
      if (name == ".")
      {
        cout << "\nProgram Terminated\n";
        return 0;
      }
      name=name+".txt";
      ifstream file (name.c_str());
      if (!file.is_open())
      {
        system("CLS");
        Header();
        cout << "\nSorry, the file can't be opened\n";
        cout << "\nSelect another file\n";
        goto startG;
      }

      else
      {
        while (file >> data)
        {
          datavec.push_back(data);
        }
      }

      cout <<"[1] - sample\n[2] - population: \n";
      cout << "Stat:|Univariate> ";
      cin>>choice1;

      switch(choice1)
      {
        case '1':
          getMeasuresOfLocation(datavec);
          getSampleVariance(datavec);
          break;
        case '2':
          getMeasuresOfLocation(datavec);
          getPopulationVariance(datavec);
          break;
      }
      break;
    }
    case '2': //Bivariate
    {
      cout << "\nFile source: \n";
      cout<<"[1] - X-Y data in One File\n[2] - X-Y data in Separate Files " << endl;
      cout << "Stat:|Bivariate> ";
      cin>>choice2;

      switch(choice2)
      {
        case '1':
        {
          startH:
          cout<< "\nEnter the filename of the bivariate data: \n";
          cout << "Stat:|Bivariate|One> ";
          cin>>name1;
          name1=name1+".txt";

          ifstream file (name1.c_str());
          if (!file.is_open())
          {
            cout << "\nThere was a problem opening the input file!\n";
            goto startH;
          }
          while (file>>data)
          {
            countXY++;
            datavec.push_back(data);
          }
          if ((countXY % 2) != 0) //Checks for the validity of data in the file
          {
            cout << "The selected file is invalid\n";
            cout << "There is an odd number of data in the file\n";
            cout << "Please select another file\n";
            datavec.clear();
            countXY = 0;
            file.close();
            goto startH;
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
          goto startF;
          break;
        }
        case '2': //for the separate files
        {
          startJ:
          cout << "Enter filename of X-data: \n";
          cout << "Stat:|Bivariate|Separate|X> ";
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
            countX++;
            q.push_back(data);
          }
          startK:
          cout << "Enter filename of Y-data: \n";
          cout << "Stat:|Bivariate|Separate|Y> ";
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
            countY++;
            w.push_back(data);
          }
          if (countX != countY)//Checks for the validity of the selected files
          {
            cout << "The selected file is invalid\n";
            cout << "There is an odd number of data in the file\n";
            cout << "Please select another file\n";
            countX = 0;
            countY = 0;
            file.close();
            file1.close();
            q.clear();
            w.clear();
            goto startJ;
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
        case '.':
          cout << "\nProgram Terminated\n";
          return 0;
          break;
    }
      default: goto startE;
    }
    startF:
    cout << endl<<"---Do you want to use the calculator again?--- \n [1] YES \n [2] NO";
    cout << endl << "Enter your choice: " ;
    cin >> choice4;
    cout << endl;

    switch(choice4)
    {
      case '1': //YES
      {
        cout << endl<< endl;
        datavec.clear();
        a.clear();
        b.clear();
        q.clear();
        w.clear();
        system("CLS");
        goto startE;
        break;
      }
      case '2': //NO
      {
        cout << "Program Ended";
        break;
      }
      case '.': //universal exit
      {
        cout << "\nProgram terminated\n";
        //return 0;
        break;
      }
      default:
        system("CLS");
        Header();
        cout << "\nInvalid Input\n";
        goto startF;
    }
}
