import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from statsmodels.tsa.seasonal import seasonal_decompose
from statsmodels.tsa.holtwinters import SimpleExpSmoothing,ExponentialSmoothing

def DecomposeResult_plot(result,ax):
    pd.DataFrame(result.observed).plot(y=0,ax=ax,label='origin')
    pd.DataFrame(result.trend).plot(y=0,ax=ax,label='trend')
    pd.DataFrame(result.seasonal).plot(y=0,ax=ax,label='seasonal')
    resid = pd.DataFrame(result1.resid).dropna()
    resid['date'] = resid.index
    resid.plot(kind='scatter',x='date',y='resid',ax=ax,label='resid',c='b')
    ax.set_ylabel('')

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# 读取数据转换为时间序列
data = pd.read_excel('dat.xls',index_col=0)
print('原数据')

# 分解时间序列
result1 = seasonal_decompose(data,model='add')
result2 = seasonal_decompose(data,model='mul')

fig_origin = plt.figure()
fig_origin.suptitle('原数据图集')
axes = [[]]

axes[0].append(fig_origin.add_subplot(311))
data.plot(title='原数据时间序列图',ax=axes[0][0])
axes[0].append(fig_origin.add_subplot(312))
DecomposeResult_plot(result1,axes[0][1])
axes[0][1].set_title('加法分解图')
axes[0].append(fig_origin.add_subplot(313))
DecomposeResult_plot(result2,axes[0][2])
axes[0][2].set_title('乘法分解图')

model = ExponentialSmoothing(data,trend='add',seasonal='add').fit()

fig_predict = plt.figure()
fig_predict.suptitle('加法 模型预测结合图')
ax = fig_predict.add_subplot(111)

data_predict = pd.DataFrame(model.predict('2008-7-31','2010-6-30'))
data_predict.columns = ['value']
data_predict = pd.concat([data,data_predict],axis=0)

data_predict.loc['2008-6-30':].plot(y='value',ax=ax,label='predict')
data_predict.loc[:'2008-6-30'].plot(y='value',ax=ax,label='train')

plt.legend()
plt.show()