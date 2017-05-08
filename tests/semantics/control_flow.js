let x = [1, 2, 3, 4];
let i = 0;
if( i instanceof x || i in x ) {
	i = 0;
}
else i = 1;

while( i < 4 ) {
	x[i] += 1;
	if( x[i] == 3 ) {
		continue;
	} 
	else break;
}

switch( x[i] ) {
	case 0: { i++; break; }
	case 1: { i--; break; }
	default:{ i = 0; }
}

for(let j = 0; j < 10; j++) {
	x[j] -= 1;
}

for(j = 0; j <= 10 && j % 2 === 0; j++)
	x[j] **= 3;


