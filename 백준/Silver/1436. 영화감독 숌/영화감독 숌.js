const fs = require('fs');
// 파일을 읽어오기 위한 filesystem 모듈 사용
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
// 윈도우에서는 터미널에서 입력을 받을 수 없어서 input txt 파일을 읽어오는 식으로 입력을 받음
let input = fs.readFileSync(filePath).toString().trim();

var a = parseInt(input);
var count = 0;

// i를 매우 큰 값까지 String으로 변환
// 변환한 String값에 666이 들어있으면 count값을 증가시켜 N번째로 작은 종말의 수를 찾는다.
for(var i=666;i<10000000;i++){
    var x = i.toString();
    if(x.includes("666")){
        count++;
    }
    if (count === a){
        console.log(i);
        break;
    }
}