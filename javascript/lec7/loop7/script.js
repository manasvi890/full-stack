// 7-> Write a program that finds the largest number in an array.

let arr=[10,50,30,100]
let max=arr[0];
{
    for(let i=1 ; i< arr.length ; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i]
        }
    }
    console.log(max);
    
}