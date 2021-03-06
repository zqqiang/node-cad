var fs = require('fs-extra');

var copy = function copy(src, dst) {
	fs.copy(src, dst, function(err) {
		if (err) return console.error(err);
		console.log('fs copy %s => %s success!', src, dst);
	})
};

copy('./Tools.cc', '../node_modules/node-occ/src/Tools.cc');
copy('./adapter.cc', '../node_modules/node-occ/src/adapter.cc');
copy('./adapter.h', '../node_modules/node-occ/src/adapter.h');
copy('./core.cc', '../node_modules/node-occ/src/core.cc');
copy('./core.h', '../node_modules/node-occ/src/core.h');
copy('./binding.gyp', '../node_modules/node-occ/binding.gyp');