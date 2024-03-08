import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
import numpy as np
import random

class KMeans:
    def __init__(self):
        self.k_num = 0
        self.feature_num = 0
        self.datas = []
        self.labels = []
        self.centers = []
        self.clusters = []
        self.default_centers_initialize: function
    def clear_cluster(self):
        # self.clusters = [[]] * self.k_num
        self.clusters = [[] for k in range(self.k_num)]
        return self.clusters
    def kmeans_pp(self):
        self.centers = []
        self.centers.append(self.datas[random.randint(0,len(self.datas) - 1)])
        for k in range(1,self.k_num):
            fit_d = 0
            max_dist_rms = 0.0
            for d in range(len(self.datas)):
                dist_rms = 0.0
                for front in range(k):
                    dist = self.distance(self.centers[front],self.datas[d])
                    if dist == 0.0:
                        dist_rms = 0.0
                        break
                    dist_rms += dist ** 2
                # print(k,d,dist)
                (fit_d,max_dist_rms) = (d,dist_rms) if dist_rms > max_dist_rms else (fit_d,max_dist_rms)
            self.centers.append(self.datas[fit_d])
            # print(fit_d,max_dist_rms,'\n')
        return self.centers
    def setup(self,k,fn,dts,lbls):
        self.k_num = k
        self.feature_num = fn
        self.datas = dts
        self.labels = lbls
        self.default_centers_initialize = self.kmeans_pp
    def distance(self,dt1,dt2):
        dist = 0.0
        for f in range(self.feature_num):
            dist += (dt1[f] - dt2[f]) ** 2
        return dist
    def partition(self):
        for d in range(len(self.datas)):
            fit_k = 0
            low_dist = -1.0
            for k in range(self.k_num):
                dist = self.distance(self.datas[d],self.centers[k])
                (fit_k,low_dist) = (k,dist) if dist < low_dist or low_dist == -1.0 else (fit_k,low_dist)
            self.clusters[fit_k].append(d)
            # print(d,fit_k,low_dist)
        return self.clusters
    def set_centers(self):
        errors = [0.0] * self.k_num
        # sses = [0.0] * self.k_num
        for k in range(self.k_num):
            # print(k,len(self.clusters[k]),self.clusters[k])
            center_sum = [0.0] * self.feature_num
            for dn_c in self.clusters[k]:
                center_sum = [cf + df for cf,df in zip(center_sum,self.datas[dn_c])]
            # for c in range(len(self.clusters[k])):
            #     center = [cf + df for cf,df in zip(center,self.datas[self.clusters[k][c]])]
            center = [c / len(self.clusters[k]) for c in center_sum]
            errors[k] = self.distance(center,self.centers[k])
            # sses[k] = 0.0
            # for dn_c in self.clusters[k]:
            #     sses[k] += self.distance(center,self.datas[dn_c])
            self.centers[k] = center
        # time.sleep(10)
        return errors
    def reason_parttition(self,init_centers=[],times=10000,stop_error=0.0001):
        if len(init_centers) == self.k_num:
            self.centers = init_centers
        elif len(init_centers) == 0:
            self.default_centers_initialize()
        else:
            return -1
        for t in range(times):
            self.clear_cluster()
            self.partition()
            errors = self.set_centers()
            if max(errors) <= stop_error:
                return t + 1
        return times

sanple_num = 1000
center_num = 5
feature_num = 2

X,y = make_blobs(n_samples=sanple_num,n_features=feature_num,centers=center_num,random_state=100)

kmeans = KMeans()
kmeans.setup(center_num,feature_num,X,y)
print('run for',kmeans.reason_parttition(stop_error=0.000001),'times')

color = ['r','g','b','c','m','y','k']

dts = [np.array(0)] * center_num
lbls = [[]] * center_num
clusters = {}
for i in range(center_num):
    dts[i] = np.array([kmeans.datas[data_num] for data_num in kmeans.clusters[i]])
    lbls[i] = [kmeans.labels[label_num] for label_num in kmeans.clusters[i]]
    clusters[i] = lbls[i]
print(clusters)

figure,axes = plt.subplots(1,2)

axes[0].set_title('原始数据',fontproperties='Microsoft YaHei')
axes[0].scatter(X[:,0],X[:,1])

axes[1].set_title('聚类显示数据',fontproperties='Microsoft YaHei')
sc = [0] * center_num
for i in range(center_num):
    sc[i] = axes[1].scatter(dts[i][:,0],dts[i][:,1],c=color[i],cmap='coolwarm',label=('center'+str(i)))
axes[1].legend()

# plt.subplot(121)
# plt.title('原始数据')
# plt.scatter(X[:,0],X[:,1])

# plt.subplot(122)
# plt.title('聚类显示数据')
# for i in range(center_num):
#     plt.scatter(dts[i][0],dts[i][1])
# plt.legend()

plt.show()