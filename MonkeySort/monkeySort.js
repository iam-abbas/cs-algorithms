//the worst/best sorting Algorithm 
numbers = [];
function fillNumbers() {
    for (i = 0; i < 100; i++) {
        numbers[i] = Math.random() * 10
    }
}
function sort() {
    while (!isSorted(numbers)) {
        for(i=0;i<numbers.length;i++){
            let temp = numbers[i];
            numbers[i] = numbers[Math.random()*numbers.length];
            numbers[Math.random()*numbers.length]=temp;
        }
    }
}

function isSorted(array) {
    for (i = 1; i < array.length; i++) {
        if (array[i] < array[i - 1]) {
            return false;
        }
    }
}