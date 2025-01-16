import pandas as pd
import numpy as np

# weights = {
#    'F': 0.25,'SF': 0.15,'R': 0.20,'SV': 0.23,'M': 0.17
# }
# 将权重修改为本题的内容：
weights = {
    'r1': 0.15, 'r2': 0.20, 'r3': 0.20, 'r4': 0.25, 'r5': 0.20
}

# 将数据改为作业三的数据
data = [
    [8.6, 9.1, 9.2, 8.8, 8.9],
    [6.8, 7.9, 5.9, 6.6, 6.1],
    [9.1, 9.9, 8.9, 8.8, 7.8],
    [3.5, 4.2, 5.6, 4.9, 5.2]
]

def main():
    dataframe = pd.DataFrame(data, columns=['r1', 'r2', 'r3', 'r4', 'r5'])
    dataframe['y1'] = dataframe.apply(lambda
                                         row: np.prod([row[attr] ** weights[attr] for attr in weights]), axis=1)
    print(dataframe)


if __name__ == '__main__':
    main()