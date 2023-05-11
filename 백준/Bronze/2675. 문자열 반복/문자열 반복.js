const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

// a : 97, z: 122
let T = +input[0];

for (let i = 1; i <= T; i++) {
    let answer = "";
    let [a, b] = input[i].split(" ");
    a = parseInt(a);
    for (let j = 0; j < b.length; j++) {
        for (let k = 0; k < a; k++) {
            answer = answer + b[j];
        }
    }
    console.log(answer);
}