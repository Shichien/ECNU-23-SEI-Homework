import cv2

image = cv2.imread("temp.jpg",) # 读取图片

Gauss = cv2.GaussianBlur(image ,(11,11), 0) # 均值滤波（图片，内核大小）
# 这里sigmaX = 0，代表这个值由内核决定
Median = cv2.medianBlur(image, 11) # 中值滤波（图片，内核大小）

cv2.imshow("After GaussBlur", Gauss)
cv2.imshow("Before Blur", image)
cv2.imshow("After MedianBlur", Median)
cv2.waitKey() # 等待按键，为了让图片不一闪而过
