const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split(" ");

var a = parseInt(input[0]);
var b = parseInt(input[1]);

if (b < 45) {
    a = a - 1;
    b = b + 15;
    if (a === -1) {
        a = 23;
    }
}
else {
    b = b - 45;
}

console.log(a + " " + b);