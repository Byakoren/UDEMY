let choice ;
let number1;
let number2;
let result;

do {
    choice = prompt("Que souhaitez vous faire ? \n\n 1. Addition \n\n 2. Multiplication \n\n 3. Soustraction \n\n 4. Division");
    choice = parseInt(choice);
}while (choice !== 1 && choice !== 2 && choice !== 3 && choice !== 4);

do {
    number1 = prompt("Quel est ton premier nombre ?");
    number2 = prompt("Quel est ton second nombre ?");
} while (
    number1 === null || number1 === "" || isNaN(Number(number1)) || number2 === null || number2 === "" || isNaN(Number(number2))
);

number1 = parseFloat(number1);
number2 = parseFloat(number2);


function addition(a,b) {
    result = a + b;
    return alert( a + " + " + b + " = " + result);
}

function multiplication(a,b) {
    result = a * b;
    return alert( a + " x " + b + " = " + result);
}

function soustraction(a,b) {
    result = a - b;
    return alert( a + " - " + b + " = " + result);
}

function division(a,b) {
    result = a / b;
    alert( a + " / " + b + " = " + result);
}


if (choice == 1) {
    addition(number1, number2)
}
else if (choice == 2) {
    multiplication(number1, number2)
}
else if (choice == 3) {
    soustraction(number1, number2)
}
else {
    division(number1, number2)
}