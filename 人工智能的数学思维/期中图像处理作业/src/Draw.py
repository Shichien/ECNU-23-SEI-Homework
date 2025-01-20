import cv2
import numpy as np # 导入np库的典型方式，利用这个方法来缩写库名

image = np.zeros((400, 400, 3), dtype="uint8") # 创建400x400画布图片，3通道，数据类型为uint8

cv2.line(image, (0, 0), (400, 400), (0, 255, 0), 10) # 画线（图片，起点，终点，颜色，线宽）
cv2.rectangle(image, (10, 50), (60, 100), (0, 0, 255), 2) # 画矩形（图片，左上角，右下角，颜色，线宽）
cv2.circle(image, (100, 100), 20, (255, 0, 0), -1) # 画圆（图片，圆心，半径，颜色，线宽）
cv2.putText(image, "OpenCV", (150, 150), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
# 写字（图片，文字，位置，字体，大小，颜色，线宽）
cv2.waitKey() # 等待按键，为了让图片不一闪而过