function validation(message, special){
    let sentence = prompt(message);
    if(sentence == null || sentence === ""){
        sentence = validation(`This Action is not Allowed, Try Again ${message}`, special);
    }

    if(special === "email"){
        let flag = regextValidation(sentence);
        if(!flag){
            sentence = validation(`That is not a valid email, Try Again ${message}`, special);
        }
    }else if(special === "age"){
        let flag = isValidDigit(sentence);
        if(!flag){
            sentence = validation(`That is not a valid age, Try Again ${message}`, special);
        }
        return Number(sentence);
    }
    return sentence;
}

function isValidDigit(){
    let pattern = /^[+-]?\d+(\.\d+)?$/;
    return !pattern.test(str);
}

function validateEmail(email){
    let regex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
    return regex.test(email);
}