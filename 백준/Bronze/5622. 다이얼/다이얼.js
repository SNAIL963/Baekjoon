const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

let tel = {
    2: "ABC",
    3: "DEF",
    4: "GHI",
    5: "JKL",
    6: "MNO",
    7: "PQRS",
    8: "TUV",
    9: "WXYZ"
}

let arr = input[0].split("");
let answer = 0;
for (let a = 0; a < arr.length; a++) {
    for (let b = 2; b <= 9; b++) {
        if (tel[b].includes(arr[a])) {
            answer += b + 1;
        }
    }
}
console.log(answer);