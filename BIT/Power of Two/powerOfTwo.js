const isPowerOfTwo = number => {
  if (number === 0) {
    return 1;
  }
  number & (number - 1) === 0;
}

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Please input a number: ', (answer) => {
  console.log(isPowerOfTwo(answer) === 0);
  rl.close();
});
