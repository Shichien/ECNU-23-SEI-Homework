import numpy as np

A = np.array([
    [1, 1/2, 2, 2, 1/2, 1/4],
    [2, 1, 1, 3, 2],
    [1/3, 1/2, 1, 2, 1/3],
    [1/2, 1/3, 1/2, 1, 2],
    [2, 1/2, 3, 1/2, 1]
])

def calculate_ev_weights(matrix):
    eigenvalues, eigenvectors = np.linalg.eig(matrix)  # 返回值为元组，第一个元素为特征值，第二个元素为特征向量
    max_index = np.argmax(eigenvalues)  # 取最大特征值对应的特征向量
    weights = eigenvectors[:, max_index].real
    # 归一化
    return weights / np.sum(weights)

def calculate_llsm_weights(matrix):
    # 分子 = 每行的乘积 × 开维度数次方
    numerator = np.prod(matrix, axis=1) ** (1 / matrix.shape[0])
    # 分母 = 每行的分子相加
    denominator =  np.sum(numerator)
    # 归一化
    return numerator / denominator

def calculate_csm_weights(matrix: np.array, epsilon: float, max_iterations: int) -> np.ndarray:
    '''计算 CSM，传入: matrix, precision, maximum iterations'''
    n = matrix.shape[0]
    # 初始化初始解
    W = np.ones(n) / n

    for k in range(max_iterations):
        e = np.zeros(n)
        for i in range(n):
            e[i] = np.sum([(1 + matrix[j, i] ** 2) * (W[i] / W[j]) - (1 + matrix[i, j] ** 2) * (W[j] / W[i])
                           for j in range(n) if j != i])

        max_e = np.max(np.abs(e))
        if max_e <= epsilon: # 若精度已到达，那么停止迭代
            print(f"在迭代次数为 {k} 次时收敛")
            break

        m = np.argmax(np.abs(e)) # 查找最大无差的索引

        # 计算 T(k)
        up = np.sum([(1 + matrix[m, j] ** 2) * (W[j] / W[m]) for j in range(n) if j != m])
        bottom = np.sum([(1 + matrix[j, m] ** 2) * (W[m] / W[j]) for j in range(n) if j != m])
        T = np.sqrt(up / bottom)

        # 更新矩阵向量，归一化
        X = W.copy()
        X[m] *= T
        W = X / np.sum(X)

    return W

def calculate_csm_weights_ppt():
    n = 5 # 方针阶数
    a = []
    print("输入方阵：")
    for i in range(0, n):
        row = list(map(float, input().split()))
        a.append(row)
    # 步骤 （1）
    epsilon = 1e-10
    w = [1 / n for i in range(0, n)] # 初始解
    while True:
        # 步骤 （2）
        m = None
        max_val = None
        for i in range(0, n):
            val = 0
            for j in range(0, n):
                val += (1 + a[j][i] * a[j][i]) * (w[i] / w[j]) - (1 + a[i][j] * a[i][j]) * (w[j] / w[i])
            val = abs(val)
            if max_val == None or val > max_val:
                max_val = val
                m = i
        if max_val <= epsilon:
            break
        # 步骤（3）
        up = 0
        bottom = 0
        for j in range(0, n):
            if j != m:
                up += (1 + a[m][j] * a[m][j]) * (w[j] / w[m])
                bottom += (1 + a[j][m] * a[j][m]) * (w[m] / w[j])

        T = pow(up / bottom, 1 / 2)
        X = w
        X[m] *= T
        sum_X = sum(X)
        for i in range(0, n):
            w[i] = X[i] / sum_X
    return w

def calculate_td(matrix: np.array, weight_vector: np.ndarray) -> float:
    n = len(weight_vector)
    td = 0.0
    for i in range(n):
        for j in range(n):
            td += abs(matrix[i, j] - (weight_vector[i] / weight_vector[j]))
    return td

def main():
    weights_ev = calculate_ev_weights(A)
    weights_llsm = calculate_llsm_weights(A)
    weights_csm = calculate_csm_weights(A, 1e-10, 1000)

    print("判断矩阵:\n", A)
    print("权重向量 EV:", weights_ev)
    print("权重向量 LLSM:", weights_llsm)
    print("CSM 权重向量:", weights_csm)

    # 添加用户交互功能，选择保留几位小数
    decimal_places = int(input("请输入要保留的小数点位数："))
    w1 = np.round(weights_ev, decimal_places)
    w2 = np.round(weights_llsm, decimal_places)
    w3 = np.round(weights_csm, decimal_places)

    print(f"保留到小数点后 {decimal_places} 位的权重向量：")
    print("EV 权重向量:", w1)
    print("LLSM 权重向量:", w2)
    print("CSM 权重向量:", w3)

    # 计算 TD 值
    TD_EV = calculate_td(A, w1)
    TD_LLSM = calculate_td(A, w2)
    TD_CSM = calculate_td(A, w3)

    print("TD EV:", TD_EV)
    print("TD LLSM:", TD_LLSM)
    print("TD CSM:", TD_CSM)

    td_values = {"EV": TD_EV, "LLSM": TD_LLSM, "CSM": TD_CSM}
    min_method = min(td_values, key=td_values.get)
    print(f"最小的 TD 值为 {td_values[min_method]}，选 {min_method} 计算的权重向量为可信属性的权重向量。")


if __name__ == "__main__":
    main()