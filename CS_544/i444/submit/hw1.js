var assert = require('assert');

//Question 1;
function selectListsWithLengthMultiple(lists, multiple=2){
    return lists.filter(list => list.length % multiple === 0);
}
//---------------------------
//Question 2
function reverse(text){
    return text.split('').reverse().join("");
}
//---------------------------
//Question3
function isPalindrome(text){
    return (text.replace(/\W+/g, '') === text.replace(/\W+/g, '').split('').reverse().join(""));
}
//---------------------------
//Question 4
function minLenArg(...objs){
    return objs[objs.map(e => e.length).indexOf(Math.min(...objs.map(e => e.length)))];
}
//---------------------------
//Question5
function formatInt(int, {base = 10, n = 3, sep = ','} = {base: 10, n:3, sep: ','}){
   return int.toString(base).split('').reverse().join("").match(new RegExp((n > 0 ? `.{1,${n}}`: `.+` ),"g")).join(sep).split('').reverse().join("");
} 
//---------------------------
// Question6
function isEvenParity(int){
    return (Number(int).toString(2).split('').reduce((acc, val) => acc + parseInt(val,10), 0)%2 === 0); 
}
//---------------------------
// Question7
function bitIndexesToInt(indexes){
    return indexes.map(e => Math.pow(2,e)).reduce((acc, val) => acc + val,0);
}
//---------------------------
// Question8
function intToBitIndexes(int){
    return int.toString(2).split('').reverse().map((e, i) => e === '1' ? i : '').filter(String);
}
//---------------------------
// Question9
function multiIndex(obj, indexes){
    return (indexes === ''? obj : indexes.split('.').reduce((o, key) => (o && o[key] !== 'undefined') ? o[key] : undefined, obj));
}
//---------------------------
// Question10
function zip(list1, list2){
    return list1.map((e,i) => [list1[i], list2[i]]);
}
//---------------------------
// Question11
function multiZip(...lists){
    return lists[0].map((e,index) => lists.reduce((a,e) => a.concat(e[index]), []));
}
//---------------------------
// Question12
function multiZipAny(...lists){
    return lists.concat().sort(function(a,b){return a.length>b.length})[0].map((e,index) => lists.reduce((a,e) => a.concat(e[index]), []));
}
//---------------------------
// Question13
/* 
The issue with the response given was that it was using '==' for comparison not '==='
Also that it was checking for null and not undefined
*/
function edditedQuestion13(){
    const results = {};
    if (results[key] === undefined) {
      console.log(`${key} is not defined`);
    }    
}

//---------------------------
//Question 14
/* 
1. Abstract-Factory: No need to have a factory because classes are first class objects so they
can be used and operated on where any other value or object can be used, meaning there's no need to build extra dynamic objects just to hold
types, because the type objects themselves will do.

2. Iterator: This is unneccessary in Javascript simply because we can use 'for..of' or 'for...each'. Essentially
 it is unneccessary to have internal iterators implemented for each object

3. Prototype: This is simplified substantially in Javascript seeing as you can assign functions to specific object prototypes as seen in question 15.
*/

//---------------------------
//Question 15
/*
1. You can't use a fat arrow function because a fat arrow function would not bind to 'this' and would instead have this refer to the contextual this
2. You could use the function call in the Rect constructor:

    function Rect(x, y, w, h) {
        Shape.call(this,x,y);
        this.width = w; this.height = h;
    }

*/

//TESTS
function question1Tests(){
    assert(selectListsWithLengthMultiple([[1, 2, 3], [1, 2], []]).toString() === [[1,2], []].toString());
    assert(selectListsWithLengthMultiple([[1, 2, 3], [1, 2], []], 3).toString() === [ [ 1, 2, 3 ], [] ].toString());
    assert(selectListsWithLengthMultiple([[1, 2, 3], [1, 2], ], 4).toString() === [].toString());
    assert(selectListsWithLengthMultiple([]).toString() === [].toString());
}

function question2Tests(){
    assert(reverse('Hello') === 'olleH');
    assert(reverse('') === '');
}

function question3Tests(){
    assert(isPalindrome('anna') === true);
    assert(isPalindrome('ann') === false);
    assert(isPalindrome('a man, a plan, a canal, panama') === true);
    assert(isPalindrome('a man, a planx, a canal, panama') === false);
}

function question4Tests(){
    assert(minLenArg([1, 2, 3], 'ab', [3, 4]) === 'ab');
    assert(minLenArg([1, 2, 3], 'ab', [3]).toString() === [3].toString());
    assert(minLenArg([1, 2, 3], 'ab', [3], '') === '');
    assert(minLenArg([], 'ab', [3], '').toString() === [].toString());
}

