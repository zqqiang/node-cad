# README #

Software for Declarative CAD Feature Recognition — an efﬁcient approach

### What is this repository for? ###

* v0.0.1
* [Learn More]()

### How do I get set up? ###

* Summary of set up
  
	1.npm install  
	2.set-env.bat  
	3.node install.js  
	4.cd node_modules/node-occ  
	5.npm install  
	6.cd ../..  
	7.node app.js  
	8.browse [http://localhost:3000/](http://localhost:3000/) and [http://localhost:3000/viewer](http://localhost:3000/viewer)  

* Steps of add c++ module

	1.cd ./src  
	2.add xxx.cc and xxx.h  
	3.modify install.js to add "copy('./xxx.cc', '../node_modules/node-occ/src/xxx.cc');"  
	4.modify install.js to add "copy('./xxx.h', '../node_modules/node-occ/src/xxx.h');"  
	5.modify binding.gyp to add xxx.cc and xxx.h to "sources" property  

* Steps of compile src

	1.cd ./src  
	2.node install.js  
	3.cd ../  
	4.set-evn.bat  
	5.node_modules/node-occ/  
	6.npm install  

* Configuration
* Dependencies

	you need [Microsoft Visual Studio 2012](http://www.microsoft.com/en-us/download/details.aspx?id=30682)  
	download and install [cmake](http://www.cmake.org/download/)  
	install node-js 32 bits version 0.12 from [www.nodejs.org](http://nodejs.org/dist/v0.12.0/node-v0.12.0-x86.msi)  

* Database build and install

	0.install all dependence. [Building with Visual C++ Requirements](http://www.postgresql.org/docs/devel/static/install-windows-full.html)  
	1.download postgresql [9.5.1](https://ftp.postgresql.org/pub/source/v9.5.1/postgresql-9.5.1.tar.bz2)  
	2.unzip to ./postgresql-9.5.1  
	3.node ./db/install.js  
	4.open "Developer Command Prompt for VS2012" cmder  
	5.cd ./postgresql-9.5.1/src/tools/msvc/  
	6.build.bat  
	7.install.bat ./path/to/install/  

* Database start and access

	0.set env => a. cd nxCad/node-cad/db/ b. pgenv.bat  
	1.initialize db (only first time) => initdb -D ./pgsql/data  
	2.start db => pg_ctl start -D ./pgsql/data -l pgrun_log  
	3.create db => createdb mydb  
	4.accessing database => psql mydb  

* Database query

	0. CREATE FUNCTION cadinit(cstring) RETURNS int AS 'cadfix' LANGUAGE C;  
	1. select cadinit('path/to/cad.step');  
	2. CREATE FUNCTION full_edge(cstring,cstring) RETURNS int AS 'cadfix' LANGUAGE C;  
	3. select full_edge('evaluate','path/to/evaluate.csv');  
	4. select full_edge('import','path/to/import.csv');  
	5. CREATE unlogged TABLE IF NOT EXISTS full_edge ( EDGE INTEGER, face1 INTEGER, FACE2 INTEGER , DIHEDRAL INTEGER);  
	6. COPY full_edge FROM 'path/to/import.csv' with csv;  
	7. CREATE TABLE RESULT AS SELECT
	   full_edge_e1.edge as e1,  
	   full_edge_e1.face1 as f1,  
	   full_edge_e1.face2 as f2,  
	   full_edge_e2.edge as e2,  
	   full_edge_e2.face2 as f3,  
	   full_edge_e3.edge as e3,  
	   full_edge_e3.face2 as f4,  
	   full_edge_e4.edge as e4,  
	   full_edge_e5.edge as e5  
	   FROM  
	   full_edge full_edge_e5,  
	   full_edge full_edge_e4,  
	   full_edge full_edge_e3,  
	   full_edge full_edge_e2,  
	   full_edge full_edge_e1  
	   WHERE  
	   full_edge_e1.face2=full_edge_e2.face1 AND  
	   full_edge_e1.face1=full_edge_e3.face1 AND  
	   full_edge_e1.face1=full_edge_e4.face1 AND  
	   full_edge_e1.face2=full_edge_e5.face1 AND  
	   full_edge_e2.face2=full_edge_e4.face2 AND  
	   full_edge_e2.face1=full_edge_e5.face1 AND  
	   full_edge_e3.face1=full_edge_e4.face1 AND  
	   full_edge_e3.face2=full_edge_e5.face2 AND  
	   full_edge_e1.dihedral=1 AND  
	   full_edge_e2.dihedral=2 AND  
	   full_edge_e3.dihedral=2 AND  
	   full_edge_e4.dihedral=2 AND  
	   full_edge_e3.face2<>full_edge_e2.face2 AND  
	   full_edge_e3.face2<>full_edge_e1.face2 AND  
	   full_edge_e3.face2<>full_edge_e1.face1 AND  
	   full_edge_e2.face2<>full_edge_e1.face2 AND  
	   full_edge_e2.face2<>full_edge_e1.face1 AND  
	   full_edge_e1.face2<>full_edge_e1.face1 AND  
	   full_edge_e5.edge<>full_edge_e4.edge AND  
	   full_edge_e5.edge<>full_edge_e3.edge AND  
	   full_edge_e5.edge<>full_edge_e2.edge AND  
	   full_edge_e5.edge<>full_edge_e1.edge AND  
	   full_edge_e4.edge<>full_edge_e3.edge AND  
	   full_edge_e4.edge<>full_edge_e2.edge AND  
	   full_edge_e4.edge<>full_edge_e1.edge AND  
	   full_edge_e3.edge<>full_edge_e2.edge AND  
	   full_edge_e3.edge<>full_edge_e1.edge AND  
	   full_edge_e2.edge<>full_edge_e1.edge ;  


* How to run tests

	1.browse [http://localhost:3000/viewer](http://localhost:3000/viewer).  
	2.Click 'Choose Files' to upload ./data/Cable Tie 2,5*100 MM.STEP  
	3.Check if the step file can render?  


	![Image of Cable Tie](./data/CableTie.png)  

* Deployment instructions

### Todo List ###

* Bug list

	1.Dependence Walker: Error: A circular dependency was detected.

* SQL Callback

	1. create table r(edge int, face int)  
	2. create table ef(edge int, face1 int, face2 int)

### Contribution guidelines ###

* Writing tests
* Code review
* Other guidelines

### Who do I talk to? ###

* Repo owner or admin
* Other community or team contact