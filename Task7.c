
/*	This function calculate length of the wire that you need to connect N sensors,
 distanse between any neighbour sensors and between first sensor and the base station
 equals D.
	Calculates as sum of simple arithmetic progression(Sn=(a1+an)*n/2) and has
 asymptotic comlexity O(1), because number of operation is independ from input parametrs.*/

int calc_wire_length(int D, int N) {
	if (N <= 0)
		return 0;
	int a1 = D;
	int an = N*D; // the same us an=a1+(n-1)*D, because a1=D;
	return (a1 + an) * N / 2;
}
