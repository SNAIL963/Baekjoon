const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

let arr = new Array(30);
let newArr = input[0].split(" ").map(item => Number(item));
let basket = +newArr[0];
let M = +newArr[1];

for (let i = 0; i < 28; i++) {
    let a = +input[i];
    arr[a] = 1;
}
for (let i = 1; i <= 30; i++) {
    if(typeof(arr[i]) === 'undefined'){
        console.log(i);
    }
}