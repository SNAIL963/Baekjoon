const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split(" ");

var a = parseInt(input[0]);
var b = parseInt(input[1]);
var c = parseInt(input[2]);

if (a == b && b == c) {
    console.log(10000 + 1000 * a);
}
else if (a == b || b == c) {
    console.log(1000 + 100 * b);
}
else if (a == c) {
    console.log(1000 + 100 * a);
}
else {
    if (a > b && a > c) {
        console.log(100 * a);
    }
    else if (b > a && b > c) {
        console.log(100 * b);
    }
    else {
        console.log(100 * c);
    }
}
