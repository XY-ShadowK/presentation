import matplotlib.pyplot as plt
from sklearn.datasets import load_digits
from sklearn.preprocessing import scale
from sklearn.cluster import KMeans as skl_Kmeans
import numpy as np
import random
import time

from self_kmeans import KMeans as self_Kmeans

digits = load_digits()
datas = scale(digits.data)

sample_num = len(datas)
center_num = 10
feature_num = len(datas[0])

self_kmeans = self_Kmeans()
self_kmeans.setup(center_num,feature_num,datas,digits.target)

t_before_self = time.time()
print('run for',self_kmeans.reason_parttition(stop_error=0.000001),'times')
t_after_self = time.time()

t_before_skl = time.time()
y_pred = skl_Kmeans(n_clusters=center_num,random_state=100).fit_predict(datas)
t_after_skl = time.time()

row_elements,row_counts = np.unique(digits.target,return_counts=True)

self_elements = []
self_counts = []
skl_counts = []
for c in range(center_num):
    self_counts.append([0] * center_num)
    skl_counts.append([0] * center_num)

for c in range(center_num):
    self_elements.append('C'+str(c))
    # sn,counts = np.unique(self_kmeans.clusters[c],return_counts=True)
    # self_counts.append(counts)
    for i in self_kmeans.clusters[c]:
        self_counts[digits.target[i]][c] += 1

for i in range(len(y_pred)):
    skl_counts[digits.target[i]][y_pred[i]] += 1

print('self_counts\n',self_counts)
print('\nskl_counts\n',skl_counts)

figure,axes = plt.subplots(2,2)

axes[0][0].set_title('原数据',fontproperties='Microsoft YaHei')
axes[0][0].bar(row_elements,row_counts)

axes[0][1].set_title('用时',fontproperties='Microsoft YaHei')
axes[0][1].bar(['self_kmeans','skl_kmeans'],[t_after_self - t_before_self,t_after_skl - t_before_skl])

axes[1][0].set_title('self_kmeans',fontproperties='Microsoft YaHei')
axes[1][1].set_title('skl_kmeans',fontproperties='Microsoft YaHei')

self_bottom_y = [0] * center_num
skl_bottom_y = [0] * center_num
for c in range(center_num):
    axes[1][0].bar(self_elements,self_counts[c],bottom=self_bottom_y,label='target'+str(c))
    axes[1][1].bar(self_elements,skl_counts[c],bottom=skl_bottom_y,label='target'+str(c))
    self_bottom_y = [sby + sc for sby,sc in zip(self_bottom_y,self_counts[c])]
    skl_bottom_y = [skby + skc for skby,skc in zip(skl_bottom_y,skl_counts[c])]

axes[1][0].legend()
axes[1][1].legend()

plt.show()