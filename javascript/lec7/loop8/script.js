// 8-> Write a program that counts the number of vowels in a given string.

let vowels=["a" , "A" , "e" , "E" , "i" , "I" , "o" , "O" , "u" , "U"]
let count = 0;
let str=prompt("enter string:")
console.log(str);

{
    for(let i of str)
    {
        if(vowels)
        {
            count++;
        }
    }
}
console.log(count);
