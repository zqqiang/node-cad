var fs = require('fs-extra');

fs.copy('./Tools.cc', '../node_modules/node-occ/src/Tools.cc', function(err) {
	if (err) return console.error(err)
	console.log("success!")
})