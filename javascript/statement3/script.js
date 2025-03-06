// 3-> determine the largest of three numbers

let num1=parseInt(prompt("enter num1"))
let num2=parseInt(prompt("enter num2"))
let num3=parseInt(prompt("enter num3"))
let largest
if(num1>= num2 && num1>= num3)
{
    largest=num1  
    console.log();
    
}
else if(num2>= num1 && num2>= num3)
    {
        largest=num2 
    }
    
else{
    largest=num3
}
console.log("largest number is:",+largest);
