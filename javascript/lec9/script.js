/* javascript String Methods */

/* String.At() */

// at(index)

// {
//     let str = "This is Javascript String Method!"
             

//     console.log(str.length);

//     console.log(str.at(12));

//     console.log(str.at(28));

//     console.log(str.at(-9));

//     console.log(str.at(33));

//     console.log(str.at(0));

//     console.log(str.at(-1));
    
// }

/* Javascript String.trimStart() ,String.trimEnd() , String.trim() method */

// trim()
// trimStart()
// trimEnd()

// {
//     let str = "            This is Javascript String Method!         "

//     console.log(str.length);

//     let strDemo = str.trim()

//     console.log(strDemo.length);

//     let strDemo1 = str.trimStart()
//     let strDemo2 = str.trimEnd()

//     console.log(strDemo1.length);
//     console.log(strDemo2.length);
    
// }

/* javascript String.charCodeAt()  method  */

// charCodeAt(index)

// {
//       let str = "This is Javascript String Method!"

//       console.log(str.charCodeAt(-10));
// }

/* javascript String.charAt()  method  */

// charAt(index)

    // {
    //     let str = "This is Javascript String Method!"

    //     console.log(str.charAt(-20));
    // }

/* javascript String.concat() method */

// concat(str1)
// concat(str1, str2)
// concat(str1, str2, /* …, */ strN)

// {
//     let str1 = "Hello"
//     let str2 = "World"
//     let str3 = "Javascript"

//     console.log(str1.concat(str3 , str2));
    
// }

/* javascript String.padStart() and String.padEnd() Method */

// padEnd(targetLength)
// padEnd(targetLength, padString)
// padStart(targetLength)
// padStart(targetLength, padString)

// {
//     let str = "5"

//     console.log(str.padStart(3 , "0"));
//     console.log(str.padEnd(5 , "0"));
// }

/* javascript String.includes(Method */

// String.includes(string)
// includes(searchString, position)

// {
//     let str = "This is Javascript String Method!"

//     console.log(str.includes("h" , 5));
// }


/* javascript String.startsWith() and String.endsWith() Method */

// startsWith(searchString)
// startsWith(searchString, position)
// startsWith(searchString)
// startsWith(searchString, position)


    // {
    //     let str = " This is Javascript String Method!"

    //     console.log(str.startsWith("T" , 1));
    //     console.log(str.endsWith("!"));
    // }

/* javascript String.split() Method */


// {
//     let str = " This is Javascript String Method!"

//     console.log(str.split(''));
// }

/* javascript String.repeat() Method */

// String.repeat(count)


// {
//     let str = "Hello"

//     console.log(str.repeat(10));
// }

/* javascript String.toUppercase() Method */

// String.repeat(count)


    // {
    //     let str = "Hello"

    //     console.log(str.toUpperCase());
    // }

/* javascript String.toLowercase() Method */

// String.repeat(count)


// {
//     let str = "HELLO"

//     console.log(str.toLowerCase());
// }

/* javascript String.toString() Method */

// {
//     let str = new String("Hello")
//     let str = new String(123)

//     let str = 123

//     console.log(str.toString());
//     console.log(str.valueOf());
// }

// {
//     let str = new String("hello")
//     let str1 = new String(123)
//     let str2 = 456
//     console.log(str1.toString());
//     console.log(str.toString());
//     console.log(str2.toString());
    
// }

/* javascript String.slice() and String.subString() Method */

// slice(indexStart)
// slice(indexStart, indexEnd)
// substring(indexStart)
// substring(indexStart, indexEnd)

// {
//     let str = "This is slice method in string!"

//             console.log(str.length);

//             console.log(str.slice(15));
//             console.log(str.substring(15));

//             console.log(str.slice(-15));
//             console.log(str.substring(-20));

//             console.log(str.slice(15 , 25));
//             console.log(str.substring(15 , 25));

//             console.log(str.slice(-15 , 18));
//             console.log(str.substring(-15 , 25));

//             console.log(str.slice(-15 , -18));
//             console.log(str.substring(-15 , -25));

//             console.log(str.slice(15 , 0));
//             console.log(str.substring(15 , 0));
// }