var array = process.argv;
var sum = 0;

for (let index = 2; index < array.length; index++) {
	sum += parseInt(array[index]);
}
console.log(sum);