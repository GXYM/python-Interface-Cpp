#!/usr/bin/python
#Filename:TestModule.py
import numpy as np
import cv2

def arrayreset(array):
    a = array[:, 0:len(array[0] - 2):3]
    #b = array[:, 1:len(array[0] - 2):3]
    #c = array[:, 2:len(array[0] - 2):3]
    #print(a.shape, b.shape, c.shape)
    #a = a[:, :, 3]
    #b = b[:, :, 3]
    #c = c[:, :, 3]
    #m = np.concatenate((a, b, c), axis=2)

    return a

def load_image(image):
    cv2.imshow("test",image)
    cv2.waitKey(0)

class Example():
    def __init__(self):
        self.word = "sbsbsbsb"
        print("sbsbsbsb")

    def load_image(self, image):
        cv2.imshow("test", image)
        cv2.waitKey(0)
        print(self.word)
        return 1

    def deal_image(self, image):
        print(self.word)
        im = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
        cv2.imshow("test", im)
        cv2.waitKey(0)

        return "c"
        
