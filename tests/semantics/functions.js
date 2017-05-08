function zero() {
	return 0;
}

function successor(x) {
	return x+1;
}

let firstProjection = function(x, y) {
	return x;
};

const f = function(x) {
	return function(y) {
		return x+y;
	};
};
