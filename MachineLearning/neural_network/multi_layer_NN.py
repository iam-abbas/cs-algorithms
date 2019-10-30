'''
This is simple code for building multilayer neural network (NN) using Keras Sequential API
'''
from keras.models import Sequential
from keras.layers import Dense, Activation
from keras.optimizers import SGD
from keras.models import Model

from sklearn.datasets import load_svmlight_file
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from keras.utils.vis_utils import plot_model

import numpy as np

#convert [0,3,1] to one-hot vector -> [[1, 0, ...],[0, 0, 0, 1, ...],[0, 1, 0, ...]]
def toOneHot(np_array1d, n_labels):
    np_array1d = np_array1d.astype(int)
    np_array2d = np.zeros((np_array1d.shape[0], n_labels))
    np_array2d[np.arange(np_array1d.shape[0]), np_array1d] = 1
    return np_array2d

#load dataset in svmlib format
X, y = load_svmlight_file("data.txt")
X = X.toarray()
y = toOneHot(y, 10)

#scaling to [0,1]
min_max_scaler = preprocessing.MinMaxScaler()
X_scaled = min_max_scaler.fit_transform(X)

#split train-testing
X_train, X_test, Y_train, Y_test = train_test_split(X_scaled, y, test_size=0.3)

model = Sequential()

model.add(Dense(output_dim=256, input_dim=779))
model.add(Activation("relu"))

model.add(Dense(output_dim=64))
model.add(Activation("relu"))

model.add(Dense(output_dim=10))
model.add(Activation("softmax"))

model.compile(loss='categorical_crossentropy', \
              optimizer=SGD(lr=0.01, momentum=0.9, nesterov=True), \
              metrics=['accuracy'])

model.fit(X_train, Y_train, \
          nb_epoch=25, \
          batch_size=32, \
          verbose=1, \
          validation_data=(X_test, Y_test))

loss_and_metrics = model.evaluate(X_test, Y_test, batch_size=32)
print (loss_and_metrics)

classes = model.predict_classes(X_test, batch_size=32)
proba = model.predict_proba(X_test, batch_size=32)
json_string = model.to_json()
print(json_string)

weights = model.get_weights()
print(weights)

plot_model(model, to_file='model.png')
model.save_weights('parameter_model.h5')