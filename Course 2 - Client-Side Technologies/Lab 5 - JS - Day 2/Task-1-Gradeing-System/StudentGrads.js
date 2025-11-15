(function(){
    let grade1 = validator(1);
    let grade2 = validator(2);
    let grade3 = validator(3);

    console.log(`Student Grades are: ${grade1}, ${grade2}, ${grade3}`);
})();

function validator(id){
    let flag = true;
    let grade = prompt(`Enter Student Grade${id}:`);

    while(flag){
        if(isNaN(grade)){
            grade = prompt(`Invalid Input. Please enter a numeric value for grade${id}:`);
        }else{
            flag = false;
        }
    }
    return grade;
}