#! /usr/bin/env python2.7

import sys, getopt, string, difflib

class Element:
    adj = 0 
    def __init__(self, adj):
        self.adj = adj
        return None
    def __repr__(self):
        return str(self.adj)


def calculate_cv (graph):

    cv = list();
    for element in graph:
        cv.insert(element.adj, element.adj)
        
#     while True:
#         do_something()
#         if condition():
#             break         
    
    print graph, cv


# list = list([
#             Element(1),
#             Element(2),
#             Element(3),
#             Element(1),
#             Element(3),
#             Element(1),
#             Element(3),
#             Element(2),
#             Element(2),
#             Element(2),
#             Element(3),
#             Element(1),
#             ])

test = list([
            Element(1),
            Element(3),
            Element(2),
            Element(3),
            Element(3),
            Element(3),
            Element(3),
            Element(1),
            Element(3),
            Element(2),
            Element(1),
            Element(2),
            Element(1),            
            ])



calculate_cv(test)

# test=0
# 
# 
# def merge(list1, list2):
#     
#     
#     if list1 is None or len(list1) == 0 :
#         return list2
#     if list2 is None or len(list2) == 0:
#         return list1
#     
#     print list1[0], "<=", list2[0]
#     if list1[0] <= list2[0] :
#         return list([list1[0]]) + merge (list1[1:], list2)
#     else :
#         return list([list2[0]]) + merge (list1, list2[1:])
#     
# 
# def mergesort (list):
#     if len(list) > 1 :
#         return merge(mergesort(list[:len(list)/2]), mergesort(list[len(list)/2:]))
#     else :
#         return list
# 
# 
# test = [8,6,3,7,9,1]
# print mergesort (test)