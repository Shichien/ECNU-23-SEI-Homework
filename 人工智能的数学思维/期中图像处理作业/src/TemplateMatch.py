import cv2
import numpy as np

image = cv2.imread("temp.jpg", cv2.IMREAD_GRAYSCALE) # 读取图片（以灰度图的形式读取）

cv2.imshow("Image", image) # 显示图片
print("The Shape is:", image.shape) # 显示图片的尺寸


template = image[310:350,380:405] # 第一个值是高（Y的值），第二个值是宽

cv2.imshow("Template", template) # 显示模板
match = cv2.matchTemplate(image, template, cv2.TM_CCOEFF_NORMED)
# TM_CCOEFF_NORMED：相关系数匹配法，防止因为光照导致的结果不准确

locations = np.where(match >= 0.4) # 匹配系数 >= 0.9
high, weight = template.shape

for point in zip(*locations[::-1]):
    cv2.rectangle(image, point, (point[0] + 5, point[1] + 5), 255, 1)
    # 画矩形框：图片，左上角坐标，右下角坐标，颜色，线宽

cv2.imshow("Match", image)
cv2.waitKey()
