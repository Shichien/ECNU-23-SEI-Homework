import cv2

image1 = cv2.imread("temp.jpg")
image2 = cv2.imread("temp2.jpg")

image1_resized = cv2.resize(image1, (1000, 1000))
image2_resized = cv2.resize(image2, (1000, 1000))

Final = cv2.addWeighted(image1_resized, 0.6, image2_resized, 0.6, 0)
# 图像混合函数，两张图片的尺寸大小必须一致

cv2.imshow("Final", Final)
cv2.waitKey()
cv2.destroyAllWindows()

# 以上代码实现了两张图片的混合，其中 addWeighted 函数的参数分别为两张图片，两张图片的权重，以及亮度