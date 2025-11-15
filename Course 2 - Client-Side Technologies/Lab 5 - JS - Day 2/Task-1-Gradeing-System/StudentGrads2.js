(function(){
    let grade1;
    let grade2;
    let grade3;

    for(let i=1; i<=3; i++){
        let grade;
        let flag = true;

        grade = prompt(`Enter Student Grade${i}:`);
        
        while(flag){
            if(isNaN(grade)){
                grade = prompt(`Invalid Input. Please enter a numeric value for grade${i}:`);
            }else{
                flag = false;
            }
        }
        
        if(i === 1){ 
            grade1 = grade;
        }else if(i === 2){ 
            grade2 = grade;
        }else if(i === 3){ 
            grade3 = grade;
        }
    }

    console.log(`Student Grades are: ${grade1}, ${grade2}, ${grade3}`);
    console.log(`Summition = ${parseFloat(grade1) + parseFloat(grade2) + parseFloat(grade3)}`);
})();
