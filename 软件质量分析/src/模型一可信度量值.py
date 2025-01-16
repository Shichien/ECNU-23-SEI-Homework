import pandas as pd
import numpy as np

# 数据格式：
#      F   SF    R   SV    M         T
# 0  6.8  8.2  7.8  6.8  7.9  7.373809
# 1  8.8  8.9  9.2  9.0  9.3  9.024115
# 2  5.6  5.9  6.0  9.0  5.3  6.322775
# 3  4.6  7.8  3.8  5.1  4.5  4.889311

weights = {
    'F': 0.25,'SF': 0.15,'R': 0.20,'SV': 0.23,'M': 0.17
}

data = [
    [6.8, 8.2, 7.8, 6.8, 7.9],
    [8.8, 8.9, 9.2, 9.0, 9.3],
    [5.6, 5.9, 6.0, 9.0, 5.3],
    [4.6, 7.8, 3.8, 5.1, 4.5]
]

def main():
    dataframe = pd.DataFrame(data, columns=['F', 'SF', 'R', 'SV', 'M'])
    dataframe['T'] = dataframe.apply(lambda row: np.prod([row[attr] ** weights[attr] for attr in weights]), axis=1)
    print(dataframe)

if __name__ == '__main__':
    main()
