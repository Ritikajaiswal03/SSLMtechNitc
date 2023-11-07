
# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
#question 1

import pandas as pd
import numpy as np

student = pd.read_csv("C:\\Users\\jrits\\Desktop\\Student_marks.csv")

#print(student)

mean_math = student['math score'].mean()

mean_reading = student['reading score'].mean()

mean_writing = student['writing score'].mean()

student['math score'].fillna(mean_math,inplace = True)

student['reading score'].fillna(mean_reading,inplace = True)

student['writing score'].fillna(mean_writing,inplace = True)

mean_math = student['math score'].mean()

mean_reading = student['reading score'].mean()

mean_writing = student['writing score'].mean()

sd_math = student['math score'].std()

sd_reading = student['reading score'].std()

sd_writing = student['writing score'].std()

dict = {'math score' :[mean_math,sd_math],
        'reading score' :[mean_reading,sd_reading],
        'writing score' :[mean_writing,sd_writing]
        }

df = pd.DataFrame(dict)

df.index = ['Mean', 'Standard Deviation']

print(df)

#question 2

myDict = {}

for i in range(len(student)):
    mykey = 'S'+str(i+1)+"_"+student.loc[i,"group"].split()[1]
    myDict[mykey] = [student.loc[i,"math score"],student.loc[i,"reading score"],student.loc[i,"writing score"]]
    
ide = input()
   
print(myDict[ide])

#question 3

from collections import defaultdict
newdict = defaultdict(list)

for key,value in myDict.items():
    getgroup= key[-1]
    newdict[getgroup].append(value[0])
    
rows=[]
for key,value in newdict.items():
    cnt=0
    for i in range(len(value)):
        if(value[i]>50):
            cnt=cnt+1
    prob=cnt/len(value)
    rows.append([key,np.mean(value),np.std(value),prob])

table=pd.DataFrame(rows,columns=["Group","Mean math score","Stan. Dev. math score","Prob_scoring above 50_maths"])
a = table.sort_values(by ='Group', ascending = 1)
print(a.to_string(index=False))



