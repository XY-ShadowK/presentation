XYZ = input()
XYZ = XYZ.split('\t')

X = float(XYZ[0])
Y = float(XYZ[1])
Z = float(XYZ[2])

var_X = X / 100
var_Y = Y / 100
var_Z = Z / 100

var_R = var_X * 3.2406 + var_Y * (-1.5372) + var_Z * (-0.4986)
var_G = var_X * (-0.9689) + var_Y * 1.8758 + var_Z * 0.0415
var_B = var_X * 0.0557 + var_Y * (-0.2040) + var_Z * 1.0570

one_2p4 = 1 / 2.4
vR = 1.055 * (var_R ** one_2p4) - 0.055 if var_R > 0.0031308 else 12.92 * var_R
vG = 1.055 * (var_G ** one_2p4) - 0.055 if var_G > 0.0031308 else 12.92 * var_G
vB = 1.055 * (var_B ** one_2p4) - 0.055 if var_B > 0.0031308 else 12.92 * var_B

sR = vR * 255
sG = vG * 255
sB = vB * 255

print(X,Y,Z,'\n',sR,sG,sB)

# import pandas as pd

# reflection_str = input()
# reflection_str = reflection_str.split('\t')
# reflection = list(map(float,reflection_str))

# df = pd.DataFrame({'reflection':reflection})
# df.to_csv('reflection.csv',index=False)

# Drgb = input()
# Drgb = Drgb.split('\t')
# drgb = list(map(float,Drgb))
# drgb = [1 / (10 ** d) for d in drgb]
# print(Drgb,'\n',drgb)

# def cf(num,std):
#     return (num - std) ** 2

# import math
# arr = input()
# arr = arr.split(' ')
# arr = list(map(float,arr))
# avg = [0.0] * 3
# avg[0] = (arr[0] + arr[3] + arr[6] + arr[9] + arr[12]) / 5
# avg[1] = (arr[1] + arr[4] + arr[7] + arr[10] + arr[13]) / 5
# avg[2] = (arr[2] + arr[5] + arr[8] + arr[11] + arr[14]) / 5
# print(avg[1],' ',avg[2])
# print((cf(arr[1], avg[1]) + cf(arr[4], avg[1]) + cf(arr[7], avg[1]) + cf(arr[10], avg[1]) + cf(arr[13], avg[1])) / 5)
# print((cf(arr[2], avg[2]) + cf(arr[5], avg[2]) + cf(arr[8], avg[2]) + cf(arr[11], avg[2]) + cf(arr[14], avg[2])) / 5)
