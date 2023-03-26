const fs = require('fs');
// 파일을 읽어오기 위한 filesystem 모듈 사용
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
// 윈도우에서는 터미널에서 입력을 받을 수 없어서 input txt 파일을 읽어오는 식으로 입력을 받음
let input = fs.readFileSync(filePath).toString().split(" ");
// 입력이 띄어쓰기를 구분자로 input에 배열의 형태로 저장된다.

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