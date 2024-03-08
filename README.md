# TournementArc
## Description
Tournament Arc is a random Tournamnet Generator, the idea is that a list of random teams are made and they essensially roll dice in a one v one fassion until only one remains
It allows the user to specify the number of teams, then select favourite teams from the list provided to higlight them and watch there progress
Finally it appends the winner to a txt file, so you have history of all the teams that won.

## Enviroment
I used C++ and was more so experimenting and seeing how the language worked.
I spent about 4 hours learning the basics of C++, and four days of work each day culminating in about 4 hours of work for total time of just under 20 hours.
I used a fair ammount of libraries
-	<iostream>: This library is used for input/output operations. Since my program just prints to the console this was pretty important
-	<cstdlib>: This library contains general purpose functions, including functions for memory management, process control, environment, conversions and others. In this code. I used it for the random name/number generators
-	<ctime>: This library is used to handle time in your programs. I used this for having the date on the txt file .
-	<string>: This library provides the std::string class that is used to create and manipulate strings.
-	<thread>: This library is used to create, manage and synchronize threads. I used this to delaying the output to the console.
-	<chrono>: This library is used to deal with time. It provides useful time duration types and clocks. In this code, it's used in conjunction with <thread> to pause the program.
-	<map>: This library provides the std::map container that stores elements formed by a combination of a key value and a mapped value, following a specific order. In this code, it's used to store favorite teams and their corresponding color codes.

## Websites
-[W3 School]https://www.w3schools.com/cpp/
-[Someguys youtube tutorial]https://www.youtube.com/watch?v=ZzaPdXTrSb8&t=1327s
-Various Stack Flow google results.

## Future Work
- A franchise mode there the same teams compete over and over again with mild tweaks to power level
- A displayable hall of winners
- diferent types of tournemnets, i.e. double elim, swiss, round robin.
