const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

let arr = new Array();
let newArr = input[0].split(" ").map(item => Number(item));
let basket = +newArr[0];
let h = +newArr[1];

for (let i = 1; i <= h; i++) {
    let [a, b, c] = input[i].split(" ").map(item => Number(item));
    for (let j = a; j <= b; j++) {
        arr[j-1] = c;
    }
}
for (let i = 0; i < basket; i++) {
    if (typeof arr[i] === 'undefined') {
        arr[i] = 0;
    }
}
console.log(arr.join(' '));