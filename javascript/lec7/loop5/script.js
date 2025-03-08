// 5->  Write a program that reverses a given string.

let string=prompt("enter string:")
console.log(string);
let temp ; length ; newstring=""
for(let i=string.length-1 ; i>=0 ; i--)
{
    newstring+= string[i];
}
console.log(newstring);
