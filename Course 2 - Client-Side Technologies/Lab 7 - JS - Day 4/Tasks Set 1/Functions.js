// 1
const createStudent = function(firstName, lastName, age, email, department){
    return {
        fullName:{
            firstName,
            lastName
        },
        age, 
        email, 
        department,
        toString(){
            return JSON.stringify(this);
        }
    }
}

//3
function getOldestStudent(students) {
    let oldest = students[0];

    for (let i = 1; i < students.length; i++) {
        if (students[i].age > oldest.age) {
            oldest = students[i];
        }
    }

    let oldestName = oldest.fullName.firstName + " " + oldest.fullName.lastName;

    return oldestName;
}

//4
function getPascalCase(students){
    let PascalNames = [];

    for(let i = 0; i < students.length; i++){
        let fullNameObj = students[i].fullName;

        let firstName = fullNameObj.firstName[0].toUpperCase() + fullNameObj.firstName.slice(1);
        let lastName  = fullNameObj.lastName[0].toUpperCase() + fullNameObj.lastName.slice(1);

        PascalNames.push(firstName + lastName);
    }

    return PascalNames;
}

//6
function getAverageAge(students){
    let ages = [];
    for(let i = 0; i < students.length; i++){
        ages.push(students[i].age);
    }
    let ageSum = 0;
    for(let i = 0; i < ages.length; i++){
        ageSum += ages[i];
    }

    return ageSum/ages.length;
}

//7
function sortByName(students){
    students.sort((a,b) => {
        if(a.fullName.firstName > b.fullName.firstName){
            return 1;
        }else if(a.fullName.firstName < b.fullName.firstName){
            return -1;
        }else if(a.fullName.firstName === b.fullName.firstName){
            if(a.fullName.lastName > b.fullName.lastName){
                return 1;
            }else if(a.fullName.lastName < b.fullName.lastName){
                return -1;
            }else{
                return 0;
            }
        }
    }
    );
    return students;
}

//8
function simplify(students){
    let newStudents = [];
    for(let i = 0; i < students.length; i++){
        let member = {
            fullName: students[i].fullName,
            age: students[i].age
        }
        newStudents.push(member);
    }
    return newStudents;
}