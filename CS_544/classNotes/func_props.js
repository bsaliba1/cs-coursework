days = ['Mon', 'Tues', 'Wed'];

let getDays = {
    days_of_week: days, 
    convert_to_day: (x) => this.days_of_week[x],
}

let getDays2 = {
    days_of_week: days, 
    convert_to_day: function (x){ return this.days_of_week[x] },
}

let lambda_getDays = getDays.convert_to_day;
let regular_getDays = getDays2.convert_to_day.bind(getDays2);

console.log("Lambda Func: day[0] = "+ lambda_getDays(0));
console.log("Regular Func: day[0] = "+ regular_getDays(0));
