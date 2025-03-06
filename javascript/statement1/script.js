// 1-> check if the number is positive , negative or zero

let number=prompt("enter number")
console.log(parseInt(number));

if(number == 0){
    console.log("number is zero");  
}
else if(number < 0){
    console.log("number is negative");   
}
else if(number > 0){
    console.log("number is positive");   
}
else{
    console.log("number is null");  
}