// javascript number method

{
    let num=10000000
 typeof num
 console.log(typeof num);
     
}

// isFinite()

{let num=Number.isFinite(1/0)
    let num1 = Number.isFinite(0/1)
   let num2 = Number.isFinite(Infinity)
   let num3 = Number.isFinite(-Infinity)
   let num4 = Number.isFinite(NaN)
   let num5 = Number.isFinite(10)
   let num6 = Number.isFinite(10.54)
   let num7 = Number.isFinite(-10)
   

  console.log(num);
   console.log(num1);
   console.log(num2);
   console.log(num3);
   console.log(num4);
   console.log(num5);
   console.log(num6);
   console.log(num7);
}

// isNaN()

{
    let num8=Number.isNaN("skillQode")
    let num9=Number.isNaN("10"/8)
    let num10=Number.isNaN("10"/"30")
    let num11=Number.isNaN(6+5)
    let num13=Number.isNaN("10skill"/5)
    let num12=Number.isNaN("10skill"/5)


    console.log(num8);
    console.log(num9);
    console.log(num10);
    console.log(num11);
    console.log(num12);
    console.log(num13);
    
}

// isSafeInteger()

{
     let num10 = Number.isSafeInteger(1000000000000000000)
 
   console.log(num10);
}

// parseFloat()

{
     let num11 = Number.parseFloat(false)
 
   console.log(num11);
 
}

// parseInt()

{
    let num12 = Number.parseInt(10.66)
 
   console.log(num12);
}

// toExponential()
 
// toExponential()
// toExponential(fractionDigits) is between 0 to 100

   {let num = 45.256984
 
   let expo = num.toExponential()
   let expo1 = num.toExponential(1)
   let expo2 = num.toExponential(2)
   let expo3 = num.toExponential(50)

    console.log(expo);
   console.log(expo1);
   console.log(expo2);
   console.log(expo3);
}

{
   let num = 45000000
  let fix = num.toFixed()
   let fix1 = num.toFixed(1)
   let fix2 = num.toFixed(2)


   console.log(fix);
   console.log(fix1);
   console.log(fix2);
}

{
    //.toPrecision()
 
   let num = 450.78790
 
   let pre = num.toPrecision()
   let pre1 = num.toPrecision(1)
   let pre2 = num.toPrecision(2)
 
   console.log(pre);
   console.log(pre1);
   console.log(pre2);
}