

def binsearch (A, value):
    low = 0
    high = len(A) - 1

    while low <= high :
        mid = (low + high) / 2
        if A[mid] > value :
            high = mid -1
        elif A[mid] < value :
            low = mid + 1
        else :
            return mid
    return None

def rbinsearch (A, value):
    low = 0
    high = len(A) - 1

    # Invarianten:
    #  value > A[i] for all i < high
    #  value < A[i] for all i > low

    while low <= high :
        mid = (low + high) / 2
        if A[mid] < value :
            high = mid -1
        elif A[mid] > value :
            low = mid + 1
        else :
            return mid
    return None


print binsearch(list([0,1,2,3,4,5,6,7,8,9]), 5)
print rbinsearch(list([9,8,7,6,5,4,3,2,1,0]), 8)