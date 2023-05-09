const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input;
rl.on("line", (line) => {
    input = parseInt(line);
    rl.close();
}).on("close", function () {
    solution(input);
});

function solution(a) {
    let sum = 0;
    for (let i = 1; i <= a; i++) {
        sum = sum + i;
    }
    console.log(sum);
}