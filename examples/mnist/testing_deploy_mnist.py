import os
import numpy as np
import sys
import cv2
import logging
import cProfile, pstats, StringIO
from datetime import datetime

startTime = datetime.now()

# Make sure that caffe is on the python path:
CAFFE_ROOT = '/home/jarg/TestingRemoval1/' # CHANGE THIS LINE TO YOUR Caffe PATH
sys.path.insert(0, CAFFE_ROOT + 'python')

import caffe

# Set the right path to your model definition file, pretrained model weights,
# and the image you would like to classify.
MODEL_FILE = CAFFE_ROOT + 'examples/mnist/lenet_deploy.prototxt'
PRETRAINED = CAFFE_ROOT + 'examples/mnist/lenet_iter_10000.caffemodel' 

imageArray = [];
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_1_is2.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_2_is0.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_3_is9.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_4_is0.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_5_is3.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_6_is7.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_7_is0.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_8_is3.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_9_is0.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_10_is3.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_11_is5.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_12_is7.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_14_is0.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_15_is4.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_16_is3.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_17_is3.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_18_is1.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_19_is9.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_20_is0.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_35_is6.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/img_45_is8.jpg')
imageArray.append(CAFFE_ROOT + 'examples/mnist/mnistasjpg/testSample/test_3.png')

net = caffe.Net(caffe.TEST)
transformer = caffe.io.Transformer({'data': (1, 1, 28, 28)})
transformer.set_transpose('data', (2, 0, 1))    
transformer.set_raw_scale('data', 1/255.)

testsRun = 0
testsPassed = 0

for arrayImage in imageArray:
	assert os.path.exists(arrayImage), "image %s not found" % arrayImage
	image = cv2.imread(arrayImage)
	image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
	image.resize((28, 28, 1))

	net.blobs['data'].reshape(1, 1, 28, 28)
	net.blobs['data'].data[...] = transformer.preprocess('data', image)    

	net.forward()
	scores = net.blobs['ip2'].data

	testsRun += 1
	if (scores.argmax() == int(arrayImage[-5])):
		testsPassed += 1
	else:
		print 'test failed with the following image: ',arrayImage

print 'Tests passed = ',testsPassed,'/',testsRun	
print 'Script took', datetime.now()-startTime, 'seconds.'

## This code has been copied and modified from the following link:
## https://github.com/9crk/caffe-mnist-test/blob/master/mnist_test.py



