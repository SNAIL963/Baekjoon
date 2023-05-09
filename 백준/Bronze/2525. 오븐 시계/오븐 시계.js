const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let input = [];

rl.on("line", (line) => {
    input.push(line.split(" ")); // 문자열
});

rl.on("close", () => {
    solution(parseInt(input[0][0]), parseInt(input[0][1]), parseInt(input[1][0]));
    process.exit();
});

function solution(hour, minute, ov) {
    var temp = minute + ov;
    if (temp >= 60) {
        while (temp >= 60) {
            temp = temp - 60;
            hour = hour + 1;
            if (hour >= 24) hour = hour - 24;
        }
        console.log(hour + " " + temp);
    }
    else {
        console.log(hour + " " + temp);
    }
}