Philosophers: The Deadly Game of Threads and Mutexes

Description

In this project, the core concept is threading a process, demonstrated through a game of philosophers seated around a table, eating and thinking alternately. The program simulates this scenario where the philosophers' states change between eating, thinking, or sleeping, and their state changes are documented as log outputs. The rules of the game dictate that philosophers must eat with two forks, one on each side, but since the number of forks is equal to the number of philosophers, mutexes are implemented to avoid fork duplication. The simulation stops when a philosopher dies of starvation, making this a deadly game indeed.

How to Run It

The program is written in C and can be compiled using a Makefile.

./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]
Please note that the Makefile should contain the rules $(NAME), all, clean, fclean, and re.

Program Input

The program takes the following arguments:

number_of_philosophers: The number of philosophers and also the number of forks.
time_to_die: (in milliseconds) If a philosopher didn't start eating within this time since the beginning of their last meal or the beginning of the simulation, they die.
time_to_eat: (in milliseconds) The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
time_to_sleep: (in milliseconds) The time a philosopher will spend sleeping.
number_of_times_each_philosopher_must_eat (optional): If all philosophers have eaten at least this number of times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
Here's an example command to run the program:

./philo 5 800 200 200 7

This means there are 5 philosophers, each will die if they don't start eating within 800 milliseconds, it takes them 200 milliseconds to eat using two forks, and they will sleep for 200 milliseconds. The simulation will stop once all philosophers have eaten 7 times, or if a philosopher dies.

Please note that the program is designed to be race-condition free, ensuring that no two philosophers can use the same fork at the same time, and no philosopher will starve to death under the provided conditions.