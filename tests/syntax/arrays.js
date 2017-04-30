var arr = [
	[1, 2, 3],
	[{x: 1, y: "john"}, {
		f: function() {
			return {
				p: [1, {}]
			};
		},
		empty: {}
	}]
];

console.log(arr[2-1][1].f().p[0]);
