const fs = require('fs');
// 파일을 읽어오기 위한 filesystem 모듈 사용
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
// 윈도우에서는 터미널에서 입력을 받을 수 없어서 input txt 파일을 읽어오는 식으로 입력을 받음
let input = fs.readFileSync(filePath).toString().trim();


var a = parseInt(input);

if (a % 4 == 0) {
    if (a % 100 == 0 && a % 400 != 0) {
        console.log(0);
    }
    else {
        console.log(1);
    }
}
else{
    console.log(0);
}