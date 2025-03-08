// 4-> 4. Write a program that prints the first 10 numbers in the Fibonacci sequence.

let n=parseInt(prompt("enter number n:"))
let a=0 ; b=1 
let next
for(i=0 ; i<=n ;i++)
{
    console.log(a);
    next = a+b;
    a=b;
    b=next;
    
}