function question5Tests(){
    assert(formatInt(999999) === '999,999');
    assert(formatInt(1234567890) === '1,234,567,890');
    assert(formatInt(1 << 30, { base: 2, n: 4, sep: '_'}) === '100_0000_0000_0000_0000_0000_0000_0000');
    assert(formatInt((1<<30) - 1, { base: 2, n: 4, sep: '_' }) === '11_1111_1111_1111_1111_1111_1111_1111');
    assert(formatInt((1<<30) - 1, { base: 16, n: 4, sep: '_' }) === '3fff_ffff');
    assert(formatInt((1<<30) - 1, { base: 16, n: 0, sep: '_' }) === '3fffffff');
}

function question6Tests(){
    assert(isEvenParity(0) === true);
    assert(isEvenParity(1) === false);
    assert(isEvenParity(0xc) === true);
    assert(isEvenParity(0xd) === false);
    assert(isEvenParity(0xffed) === true);
}

function question7Tests(){
    assert(bitIndexesToInt([0, 1, 2, 3]) === 15);
    assert(bitIndexesToInt([4, 8]) === 272);
    assert(bitIndexesToInt([5, 3]) === 40);
    assert(bitIndexesToInt([]) === 0);
}

function question8Tests(){
    assert(intToBitIndexes(15).toString() === [ 0, 1, 2, 3 ].toString());
    assert(intToBitIndexes(272).toString() === [ 4, 8 ].toString());
    assert(intToBitIndexes(0).toString() === [].toString());
    assert(intToBitIndexes(40).toString() === [3,5].toString());
}

function question9Tests(){
    assert(multiIndex({a: 42}, 'a') === 42);
    assert(multiIndex({a: [ 22, { b: 42} ]}, 'a.1.b') === 42);
    assert(multiIndex({a: [ 22, { b: 42} ]}, 'a.0.b') === undefined);
    assert(multiIndex({a: [ 22, { b: 42} ]}, 'a.0') === 22);
    assert(multiIndex(42, '') === 42);
}

function question10Tests(){
    assert(zip([1, 2, 3], ['a', 'b', 'c']).toString() === [ [ 1, 'a' ], [ 2, 'b' ], [ 3, 'c' ] ].toString());
    assert(zip([1], ['a']).toString() === [ [ 1, 'a' ] ].toString());
    assert(zip([], []).toString() === [].toString());
}

function question10Tests(){
    assert(zip([1, 2, 3], ['a', 'b', 'c']).toString() === [ [ 1, 'a' ], [ 2, 'b' ], [ 3, 'c' ] ].toString());
    assert(zip([1], ['a']).toString() === [ [ 1, 'a' ] ].toString());
    assert(zip([], []).toString() === [].toString());
}

function question11Tests(){
    assert(multiZip([1, 2, 3], [4, 5, 6], [7, 8, 9]).toString() === [ [ 1, 4, 7 ], [ 2, 5, 8 ], [ 3, 6, 9 ] ].toString());
    assert(multiZip([1, 2, 3], [4, 5, 6], [7, 8, 9], ['x', 'y', 'z']).toString() === [ [ 1, 4, 7, 'x' ], [ 2, 5, 8, 'y' ], [ 3, 6, 9, 'z' ] ].toString());
    assert(multiZip([1, 2, 3]).toString() === [ [ 1 ], [ 2 ], [ 3 ] ].toString());
    assert(multiZip([], [], [], [], []).toString() === [].toString());
}

function question12Tests(){
    assert(multiZipAny([1, 2], [3, 4, 5], [6, 7, 8, 9]).toString() === [ [ 1, 3, 6 ], [ 2, 4, 7 ]].toString());
    assert(multiZipAny([1, 2, 3], [3, 4, 5], [6, 7, 8, 9], ['a']).toString() === [ [ 1, 3, 6, 'a' ] ].toString());
    assert(multiZipAny([1, 2, 3], [3, 4, 5], [6, 7, 8, 9]).toString() === [ [ 1, 3, 6 ], [ 2, 4, 7 ], [ 3, 5, 8 ] ].toString());
    assert(multiZipAny([], [3, 4, 5], [6, 7, 8, 9]).toString() === [].toString());
}

//Call all tests
question1Tests();
question2Tests();
question3Tests();
question4Tests();
question5Tests();
question6Tests();
question7Tests();
question8Tests();
question9Tests();
question10Tests();
question11Tests();
question12Tests();

