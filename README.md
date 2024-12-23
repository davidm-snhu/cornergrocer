# cornergrocer

This code is for Project 3 in SNHU's CS210. Its purpose is to read a text file that has the name of a fruit on each line, count how many times each fruit appears, and show that information in a few different ways.

Something I did well here was formatting the outputs and error messages. The histogram in particular it a lot harder to read if you don't put in the effort to align its first character.

The code could be enhanced most by making it more reusable, in my opinion. Rewriting code to go through menus is tedious and error prone; it would be a good idea to make some generic menu code that takes a series of menu titles and functions to run when that entry is chosen, and handles printing and moving around beween menu choices automatically. Same for StringCounter, it would be convenient to have a more general Counter.

The most challenging part of this project was not in the code, but in working with Visual Studio and the online lab environment, especially when it comes to making sure all the files come over. The big thing I learned was to put source and header files in the same folder as the solution; adding them from somewhere else establishes a link instead of copying them to be bundled when you export later. I plan to add some practice in Visual Studio on my own time in the future.

The primary transferable learning I took away from this project was working with a fully-fledged IDE. I'm accustomed to relatively plain text editors and command-line compiling. Professional work will have more complicated projects and build processes, so I'm glad I got some practice with a more sophisticated tool.

To make this program maintainable, readable, and adaptable, I divided the code into separate classes along reasonable logical boundaries, added inline comments where the intent did not seem clear, and chose carefully which class members and helper functions could be public, and which ones should be private.
