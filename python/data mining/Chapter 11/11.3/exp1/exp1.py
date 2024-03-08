import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from statsmodels.tsa.stattools import adfuller as ADF
from statsmodels.graphics.tsaplots import plot_acf
from statsmodels.graphics.tsaplots import plot_pacf
from statsmodels.stats.diagnostic import acorr_ljungbox
import statsmodels.tsa.arima.model as stam
import statsmodels.api as sm

# 平稳性检测-单位根检验
def test_adf(dat):
    print('ADF检验结果为：',ADF(dat['value']),'判断为非平稳序列' if ADF(dat['value'])[1] > 0.05 else '判断为平稳序列')

# 白噪声检验
def test_whitenoise(dat):
    print('白噪声检验结果为：',acorr_ljungbox(dat,lags=1))

# AIC BIC HQ 统计量检验
def get_stats_mod_test(model):
    return model.aic,model.bic,model.hqic

# Ljung-Box检验 模型白噪声检验
def test_model_whitenoise(model):
    resid = model.resid
    r,p,q = sm.tsa.acf(resid.values.squeeze(),qstat=True)
    datap = np.c_[range(1,20),r[1:],q,p]
    table = pd.DataFrame(datap,columns=['lag','AC','Q','Prob(>Q)']).set_index('lag')
    return table

# 模型检验
def verify_model(dat,file_output,order=(0,0,0),freq='M',level_significance=0.05):
    model = stam.ARIMA(dat,order=order,freq=freq).fit()
    aic,bic,hqic = get_stats_mod_test(model)
    print('p=',order[0],', q=',order[2],get_stats_mod_test(model))
    table = test_model_whitenoise(model)
    for i in range(1,13):
        if table.loc[i,'Prob(>Q)'] < level_significance:
            # print('not white noise!')
            print('p=',order[0],', q=',order[2],(aic,bic,hqic),file=file_output)
            return ()
    # print('white noise.')
    return (aic,bic,hqic)

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# 读取数据转换为时间序列
data = pd.read_excel('dat.xls',index_col=0)
print('原数据')

fig_pretest = plt.figure()
fig_pretest.suptitle('预测试图集')
axes = [[]]

# 绘制时间序列图
axes[0].append(fig_pretest.add_subplot(331))
data.plot(title='原数据时间序列图',ax=axes[0][0])

#原数据平稳性检验
test_adf(data)

# 自相关检验
axes[0].append(fig_pretest.add_subplot(332))
plot_acf(data,ax=axes[0][1],title='原数据自相关图')

# 偏自相关检验
axes[0].append(fig_pretest.add_subplot(333))
plot_pacf(data,ax=axes[0][2],title='原数据偏自相关图')

# 白噪声检验
test_whitenoise(data)

# 1阶差分
data_diff1 = data.diff(1).dropna()
axes[0].append(fig_pretest.add_subplot(334))
data_diff1.plot(title='1阶差分数据序列图',ax=axes[0][3])
axes[0].append(fig_pretest.add_subplot(335))
plot_acf(data_diff1['value'],lags=10,ax=axes[0][4],title='1阶差分数据自相关图')
axes[0].append(fig_pretest.add_subplot(336))
plot_pacf(data_diff1['value'],lags=10,ax=axes[0][5],title='1阶差分数据偏自相关图')
data_diff2 = data_diff1.diff(1).dropna()
axes[0].append(fig_pretest.add_subplot(337))
data_diff2.plot(title='2阶差分数据序列图',ax=axes[0][6])
axes[0].append(fig_pretest.add_subplot(338))
plot_acf(data_diff2['value'],lags=10,ax=axes[0][7],title='2阶差分数据自相关图')
axes[0].append(fig_pretest.add_subplot(339))
plot_pacf(data_diff2['value'],lags=10,ax=axes[0][8],title='2阶差分数据偏自相关图')
print('1阶差分')
test_adf(data_diff1)
test_whitenoise(data_diff1) # 1阶差分为白噪声，不可选
print('2阶差分')
test_adf(data_diff2)
test_whitenoise(data_diff2)

# 以2阶差分选择最佳模型 得 ARIMA(7,2,7)
# mt = [1600,1600,1600]
# para = [0,0,0]
# chosen_model = None
# file_o = open('verify_output.txt','w')
# for ip in range(11):
#     for iq in range(11):
#         cnt = 0
#         t = verify_model(data,file_o,order=(ip,2,iq))
#         if len(t) > 0:
#             cnt += 1 if t[0] < mt[0] else 0
#             cnt += 1 if t[1] < mt[1] else 0
#             cnt += 1 if t[2] < mt[2] else 0
#         if cnt > 1:
#             mt = list(t)
#             chosen_model = stam.ARIMA(data,order=(ip,2,iq),freq='M').fit()
#             para = [ip,2,iq]
# file_o.close()
chosen_model = stam.ARIMA(data,order=(7,2,7),freq='M').fit()
para = [7,2,7]

# Ljung-Box检验 白噪声校验 已完成
table = test_model_whitenoise(chosen_model)
print(para)
print(table)

fig_predict = plt.figure()
fig_predict.suptitle('模型预测结合图')
ax = fig_predict.add_subplot(111)

data_predict = pd.DataFrame(chosen_model.predict('2008-7-31','2010-6-30',dynamic=True))
data_predict.columns = ['value']
data_predict = pd.concat([data,data_predict],axis=0)

data_predict.loc['2008-6-30':].plot(y='value',ax=ax,label='predict')
data_predict.loc[:'2008-6-30'].plot(y='value',ax=ax,label='train')

# plt.legend()
plt.show()