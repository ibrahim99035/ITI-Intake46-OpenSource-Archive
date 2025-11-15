function getLength(sentence){
    return sentence.length;
}

function toUp(sentence){
    return sentence.toUpperCase();
}

function toLow(sentence){
    return sentence.toLowerCase();
}

function firstMidLast(sentence){
    let first = sentence[0];
    let middle = sentence[Math.floor((getLength(sentence)-1)/2)];
    let last = sentence[getLength(sentence)-1];
    return `First:[${first}] - Middle:[${middle}] - Last:[${last}]`;
}

function concateName(fname, lname){
    let fullName = "";
    fullName+=fname;
    fullName+=" ";
    fullName+=lname;
    return fullName;
}

function trimLast5(sentence){
    return sentence.substring(0, getLength(sentence)-5);
}

function getIndxOf(sentence, word){
    return sentence.indexOf(word);
}

function doesItInclude(sentence, word){
    return sentence.includes(word); 
}

function replaceWord(sentence, word, replacement){
    return sentence.replace(word, replacement);
}

function getOccurance(sentence, char){
    let counter = 0;
    for(let i = 0; i<getLength(sentence); i++){
        if(sentence[i] === char){
            counter++;
        }
    }
    return counter;
}

function returnStart(sentence, letter){
    return sentence.startsWith(letter);
}

function returnEnd(sentence, letter){
    return sentence.endsWith(letter);
}

function removeSpaces(sentence){
    return sentence.replaceAll(" ", "");
}

function returnDomain(email){
    let domain = "";
    if(regextValidation(email, "email")){
        let domainIndex = getIndxOf(email,"@")+1;
        domain = email.substring(domainIndex, getLength(email));
    }
    return domain;
}

function regextValidation(sentence, type){
    let regex;
    let flag;

    if(type === "email"){
        regex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
        flag = regex.test(sentence);
    }else if(type === "phone"){
        regex = /^[\+]?[(]?[0-9]{3}[)]?[-\s\.]?[0-9]{3}[-\s\.]?[0-9]{4,6}$/;
        flag = regex.test(sentence);
    }
    return flag;
}

function makeInitials(name){
    let initials = name[0];
    for(let i = 0; i<getLength(name);i++){
        if(name[i] === " "){
            initials+=name[i+1];
        }
    }
    return toUp(initials);
}

function getReverse(sentence){
    let reversed = "";
    for(let i = getLength(sentence)-1; i>=0;i--){
        reversed+=sentence[i];
    }
    return reversed;
}

function isPalindrome(sentence){
    let reversed = getReverse(sentence);
    if(sentence === reversed){
        return true;
    }else{
        return false;
    }
}

function countVoules(sentence){
    let counter = 0;

    for(let i = 0; i<getLength(sentence);i++){
        if(doesItInclude("aeiouAEIOU", sentence[i])){
            counter++;
        }   
    }
    return counter;
}

function getTitle(sentence) {
    let result = "";
    let flag = true;

    for (let i = 0; i < sentence.length; i++) {
        if (flag && sentence[i] !== " ") {
            result += toUp(sentence[i]);
            flag = false;
        } else {
            result += sentence[i];
        }

        if (sentence[i] === " ") {
            flag = true;
        }
    }
    return result;
}

function getMasked(sentence){
    let length = getLength(sentence);
    let visible = sentence.substring(length-4, length);
    let masked = "";
    for(let i = 0; i < getLength(sentence.substring(0, length-4));i++){
        masked+="*";
    }
    return masked+visible;
}

function longestWord(sentence){
    let tempWord = "";
    let word = "";
    for(let i = 0; i <= getLength(sentence); i++){
        if(sentence[i] === " " || i === getLength(sentence)){
            if(getLength(tempWord) > getLength(word)){
                word = tempWord;
            }

            tempWord = "";
        }else{
            tempWord +=sentence[i];
        }
    }
    return word;
}

function removeRepeats(sentence){
    let result = "";

    for (let i = 0; i < sentence.length; i++) {
        if (!doesItInclude(result, sentence[i])) {
            result += sentence[i];
        }
    }
    return result;
}


function countWords(sentence){
    let spaces = getOccurance(sentence, " ");
    return spaces + 1;
}

function validation(message, count, special){
    let sentence = prompt(message);
    if(sentence == null || sentence === ""){
        sentence = validation(`This Action is not Allowed, Try Again ${message}`, count, special);
    }
    if(count > 0){
        let flag = validateWordsNumber(sentence, count);
        if(!flag){
            sentence = validation(`only ${count} words allowed, Try Again ${message}`, count);
        }
    }else if(count === 0){
        let flag = validateChar(sentence);
        if(!flag){
            sentence = validation(`only single character allowed, Try Again ${message}`, count);
        }
    }
    if(special === "email" || special === "phone"){
        let flag = regextValidation(sentence, special);
        if(!flag){
            sentence = validation(`That is not a valid ${special}, Try Again ${message}`, -1, special);
        }
    }
    return sentence;
}

function validateWordsNumber(sentence, number){
    let count = countWords(sentence);
    if(count === number){
        return true;
    }else{
        return  false;
    }
}

function validateChar(sentence){
    if(getLength(sentence)===1){
        return true;
    }else{
        return false;
    }
}