from sklearn import preprocessing
import numpy as np
import json

def read_data(filename):
    file = open(filename,'r')
    str_list = file.readlines() # 读取每一行字符串作为list元素
    return str_list

def split_data(lst):
    data = []
    label = []
    for line in lst:
        line = line.strip() # 删除行首行尾空格及换行符
        row_line = line.split('\t') # 以制表符切分
        row_line = list(map(float,row_line))
        data.append(row_line[:21])
        label.append([row_line[21]])
    return data,label

def make_matrix(m,n,fill=0.0):
    matrix = []
    for i in range(m):
        matrix.append([fill] * n)
    return matrix

def rand(min,max):
    return (max - min) * np.random.random() + min

def sigmoid(x):
    return 1.0 / (1.0 + np.exp(-x)) if x >= 0 else np.exp(x) / (1.0 + np.exp(x))

def sigmoid_derivative(x):
    return sigmoid(x) * (1.0 - sigmoid(x))

def cost_function(predict,reality):
    return sum((p - r) ** 2.0 for p,r in zip(predict,reality))

def loss_function(predict,reality):
    return cost_function(predict,reality) / len(predict) / 2.0

# 数据预处理类
class Preprocess:
    def __init__(self):
        self.scaler = preprocessing.StandardScaler()
    # 对data标准化fit
    def fit_scale(self,data):
        self.scaler = preprocessing.StandardScaler().fit(data)
    # 将data标准化transform
    def transform_scale(self,data):
        return self.scaler.transform(data)

class BPNeuralNetwork:
    def __init__(self):
        # 各层节点数
        self.input_num = 0
        self.hidden_num = 0
        self.output_num = 0
        # 各层节点值
        self.input_values = []
        self.hidden_row_values = []
        self.hidden_values = []
        self.output_row_values = []
        self.output_values = []
        # 各层权重
        self.input_weights = []
        self.hidden_weights = []
        # 各层偏移值
        self.input_delta_w = []
        self.hidden_delta_w = []
        # self.input_delta_b = []
        self.hidden_delta_b = []
        self.output_delta_b = []
        # 各层偏置元
        # self.input_bias = []
        self.hidden_bias = []
        self.output_bias = []
        # 激活函数与其导数
        self.activate_function = ()
        self.activate_function_derivative = ()
    def setup(self,input_num,hidden_num,output_num):
        # 设置各层节点数
        self.input_num = input_num
        self.hidden_num = hidden_num
        self.output_num = output_num
        # 设置各层节点值
        self.input_values = [0.0] * self.input_num
        self.hidden_row_values = [0.0] * self.hidden_num
        self.hidden_values = [0.0] * self.hidden_num
        self.output_row_values = [0.0] * self.output_num
        self.output_values = [0.0] * self.output_num
        # 构建转移矩阵
        self.input_weights = make_matrix(self.input_num,self.hidden_num)
        self.hidden_weights = make_matrix(self.hidden_num,self.output_num)
        for ni in range(self.input_num):
            for nh in range(self.hidden_num):
                self.input_weights[ni][nh] = rand(-1,1)
        for nh in range(self.hidden_num):
            for no in range(self.output_num):
                self.hidden_weights[nh][no] = rand(-1,1)
        # 构建偏移矩阵
        self.input_delta_w = make_matrix(self.input_num,self.hidden_num)
        self.hidden_delta_w = make_matrix(self.hidden_num,self.output_num)
        self.hidden_delta_b = [0.0] * self.hidden_num
        self.output_delta_b = [0.0] * self.output_num
        # 设置各层偏置元
        # self.input_bias = [0.0] * self.input_num
        self.hidden_bias = [0.0] * self.hidden_num
        self.output_bias = [0.0] * self.output_num
    def export2dict(self):
        return {
            'input_num':self.input_num,'hidden_num':self.hidden_num,'output_num':self.output_num,
            'input_weights':self.input_weights,'hidden_weights':self.hidden_weights,
            'input_delta_w':self.input_delta_w,'hidden_delta_w':self.hidden_delta_w,
            'hidden_delta_b':self.hidden_delta_b,'output_delta_b':self.output_delta_b,
            'hidden_bias':self.hidden_bias,'output_bias':self.output_bias
            }
    def import_from_dict(self,act_func,act_func_deri,dictionary):
        self.setup(dictionary['input_num'],dictionary['hidden_num'],dictionary['output_num'])
        self.input_weights = dictionary['input_weights']
        self.hidden_weights = dictionary['hidden_weights']
        self.input_delta_w = dictionary['input_delta_w']
        self.hidden_delta_w = dictionary['hidden_delta_w']
        self.hidden_delta_b = dictionary['hidden_delta_b']
        self.output_delta_b = dictionary['output_delta_b']
        self.hidden_bias = dictionary['hidden_bias']
        self.output_bias = dictionary['output_bias']
        self.activate_function = act_func
        self.activate_function_derivative = act_func_deri
        return self
    def predict(self,inputs):
        # 获取输入层值
        for i in range(self.input_num):
            self.input_values[i] = inputs[i]
        # 计算隐藏层值
        for h in range(self.hidden_num):
            # total = 0.0
            # for i in range(self.input_num):
            #     total += self.input_values[i] * self.input_weights[i][h]
            total = sum(self.input_values[i] * self.input_weights[i][h] for i in range(self.input_num))
            self.hidden_row_values[h] = total + self.hidden_bias[h]
            self.hidden_values[h] = self.activate_function(self.hidden_row_values[h])
        # 计算输出层值
        for o in range(self.output_num):
            # total = 0.0
            # for h in range(self.hidden_num):
            #     total += self.hidden_values[h] * self.hidden_weights[h][o]
            total = sum(self.hidden_values[h] * self.hidden_weights[h][o] for h in range(self.hidden_num))
            self.output_row_values[o] = total + self.output_bias[o]
            self.output_values[o] = self.activate_function(self.output_row_values[o])
        return self.output_values
    def back_propagate(self,sample_num,labels,alpha,Lambda=0.0):
        # 计算输出层残差
        output_deltas = [0.0] * self.output_num
        for o in range(self.output_num):
            error = labels[o] - self.output_values[o]
            output_deltas[o] = - error * self.activate_function_derivative(self.output_row_values[o])
        # 计算隐藏层残差
        hidden_deltas = [0.0] * self.hidden_num
        for h in range(self.hidden_num):
            # error = 0.0
            # for o in range(self.output_num):
            #     error += output_deltas[o] * self.hidden_weights[h][o]
            error = sum(output_deltas[o] * self.hidden_weights[h][o] for o in range(self.output_num))
            hidden_deltas[h] = error * self.activate_function_derivative(self.hidden_row_values[h])
        # 计算偏移值并更新
        self.output_delta_b = [0.0] * self.output_num
        for h in range(self.hidden_num):
            for o in range(self.output_num):
                hidden_grad_w = output_deltas[o] * self.hidden_values[h]
                output_grad_b = output_deltas[o]
                self.hidden_delta_w[h][o] = hidden_grad_w
                self.output_delta_b[o] += output_grad_b
                self.hidden_weights[h][o] -= alpha * (self.hidden_delta_w[h][o] / sample_num + Lambda * self.hidden_weights[h][o])
        for o in range(self.output_num):
            self.output_bias[o] -= alpha * self.output_delta_b[o] / sample_num
        self.hidden_delta_b = [0.0] * self.hidden_num
        for i in range(self.input_num):
            for h in range(self.hidden_num):
                input_grad_w = hidden_deltas[h] * self.input_values[i]
                hidden_grad_b = hidden_deltas[h]
                self.input_delta_w[i][h] = input_grad_w
                self.hidden_delta_b[h] += hidden_grad_b
                self.input_weights[i][h] -= alpha * (self.input_delta_w[i][h] / sample_num + Lambda * self.input_weights[i][h])
        for h in range(self.hidden_num):
            self.hidden_bias[h] -= alpha * self.hidden_delta_b[h] / sample_num
        # 返回均方误差
        return sum(0.5 * (labels[l] - self.output_values[l]) ** 2 for l in range(len(labels)))
    def train(self,act_func,act_func_deri,datas,labels,times,alpha=0.05,Lambda=0.0,stop_error=0.001):
        self.activate_function = act_func
        self.activate_function_derivative = act_func_deri
        for t in range(times):
            error = 0.0
            for i in range(len(datas)):
                self.predict(datas[i])
                error += self.back_propagate(len(datas),labels[i],alpha,Lambda)
            if error <= stop_error:
                return t+1
        return times

