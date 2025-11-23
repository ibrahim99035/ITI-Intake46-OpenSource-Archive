function createBook(title, author, year, price){
    if(!validateNumeric(year)){return "Not a valid year";}
    if(!validateNumeric(price)){return "Not a valid price";}
    if(!validateYear(year)){return "Post year can't be in the future";}

    return {
        title, 
        author,
        year,
        price,
        isClassic(){
            return new Date().getFullYear() - year > 20 ? true : false;
        },
        ApplyDicount(percent){
            return price -= price*percent;
        }
    }
}

function validateNumeric(value){
    let pattern = /^[+-]?\d+(\.\d+)?$/;
    return !pattern.test(value);
}

function validateYear(year){
    if(year >= 2026){return false;}
    return true;
}

let books = [];
books.push(createBook("The Alchemist", "Paulo Coelho", 1988, 12.99));
books.push(createBook("1984", "George Orwell", 1949, 9.99));
books.push(createBook("To Kill a Mockingbird", "Harper Lee", 1960, 14.50));
books.push(createBook("The Great Gatsby", "F. Scott Fitzgerald", 1925, 10.75));
books.push(createBook("The Prophet", "Kahlil Gibran", 1923, 8.99));

for(let i = 0; i < books.length; i++){
    console.log(books[i].title, books[i].isClassic()?' is a classic': ' is not a classic');
}

books = books.map(book => {
    if(new Date().getFullYear - book.year > 10){
        book.ApplyDicount(0.9);
    }
    return book;
});