//1
let names = ["Sara", "Ali", "Mona"];
let ages = [20, 22, 19];
console.log(peopleObjectify(names, ages));

//2
let characters = ["a", "b", "a", "c", "b", "a"];
console.log(calculateFrequency(characters));

//3
let grades = [95, 82, 60, 45, 77, 88];
console.log(objectifyGPA(grades));

//4
let persons = [
    {name:"ahmed", grade:90}, 
    {name:"mona", grade:80}, 
    {name:"ali", grade:70}, 
    {name:"sara", grade:95}
];
persons.forEach(person =>{
    person.name = person.name[0].toUpperCase()+person.name.slice(1);
});
console.log(persons);

//5
persons.sort((a,b)=>a.grade-b.grade);
console.log(persons);

//6
let highestGrade = persons[0];

for (let i = 1; i < persons.length; i++) {
    if (persons[i].grade > highestGrade.grade) {
        highestGrade.grade = persons[i].grade;
    }
}
console.log(highestGrade);

//7
persons.filter(person => person.grade >= 60)

//8
console.log(arrayfy(persons));

//9
let higherThan4 = persons.filter(person => person.name.length >= 4)
console.log(`Number of people with a name biger than or equal to  4 letters = ${higherThan4.length}`);