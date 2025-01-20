import cv2
import numpy as np

def adjust_contrast(image, alpha, beta):
    adjusted_image = cv2.convertScaleAbs(image, alpha=alpha, beta=beta)
    return adjusted_image

image = cv2.imread('temp.jpg')

# 调整对比度和亮度
alpha = 1.5  # 对比度增益因子
beta = 5   # 亮度增益
adjusted_image = adjust_contrast(image, alpha, beta)

cv2.imshow('Original Image', image)
cv2.imshow('Adjusted Image', adjusted_image)
cv2.waitKey()
cv2.destroyAllWindows()


# opencv 图像 存储在 numpy 数组中，存储的是三个灰度图（存储在第三个维度上）
# BGR 是存储空间的顺序

