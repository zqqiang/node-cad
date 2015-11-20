// var debug = require('debug')('set-env');
var exec = require('child_process').exec;

process.env.CL = __dirname + '\\oce-0.17\\include\\oce';
process.env.LINK = '/LIBPATH:' + __dirname + '\\oce-0.17\\Win32\\lib';
process.env.PATH += (';' + __dirname + '\\oce-0.17\\Win32\\bin');

// debug(process.env.CL);
// debug(process.env.LINK);
// debug(process.env.PATH);

console.log('CL [%s]', process.env.CL);
console.log('LINK [%s]', process.env.LINK);
console.log('PATH [%s]', process.env.PATH);

exec('git clone https://github.com/erossignon/node-occ ./node_modules/node-occ', function(error, stdout, stderr) {
	console.log('stdout: ' + stdout);
	console.log('stderr: ' + stderr);
	if (error !== null) {
		console.log('exec error: ' + error);
	}
});