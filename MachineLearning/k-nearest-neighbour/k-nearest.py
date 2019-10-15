import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.datasets import make_blobs
X, y = make_blobs(n_samples=200, centers=2, n_features=2, random_state=35)
plt.scatter(X[:,0],X[:,1],c=y)
plt.show()
query_x=np.array([-6,-3])
plt.scatter(X[:,0],X[:,1],c=y)
plt.scatter(query_x[0],query_x[1],c='red')
plt.show()


class KNN:
    def __init__(self,k=10):
        self.k=k
    def fit(self,X,y,x):
        self.X=X
        self.y=y
        self.x=x
        dis=[]
        res=[]
        for j in range(X.shape[0]):
            distan=self.distance(X[j],x)
            dis.append(distan)
        li=np.argsort(dis)
        top_k=li[:self.k]
        for i in top_k:
            res.append(y[i])
        
        u,val=np.unique(res,return_counts=True)
        
        return u[np.argmax(val)]
        
    def distance(self,x1,x2):
        return np.sum((x1-x2)**2)
    def score(self,x_train,y_train):
        res=self.fit(self.X,self.y,x_train)
        return np.sum((res==y_train)/len(y_train))

def main():
    model=KNN(k=10)
    result=model.fit(X,y,query_x)
    print(result)

if __name__ == "__main__":
    main()