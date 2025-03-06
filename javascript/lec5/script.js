// Javascript Statements

// if Statement

{
  let InStock = true;

  if (InStock) {
    console.log("Product is Available!!!");
  }
}

// if....else Statement

{
  let InStock = false;

  if (InStock) {
    console.log("Product is Available!!!");
  } else {
    console.log("Product is Not Available!!!");
  }
}

// Nested Statements


{
  let InStock = true;
  let Item = "kitchen";
  
  if (Item === "toys") {
    if (InStock) {
      console.log("Product is Available!!!");
    } else {
      console.log("Product is Not Available!!!");
    }
  } else {
    console.log("Product is Not Available!!!");
  }
  
}

// if....else..if Statement

{
  let Book = "social"

  if(Book === "maths"){
    console.log('maths book is available!');
  }else if(Book === "physics"){
    console.log('physics book is available!');
  }else if(Book === "english"){
    console.log('english book is available!');
  }else if(Book === "chemistry"){
    console.log('chemistry book is available!');
  }else if(Book === "drawing"){
    console.log('drawing book is available!');
  }else{
    console.log('book is not available!');
  }
}


// Switch case Statements

{
  let Book = "maths"

  switch(Book){
    case "maths" : console.log('maths book is available!');
    break;
    case "physics": console.log('physics book is available!');
    break;
    case "english": console.log('english book is available!');
    break;
    case "chemistry" : console.log('chemistry book is available!');
    break;
    case "drawing" :  console.log('drawing book is available!');
    break;
    default: console.log('book is not available!');
  }
}