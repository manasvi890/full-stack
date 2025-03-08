// 3-> Write a program that calculates the factorial of a given number (for example, 5!).

let n=parseInt(prompt("enter value of n:"))
let i=1, fact=1
while(i<=n)
{
  fact = fact*i 
  i++
}
console.log(fact)