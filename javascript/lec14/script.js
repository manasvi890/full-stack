// Javascript Map objectFit:

let mapObject = new Map();
 
   console.log(mapObject);

//  map.set
    mapObject.set("key1", "toyes");
   mapObject.set("key2", "banana");

     let object = {
     name: "skillqode",
     profile: "Learning Institute",
   };

//  map.length
  console.log(object.length);
 
//   map.size
   console.log(mapObject.size);

//    map.clear

//  mapObject.clear()
 console.log(mapObject);

// map.get

let key1 = mapObject.get('key3')
 
   console.log(key1);

//    map.has

  console.log(mapObject.has('key3'));

//      map.delete

  mapObject.delete('key1')
 
   console.log(mapObject);

//    map.entries


   let demo = mapObject.entries()
 
   console.log(demo.next().value);
   console.log(demo.next().value);






   // Javascript Set objectFit:

   let array = [1 , 2 , 3 , 4 , 5 , 6]
 
 {
   let demo = array.entries()
 
   console.log(demo.next().value);
   console.log(demo.next().value);
   console.log(demo.next().value);
   console.log(demo.next().value);
   console.log(demo.next().value);
   console.log(demo.next().value);
}



   let demo2 = mapObject.values()
 
   console.log(demo2.next().value);
   console.log(demo2.next().value);
   console.log(demo2.next().value);


 

let demo1 = mapObject.keys()
 
   console.log(demo1.next().value);
   console.log(demo1.next().value);
   console.log(demo1.next().value);
   

// function Elements(key , value , map){
   //   console.log(`${key} = ${value}`);
     
   // }
 
   // new Map([['1' , 'kiwi'] , ['2' , 'watermelon'], ['3' , 'orange']]).forEach(Elements)
   
   // console.log(mapObjectFor);
 
 //   let profile = {
 //     fullName:'Raju Rastogi',
 //     age:45,
 //     gender:'male',
 //     getFullInfo : function(){
 //       console.log(`my name is ${this.fullName} and my age is ${this.age}and last my gender is ${this.gender}`);
 //     }
 // }
 
 // console.log(profile.fullName);
 

//  console.log(mapObjectFor);
 
//    let profile = {
//      fullName:'Raju Rastogi',
//      age:45,
//      gender:'male',
//      getFullInfo : function(){
//        console.log(`my name is ${this.fullName} and my age is ${this.age}and last my gender is ${this.gender}`);
//      }
//  }
 
//  console.log(profile.fullName);

 /* Set Object In Javascript */
 
 {
    let setObject = new Set()
  
    console.log(setObject);
  
    console.log(setObject.size);
  
    setObject.add('Lemon')
  
    setObject.add('potato')
  
    setObject.add('tomato')
  
    console.log(setObject);
  
    // setObject.clear()
  
    // setObject.delete('Lemon')
  
    console.log(setObject);
    
    let demo = setObject.entries()
  
    console.log(demo.next().value);
    console.log(demo.next().value);
    console.log(demo.next().value);
  
    let demoKeys = setObject.keys()
  
    console.log(demoKeys.next().value);
    console.log(demoKeys.next().value);
    console.log(demoKeys.next().value);
    console.log(demoKeys.next().value);
  
    let demoValues = setObject.values()
  
    console.log(demoValues.next().value);
    console.log(demoValues.next().value);
    console.log(demoValues.next().value);
    console.log(demoValues.next().value);
  
    console.log(setObject.has('Lemons'));
  
    let setDemoObject = new Set([1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9])
  
  
    let setDemoObject1 = new Set([1 , 2 , 3 , 4 , 5 , 10])
  
    let demos = setDemoObject1.difference(setDemoObject)
  
    
    let demos1 = setDemoObject.intersection(setDemoObject1)
    
    console.log(demos1);
  
    let demos2 = setDemoObject.isDisjointFrom(setDemoObject1)
  
    let demos3 = setDemoObject.isSubsetOf(setDemoObject1)
  
    let demos4 = setDemoObject.isSupersetOf(setDemoObject1)
  
    let demos5 = setDemoObject.symmetricDifference(setDemoObject1)
  
    let demos6 = setDemoObject.union(setDemoObject1)
  
    // console.log(demos2);
  
    console.log(demos3);
    console.log(demos4);
  
    console.log(demos5);
  
    console.log(demos6);
    
    
  
    
  
    
    
    
    
    
    
  }
 
