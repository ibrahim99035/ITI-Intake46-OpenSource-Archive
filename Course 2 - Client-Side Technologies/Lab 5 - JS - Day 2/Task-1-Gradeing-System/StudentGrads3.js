(function(){
    let rounds = validator("n");
    rangeValidator(rounds,2,10,"n");

    let summition = 0;

    for(let i = 1; i<=rounds; i++){
        let grade = validator("g", i);
        rangeValidator(grade,0,100,"g");

        summition += parseFloat(grade);
    }
    console.log(`Summition = ${summition}`);
})();


function validator(char, id){
    let message;
    let warn;
    if(char === "n"){
        message = "How Many Grades You want to Enter: ";
        warn = "Invalid Input. Please enter a numeric value:";
    }else{
        message = `Enter Student Grade${id}:`;
        warn = `Invalid Input. Please enter a numeric value for grade${id}:`;
    }

    let flag = true;
    let n = prompt(message);

    while(flag){
        if(isNaN(n)){
            n = prompt(warn);
        }else if(n === null|| n===""){
            n = prompt("not suitable to canclel or empty. " + message);
        }else{
            flag = false;
        }
    }
    return n;
}

function rangeValidator(num,min,max,flag,id){
    let message;
    if(flag==="n"){
        message = "Roundes";
    }else{
        message = `Grade${id}`;
    }

    if(num>max || num<min){
        alert(`${message} value must be between ${min} and ${max}`);
    }
}