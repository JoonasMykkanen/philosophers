# Philosophers🍝🧙🏼‍♂️ - Multithreading and Mutexes

## Description

In this project, we learn about the fundamentals of threading a process. The aim is to understand how to create threads and how to prevent data races with mutexes. The project represents a scenario where philosophers sit at a round table with a large bowl of spaghetti, they alternatively eat, think, or sleep. To eat, a philosopher needs to have forks in both hands. There are only as many forks as there are philosophers, this means that not all of them can eat at the same time. The simulation stops when a philosopher dies of starvation. 

## How to Run

1. Clone the repository to your local machine.
2. Makefile is in ./philo directory
3. Compile the program by typing `make` in your terminal.
4. run with `./philo args`


## Program Inputs

The program requires the following arguments:

- `number_of_philosophers`: The number of philosophers and also the number of forks.
- `time_to_die (in milliseconds)`: If a philosopher didn't start eating `time_to_die` milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
- `time_to_eat (in milliseconds)`: The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
- `time_to_sleep (in milliseconds)`: The time a philosopher will spend sleeping.
- `number_of_times_each_philosopher_must_eat (optional argument)`: If all philosophers have eaten at least `number_of_times_each_philosopher_must_eat` times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

## Example Input and Expected Output

For instance, to run the program with 5 philosophers, where `time_to_die` is 8000 milliseconds, `time_to_eat` is 200 milliseconds, `time_to_sleep` is 200 milliseconds, and each philosopher must eat 10 times:

The timestamp is given in milliseconds and X represents the philosopher number.
```sh
./philo 5 8000 200 200 10
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```
