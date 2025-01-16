# Code By Deralive (10235101526)
# 2024/11/07
# https://github.com/Shichien
# Connect: 10235101526@stu.ecnu.edu.cn
# Bilibili: 诗千 Shichien
# Wechat: Deralive

# 可信属性度量值计算以及软件可信度量值计算模型都使用幂积公式

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
pd.set_option("display.max_row", None)
pd.set_option("display.max_columns", None)

plt.rcParams['font.sans-serif'] = ['SimHei']  # 使用SimHei字体
plt.rcParams['axes.unicode_minus'] = False  # 正确显示负号

# 定义字母到分数的映射
letter_to_score = {
    'A': 10,
    'B': 9,
    'C': 7,
    'D': 2
}

# 属性权重（从表格提取）
attribute_weights = np.array([0.05, 0.17, 0.20, 0.15, 0.09, 0.09, 0.11, 0.05, 0.09])

# 子属性权重
sub_attribute_weights = np.array([
    0.31, 0.36, 0.33, # 总体策划与执行情况 GroupLength = 3
    0.33, 0.33, 0.34, # 分析与设计情况 GroupLength = 3
    0.16, 0.17, 0.17, 0.17, 0.17, 0.16, # 测试验证情况 GroupLength = 6
    0.33, 0.34, 0.33, # 可靠性和安全性情况
    0.34, 0.33, 0.33, # 软件技术状态更改情况
    0.50, 0.50,       # 质量问题归零及举一反三情况
    0.33, 0.34, 0.33, # 配置管理情况
    0.50, 0.50,       # 软件开发环境情况
    0.33, 0.33, 0.34  # 第三方评测情况
])

group_lengths = [3, 3, 6, 3, 3, 2, 3, 2, 3]

# 输入的字母形式的 scores
letter_scores = np.array([
    ['C', 'B', 'C', 'D', 'B', 'B', 'C', 'A', 'C', 'D', 'C', 'A', 'C', 'C', 'C', 'C', 'C', 'A', 'D', 'C', 'A', 'A', 'A', 'B', 'B', 'C', 'C', 'D'],
    ['C', 'B', 'B', 'B', 'D', 'D', 'B', 'C', 'C', 'C', 'B', 'C', 'B', 'C', 'C', 'A', 'B', 'A', 'A', 'C', 'A', 'A', 'A', 'B', 'B', 'A', 'A', 'A'],
    ['C', 'B', 'B', 'B', 'D', 'D', 'A', 'A', 'C', 'C', 'A', 'C', 'B', 'B', 'B', 'A', 'B', 'A', 'A', 'C', 'A', 'A', 'A', 'B', 'B', 'A', 'A', 'A'],
    ['C', 'B', 'B', 'B', 'D', 'D', 'B', 'C', 'C', 'C', 'B', 'C', 'B', 'C', 'C', 'A', 'B', 'A', 'A', 'C', 'A', 'A', 'A', 'B', 'B', 'A', 'A', 'A'],
    ['C', 'B', 'B', 'B', 'D', 'D', 'B', 'C', 'C', 'C', 'B', 'C', 'B', 'C', 'C', 'A', 'B', 'A', 'A', 'C', 'A', 'A', 'A', 'B', 'B', 'A', 'A', 'A'],
    ['C', 'B', 'B', 'B', 'D', 'D', 'A', 'B', 'C', 'C', 'B', 'C', 'B', 'B', 'B', 'A', 'B', 'A', 'A', 'C', 'A', 'A', 'A', 'B', 'B', 'A', 'A', 'A'],
    ['C', 'B', 'B', 'B', 'D', 'D', 'B', 'C', 'C', 'C', 'B', 'C', 'B', 'C', 'C', 'A', 'B', 'A', 'A', 'C', 'A', 'A', 'A', 'B', 'B', 'A', 'A', 'A'],
    ['C', 'B', 'B', 'B', 'D', 'D', 'B', 'C', 'C', 'C', 'B', 'C', 'B', 'C', 'C', 'A', 'B', 'A', 'A', 'C', 'A', 'A', 'A', 'B', 'B', 'A', 'A', 'B']
])

# 转换字母为分数
scores = np.vectorize(letter_to_score.get)(letter_scores)

def calculate_group_results(scores, sub_attribute_weights, group_lengths):
    """计算每个组的加权几何平均值"""
    results = []
    for row in scores:
        idx = 0
        row_results = []
        for length in group_lengths:
            x_i = row[idx:idx + length]
            w_i = sub_attribute_weights[idx:idx + length]
            G = np.prod(x_i ** w_i)  # 幂积公式计算加权几何平均值
            row_results.append(G)
            idx += length
        results.append(row_results)
    return np.array(results)


