const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split("\n");

let i = 0;

while (1) {
    let newArr = input[i].split(" ").map(item => Number(item));
    if (newArr[0] == 0) break;
    console.log(newArr[0] + newArr[1]);
    i++;
}