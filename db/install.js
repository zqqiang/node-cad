var fs = require('fs-extra');

var copy = function copy(src, dst) {
	fs.copy(src, dst, function(err) {
		if (err) return console.error(err);
		console.log('fs copy %s => %s success!', src, dst);
	})
};

copy('./config.pl', '../postgresql-9.5.1/src/tools/msvc/config.pl');
copy('./VSObjectFactory.pm', '../postgresql-9.5.1/src/tools/msvc/VSObjectFactory.pm');

fs.access('../postgresql-9.5.1/contrib/cadfix/', function(err) {
	if (err) {
		console.log('../postgresql-9.5.1/contrib/cadfix/ doesn\'t exist! create it.');
		fs.mkdir('../postgresql-9.5.1/contrib/cadfix/', function(err) {
			if (err) {
				console.log('mkdir failed!');
			} else {
				copy('./cadfix/Makefile', '../postgresql-9.5.1/contrib/cadfix/Makefile');
				copy('./cadfix/cadfix.c', '../postgresql-9.5.1/contrib/cadfix/cadfix.c');
				copy('./cadfix/occapi/occapi/occapi.h', '../postgresql-9.5.1/contrib/cadfix/occapi.h');
				copy('./cadfix/occapi/Debug/occapi.lib', '../postgresql-9.5.1/contrib/cadfix/occapi.lib');
			}
		})
	} else {
		copy('./cadfix/Makefile', '../postgresql-9.5.1/contrib/cadfix/Makefile');
		copy('./cadfix/cadfix.c', '../postgresql-9.5.1/contrib/cadfix/cadfix.c');
		copy('./cadfix/occapi/occapi/occapi.h', '../postgresql-9.5.1/contrib/cadfix/occapi.h');
		copy('./cadfix/occapi/Debug/occapi.lib', '../postgresql-9.5.1/contrib/cadfix/occapi.lib');
	}
});