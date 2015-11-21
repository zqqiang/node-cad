// var debug = require('debug')('set-env');
var exec = require('child_process').exec;

var CL = __dirname + '\\oce-0.17\\include\\oce';
var LINK = __dirname + '\\oce-0.17\\Win32\\lib';
var PATH = __dirname + '\\oce-0.17\\Win32\\bin';

console.log('CL [%s]', process.env.CL);
console.log('LINK [%s]', process.env.LINK);
console.log('PATH [%s]', process.env.PATH);

// >SET CL=/Ic:\OCE-0.17\include\oce
// >SET LINK=/LIBPATH:c:\OCE-0.17\Win32\lib
// >PATH c:\OCE-0.17\Win32\bin;%PATH%

var execCmd = function(cmd) {
	exec(cmd, function(error, stdout, stderr) {
		console.log('stdout: ' + stdout);
		console.log('stderr: ' + stderr);
		if (error !== null) {
			console.log('exec error: ' + error);
		}
	});
};

execCmd('git clone https://github.com/erossignon/node-occ ./node_modules/node-occ');