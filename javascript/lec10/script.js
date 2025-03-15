// string.replace method

{
    let string1 ="This is php String,this is javascript string"
console.log(string1);
console.log(string1.replace("php" , "javascript"));
}
console.log("***");

{
     let string1 ="This is php String,this is javascript string"
    const regex = /this/g;
    const regex1 = /is/g;
console.log(string1.replace(regex , "That"));
console.log(string1.replaceAll(regex1 , "IS"));
}
console.log("***");

{
    let string1 ="This is php String,this is javascript string"
    const regex = /this/i;
    const regex1 = /is/i;
console.log(string1.replace(regex , "That"));
// console.log(string1.replaceAll(regex1 , "IS"));
}
console.log("***");


{
    let string1 ="This is php String,this is javascript string"
    const regex = /this/gi;
    const regex1 = /is/gi;
console.log(string1.replace(regex , "That"));
console.log(string1.replaceAll(regex1 , "IS"));

}

// javascript string secrch method

// string.search()

{
    let str="Your Dog is beautyfull but My Dog is more beautyfull than yours"

    let split=str.split(' ')
    console.log(split);

    let reverse=split.reverse()
    console.log(reverse);
    
    let join=reverse.join()
    console.log(join);
    console.log(str.split('').reverse().join(''));
    
          let Regex = /beautyfull/g

    console.log(str.search(Regex));
}

// javascript string.match()

{
    let str="Your Dog is beautyfull but My Dog is more beautyfull than yours"
 let regex=/Dog/gi

 console.log(str.match(regex));
 console.log(...str.matchAll(regex));
 
}