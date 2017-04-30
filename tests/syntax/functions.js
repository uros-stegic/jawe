function f(x) {
	return x**2;
}

let x = f(3);
let g = function(x, y) { return x + y; };

const obj = {
	x: 1,
	y: function() {
		return x;
	}
};

console.log(obj.y());

