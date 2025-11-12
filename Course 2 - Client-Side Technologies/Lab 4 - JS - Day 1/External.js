console.log('Hi');

console.log("value of num1 in external file before declaration: ",num1); 
//let -> Uncaght ReferenceError: can not access num1 before initialization
/* 
variables declared using let and const are hoisted 
but in temporal dead zone till the line of initialization
*/
//var-> variables hiosted but taakes the value undefined till the line of initialization

console.log("value of num2 in external file before declaration: ",num2); 
console.log("value of num3 in external file before declaration: ",num3); 


//let num1 = 3;
var num1 = 3;
//num1 = 3;// RefrenceError: num1 is not defined in  all 3 scripts - not hiosted- implicit declaration

//let num2 = 2.9;
var num2 = 2.9;
//num2 = 2.9; //interpreter would not reach here

//let num3 = 0xff;
var num3 = 0xff;
//num3 = 0xff; //interpreter would not reach here

var firstName = "Ibrahim"; 
var middleName = 'Mohamed';
var lastName = `Eita`;

flag = true;

console.log("This is the External JavaScript file");


/* 
num1 = 6
6
num2 = 9.5
9.5
num3 = 0xff
255
num3 = 0xfc
252
*/

firstName[3] = "A";
console.log("firstName after modification: ",firstName); //no change as strings are immutable in JS

console.log("typeof firstName: ",typeof firstName); //string
console.log("typeof middleName: ",typeof middleName); //string
console.log("typeof lastName: ",typeof lastName); //string
console.log("typeof num1: ",typeof num1); //number
console.log("typeof num1: ",typeof num2); //number
console.log("typeof num1: ",typeof num3); //number
console.log("typeof flag: ",typeof flag); //boolean


function evenOrOdd(num){
    if(num % 2 == 0){
        return "Even";
    }else{
        return "Odd";
    }
}

console.log(`${num1} is ${evenOrOdd(num1)}`);//odd
console.log(`${num2} is ${evenOrOdd(num2)}`);//odd
console.log(`${num3} is ${evenOrOdd(num3)}`);//odd
console.log(`4 is ${evenOrOdd(4)}`);//even

for(var i=1; i<=10; i++){
    console.log(i);
}

function posNegZero(num){
    if(num > 0){
        return "Positive";
    }else if(num < 0){
        return "Negative";
    }else{
        return "Zero";
    }
}

console.log(`${num1} is ${posNegZero(num1)}`);//positive
console.log(`${-num2} is ${posNegZero(-num2)}`);//negative
console.log(`0 is ${posNegZero(0)}`);//0

function multiplicationTable(num){
    for(var i=1; i<=10; i++){
        console.log(`${num} * ${i} = ${num * i}`);
    }
}
multiplicationTable(num1);

function DayWeek(num){
    switch(num){
        case 1:
            return "Saturday";
        case 2:
            return "Sunday";
        case 3:
            return "Monday";
        case 4:
            return "Tuesday";
        case 5:
            return "Wednesday";
        case 6:
            return "Thursday";
        case 7:
            return "Friday";
        default:
            return "Invalid day number";
    }
}
console.log(`Day 1 is ${DayWeek(1)}`);

function isWeekend(num){
    if(num == 1 || num == 7){
        return "weekend";
    }else{
        return "weekday";
    }
}
console.log(`${DayWeek(1)} is a ${isWeekend(1)}`);
console.log(`${DayWeek(4)} is a ${isWeekend(4)}`);

