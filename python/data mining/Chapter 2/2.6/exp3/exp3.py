def ReadData(filename):
    file = open(filename,'r')
    rowList = file.readlines()
    return rowList

def CollateData(rowList):
    dataArr = []
    labelArr = []
    for strLine in rowList:
        strLine = strLine.strip()
        listLine = strLine.split('\t')
        # listLine = list(map(float,listLine))
        labelArr.append(listLine[21])
        listLine.pop()
        dataArr.append(listLine)
    return {'dataArr':dataArr,'labelArr':labelArr}

rowList = ReadData('horseColic.txt')
collatedDict = CollateData(rowList)
print('dataArr:')
print(collatedDict['dataArr'][:3])
print('\nlabelArr:')
print(collatedDict['labelArr'][:3])