const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split("\n");

let num = +input[0];
let answer = "";

for (let i = 1; i <= num; i++) {
    let newArr = input[i].split(" ").map(item => Number(item));
    console.log("Case #" + i + ": " + (newArr[0] + newArr[1]));
}