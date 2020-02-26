/*
Created on Sun Feb 23 17:07:27 2020
@author: Nicola Cantarutti
*/



#ifndef TIMESERIES_HPP
#define TIMESERIES_HPP



#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;



class TimeSeries
{
  
private:

  vector<double> series;


public:

  // constructors:
  
  TimeSeries(){};
  TimeSeries(const vector<double>& vec);
  TimeSeries(const double *vec, int len);


  // useful methods:
  
  double& operator[](unsigned long i);
  
  // read a column from a .csv file. If skip_header is true, it skips the first line.
  void read_csv(string filename, unsigned int column=0, bool skip_header=true);

  int length();                      // length of the series
  void append(double value);         // appends a value 

  double mean();   // mean of the series
  double var();    // unbiased variance of the series
  double std();    // unbiased standard deviation of the series

  double corr( TimeSeries &series2 );   // correlation of the current time series with series2

  TimeSeries moving_average(unsigned int window);  // moving average
  // return by value is optimized by the compiler (RVO). No need to use pointers or to define a copy constructor here.

  
  // print methods:
  
  void print_all();   // prints all the series
  void head();        // prints top 5
  void tail();        // prints bottom 5
  
};


#endif
