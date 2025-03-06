// 4-> Check if a year is a leap year

let year=parseInt(prompt("enter year"))
let leapYear
if(year % 100 === 0)
{
    console.log("This is leap year");
}
else if(year % 400 === 0)
    {
        console.log("This is leap year");
        
    }
else if(year % 4 === 0)
    {
            console.log("This is leap year");
            
    }
else{
    console.log("This is not leap year");  
}