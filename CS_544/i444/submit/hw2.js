//CS 544
//HW 2

/* 
Question 1
The array function parameter is useful if you are trying to use a previously defined function
*/
function question1(){
    function f(num,index,array){
        return array[array.length - 1 - index] + array[index];
    }
    let even_arr = [2,4,6,8,10,12];
    let add_first_and_last = even_arr.map(f);
    console.log(add_first_and_last);
}

/*
Question 2
Below are functional implementations of the regexs
*/
function question2(regex){
    let octo_regex = /^0[0-7]+$/g;
    let bin_under_5 = /^0*(0|1|10|11|100|101)$/g;
    let fermat_theorem = /^0*(1|10)$/g;
    let morse_code = /^(?=-*(?:\.-*\.-*)*$)(?=\.*(?:-\.*-\.*)*$).*$/g;
    let ip_address = /^(([a-f]|[0-9]){1,4}:){7}([a-f]|[0-9]){1,4}$/g;
}

/*
Question 3
As an evil spammer you could parse each sentence of the email for an email pattern
using the following regex
*/
function question3(email){
    let email_regex = /(\w+@\w+\.(com|net|edu|gov)|\w+ at \w+ dot (com|net|edu|gov))/g;
    email.match(email_regex).map(element => {
        element = element.replace(" at ","@").replace(" dot ",".");
        console.log(element);
    })
}

/*
Question 4
You could implement a function that would use the system clock and do a sequence of random operations to randomize it more
*/
function question4(range){
    let d1 = new Date(Date.now());
    let n1 = d1.getMilliseconds();

    let retVal = Math.pow(n1,n1%8+6)%range;
    console.log(retVal);
    return retVal;
}

const fs = require('fs');
const util = require("util");

/*
Question 5
A. You could create a callback function which will write all data that is returned from readFile function
*/
function question5_callback(){
    fs.readFile('text.txt', function (err, data) {
        if (err) throw err;
        fs.writeFile('text2.txt', data, (err) => { 
            if (err) throw err; 
        }) 
    });
}
/*
B. You could create two new functions, one to read and one to write, both of which return a promise
Then when resolving the readFile function you would call the writeFile function
*/
function question5_promises(){
    // make promise version of fs.readFile()
    readFilePromise = function(filename) {
        return new Promise(function(resolve, reject) {
            fs.readFile(filename, function(err, data){
                if (err) 
                    reject(err); 
                else 
                    console.log(data);
                    resolve(["text3.txt",data]);
            });
        });
    };
    writeFilePromise = function([file, data]){
        return new Promise(function(resolve, reject){
            fs.writeFile(file, data, error => {
                if (error){
                    reject(error);
                }else{
                    resolve("file created successfully with handcrafted Promise!");
                }
            });
        });
    };
    readFilePromise("text.txt").then(writeFilePromise);
}
/*
C. 
Create a make fs.write and fs.read return a promise then call read
Await that promise resolution and pass it to the writeFile
*/
async function question5_async(){
    let writeFileAsync = util.promisify(fs.writeFile);
    let readFileAsync = util.promisify(fs.readFile);

    let data = await readFileAsync('text.txt').catch(()=> "default value");
    await writeFileAsync('text4.txt',data);
}

/*
Question 6
A. 
Create a error handler which takes in the error from the callback function
and which will return a default value when called and assign that to the field that expects the output
*/
let DEFAULT_VALUE = "THIS IS THE DEFAULT VALUE";
function handleError(err){
    //Have a line in here to check that this error is handled correctly 
    return DEFAULT_VALUE;
}
function question6_callback(){
    fs.readFile('text.txt', function (err, data) {
        if (err){
            data = handleError(err);
        } 
        fs.writeFile('text2.txt', data, (err) => { 
            if (err) throw err; 
        }) 
    }); 
}
/*
B. Use catch blocks after calling your functions that return a promise
In the catch block call the error handling function
If you make the error handler return a promise,
You can use a then block after the catch to access the return value of the error handling function

C. Use a catch block after calling the function that you have promisified
Just like 'B.', call the error handling function in the catch block
If you make the error handler return a promise,
you can use a then block after the catch to access the return value of the error handling function
*/


/*
Question 7 

Comments:
    A couple of syntax errors which you see fixed in the fixed version below
    Style: 
        The programmer should be using 'let' instead of 'var'. 
        Why are they using 'c' as a variable name, should rename to num_employees.
        Redeclaring c, in this case works it is very unclear.
        How they assigned a var as 'total' when there's already a 'sum' var. Those can easily get mixed up. 

    Brittleness: 
        If the naming for the properties of the 'scores' object change then this would break. 
        Additionally they forgot to put a 'break' in a for loop so the logic won't work.
    Specification Bugs:
        The return value is very poorly explained and is prone to mistakes. The return would be better as an object rather than an array.
        An example of how it should be done is like this:
        [
            total_average: 7.7,
            grading chart: { 
                fired: [John Smith, Foo Bar],
                poor: [Mark Dinkle, Karen Phillipelli, Jim Halpert],
                ...
            }
        ]

Fixed version:
*/
function performanceReview(scores, cutoffs) {
  let categories = {};
  let num_employees = 0;
  let sum_of_scores = 0;
  for (let employee_name in scores) {
    sum_of_scores += scores[employee_name].total;
    num_employees++;
    for (let cut in cutoffs) {
      if (scores[employee_name].total < cut){
          categories[cut].push(employee_name);
          break;
      }
    }
  }
  let total_average = sum_of_scores/num_employees;
  return [total_average, categories];
}

/*
Question 8
Using promise.all allows you to remove sequential awaits in this code
*/

async function cheapestFare(fromAirport, toAirport, date, fareType) {
    let cheapest = Number.MAX_SAFE_INTEGER;
    let promises = [];
    for (const [airline, params] of Object.entries(AIRLINE_PARAMS)) {
        let promise = getAirFare(params, fromAirport, toAirport, date, fareType);
        promises.push(promise);
    }
    const allResults = await Promise.all(promises);
    for(let fare of allResults){
        if(fare<cheapest){
            cheapest = fare;
        }
    }
    return cheapest;
}

/*
Question 9

a. 
This is false javascript supports 53 bit integers. 
This is because In javascript every number is a floating point and has the form:
sign , mantissa , 2exponent. Where the mantissa is 53 bits. So after you reach 2^53 (~9e14)
you can multiply the mantissa by two by bumping up the 2exponent to 1. This will only result in even numbers tho.
Ex.
    > Math.pow(2, 53)  // 54 bits
    9007199254740992
    > Math.pow(2, 53) + 1
    9007199254740992

b.
This is false.
You even if you declare an object as const doesn't mean it's immutable,
it simply means it's unassignable. For example, if you do 'const x = {a:1}'
Then line x.a = 2, still works but x = {a:2}, doesn't.

c.
This is true.
The new operator will create a brand new object from the function prototype.
That object is then the return type so trying to compare two brand new objects will
always return false.

d.
This is false.
It is just good practice to name a 'class' constructor with a capital letter.
What makes a function a constructor is if you call it using a the 'new' keyword.

e.
This is true.
Even if the an object was intialized prior to the prototype being changed, the changes will still
represented in the object. For example:
> function Parent(){}
> let parent = new Parent();
> Parent.prototype.greet = function(){ console.log("Hello all")};
> parent.greet(); // outputs "Hello all"
*/