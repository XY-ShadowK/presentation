import json

def BuildDict():
    holidayDict = {}
    # 2016年5月有31天
    for i in range(31):
        day = i+1
        keyDay = '1605'
        fill = ''
        if day < 10:
            fill = '0'
        keyDay = keyDay + fill + str(day)
        holidayDict[keyDay] = 0
        # 5月1日是周日
        # 不管节日，只认为周末放假
        dModSeven = day % 7
        if dModSeven == 0 or dModSeven == 1:
            holidayDict[keyDay] = 1
    return holidayDict

def saveDict(filename,dictSave):
    file = open(filename,'w')
    json.dump(dictSave,file)
    file.close
    return

def readDict(filename):
    file = open(filename,'r')
    dictRead = json.load(file)
    return dictRead

holidayDict = BuildDict()
print('The origin dict of holiday is below.')
print(holidayDict)
print()

key = input("input keyDay to query or 'end' for break : ")
while key != 'end':
    print(holidayDict[key])
    key = input("input keyDay to query or 'end' for break : ")

print('\nThe saved dict of holiday is below.')
saveDict('holiday.json',holidayDict)
dictRead = readDict('holiday.json')
print(dictRead)