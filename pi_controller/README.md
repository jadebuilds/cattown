# Raspberry Pi

## Functions

The Raspberry Pi in Cat Town performs a few key functions:

* Runs computer vision to detect the cat's location;
* Simulates mouse personalities to decide where the mice will run next;
* Decides when to deploy mice and which ones;
* Serves a user interface over the Web for remote viewing and control.

## Module Architecture

Cat Town is a monolithic Python program with modules for each basic function. Modules are expected to handle their own threading/subprocesses.

* The **Platform Manager** (`/platform_mgr`) tracks which mice are active, deploys new mice, and handles mouse changes;
* The Platform Manager runs a set of **Personalities** (`/personalities/*`);
* The **Computer Vision System** (`/cv`) uses the camera to report the cat's location to Personalities;
* The **User Interface** is not yet started! See https://feline.atlassian.net/wiki/spaces/FES/pages/34045954/Local+Web+Server for the bounty :D

> todo: where does detecting mouse catch events go in here? CV? platform? maybe a new module/class that uses both of those two? idk

## Personalities 

Personalities use an abstract base class, and the personality for each toy is hard-coded in __main__.

## Developer Guide

The package is based on the following cookiecutter template: 

https://github.com/cjolowicz/cookiecutter-hypermodern-python
