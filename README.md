Queue
====================
Building with AppVeyor: [![Build status](https://ci.appveyor.com/api/projects/status/kabn8dnwy8ccsad0?svg=true)](https://ci.appveyor.com/project/DanielSLima/queue)

Building with Travis: [![Build Status](https://www.travis-ci.com/danielScLima/Queue.svg?branch=master)](https://www.travis-ci.com/danielScLima/Queue)

This repository has a project with the implementation of a Queue.

It is written in C++.

The code of the Queue is independent of platform.

Is has two possible main files:

* [Codes](#markdown-header)
	* [A main that triggers unit test;](#markdown-header-emphasis)

	* [A Qt project to manage the queue (With Gui).](#markdown-header-strikethrough)
	
The library used to make the Unit Test is the Catch v2.12.3. The code is already in this repository.

The Qt project generates images of the Queue, using the lib Graphviz.
Install this lib in your computer for you to be able to create such images.

The code was written containing the Doxygen documentation.

- - -

You have several options to build the project: 
====================

* [Build tools](#markdown-header)
	* [Makefile (using the file named MakefileGeneral);](#markdown-header-emphasis)
	* [CMake.](#markdown-header-emphasis)
	* [Qt Project (With QMake).](#markdown-header-emphasis)

The project has no leaks (Fully tested with Valgrind).

All the unit tests are ok.

- - -

The functionalities available are: 
====================

* [Functionalities](#markdown-header)
	* [Insert;](#markdown-header-emphasis)
	* [GetTop;](#markdown-header-emphasis)	
	* [Remove;](#markdown-header-emphasis)
	
- - -

Insertion demo steps: 
====================

## Initial

![Alt text](images/inserting/1.png)

## Inserting 70

![Alt text](images/inserting/2.png)

## Inserting 10

![Alt text](images/inserting/3.png)

## Inserting 20

![Alt text](images/inserting/4.png)

## Inserting 7

![Alt text](images/inserting/5.png)

- - -

Remove demo steps: 
====================

## Initial 

![Alt text](images/inserting/5.png)

## Removing

![Alt text](images/removing/1.png)

## Removing

![Alt text](images/removing/2.png)

## Removing

![Alt text](images/removing/3.png)

## Removing

![Alt text](images/removing/4.png)


Qt gui project: 
====================
The qt gui application gui is shown below:

![Alt text](images/sample.png)
