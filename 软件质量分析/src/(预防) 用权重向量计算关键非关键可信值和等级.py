from pprint import pprint

import numpy as np

# 作业
Critical_Confidence_value = np.array([8.430, 8.530, 6.042, 9.094, 8.289])

Non_Critical_Confidence_value = np.array([6.192, 8.020, 7.984, 8.713, 9.211, 7.777, 7.897, 8.075])

Critical_A = np.array([
    [1, 2, 1/2, 2, 1/4],
    [1/2, 1, 2, 3, 1/2],
    [2, 1/2, 1, 1, 1/2],
    [1/2, 1/3, 1, 1, 1/2],
    [4, 2, 2, 2, 1]
])

Non_Critical_A = np.array([
    [1, 3, 2, 1/2, 2, 1, 3, 3],
    [1/3, 1, 2, 1, 2, 2, 2, 2],
    [1/2, 1/2, 1, 1/2, 1, 1/2, 3, 3],
    [2, 1, 2, 1, 3, 1/2, 3, 3],
    [1/2, 1/2, 1, 1/3, 1, 1, 2, 2],
    [1, 1/2, 2, 2, 1, 1, 2, 2],
    [1/3, 1/2, 1, 1/3, 1/2, 1/2, 1, 2],
    [1/3, 1/2, 2, 1/3, 1/2, 1/2, 1/2, 1]
])


def classify_trust_level(T, scores):
    """
    分类可信等级
    :param: T: 系统可信度值
    :param: scores: 可信属性值数组
    :return: 可信等级
    """
    n = len(scores)
    threshold_2_3 = n - int(np.ceil(2 * n / 3))  # 计算 n - ⌈n × 2/3⌉

    # 统计低于某些阈值的属性个数
    low_9_5 = np.sum(scores < 9.5)
    low_8_5 = np.sum(scores < 8.5)
    low_7_0 = np.sum(scores < 7.0)
    low_4_5 = np.sum(scores < 4.5)

    if T >= 9.5:
        if low_9_5 <= threshold_2_3 and low_8_5 == 0:
            return "V"

    if 8.5 <= T < 9.5 or (T > 9.5):
        if low_8_5 <= threshold_2_3 and low_7_0 == 0:
            return "IV"

    if 7.0 <= T < 8.5 or (T > 8.5):
        if low_7_0 <= threshold_2_3 and low_4_5 == 0:
            return "III"

    if 4.5 <= T < 7.0 or (T > 7.0):
        if low_4_5 <= threshold_2_3:
            return "II"

    if T < 4.5 or (T > 4.5):
        return "I"


def calculate_system_trustworthiness(
        Critical_Confidence_value, Non_Critical_Confidence_value,
        alpha, beta, FC, NFC
):
    """
    计算系统可信度值 T_S

    参数:
    - Critical_Confidence_value: 关键组件的可信值数组 (numpy array)
    - Non_Critical_Confidence_value: 非关键组件的可信值数组 (numpy array)
    - alpha: 关键组件权重系数
    - beta: 非关键组件权重系数
    - FC: 关键组件权重向量 (numpy array)
    - NFC: 非关键组件权重向量 (numpy array)

    返回:
    - 系统可信度值 T_S
    """
    critical_product = np.prod(
        np.power(Critical_Confidence_value, FC)
    )
    print(f"关键属性乘积: {critical_product}")

    non_critical_product = np.prod(
        np.power(Non_Critical_Confidence_value, NFC)
    )
    print(f"非关键属性乘积: {non_critical_product}")

    T_S = alpha * critical_product + beta * non_critical_product

    return T_S

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
            print(f"CSM 算法在迭代次数为 {k} 次时收敛")
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

def calculate_td(matrix: np.array, weight_vector: np.ndarray) -> float:
    n = len(weight_vector)
    td = 0.0
    for i in range(n):
        for j in range(n):
            td += abs(matrix[i, j] - (weight_vector[i] / weight_vector[j]))
    return td


print("——————————————————————")
print("以下是关键组件的判断矩阵：")


print("判断矩阵:")
pprint(Critical_A)
print("——————————————————————")

weights_ev = calculate_ev_weights(Critical_A)
print("权重向量 EV:", weights_ev)

weights_llsm = calculate_llsm_weights(Critical_A)
print("权重向量 LLSM:", weights_llsm)

weights_csm = calculate_csm_weights(Critical_A, 1e-10, 1000)
print("CSM 权重向量:", weights_csm)

TD_EV = calculate_td(Critical_A, weights_ev)
TD_LLSM = calculate_td(Critical_A, weights_llsm)
TD_CSM = calculate_td(Critical_A, weights_csm)

print("TD EV:", TD_EV)
print("TD LLSM:", TD_LLSM)
print("TD CSM:", TD_CSM)

td_values = {"EV": TD_EV, "LLSM": TD_LLSM, "CSM": TD_CSM}
min_method = min(td_values, key=td_values.get)
print(f"最小的 TD 值为 {td_values[min_method]}，选 {min_method} 计算的权重向量为可信属性的权重向量。")
final_critical_weights = weights_ev if min_method == "EV" else weights_llsm if min_method == "LLSM" else weights_csm

print("————————————————————————")
print("以下是非关键组件的判断矩阵：")

print("判断矩阵:")
pprint(Non_Critical_A)
print("——————————————————————")

weights_ev = calculate_ev_weights(Non_Critical_A)
print("权重向量 EV:", weights_ev)

weights_llsm = calculate_llsm_weights(Non_Critical_A)
print("权重向量 LLSM:", weights_llsm)

weights_csm = calculate_csm_weights(Non_Critical_A, 1e-10, 1000)
print("CSM 权重向量:", weights_csm)

TD_EV = calculate_td(Non_Critical_A, weights_ev)
TD_LLSM = calculate_td(Non_Critical_A, weights_llsm)
TD_CSM = calculate_td(Non_Critical_A, weights_csm)

print("TD EV:", TD_EV)
print("TD LLSM:", TD_LLSM)
print("TD CSM:", TD_CSM)

td_values = {"EV": TD_EV, "LLSM": TD_LLSM, "CSM": TD_CSM}
min_method = min(td_values, key=td_values.get)
# min_method = "LLSM"
print(f"最小的 TD 值为 {td_values[min_method]}，选 {min_method} 计算的权重向量为可信属性的权重向量。")
final_non_critical_weights = weights_ev if min_method == "EV" else weights_llsm if min_method == "LLSM" else weights_csm

alpha = 0.6
beta = 0.4
print(f"此时的 Alpha 值为 {alpha}, Beta 值为 {beta}")

T_S = calculate_system_trustworthiness(
    Critical_Confidence_value, Non_Critical_Confidence_value,
    alpha, beta, final_critical_weights, final_non_critical_weights
)

print(f"Ts的值为：{T_S}")
Level = classify_trust_level(T_S, Critical_Confidence_value)
print("该软件的可信等级为：" + Level)



