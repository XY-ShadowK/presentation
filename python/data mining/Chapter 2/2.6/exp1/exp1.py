def BuildList():
    SList = []
    n = int(input('input length of list : '))
    for i in range(n):
        temp = int(input('input value : '))
        SList.append(temp)
    return SList

def BuildListWithoutN():
    strList = input('input all value in list in one line : ')
    SList = strList.split(' ')
    SList = list(map(int,SList))
    return SList

def BubblingSort(listOrigin):
    length = len(listOrigin)
    needLen = length
    flag = True
    while flag:
        flag = False
        for i in range(needLen):
            if i == needLen-1:
                break
            if listOrigin[i] > listOrigin[i+1]:
                temp = listOrigin[i+1]
                listOrigin[i+1] = listOrigin[i]
                listOrigin[i] = temp
                flag = True
        needLen -= 1
    return listOrigin

# lst = BuildList()
lst = BuildListWithoutN()
lst = BubblingSort(lst)
print(lst)