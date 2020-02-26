Time Series test library
============================


List of files:

- TimeSeries.hpp     (header file, containing the class TimeSeries)        
- TimeSeries.cpp     (file containing implementations of TimeSeries methods)
- main.cpp           (file with main function. It contains some examples of the class usage)
- test.py            (python3 program used for comparison) 
- Makefile        
- time_series.csv    (time series of recent AAPL and GOOGL prices)



In order to compile the C++ files, enter in the terminal the command:

>> make

and then run it by:

>> ./main


The Makefile calls the gcc compiler. Do not use other compilers (i.e. clang++) because I wrote some lines of code not compatible. 
I'm using the gcc version: 
gcc (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609   


In order to run the python file, just enter:

>> chmod +x test.py
>> ./test.py


COMMENTS:

I thought the meaning of the exercise was to create a "library" from scratch (well, I used the STL std::vector powerful properties).
For this reason I decided to use C++ and to create the class TimeSeries. In my opinion this class is easily extendable, by adding new member functions or member data.

I also wrote a short python3 script (test.py) that uses pandas, in order to compare the output.
(pandas is great!!)
