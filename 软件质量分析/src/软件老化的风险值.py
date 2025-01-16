import math
from fractions import Fraction


def input_data():
    """
    输入数据，包括类别数、各类别的权重（手动输入或通过表格计算）、度量元数量及其权重和风险值。
    """
    n = int(input("类别数："))

    # 判断用户是否提供权重
    has_weights = input("是否提供了各类别的权重？(y/n): ").strip().lower()
    if has_weights == 'y':
        theta = list(map(float, input("请输入各类别的权重（用空格分隔）：").split()))
    else:
        print("请输入表格数据来计算各类别权重：")
        table = []
        for i in range(n):
            row = list(map(lambda x: float(Fraction(x)), input(f"  第 {i + 1} 行的数据（用空格分隔）：").split()))
            table.append(row)

        # 计算各行总计
        row_totals = [sum(row) for row in table]
        total_sum = sum(row_totals)
        theta = [row_total / total_sum for row_total in row_totals]

        # 提示用户保留小数点位数
        decimal_places = int(input("计算得到的各类别权重值为：{}\n请输入需要保留的小数点位数：".format(theta)))
        theta = [round(w, decimal_places) for w in theta]  # 保留用户指定的小数位数
        print(f"保留到小数点后 {decimal_places} 位的权重值为：{theta}")

    m = list(map(int, input("各个类别的度量元数量（用空格分隔）：").split()))

    R = []  # 各类别度量元的最大风险值
    BETA = []  # 各类别度量元的权重
    for i in range(n):
        print(f"输入第 {i + 1} 个类别的数据：")
        beta = list(map(lambda x: float(Fraction(x)), input(f"  各度量元的权重（用空格分隔）：").split()))
        r = list(map(lambda x: float(Fraction(x)), input(f"  各度量元的最大风险值（用空格分隔）：").split()))
        BETA.append(beta)
        R.append(r)

    return n, theta, m, R, BETA


def calculate_entropy_and_trust(n, m, R, BETA):
    """
    计算各类别的熵 (H) 和可信值 (U)。
    """
    Hs = []  # 熵
    Us = []  # 可信值
    for i in range(n):
        # 计算熵 H
        H = sum(BETA[i][j] * math.log10(R[i][j]) for j in range(m[i]))

        # 计算可信值 U
        U = max(10 * math.exp(-H), 1)

        Hs.append(H)
        Us.append(U)

    return Hs, Us


def calculate_total_trust(n, theta, Us):
    """
    计算最终的可信值 T。
    """
    T = 1
    for i in range(n):
        T *= math.pow(Us[i], theta[i])
    return T


def main():
    n, theta, m, R, BETA = input_data()

    # 计算熵和可信值
    Hs, Us = calculate_entropy_and_trust(n, m, R, BETA)

    print("各类别的熵：", Hs)
    print("各类别的可信值：", Us)

    T = calculate_total_trust(n, theta, Us)
    print("总可信值：", T)


if __name__ == "__main__":
    main()
