import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# fuction that returns sigmoid value of x
def sigmoid(theta, X):
    return 1/(1+np.exp(-np.dot(X, theta.T)))

# Calculates cost of training model. We have to minimize this cost
def gradient(X, theta, y):
    m = len(y)
    sigmoid_result = sigmoid(theta, X)
    value = (-1/m)*np.sum(y*np.log(sigmoid_result) + (1-y)*np.log(1-sigmoid_result))
    return value

# Returns partial diffrentiation value of gradient
def log_gradient(theta, X, y):
    m = len(y)
    h = sigmoid(theta, X) - y
    result = (1/m)*np.dot(h.T, X)
    return result

# Original gradient descent algorithm which minimize the cost function (gradient)	
def gradientDescent(X, theta, y, learning_rate=.01, converge_change=.00001):
    cost = gradient(X, theta, y)
    change_cost=1
    n=1
    while(change_cost > converge_change):
        old_cost=cost
        theta = theta - learning_rate*log_gradient(theta,X,y)
        cost = gradient(X, theta, y)
        change_cost = old_cost - cost
        n+=1
    print(n)
    return theta
	
# Method to train our model on training data
def fit(X_train, y_train):
	theta = np.zeros(X_train.shape[1])
	updated_parameters = gradientDescent(X_train, theta, y_train)
	return updated_parameters

# Method to predict output on new data or test data
def predict(X_test, final_theta):
	predicted_probabilities = sigmoid(final_theta, X_test)
	predicted_value = np.where(predicted_probabilities >= .5, 1, 0)
	return predicted_value

# method to visualize logistic regression. A plot between all samples and decision boundary
def plot_reg(X, y, theta): 
    ''' 
    function to plot decision boundary 
    '''
    # labelled observations
    X=np.array(X)
    x_0 = pd.DataFrame(X[np.where(y == 0)])
    x_1 = pd.DataFrame(X[np.where(y == 1)])
    
    # plotting points with diff color for diff label 
    plt.scatter(x_0.iloc[:,1], x_0.iloc[:,2], c='b', label='y = 0') 
    plt.scatter(x_1.iloc[:,1], x_1.iloc[:, 2], c='r', label='y = 1') 
    print(theta)
    # plotting decision boundary 
    x1 = np.arange(0, 10, 1) 
    x2 = -(theta[0] + theta[1]*x1)/theta[2] 
    plt.plot(x1, x2, c='k', label='reg line')
  
    plt.xlabel('x1') 
    plt.ylabel('x2') 
    plt.legend() 
    plt.show() 

	
if __name__ == "__main__":
    df = pd.read_csv("data.csv")
    df.insert(0, 'x0', 1.0)
    X_train = df.iloc[:,0:3]
    y_train = df['label']
    parameters = fit(X_train, y_train)
    X_test = np.array([[1, 5.123, 6.872], [1, 1.239, 6.165], [1, 8.6254, 7.829], [1, 2.382, 7.525], [1, 9.282, 1.626], [1, 3.272, 5.737], [1, 6.345, 4.276], [1, 3.372, 8.238]])
    result = predict(X_test, parameters)
    print(result)
    plot_reg(X_train, y_train, parameters)