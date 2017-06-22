module.exports.test2 = function() {
	var i = 0;
	while (i < 100000000) {
		i++;
	}
	while (i > 0) {
		i--;
	}
	return "coco js!";
}