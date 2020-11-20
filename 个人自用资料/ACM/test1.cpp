import pandas as pd
import datetime
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
%matplotlib inline
plt.rcParams['font.sans-serif']=['SimHei'] #用来正常显示中文标签
plt.rcParams['axes.unicode_minus']=False #用来正常显示负号
# 读取前五行数据
data = pd.read_csv('dataset.csv')
data.head()
# 数据集信息，包含数据集大小，列名，类型
data.info()
data.columns.values