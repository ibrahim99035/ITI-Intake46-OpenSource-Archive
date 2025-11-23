//1
function peopleObjectify(names, ages){
    let higherLength = ages.length;
    if(names.length > ages.length){
        higherLength = names.length;
    }
    let people = [];
    for(let i = 0; i<higherLength; i++){
        people.push({name:names[i], age:ages[i]});
    }
    return people;
}

//2
function calculateFrequency(characters){
    let charactersUnique = new Set(characters);
    let freqObj = {};
    for(let i = 0; i < charactersUnique.length; i++){
        freqObj.push({i:0});
    }
    for(let i = 0; i < characters.length; i++){
        if(freqObj.characters[i]){
            freqObj.characters[i]++;
        }
    }

    return freqObj;
}

//3
function objectifyGPA(grades){
    let gpaObj = {A:[], B:[], C:[], D:[], F:[]};
    for(let i = 0; i < grades.length; i++){
        if(grades[i] >= 90){
            gpaObj.A.push(i);
        }else if(grades[i] >= 80){
            gpaObj.B.push(i)
        }else if(grades[i] >=  70){
            gpaObj.C.push(i);
        }else if(grades[i] >= 60){
            gpaObj.D.push(i);
        }else{
            gpaObj.F.push(i);
        }
    }
    return gpaObj;
}

//8
function arrayfy(persons){
    let personsArr = [];
    for(let i = 0; i < persons.length; i++){
        personsArr.push([persons[i].name+" "+persons[i].grade]);
    }
    return personsArr;
}