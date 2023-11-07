# -*- coding: utf-8 -*-
"""
Created on Sun Sep 25 11:57:20 2022

@author: jrits
"""
import pandas as pd

file = open('C:\\Users\\jrits\\Desktop\\Set2B(practice)\\doc1.txt')
str1 = file.read()
file.close()

file = open('C:\\Users\\jrits\\Desktop\\Set2B(practice)\\doc2.txt')
str2 = file.read()
file.close()

file = open('C:\\Users\\jrits\\Desktop\\Set2B(practice)\\doc3.txt')
str3 = file.read()
file.close()

file = open('C:\\Users\\jrits\\Desktop\\Set2B(practice)\\doc4.txt')
str4 = file.read()
file.close()

punc = '''!()-[]{};:'"\,<>./?@#$%^&*_~'''

for ele in str1:
    if ele in punc:
        str1 = str1.replace(ele, "")
str1 = str1.lower()
        
for ele in str2:
    if ele in punc:
        str2 = str2.replace(ele, "")
str2 = str2.lower()
        
for ele in str3:
    if ele in punc:
        str3 = str3.replace(ele, "")
str3 = str3.lower()
        
for ele in str4:
    if ele in punc:
        str4 = str4.replace(ele, "")
str4 = str4.lower()

li1 = list(str1.split())
print(li1)

li2 = list(str2.split())
print(li2)

li3 = list(str3.split())
print(li3)

li4 = list(str4.split())
print(li4)

lest =[]

for x in li1:
        if x not in lest:
            lest.append(x)
            
for x in li2:
        if x not in lest:
            lest.append(x)
            
for x in li3:
        if x not in lest:
            lest.append(x)
            
for x in li4:
        if x not in lest:
            lest.append(x)
            
import numpy as np
lst = np.array(lest)
lst = np.unique(lest)
        
print(lst)

#question 2

dict1 = {}
for i in range(len(lst)):
        if (lst[i] in li1):
            dict1[lst[i]] = li1.count(lst[i])
        else:
            dict1[lst[i]] = 0
print(dict1)
           
dict2 = {}
for i in range(len(lst)):
        if (lst[i] in li2):
            dict2[lst[i]] = li2.count(lst[i])
        else:
            dict2[lst[i]] = 0
print(dict2)
            
dict3 = {}
for i in range(len(lst)):
        if (lst[i] in li3):
            dict3[lst[i]] = li3.count(lst[i])
        else:
            dict3[lst[i]] = 0
print(dict3)
            
dict4 = {}
for i in range(len(lst)):
        if (lst[i] in li4):
            dict4[lst[i]] = li4.count(lst[i])
        else:
            dict4[lst[i]] = 0
print(dict4)
            
df = pd.DataFrame([dict1,dict2,dict3,dict4])
print(df)

y=[]
for i,j in df.iterrows():
    x = list(j)
    y.append(x)
    a = np.array(y)
print(a)

#creating similarity matrix
b=[]
for i in range(4):
    z=[]
    moda = np.linalg.norm(a[i])
    for j in range(4):
        ddot = np.dot(a[i],a[j])
        modb = np.linalg.norm(a[j])
        prod = moda * modb
        z.append(ddot/prod)
    b.append(z)
    similarity_matrix = np.array(b)
print(similarity_matrix)
        


