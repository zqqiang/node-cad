// var debug = require('debug')('set-env');
var exec = require('child_process').exec;

var CL = __dirname + '\\oce-0.17\\include\\oce';
var LINK = __dirname + '\\oce-0.17\\Win32\\lib';
var PATH = __dirname + '\\oce-0.17\\Win32\\bin';

console.log('CL [%s]', CL);
console.log('LINK [%s]', LINK);
console.log('PATH [%s]', PATH);

exec('git clone https://github.com/erossignon/node-occ ./node_modules/node-occ', function(error, stdout, stderr) {
	console.log('stdout: ' + stdout);
	console.log('stderr: ' + stderr);
	if (error !== null) {
		console.log('exec error: ' + error);
	}
});

// >SET CL=/Ic:\OCE-0.17\include\oce
// >SET LINK=/LIBPATH:c:\OCE-0.17\Win32\lib
// >PATH c:\OCE-0.17\Win32\bin;%PATH%

exec('SET CL=/I' + CL, function(error, stdout, stderr) {
	console.log('stdout: ' + stdout);
	console.log('stderr: ' + stderr);
	if (error !== null) {
		console.log('exec error: ' + error);
	}
});

exec('SET LINK=/LIBPATH:' + LINK, function(error, stdout, stderr) {
	console.log('stdout: ' + stdout);
	console.log('stderr: ' + stderr);
	if (error !== null) {
		console.log('exec error: ' + error);
	}
});

exec('PATH ' + PATH + ';%PATH%', function(error, stdout, stderr) {
	console.log('stdout: ' + stdout);
	console.log('stderr: ' + stderr);
	if (error !== null) {
		console.log('exec error: ' + error);
	}
});