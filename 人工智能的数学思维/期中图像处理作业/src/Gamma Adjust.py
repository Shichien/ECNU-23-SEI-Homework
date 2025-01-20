import cv2
import numpy as np

def adjust_gamma(image, gamma=1.0):
    # 通过构建伽马校正查找表进行伽马校正
    inv_gamma = 1.0 / gamma
    # 使用 numpy 的 arange 函数创建了一个查找表
    # 生成从0到255的数字数组（RGB）
    # 数组中的每个值 i 都通过除以 255.0 进行归一化
    # 然后乘以 inv_gamma 的幂，再缩放回 0 ~ 255 的范围
    # 得到的数组转换为 8位 无符号整数数组
    table = np.array([((i / 255.0) ** inv_gamma) * 255
        for i in np.arange(0, 256)]).astype("uint8")

    # 最后，使用OpenCV的LUT函数将查找表应用到图像
    # 根据查找表映射图像的像素值进行伽马校正
    return cv2.LUT(image, table)

# 读取图像
image = cv2.imread('Gamma Before.jpg')

# 设置伽马值（可根据需要调整）
gamma = 1.35

# 进行伽马校正
adjusted_image = adjust_gamma(image, gamma=gamma)

# 显示原始图像和伽马校正后的图像
cv2.imshow('Original Image', image)
cv2.imshow('Adjusted Image', adjusted_image)

# 保存伽马校正后的图像
cv2.imwrite('Gamma After.jpg', adjusted_image)
cv2.waitKey(0)
cv2.destroyAllWindows()

