const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

let arr = new Array();
let newArr = input[0].split(" ").map(item => Number(item));
let basket = +newArr[0];
let M = +newArr[1];

for (let i = 0; i < basket; i++) {
    arr[i] = i + 1;
}
for (let i = 1; i <= M; i++) {
    let [a, b] = input[i].split(" ").map(item => Number(item));
    a--; b--;
    let temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
console.log(arr.join(' '));