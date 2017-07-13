if( x == 1 ) {
	var test = function() {
		if( x == 2 ) {
			if( x == 3 ) {
				++x;
				let a = 1;
				--x;
				const b = 2;
				var c = 3;
			}
		}
	};
}
