const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

let arr = [];
let [N, M] = input[0].split(" ").map(item => Number(item));

for (let i = 1; i <= N; i++) {
    arr[i] = i;
}

for (let i = 1; i <= M; i++) {
    let [a, b] = input[i].split(" ").map(item => Number(item));
    let num = b - a;
    let newArr = [];
    for (let j = 0; j <= num; j++) {
        newArr[j] = arr[b - j];
    } 
    let temp = 0;
    for (let k = a; k <= b; k++) {
        arr[k] = newArr[temp];
        temp++;
    }
}

let answer = "";
for(let i=1; i<=N;i++){
    answer = answer + arr[i] + " ";
}

console.log(answer);