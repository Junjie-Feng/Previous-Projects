# Name : Junjie Feng
# Course : SE II
# Homework 3 : Bayesian Curve Fitting
# Date of submission : Feb 26 2016
import numpy as np
import math
import pylab as pl
# store data function
def store(filename):
    file = open(filename)
    data = []
    for i in file:
            data.append(float(i))
    return(data)

#get the mean fucntion
def Mean(x, sPhiTn, beta, m):
    phiXT = []
    for i in range(m+1):
        phiXT.append(math.pow(x, i))
    phiXT = np.matrix(phiXT)
    return beta*np.dot(phiXT, sPhiTn)

#get the error function
def errors(data, start):
    alpha = 0.005
    beta = 11.1
    #the highest order of the curving polynamial function
    m =5
    #n is the size of data set.
    n = 10

    #initial the real data set
    tn = data[start:start+n]

    #calculate phi(X) matrix
    #1^0 2^1 .......n^1
    #1^1 2^2 .......n^2
    #...
    #1^m    .......n^m
    phi = []
    for i in range(n):
        phiX = []
        for j in range(m+1):
            element = [math.pow(i+1, j)]
            phiX.append(element)
        phi.append(np.matrix(np.array(phiX)))

    #calculate the matrix S (m+1*m+1)
    I = np.matrix(np.identity(m+1))
    sIn = I*alpha
    #sum the dot product of phi(x) and phi(x)'s transfer
    for i in range(n):
        sIn += beta*np.dot(phi[i], phi[i].getT())
    s = sIn.getI()

    #calculate S * phi(x) * real data
    phiTn = 0
    for i in range(n):
        phiTn += phi[i]*tn[i]
    #dot product of S and phi
    sPhiTn = np.dot(s, phiTn)

    predicted_value = Mean(n+1,sPhiTn,beta,m)

    error = 0
    sum = 0
    for i in range(n):
        error += abs(tn[i] - Mean(i+1,sPhiTn,beta,m))
        sum += tn[i]
    #print round(float(predicted_value),2), "\t\t\t\t", round(data[start+n],2), "\t\t\t", round(float(error/n),3), "\t\t", round(float(error/sum),3)*100,"%"
    print round(float(predicted_value),2), "\t\t\t\t", round(float(error/n),3), "\t\t", round(float(error/sum),3)*100,"%"

# main function
def main():
    data = store("data_set.csv")
    print "predicted value     expected value     AME        ARE"
    for i in range(10):
    	errors(data, 17*i)

    data1 = [28.32,28.5,27.91,27.37,28.26,28.55,28.65,29.05,28.64,28.11]
    data2 = [25.67,26.87,28.55,29.32,28.26,28.55,30.18,32.11,29.14,28.11]
    data3 = [125.67,126.87,128.55,132.44,123.55,128.88,130.12,134.5,139.21,137.45]
    data4 = [325.67,331.87,331.55,330.42,333.55,332.88,330.12,334.5,335.21,334.45]
    data5 = [1325.67,1321.87,1331.55,1334.52,1333.15,1328.88,1324.12,1330.35,1335.21,1334.45]
    data6 = [27,30,47,30,53,28,39,16,22,22]
    #print "predicted value     AME        ARE"
    #errors(data6, 0)

if __name__=='__main__':
    main()