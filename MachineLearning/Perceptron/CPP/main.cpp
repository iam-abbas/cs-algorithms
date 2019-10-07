#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

double f(double x){
    const double m = 0.3;
    const double b = 0.2;
    return m * x + b;
}

class Perceptron{
    public:
        vector<double> weights;
        double lr;

        Perceptron(int inputLength, double learningRate){
            weights.resize(inputLength,0);

            for(int i=0; i<weights.size(); i++){
                weights[i] = -1 + 2 * (double)rand()/RAND_MAX;
            }

            lr = learningRate;
        }

        double sing(double value){
            return value > 0 ? 1 : -1;
        }

        double guess(vector<double> inputs){
            double sum = 0;

            for(int i=0; i<inputs.size(); i++){
                sum += inputs[i] * weights[i];
            }

            return sing(sum);
        }

        void train(vector<double> inputs, double target){
            double attempt = guess(inputs);
            double error = target - attempt;

            for(int i=0; i<weights.size(); i++){
                weights[i] += error * inputs[i] * lr;
            }
        }  
};

class Point{
    public:
        double x,y,label;
        double bias = 1;
        
        Point(){
            x = -1 + 2 * (double)rand()/RAND_MAX;
            y = -1 + 2 * (double)rand()/RAND_MAX;
            label = y >= f(x) ? 1 : -1;
        }
};

int main(){
    srand(time(0));

    int pointssize = 1000;
    double trainedRate = 0;
    double untrainedRate = 0;

    Perceptron perceptron(3,0.1);

    vector<Point> points;
    points.resize(pointssize);

    for(int i=0; i<points.size(); i++){
        Point p;
        points[i] = p;
        //cout << points[i].x << endl;
    }

    for(int i=0; i<points.size(); i++){
        vector<double> inputs;
        inputs.push_back(points[i].x);
        inputs.push_back(points[i].y);
        inputs.push_back(points[i].bias);

        double target = points[i].label;
        double guess = perceptron.guess(inputs);

        if(guess == target){
            untrainedRate++;
        }
    }

    for(int i=0; i<points.size(); i++){
        vector<double> inputs;
        inputs.push_back(points[i].x);
        inputs.push_back(points[i].y);
        inputs.push_back(points[i].bias);
        double target = points[i].label;

        perceptron.train(inputs,target);
    }

    for(int i=0; i<points.size(); i++){
        vector<double> inputs;
        inputs.push_back(points[i].x);
        inputs.push_back(points[i].y);
        inputs.push_back(points[i].bias);

        double target = points[i].label;
        double guess = perceptron.guess(inputs);

        if(guess == target){
            trainedRate++;
        }
    }

    cout << "Trained: " << trainedRate/pointssize << " Untrained: " << untrainedRate/pointssize <<  endl;

    return 0;
}