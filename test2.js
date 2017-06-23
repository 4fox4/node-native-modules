module.exports.test2 = function() {
	var i = 0;
	var nbOps = 0;
	var loopState = 0;
	while (loopState < 20) {
		while (i < 100000000) {
			i++;
			nbOps++;
		}
		while (i > 0) {
			i--;
			nbOps++;
		}
		loopState++;
	}
	return nbOps;
}