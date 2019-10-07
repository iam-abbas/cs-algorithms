class Perceptron{
    constructor(inputLength, learningRate){
        this.weights = [];
        this.learningRate = learningRate;

        for(let i=0; i < inputLength; i++){
            this.weights[i] = this.random(1,-1);
        }
    }

    sing(value){
        return value > 0 ? 1 : -1;
    }

    random(max,min){
        return Math.random() * (max  - min) + min;
    }

    guess(inputs){
        let sum = 0;

        this.weights.forEach((weight,index) => {
            sum += inputs[index] * weight;
        });

        return this.sing(sum);
    }

    train(inputs, target){
        const guess = this.guess(inputs);
        const error = target - guess;

        for(let i=0; i < this.weights.length; i++){
            this.weights[i] += error * inputs[i] * this.learningRate;
        }
    }
}

class Point{
    constructor(){
        this.x = this.random(1,-1);
        this.y = this.random(1,-1);
        //this.label = this.x > this.y ? 1 : -1;
        this.label = this.y >= f(this.x) ? 1 : -1;
        this.bias = 1;
    }

    random(max,min){
        return Math.random()    * (max  - min) + min;
    }
}

function f(x){
    const m = 0.3;
    const b = 0.2; 
    return m * x + b;
}

function main(){
    const perceptron = new Perceptron(3,0.1);
    const points = [];
    const pointsLenght = 1000;
    let rate = 0;
    let untrainedRate = 0;

    for(let i=0; i < pointsLenght; i++){
        points.push(new Point());
    }
    
    points.forEach(point => {
        const input = [point.x, point.y, point.bias];
        const target = point.label;
        const guess = perceptron.guess(input);

        if(guess === target){
            untrainedRate++;
        }
    });

    points.forEach(point => {
        const input = [point.x, point.y, point.bias];
        const target = point.label;
        
        perceptron.train(input, target);
    });
    
    points.forEach(point => {
        const input = [point.x, point.y, point.bias];
        const target = point.label;
        const guess = perceptron.guess(input);

        if(guess === target){
            rate++;
        }
    });
    
    console.log('Trained:', rate/pointsLenght, 
                'Untrained:',untrainedRate/pointsLenght);
}


main();