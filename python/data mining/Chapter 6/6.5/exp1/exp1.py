import matplotlib.pyplot as plt
import pandas as pd

def fixData(dFrame):
    for i in range(dFrame.shape[0]):
        if pd.isnull(dFrame.loc[i,'Chinese']) or pd.isnull(dFrame.loc[i,'Math']) or pd.isnull(dFrame.loc[i,'English']):
            dFrame.drop(index=i,inplace=True)
            continue
        if pd.isnull(dFrame.loc[i,'Id']):
            dFrame.loc[i,'Id'] = dFrame.loc[i-1,'Id'] + 1 if 1 != 0 else 1

def processData(filename,outFilename):
    df = pd.read_csv(filename)
    fixData(df)
    df.drop_duplicates(subset=['Chinese','Math','English'],inplace=True,ignore_index=True)
    df['Average'] = (df['Chinese'] + df['Math'] + df['English']) / 3
    df['Average'] = df['Average'].apply(lambda avg:round(avg,1))
    df.to_csv(outFilename,index=False)

def setColor(boxp,clr):
    for box,c in zip(boxp['boxes'],clr):
        # box.set(color=c,linewidth=2)
        box.set(facecolor=c)

processData('data.csv','processedData.csv')

pDF = pd.read_csv('processedData.csv')

figure,axes = plt.subplots(1,2)

axes[0].set_title('各科分数及平均分箱线图',fontproperties='Microsoft YaHei')
fBox = axes[0].boxplot([pDF['Chinese'],pDF['Math'],pDF['English'],pDF['Average']],labels=['Chinese','Math','English','Average'],vert=False,patch_artist=True)

axes[1].set_title('各科分数及平均分散点图',fontproperties='Microsoft YaHei')
axes[1].scatter(pDF['Id'],pDF['Chinese'],label='Chinese')
axes[1].scatter(pDF['Id'],pDF['Math'],label='Math')
axes[1].scatter(pDF['Id'],pDF['English'],label='English')
axes[1].scatter(pDF['Id'],pDF['Average'],label='Average')
axes[1].legend()

color = ['r','g','b','y']
setColor(fBox,color)

plt.show()