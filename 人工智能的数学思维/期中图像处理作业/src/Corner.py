import cv2

image = cv2.imread("temp.jpg") # 读取图片

# 转换为灰度图
Grey = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

Corners = cv2.goodFeaturesToTrack(Grey, 200, 0.1, 10)
# 角点检测（图片，返回的角点数，质量等级，特征点之间的最小距离）
# 质量等级越小，返回的点越多，具体的真实情况需要自己慢慢调整

for corner in Corners:
    x, y = corner.ravel()
    cv2.circle(image, (int(x), int(y)), 5, (255, 0, 255), -1)
    # 画圆（图片，圆心，半径，颜色，线宽）

cv2.imshow("Corners", image)
cv2.waitKey()
