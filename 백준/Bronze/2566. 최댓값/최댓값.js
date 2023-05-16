const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

let arr = Array(9);
for (let i = 0; i < 9; i++) {
    arr[i] = new Array();
}
for (let i = 0; i < 9; i++) {
    let newArr = input[i].split(" ").map(item => Number(item));
    for (let j = 0; j < 9; j++) {
        arr[i].push(newArr[j]);
    }
}
let maxNum = -1;
let [a, b] = [-1, -1];
for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
        if (arr[i][j] > maxNum) {
            maxNum = arr[i][j];
            [a, b] = [i + 1, j + 1];
        }
    }
}
console.log(maxNum);
console.log(a + " " + b);