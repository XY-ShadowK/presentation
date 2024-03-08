import pandas as pd

def fixID(dFrame):
    for i in range(dFrame.shape[0]):
        if pd.isnull(dFrame.loc[i,'Id']):
            dFrame.loc[i,'Id'] = dFrame.loc[i-1,'Id'] + 1 if 1 != 0 else 1

df = pd.read_csv('data.csv')

# 判断Id列是否有缺失值并补全
fixID(df)
# 去重
df.drop_duplicates(subset=['Chinese','Math','English'],inplace=True,ignore_index=True)
# 以三门平均分作为新列
df['Average'] = (df['Chinese'] + df['Math'] + df['English']) / 3
# 取平均分最高的记录
highest = df.loc[df['Average'] == df['Average'].max()]
# 语文及格人数
numPassChinese = len(df.loc[df['Chinese'] >= 60])
# 数学及格人数
numPassMath = len(df.loc[df['Math'] >= 60])
# 英语及格人数
numPassEnglish = len(df.loc[df['English'] >= 60])

print('最高平均分记录')
print(highest)
print('\n语文及格',numPassChinese,'人')
print('数学及格',numPassMath,'人')
print('英语及格',numPassEnglish,'人')
print('\n处理后整表输出')
print(df)