def evaluate_effect(datas,labels):
    error = 0.0
    error_num = 0
    cost_function_values = []
    for i in range(len(datas)):
        result = horseColicBP.predict(datas[i])
        for r in range(len(result)):
            error_num += 1 if labels[i][r] == result[r] else 0
            error += 0.5 * (labels[i][r] - result[r]) ** 2
            cost_function_values.append(cost_function(result,labels[i]))
            # print('计算值：',result[r],' ,实际值：',labels[i][r])
    num = len(labels)*len(labels[0])
    print('测试数：',num,'，错误数：',error_num,'，错误率：',error_num / num)
    print('总均分方差：',error,'\n无正则化项代价函数：',cost_function_values)

def save_module(module,filename):
    f = open(filename,'w')
    json.dump(module.export2dict(),f)
    f.close()

def import_module(filename):
    f = open(filename,'r')
    dictionary = json.load(f)
    f.close()
    return dictionary

def save_processed_data(data,filename):
    np.savetxt(filename,data,fmt='%f')

test_set,test_label = split_data(read_data('horseColicTest.txt'))
train_set,train_label = split_data(read_data('horseColicTraining.txt'))

save_processed_data(train_set,'train.txt')
save_processed_data(test_set,'test.txt')

preprocess = Preprocess()
preprocess.fit_scale(train_set)
train_set = preprocess.transform_scale(train_set)
test_set = preprocess.transform_scale(test_set)

horseColicBP = BPNeuralNetwork().import_from_dict(sigmoid,sigmoid_derivative,import_module('exp1/success_module/horseColicBP.json'))
# horseColicBP = BPNeuralNetwork()
# horseColicBP.setup(21,15,1)
# horseColicBP.train(sigmoid,sigmoid_derivative,train_set,train_label,5000,0.1,0.005)

evaluate_effect(test_set,test_label)
save_module(horseColicBP,'horseColicBP.json')