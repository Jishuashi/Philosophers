*This project has been created as part of the 42 curriculum by hchartie.*
# Philosophers
## Description
A C implementation of the classic **Dining Philosophers Problem**, demonstrating multi-threading, synchronization, and deadlock prevention using POSIX threads and mutexes.

The Dining Philosophers Problem is a classic synchronization problem that illustrates challenges in concurrent computing. In this project, a number of philosophers sit around a table with a bowl of spaghetti. Between each pair of philosophers lies a single fork. Each philosopher must alternately think and eat, but can only eat when they have access to both the fork on their left and the fork on their right.

## Instructions
```bash
make
```

### Run
```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

**Parameters:**
- `number_of_philosophers`: Number of philosophers (1-200)
- `time_to_die`: Time in milliseconds before a philosopher dies
- `time_to_eat`: Time in milliseconds to eat
- `time_to_sleep`: Time in milliseconds to sleep
- `number_of_times_each_philosopher_must_eat` (optional): Stop when all philosophers have eaten this many times

### Example
```bash
./philo 5 800 200 200
```

## Resources
- [POSIX Threads Documentation](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/pthread.h.html)
- [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [42 School Curriculum](https://www.42.fr)