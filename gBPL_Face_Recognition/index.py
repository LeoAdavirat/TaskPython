i = 1022
import cv2
import mediapipe as mp

# import dlib
from PIL import Image
from skimage import io

mp_face_detection = mp.solutions.face_detection.FaceDetection(
    min_detection_confidence=0.7
)
mp_drawing = mp.solutions.drawing_utils

webcam = cv2.VideoCapture(0)
while webcam.isOpened():
    success, img = webcam.read()
    i += 1
    # face detection using MediaPipe
    img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    results = mp_face_detection.process(img)

    # draw the face detection annotations on the image
    img = cv2.cvtColor(img, cv2.COLOR_RGB2BGR)
    if results.detections:
        for detection in results.detections:
            mp_drawing.draw_detection(img, detection)
            a = str(detection).split()
            xmin = int(float(a[11]) * 640)
            ymin = int(float(a[13]) * 480)
            width = int(float(a[15]) * 640)
            height = int(float(a[17]) * 480)
            cropped_img = img[ymin : ymin + height, xmin : xmin + height]
            cv2.imwrite("dataset/image{}.jpg".format(i), cropped_img)
    cv2.imshow("Koolac", img)
    if cv2.waitKey(5) & 0xFF == ord("q"):
        break

webcam.release()
cv2.destroyAllWindows()
