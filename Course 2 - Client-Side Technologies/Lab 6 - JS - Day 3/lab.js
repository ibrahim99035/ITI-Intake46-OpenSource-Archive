//1.1
let arrDuplicates = [1, 2, 2, 3, 4, 4, 5];
console.log("Original Array:", arrDuplicates);

let withSet = new Set(arrDuplicates);
console.log("Sorted With Set: ", [...withSet]);

//1.2
console.log("Sorted Without Set: ", removeDuplicates(arrDuplicates));

//2
let fruits = ["apple", "banana", "mango"];
console.log(fruits);

let stiurf = reverseWord(fruits);
console.log(stiurf);

//3
let sequnced = [1,2,3,4,5,6]
console.log("Array Sequence: ", sequnced);

let evensDoupled = doubleEven(sequnced);
console.log("Douple Even: ", evensDoupled);

//4
console.log("Finding the second largest");
let tens = [10, 30, 50, 20, 40];
console.log(tens);
console.log(`Second Largest: ${findSecondLargest(tens)}`);

//5
console.log("Enven  & Odd Indicies:");

let chars = ["a", "b", "c", "d", "e"];
console.log("Entile Array: ",chars);

let evenOddOperation = splitByIndex(chars);

let evenIndicies = evenOddOperation[0];
console.log("Even: ",evenIndicies);

let oddIndicies = evenOddOperation[1]; 
console.log("Odd: ", oddIndicies);

//6
let with50 = [20, 60, 51, 75, 33, 99] ;
console.log("Entire Array: ", with50);
console.log(`Number of elements bigger than 50 = ${countHigherThan50(with50)}`);

//7
let words = ["hi", "international", "cat", "sun"];
console.log("words: ", words);
console.log("Longest Word: ", findLongestWord(words));

//8
console.log("Random Array: ", generateRandomArray(5, 10, 50));

//9
let floats = [1.2, 3.7, 4.5];
console.log("Array of Floats: ", floats);
console.log("Floats Rounded: ", roundArray(floats));

//10
let dates = ["2024-01-01", "2024-03-01", "2024-04-15"];
console.log("Dates: ", dates);
console.log("Days since: ", daysSinceDates(dates));

//11
let unSortedDates = ["2024-05-01", "2024-01-01", "2024-03-15"];
console.log(unSortedDates);
console.log(sortDates(unSortedDates));