def calculate_final_results(results, attribute_weights):
    """计算最终的可信值"""
    final_results = []
    for row in results:
        final_value = np.prod(row ** attribute_weights)
        final_results.append(final_value)
    return np.array(final_results)


def classify_trust_levels(final_results, attribute_scores):
    """根据可信值计算可信等级"""
    trust_levels = []
    for T, scores in zip(final_results, attribute_scores):
        n = len(scores)
        print(f"n的个数为{n},", end='')
        threshold_2_3 = n - int(np.ceil(2 * n / 3))  # 使用 ceil 函数向上取整
        print(f"不能超过{threshold_2_3}个")

        # 统计低于某些阈值的属性个数
        low_9_5 = np.sum(scores < 9.5)
        low_8_5 = np.sum(scores < 8.5)
        low_7_0 = np.sum(scores < 7.0)
        low_4_5 = np.sum(scores < 4.5)

        if T >= 9.5 and low_9_5 <= threshold_2_3 and low_8_5 == 0:
            trust_levels.append("V")
            continue

        if (8.5 <= T < 9.5 and low_8_5 <= threshold_2_3 and low_7_0 == 0) or (T > 9.5 and "V" not in trust_levels):
            trust_levels.append("IV")
            continue

        if (7.0 <= T < 8.5 and low_7_0 <= threshold_2_3 and low_4_5 == 0) or (T > 8.5 and "IV" not in trust_levels):
            trust_levels.append("III")
            continue

        if (4.5 <= T < 7.0 and low_4_5 <= threshold_2_3) or (T > 7.0 and "III" not in trust_levels):
            trust_levels.append("II")
            continue

        if T < 4.5 or (T > 4.5 and "II" not in trust_levels):
            trust_levels.append("I")
            continue

    return trust_levels


def plot_attribute_distribution(results):
    """绘制可信属性值分布情况"""
    x = range(1, results.shape[1] + 1)
    plt.figure(figsize=(12, 6))

    for i in range(results.shape[0]):
        plt.plot(x, results[i], marker='o', label=f'Software No. {i + 10}')

    plt.xlabel('软件可信属性', fontsize=12)
    plt.ylabel('可信属性值', fontsize=12)
    plt.title('可信属性值分布情况', fontsize=14)
    plt.legend(loc='lower left', bbox_to_anchor=(1.05, 0), fontsize=10)
    plt.grid(True)
    plt.tight_layout()


def plot_sub_attribute_distribution(scores):
    """绘制软件可信子属性值分布情况"""
    x = range(1, scores.shape[1] + 1)
    plt.figure(figsize=(12, 6))

    for i in range(scores.shape[0]):
        plt.plot(x, scores[i], marker='o', label=f'Software No. {i + 10}')

    plt.yticks([2, 4, 6, 8, 10])
    plt.xlabel('软件可信子属性', fontsize=12)
    plt.ylabel('软件可信子属性值', fontsize=12)
    plt.title('软件可信子属性值分布情况', fontsize=14)
    plt.legend(loc='lower left', bbox_to_anchor=(1.05, 0), fontsize=10)
    plt.grid(True)
    plt.tight_layout()


def main():
    # 询问用户是否保留小数及其精度
    while True:
        try:
            decimal_places = input("是否需要保留小数？输入保留的位数（直接回车表示不保留小数）：")
            if decimal_places.strip() == "":
                decimal_places = None
            else:
                decimal_places = int(decimal_places)
            break
        except ValueError:
            print("请输入有效的整数或直接按回车跳过！")

    # 计算每组的加权几何平均值
    group_results = calculate_group_results(scores, sub_attribute_weights, group_lengths)
    print("Table of Results:")
    if decimal_places is not None:
        group_results = np.round(group_results, decimal_places)
    print(group_results)

    # 计算最终的可信值
    final_results = calculate_final_results(group_results, attribute_weights)
    print("最终计算结果：")
    if decimal_places is not None:
        final_results = np.round(final_results, decimal_places)
    print(final_results)

    # 分类可信等级
    trust_levels = classify_trust_levels(final_results, group_results)
    print("可信等级：")
    print(trust_levels)

    # 创建表格
    df = pd.DataFrame(group_results, columns=[f'属性{i + 1}' for i in range(group_results.shape[1])])
    df['最终可信值'] = final_results
    df['可信等级'] = trust_levels

    # 打印表格
    print("可信属性表：")
    print(df)

    # 绘制分布图
    plot_attribute_distribution(group_results)
    plot_sub_attribute_distribution(scores)
    plt.show()


if __name__ == "__main__":
    main()