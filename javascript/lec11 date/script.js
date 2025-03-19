// /* javascript Date Object Method */

// {
//     let currentDate = new Date()

//     console.log(currentDate);
// }

// /* Get Method / Set Method */

// /*
// 0 - january
// 11-december
// */

// {
//     let today = new Date('31 aug 2004 15:15:15')

//     console.log(today.getDate());
//     console.log(today.getDay());
//     console.log(today.getFullYear());
//     console.log(today.getMonth());
//     console.log(today.getHours());
//     console.log(today.getMinutes());
//     console.log(today.getSeconds());
//     console.log(today.getMilliseconds());
//     console.log(today.getTime());
    
// }

// {
    
//     let demo = Date.now()
    
//     console.log(demo);
    
// }

{
    setInterval(() => {
        let today = new Date()
        
        console.log(today.getSeconds());
    } , 1000)
}