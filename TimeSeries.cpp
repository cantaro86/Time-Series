/*
Created on Sun Feb 23 17:07:27 2020
@author: Nicola Cantarutti
*/

#include "TimeSeries.hpp"


// constructors

TimeSeries::TimeSeries(const vector<double>& vec): series(vec) {}

TimeSeries::TimeSeries(const double *vec, int len): series(vec,vec+len) {}




// useful methods


double& TimeSeries::operator[](unsigned long i)
{
  return series.at(i);
}


void TimeSeries::read_csv(string filename, unsigned int column, bool skip_header)
{
  ifstream IN(filename, ios::in);
  unsigned int index = 0;

  if ( IN.is_open() )                        
    {
      string line;
      if (skip_header==true)                      
	getline(IN,line,'\n');
      
      while ( getline(IN,line,'\n') )
	{
	  stringstream ss(line);
	  string token;
	  unsigned int counter = 0;
	  while ( getline(ss, token, ',') )
	    {
	      if (counter == column)
		{
		  series.push_back(stod(token));
		  ++index;
		  break;
		}
	      ++counter;
	    }
	}
      IN.close();	
    }
  else
    {
      cout << "Unable to open " << filename << endl;
      exit(EXIT_FAILURE);
    }
}


int TimeSeries::length()
{
  return series.size();
}


void TimeSeries::append( double value)
{
  series.push_back(value);
}


double TimeSeries::mean()
{
  double sum=0;
  for (unsigned int i=0; i<series.size(); ++i )
    sum += series[i];
  return sum / series.size();
}


double TimeSeries::var()
{
  double sum=0;
  double mn = mean();
  for (unsigned int i=0; i<series.size(); ++i )
    sum += (series[i]-mn) * (series[i] - mn);
  return sum / (series.size()-1) ;
}


double TimeSeries::std()
{
  return sqrt(var()) ;
}


double TimeSeries::corr( TimeSeries &series2 )
{
  if (this->length() != series2.length())
    {
      cout << "Series have different lengths!! " << this->length() << " and " << series2.length() << endl;
      exit(EXIT_FAILURE);
    }
  
  double sum=0;
  double mn_1 = this->mean();
  double mn_2 = series2.mean();
  for (unsigned int i=0; i<series.size(); ++i )
    sum += (series[i] - mn_1) * (series2[i] - mn_2);
  return (sum / (series.size()-1)) / ( this->std() * series2.std() );
}


TimeSeries TimeSeries::moving_average(unsigned int window)
{
  if ( window > static_cast<unsigned int>(this->length()) )
    {
      cout << "window must be smaller than the series length!" << endl;
      exit(EXIT_FAILURE);
    } 

  TimeSeries moving_avg;

  double sum=0;
  double mn=0;
  for (unsigned int i=0; i<window; ++i)
    sum += series[i];
  mn = sum/window;
  moving_avg.append(mn);
  
  vector<double>::iterator it1, it2; 
  for(it1=series.begin(), it2=it1+window; it2!=series.end(); ++it1, ++it2 )
    {
      mn = mn + (*it2 - *it1)/window;
      moving_avg.append(mn);
    }
  return moving_avg;
}




// print methods

void TimeSeries::print_all()
{
  cout << "---------- Time Series ---------------" << endl;
  for ( unsigned int i=0; i<series.size(); ++i )
    cout << i << '\t' << series[i] << endl;
  cout << "--------------------------------------" << endl;
  cout << endl;
}

void TimeSeries::head()
{
  unsigned int size = series.size();
  cout << "------------- HEAD ----------------" << endl;
  for (unsigned int i=0; i<min( 5u, size); ++i )
      cout << i << '\t' << series[i] << endl;
  cout << "-----------------------------------" << endl;
  cout << endl;
}

void TimeSeries::tail()
{
  unsigned int size = series.size();
  unsigned int Min = min(5u, size);
  cout << "------------- TAIL ----------------" << endl;
  for (unsigned int i=0; i<Min; ++i )
    cout << series.size()+i-Min << '\t' << series[series.size()+i-Min] << endl;  
  cout << "----------------------------------" << endl;
  cout << endl;
}

