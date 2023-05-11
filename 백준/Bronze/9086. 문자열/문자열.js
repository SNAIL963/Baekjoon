const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

let num = +input[0];

for(let i=1;i<=num;i++){
    console.log(input[i][0]+input[i][input[i].length-1]);
}