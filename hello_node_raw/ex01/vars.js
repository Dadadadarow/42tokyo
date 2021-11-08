var str = "42";
var num = 42;
var ftobj = {0:42};
var flag = 11;
var obj = {};

console.log('%s is a', str, typeof(str));
console.log('%d is a', num, typeof(num));
console.log('%o is an', ftobj[0], typeof(ftobj));
console.log('%o is an', toString(obj), typeof(obj));
console.log('%o is an', true, typeof(true));
console.log('%o is an', undefined, typeof(undefined));
