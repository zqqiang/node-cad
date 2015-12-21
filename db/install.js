var fs = require('fs-extra');

var copy = function copy(src, dst) {
	fs.copy(src, dst, function(err) {
		if (err) return console.error(err);
		console.log('fs copy %s => %s success!', src, dst);
	})
};

copy('./config.pl', '../postgresql-9.5rc1/src/tools/msvc/');