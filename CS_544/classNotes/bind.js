var module = {
  x: 42,
  getX: function() {
    return this.x;
  }
}

var unboundGetX = module.getX;
console.log(unboundGetX()); // The function gets invoked at the global scope
// expected output: undefined

temp = {
    x: 74
}

var boundGetX = unboundGetX.bind(temp);
console.log(boundGetX());
// expected output: 42
