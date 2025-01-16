import numpy as np
import pandas as pd

# 示例数据列表
#     y1   y2   y3   y4   y5   y6   y7  epsilon   rho        T3
# 0  8.3  7.1  8.1  6.9  9.1  8.5  8.6     0.10  0.10  7.830101
# 1  7.8  8.7  8.0  6.2  8.9  8.0  8.8     0.05  0.15  7.849980
# 2  5.8  8.1  6.8  5.6  7.9  6.8  8.1     0.10  0.10  6.524074
# 3  6.8  7.8  8.1  6.9  8.9  7.8  8.8     0.05  0.15  7.619947
# 4  3.8  3.7  4.8  4.7  3.9  5.8  6.8     0.10  0.10  4.209326
# 5  8.4  7.2  8.1  7.7  7.9  8.8  6.8     0.05  0.15  7.849050
# 6  9.0  8.7  8.9  8.6  9.1  8.8  8.9     0.10  0.10  8.776071
# 7  8.0  7.8  6.8  8.7  7.9  8.1  8.3     0.05  0.15  7.646313

alpha_weights = [0.3, 0.2, 0.35, 0.15] # 关键属性分别的权重
beta_weights = [0.35, 0.40, 0.25] # 非关键属性分别的权重
alpha = 0.70 # 关键属性总权重
beta = 0.30 # 非关键属性总权重

data = [
    # y1,  y2,  y3,  y4,  y5,  y6,  y7, epsilon, rho
    [8.3, 7.1, 8.1, 6.9, 9.1, 8.5, 8.6, 0.10, 0.10],
    [7.8, 8.7, 8.0, 6.2, 8.9, 8.0, 8.8, 0.05, 0.15],
    [5.8, 8.1, 6.8, 5.6, 7.9, 6.8, 8.1, 0.10, 0.10],
    [6.8, 7.8, 8.1, 6.9, 8.9, 7.8, 8.8, 0.05, 0.15],
    [3.8, 3.7, 4.8, 4.7, 3.9, 5.8, 6.8, 0.10, 0.10],
    [8.4, 7.2, 8.1, 7.7, 7.9, 8.8, 6.8, 0.05, 0.15],
    [9.0, 8.7, 8.9, 8.6, 9.1, 8.8, 8.9, 0.10, 0.10],
    [8.0, 7.8, 6.8, 8.7, 7.9, 8.1, 8.3, 0.05, 0.15]
]

df = pd.DataFrame(data, columns=['y1', 'y2', 'y3', 'y4', 'y5', 'y6', 'y7', 'epsilon', 'rho'])

def calculate_T3(row):
    y_crucial = row[['y1', 'y2', 'y3', 'y4']].values
    y_non_crucial = row[['y5', 'y6', 'y7']].values
    epsilon = row['epsilon']
    rho = row['rho']

    min = np.min((y_crucial / 10) ** epsilon)
    crucial_prod = np.prod(y_crucial ** alpha_weights) # 使用 prod 计算乘积
    crucial_prod_rho = (min * crucial_prod) ** (-rho)
    crucial_value = alpha * crucial_prod_rho

    non_crucial_prod = np.prod(y_non_crucial ** beta_weights)
    non_crucial_prod_rho = (non_crucial_prod) ** (-rho)
    non_crucial_value = beta * non_crucial_prod_rho

    T_3 = (crucial_value + non_crucial_value) ** (-1/rho)
    return T_3

def main():
    df['T3'] = df.apply(calculate_T3, axis=1)
    print(df)

if __name__ == "__main__":
    main()
