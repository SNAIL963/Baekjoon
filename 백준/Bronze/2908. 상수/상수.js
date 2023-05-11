const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

let [a, b] = input[0].split(" ");
let newA = "";
let newB = "";

for (let i = 2; i >= 0; i--) {
    newA = newA + a[i];
    newB = newB + b[i];
}

if(parseInt(newA) > parseInt(newB)){
    console.log(newA);
}
else{
    console.log(newB);
}