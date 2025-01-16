import numpy as np
import pandas as pd

weights = np.array([0.15, 0.20, 0.20, 0.25, 0.20])

data = {
    'x1': [8.6, 8.6, 6.8, 6.8, 9.1, 9.1, 3.5, 3.5],
    'x2': [9.1, 9.1, 7.9, 7.9, 9.9, 9.9, 4.2, 4.2],
    'x3': [9.2, 9.2, 5.9, 5.9, 8.9, 8.9, 5.6, 5.6],
    'x4': [8.8, 8.8, 6.6, 6.6, 8.8, 8.8, 4.9, 4.9],
    'x5': [8.9, 8.9, 6.1, 6.1, 7.8, 7.8, 5.2, 5.2],
    'rho_y': [0.01, 0.55, 0.01, 0.55, 0.01, 0.55, 0.01, 0.55]
}

df = pd.DataFrame(data)

def calculate_y1(row):
    x_values = np.array([row['x1'], row['x2'], row['x3'], row['x4'], row['x5']])
    y1 = np.prod(x_values ** weights)
    return y1

def calculate_y2(row):
    x_values = np.array([row['x1'], row['x2'], row['x3'], row['x4'], row['x5']])
    rho_y = row['rho_y']
    summation = np.sum(weights * (x_values ** -rho_y))
    y2 = summation ** (-1 / rho_y)
    return y2

def main():
    df['y1'] = df.apply(calculate_y1, axis=1)
    df['y2'] = df.apply(calculate_y2, axis=1)
    print(df)

if __name__ == "__main__":
    main()