const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

let check = +input[2];
let cnt = 0;

let newArr = input[1].split(" ").map(item => Number(item));
for (let i = 0; i < newArr.length; i++) {
    if (check == newArr[i]) {
        cnt++;
    }
}
console.log(cnt);