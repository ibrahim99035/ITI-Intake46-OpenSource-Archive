//1.2
function removeDuplicates(arr){
    let result = [];
    for(let i = 0; i < arr.length; i++) {
        if(!result.includes(arr[i])) {
            result.push(arr[i]);
        }
    }
    return result;
}

//2
let reverseWord = (arr) => {
    return arr.map(word => word.split("").reverse().join(""));
};

//3
let doubleEven = (arr) => {
    return arr.filter(num => num % 2 == 0).map(num => num * 2);
};

//4
let findSecondLargest = (arr) => {
    let largest = 0;
    let secondLargest = 0;
    
    for(let i = 0; i < arr.length; i++) {
        if(arr[i] > largest) {
            secondLargest = largest;

            largest = arr[i];
        } else if(arr[i] > secondLargest && arr[i] !== largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
};

//5
let splitByIndex = (arr) => {
    let evenIndex = [];
    let oddIndex = [];
    
    arr.forEach((item, index) => {
        if(index % 2 === 0) {
            evenIndex.push(item);
        } else {
            oddIndex.push(item);
        }
    });
    
    return [evenIndex, oddIndex ];
};

//6
let countHigherThan50 = (arr) =>{
    return arr.filter(num => num > 50).length;
}

//7
let findLongestWord = (arr) => {
    return arr.reduce((longest, current) => 
        current.length > longest.length ? current : longest
    );
};

//8
let generateRandomArray = (length, min, max) => {
    let result = [];
    for(let i = 0; i < length; i++) {
        result.push(Math.floor(Math.random() * (max - min + 1)) + min);
    }
    return result;
};

//9
let roundArray = (arr) => {
    return arr.map((number)=>Math.round(number));
}

//10
let daysSinceDates = (dates) => {
    let today = new Date();
    return dates.map(dateStr => {
        let date = new Date(dateStr);
        let diffTime = today - date;
        let diffDays = Math.floor(diffTime / (1000 * 60 * 60 * 24));
        return diffDays;
    });
};

//11
let sortDates = (dates) => {
    return dates.sort((a, b) => new Date(a) - new Date(b));
};