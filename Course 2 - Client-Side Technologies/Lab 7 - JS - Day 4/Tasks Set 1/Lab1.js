//2
let students=[];
for(let i = 0; i < 5; i++){
    let firstName = validation(`Enter A First Name(${i+1}): `);
    let lastName = validation(`Enter A Last Name(${i+1}): `);
    let age = validation(`Enter An Age(${i+1}): `);
    let email = validation(`Enter An Email(${i+1}): `);
    let department = validation(`Enter A Department(${i+1}): `);

    students.push(createStudent(firstName, lastName, age, email, department));
}

console.log(students);

//3 
console.log(`Oldest Student: ${getOldestStudent(students)}.`);

//4
console.log(getPascalCase(students));

//5
console.log('Students Older than 20: ', students.filter(obj => obj.age > 20));

//6
console.log(`The Average Age is ${getAverageAge(students)}`);

//7
console.log(sortByName(students));

//8
console.log('Students Simplifiedl: ', simplify(students));

//9+10
console.log(students[0]+"");

//11
console.log(JSON.stringify(students));