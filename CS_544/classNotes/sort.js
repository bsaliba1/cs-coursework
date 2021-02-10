function sort_map(unordered){
  let obj = {};
  let sorted = Object.keys(unordered).sort();
  for(let key of sorted){
    obj[key] = unordered[key];
  }
    return obj;
}

let m1 = { '123123': 2, '324234':4, '111212':1, '874538':6, '676732':5, '134323':3}

console.log(sort_map(m1));
