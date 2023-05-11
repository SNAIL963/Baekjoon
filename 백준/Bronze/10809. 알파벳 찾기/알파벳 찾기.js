const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

// a : 97, z: 122
let arr = [];
let ans = "";

for (let i = 97; i < 123; i++) {
    arr[i] = -1;
}

for (let i = 0; i < input[0].length; i++) {
    if (arr[input[0].charCodeAt(i)] == -1) {
        arr[input[0].charCodeAt(i)] = i;
    }
}
for (let i = 97; i < 123; i++) {
    ans = ans + arr[i] + " ";
}
console.log(ans);
