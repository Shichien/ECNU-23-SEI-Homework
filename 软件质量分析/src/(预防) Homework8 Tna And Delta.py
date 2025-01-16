def delta_ij(rho):
    if rho == 1:  # 避免除零错误
        raise ValueError("rho = 1 时，delta_ij 无法计算 (除零错误)")
    return 1 / (1 - rho)

def mu_na(kappa, rho):
    return kappa ** rho

def measure(kappa, rho):
    mu_value = mu_na(kappa, rho)  # 计算 mu_na
    if mu_value < 1 / 10:  # 判断 mu_na 是否小于 1/10
        return 1
    else:
        return 10 * mu_value

def T_na(modules, rho):
    total = 0
    for beta, kappa in modules:
        mu_value = measure(kappa, rho)  # 使用 measure 计算 μ(m)
        total += beta * (mu_value ** rho)
    return total ** (1 / rho)

modules = [
    (0.085, 0.053),  # (beta, kappa) for EM1
    (0.208, 0.132),  # (beta, kappa) for EM2
    (0.085, 0.026),  # (beta, kappa) for EM3
    (0.047, 0.000),  # (beta, kappa) for EM4
    (0.066, 0.000),  # (beta, kappa) for EM5
    (0.094, 0.105),  # (beta, kappa) for EM6
    (0.160, 0.053),  # (beta, kappa) for EM7
    (0.255, 0.026)   # (beta, kappa) for EM8
]

rho_values = [0.8, 0.6, 0.4, 0.2, 0.1, 0.01, 0.001]

print(f"{'rho':<8}{'T_na(S)':<15}{'delta_ij':<10}")
print("-" * 35)

for rho in rho_values:
    T_na_value = T_na(modules, rho)
    delta_value = delta_ij(rho)
    print(f"{rho:<8.3f}{T_na_value:<15.6f}{delta_value:<10.2f}")