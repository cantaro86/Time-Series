#!/usr/bin/env python3

"""
Created on Sun Feb 23 17:08:07 2020

@author: Nicola Cantarutti
"""


import pandas as pd
import numpy as np

# read data from csv
filename1 = "time_series.csv"
data = pd.read_csv(filename1, usecols=[1,2], parse_dates=True)


print("mean:")
print(data.mean())
print()
print("variance:")
print(data.var())
print()
print("standard deviation:")
print(data.std())
print()
print("correlation between GOOGL and AAPL: ", data.corr().iloc[0,1])

print()

# moving average
print("moving average:")
window = 30
df = data.rolling(window).mean().dropna()
print(df.reset_index().drop("index",1).tail())
