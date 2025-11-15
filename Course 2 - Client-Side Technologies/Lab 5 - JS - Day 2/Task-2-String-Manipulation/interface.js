let sentence = validation("Enter a sentence: ");
console.log(`${sentence} length = ${getLength(sentence)}`);
console.log(`${sentence} To Upper Case: ${toUp(sentence)}`);
console.log(`${sentence} To Lower Case: ${toLow()}`);

console.log(firstMidLast());

let fname = new String(validation("What's your First name?", 1));
let lname = new String(validation("What's your Last name?", 1));
console.log(`Hello, ${concateName(fname, lname)}`);

sentence = new String(validation("Enter a new statement"));
console.log(`${sentence} Down 5 chars: ${trimLast5(sentence)}`);

sentence = new String(validation("Drop a Full Sentence to search:"));
searchWord = new String(validation("Word you want to find?", 1));
console.log(`
    Does ${sentence} includes ${searchWord}? -> ${
        doesItInclude(sentence, searchWord)?"yes, at index;"+getIndxOf(sentence, searchWord):"no"        
    }`
);

let replacement = "";
if(doesItInclude(sentence, searchWord)){
    replacement = new String(validation(`Replace ${searchWord} with:`, 1));
    console.log(`your new sentence: ${replaceWord(sentence, searchWord, replacement)}.`);
}else{
    searchWord = new String(validation("Enter a word to replace:", 1));
    replacement = new String(validation(`Replace ${searchWord} with: `, 1));
    console.log(`your new sentence: ${replaceWord(sentence , searchWord, replacement)}.`);
}

let  char = new String(validation("Enter a single character to search its frequancy:", 0));
console.log(`The letter \"${char}\" Came in ${sentence} is ${getOccurance(sentence, char) }`);

char  = new String(validation("Enter a letter you think the sentence starts with", 0));
console.log(`Does ${sentence} starts with the letter T? -> ${returnStart(sentence, char)? "yes":"no"}`);

char  = new String(validation("Enter a letter you think the sentence ends with", 0));
console.log(`Does ${sentence} ends with the letter V? -> ${returnEnd(sentence, char)? "yes":"no"}`);

console.log(`No Spaces: ${replaceWord(sentence, " ", "")}`);

let email = new String(validation("Enter a valid email: ", -1, "email"));
console.log(`Email: ${email} - Domail: ${returnDomain(email)}`);

let full_name = new String(validation("Enter your full name, first and last:", 2));
console.log(`${full_name} intials: ${makeInitials(full_name)}`);

sentence = new String(validation("Enter a sentence to reverse:"));
console.log(`${sentence}\nreversed: ${getReverse(sentence)}`);

sentence = new String(validation("Enter a wrod to check if it is pakindrome:"));
console.log(`the word: \"${sentence}\" is ${isPalindrome(sentence)?"a":"not"} palindrome`);

sentence = new String(validation("Enter a sentence with a lot of voules to count:"));
console.log(`\"${sentence}\" has ${countVoules(sentence)} voules`);

let greeting = new String(validation("Every word's 1st would be cap"));
console.log(getTitle(greeting));

let phone = new String(validation("Enter a phone number", -1, "phone"));
console.log(`Phone Masked: ${getMasked(phone)}`);

sentence = new String(validation("Enter a long sentence"));
console.log(`${longestWord(sentence)} is the longest word in  your lastinput with character count = ${getLength(longestWord(sentence))}`);

sentence = new String(validation("Enter a sentence with repeated characters:"));
console.log(removeRepeats(sentence));