/*
Created on Sun Feb 23 17:07:27 2020
@author: Nicola Cantarutti
*/



#include "TimeSeries.hpp"


int main()
{

  // Example constructor 1
  
  vector<double> test1 = {10,20,30,40,50,60,70,1000}; 
  TimeSeries series1(test1);
  series1.print_all();
  
  // Example constructor 2
  
  unsigned int len = 10;
  double test2[len] = {33, 44, 55, 66, 88, 99, 140, 100, 102, 98}; 
  TimeSeries series2(test2,len);
  series2.head();

  // Read and modify values at specific time

  unsigned int i = 2;
  series2[i] = 1.77;
  cout << "The new value at index [" << i << "] is "  << series2[2] << endl;

  
  // Example default constructor + read from csv file
  
  string f_name = "time_series.csv";

  TimeSeries googl;
  TimeSeries aapl;
  aapl.read_csv(f_name, 1, true);
  googl.read_csv(f_name, 2, true);

  cout << "AAPL" << endl;
  aapl.tail();
  cout << "GOOGL" << endl;
  googl.tail();

  // Mean Var Std and Corr
  
  cout << "Mean AAPL = "  << aapl.mean()  << endl;
  cout << "Var AAPL = "   << aapl.var()   << endl;
  cout << "Std AAPL = "   << aapl.std()   << endl;
  cout << "Mean GOOGL = " << googl.mean() << endl;
  cout << "Var GOOGL = "  << googl.var()  << endl;
  cout << "Std GOOGL = "  << googl.std()  << endl;
  cout << "Corr[AAPL,GOOGL] = "  << aapl.corr(googl)  << endl;
  cout << "Corr[AAPL,AAPL] = "   << aapl.corr(aapl)   << endl;

  // Simple moving average

  cout << endl;
  cout << "Moving average:" << endl;
  
  cout << "AAPL: " << endl;
  TimeSeries moving_avg_a = aapl.moving_average(30);    // mooving average of AAPL
  moving_avg_a.tail();

  cout << "GOOGL: " << endl;
  TimeSeries moving_avg_g = googl.moving_average(30);    // mooving average of GOOGL
  moving_avg_g.tail();
  
  TimeSeries moving_avg1 = series1.moving_average(2);    // moving average of series1
  moving_avg1.print_all();

  return 0;
}
