// 1->Javascript program to print hello world

{console.log("Hello World!!!");}

// 2->Javascript program to Add two numbers

{let num1 = (45)
let num2 = (50)
console.log("Addition :",num1 + num2);}

// 3->JavaScript Program to Find the Square Root

{let a = Math.sqrt(25)
console.log("Square root:",a);}

// 4->JavaScript Program to Calculate the Area of a Triangle

{let base = (10)
let height = (5)
console.log("Area of triangle:", base*height/2);}

// 5->JavaScript Program to Swap Two Variables

{
    console.log('swap variables:');
    
let a = 40;
let b = 30;

console.log(`      before swap a=${a} b=${b}`);
[b,a]=[a,b]
console.log(`      After swap a=${a} b=${b}`);

}

// 6->JavaScript Program to Solve Quadratic Equation
console.log("Quadratic Equation:");


// 7->JavaScript Program to Convert Kilometres to Miles

let km = (2)
console.log("km to miles:",0.62137*km);

// 8->Javascript Program to Convert Celsius to Fahrenheit

let c = (45)
console.log("Fahrenheit:",(c*9/5)+32);

// 9->Javascript Program to Generate a Random Number

// 10->Javascript Program to Check if a number is Positive, Negative, or Zero

{let num=(-967)
{
    if(num>0)
    {
        console.log(`${num} is a positive number`); 
    }
    else if(num<0)
    {
        console.log(`${num} is a negative number`); 
    }
    else{
        console.log("zero");   
    }
}}

// 11->Javascript Program to Check if a Number is Odd or Even

{let num=(49)
if(num%2==0){
    console.log(`${num} : even number`);
}
else if(num%2!=0){
    console.log(`${num} : odd number`);
}}

// 12->JavaScript Program to Find the Largest Among Three Numbers

{
    let num1=(45)
    let num2=(95)
    let num3=(25)
    let largest
    if(num1>=num2 && num1>=num3)
    {
        largest=num1 
    }
    else if(num2>=num1 && num2>=num3)
    {
        largest=num2
    }
    else{
        largest=num3
    }
    console.log("largest number is:",largest);
    
}

// 13->JavaScript Program to Check Prime Number

{
let n = 60;
let isPrime = true;

if (n <= 1) {
    isPrime = false;
} else {
    for (let i = 2; i < n; i++) {
        if (n % i === 0) {
            isPrime = false;
            break;
        }
    }
}

console.log(isPrime ? `${n} is a prime number.` : `${n} is not a prime number.`);
}

// 14->JavaScript Program to Print All Prime Numbers in an Interval

{let start=2
let end=100
let prime
for(let i=start ; i<=end ; i++)
{
    if(i==1 || i==0)
        continue;

prime=1
    {
        for(let j=2 ; j<=i/2 ; j++)
        {
if(i%j==0)
{
    prime=0
    break;
}
        }
        if(prime==1)
            {
                console.log(i);
                
            }
    }

}
}

// 15->JavaScript Program to Find the Factorial of a Number

{
let number=5
let fact = 1;
for (i = 1; i <= number; i++) {
    fact *= i;
}
console.log(`The factorial of ${number} is ${fact}.`);}

// 16->JavaScript Program to Display the Multiplication Table

{
    console.log("multiplication table");
    
        for(i=0 ; i<=10 ; i++)
        {
           console.log(`     5 * ${i} = ${i * 5}`);
        }
  

}

// 17->JavaScript Program to Print the Fibonacci Sequence

let n=(10)
let a=0 ; b=1 
let next
console.log("fibbonacci sequence");

for(i=0 ; i<=n ;i++)
{
    console.log("     ",a);
    next = a+b;
    a=b;
    b=next;
    
}

// 18->JavaScript Program to Check Armstrong Number

{let e, x, d = 0;
let b =(153);
x=b;

while (x > 0) {
  e = x % 10;
  x = parseInt(x/10);
  d = d + (e*e*e);
}

if (b==d)
   console.log("given number is an armstrong number");
else
   console.log ("given number is not an armstrong number");;
  }

//19->JavaScript Program to Find Armstrong Number in an Interval

//20->JavaScript Program to Make a Simple Calculator

// let number1=prompt("enter number1")
// let sign=parseInt(prompt("enter sign"))
// let number2=parseInt(prompt("enter number2"))
// let result
// if(sign == '+' )
// {
//     result= number1 + number2
// }
// else if(sign =='-' )
//     {
//         result= number1 - number2
//     }
//    else if(sign == '*' )
//         {
//             result= number1 * number2
//         }
//         else
//             {
//                 result= number1 / number2
//             }

//             console.log(`${number1} ${sign} ${number2} = ${result}`);
            
// 21->JavaScript Program to Find the Sum of Natural Numbers

{
    let sum=0
    let number=(5)
    for(let i=0 ; i<=number ; i++)
    {
        sum+=i;
    }
    console.log(sum);
    
}

// 22->JavaScript Program to Check if the Numbers Have Same Last Digit

{
    let num1=(678)
    let num2=(788)
    let num3=(768)

    let result1= num1 % 10;
    let result2= num2 % 10;
    let result3= num3 % 10;

    if(result1 == result2 && result2 == result3)
    {
        console.log("last digit is same");
    }
    else{
        console.log("last digit is not same");    
    }
}

// 23->JavaScript Program to Find HCF or GCD

{
    let hcf
    let number1=(10)
    let number2=(5)
    for(let i=1 ; i<=number1 && i<=number2 ; i++)
    {
        if(number1 % i==0 && number2 % i==0)
        {
            hcf=i;
        }
    }
    console.log(hcf);
    
}

// 24->JavaScript Program to Find LCM

// LCM = (num1*num2) / HCF
{
    let num1=(567)
    let num2=(569)
for(let i=0 ; i<=num1 && i<=num2 ; i++)
{
    if(num1 % i == 0 && num2 % i == 0)
    {
        hcf=i;
    }
}
let lcm=(num1 * num2)/hcf
console.log(lcm);
}

// 25->JavaScript Program to Find the Factors of a Number

{
    let num=(12)
    for(let i=0 ; i <=num ; i++)
    {
        if(num % i == 0)
        {
            console.log(i);
            
        }
    }
}

// 26->JavaScript Program to Find Sum of Natural Numbers Using Recursion

{
    let num
    let n=10
    for(let i=0 ; i<=n ; i++)
    {
       let 
    }
}

