import cv2

image = cv2.imread("temp.jpg") # 读取图片

cv2.imshow("Blue", image[:, :, 0]) # 显示蓝色通道
cv2.imshow("Green", image[:, :, 1]) # 显示绿色通道
cv2.imshow("Red", image[:, :, 2]) # 显示红色通道

gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY) # 转换为灰度图
# 做平方和加权平均，将三个通道的值加权平均，得到一个灰度图
cv2.imshow("Gray", gray) # 显示灰度图
cv2.waitKey() # 等待按键，为了让图片不一闪而过