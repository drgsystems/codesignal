#!/usr/bin/env python3

def solution(inputArray):
    sum1=inputArray[0] + inputArray[1]
    for i in range(1,(len(inputArray)-1)) :
        sum2=inputArray[i] * inputArray[i+1]
        if(sum2 > sum1) : sum1 = sum2
    return sum1

myarray=[3,6,-2,-5,7,3]
print("original array =",myarray,"\n")
print("largest two adjacent elements multiplied together = ",solution(myarray))
