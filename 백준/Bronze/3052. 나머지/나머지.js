const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

let arr = [];
let cnt = 0;

for (let i = 0; i < 10; i++) {
    let a = input[i] % 42;
    if(typeof(arr[a]) === 'undefined'){
        arr[a] = 1;
        cnt++;
    }
}
console.log(cnt);