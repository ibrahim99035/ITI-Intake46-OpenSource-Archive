/*
        User Defined Objects (classes in javascript)
*/

// In ES5   (classes are functions called with new Keyword)

// constructor function
// function Animal(name="",type="omnivor",gender="male"){

//     if(this.constructor.name=="Window")
//     {
//         throw new Error("Animal is constructor function");
//     }
//     this.name=name;
//     this.type=type;
//     this.gender=gender;
//     // console.log("Hello Animal ...");
//     //memebr fuctions
   
// }

// // add all functions
// Animal.prototype.getData=function(){
//     console.log("Animal name ",this.name);
// }

// Animal.prototype.anyProperty="sharedProperty"

// // calling as function
// // Animal();  Error handeled bu developer
// //calling as Class (create Object from calss)
// let animal_1=new Animal("xxx","cat");
// console.log(typeof animal_1);
// console.log(animal_1.constructor.name);

// let animal_2=new Animal();

// function getStudentData(){
//     console.log("firstFunction");
// }

// function getStudentData(){
//     console.log("secondFunction");

// }



/*****************************
 * ES6 Classes
 */

class Person{
        //ES10  private Members
        // 1- define property #
        #id;
        static #count=0;
        constructor(id,name){
            this.name=name;
            this.#id=id;
           Person.#count++;
        }
        //concise method
        getPersonData(){
            console.log(this.id,this.name);
        }
        // getId()
        // {
        //     return this.#id;
        // }
        // setId(value)
        // {
        //  this.#id=value;
        // }
        //setter and getter
        get id(){ return this.#id;}
        // set id(value){ this.#id=value;}
        //override
        toString()
        {
            return `${this.#id} : ${this.name}`;
        }

        //getter for static function
       static get count(){return Person.#count;}

};

console.log(typeof Person);
let person_1=new Person(1,"yyy");
let person_2=new Person(2,"xxx");
person_1.name;
// person_1.#id Error

/************* inheritaince (Not classic inh but prototypal inh)  */
class Shape{// abstract
    constructor(color)
    {

        this.color=color;
    }
    draw(){
        console.log("Drawing shape......");
    }
}

class Reactangle extends Shape
{
    constructor(dim1,dim2,color)
    {
        super(color);
        this.dim1=dim1;
        this.dim2=dim2;
    }
}


class Square extends Reactangle{

    constructor(dim,color){
        super(dim,dim,color)
    }

}
// let rectanagle_1=new Reactangle("red");
let rectanagle_1=new Reactangle(2,3,"red");
let shape=new Shape("green"); //?



