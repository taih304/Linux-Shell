# Fundamental concepts

There are 2 clocks inside Linux, **hardware clock** and **system clock**. The **hardware clock**, also known as RTC, CMOS or BIOS clock, is the battery-backed clock that keeps time even when the system is shut down. The **system clock/tick** or **kernel clock** is maintained by the operating system. At boot time, the hardware clock is read and used to set the system clock. From that point onward, the system clock is used to track time.

System clock is used to implement C functions [gettimeofday() and time()](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/Time/README.md#systime).

RTCs can be read and written with ``hwclock`` command, or [directly with the ioctl() system call](https://github.com/TranPhucVinh/C/blob/master/Physical%20layer/Time/Examples.md#example-3).

# Commands

* ``date``: show current date in human readable format

``date "+%s"``: Show current date in Unix timestamps (in seconds)

Get Unix timestamps in miliseconds: ``echo $(($(date +%s%N)/1000000))``

* ``cal``: print a calendar

* ``timedatectl``: display the current time, both, the system clock and the hardware clock. This command belongs to the ``Systemd``.

## hwclock

``sudo hwclock -r``: Read current time (as display the RTC time)

## Environment variable

### $SECONDS

``SECONDS``: Return the total seconds that the current terminal has been running.

**Delay for a number of seconds using $SECONDS**

```sh
DELAY_FOR_SECONDS(){
   delay_time=$1 
   previous_time=$SECONDS
   current_time=0 
    while [ $current_time -lt $delay_time ]
    do
        current_time=$((SECONDS-previous_time))
    done 
}

while [ true ]
do
    echo "Hello, World !"
    DELAY_FOR_SECONDS 2
done    
```

# Examples

## Using sleep

Print out ``Hello, World!`` after every 1 second with ``sleep``

```sh
while [ true ]
do
	echo "Hello, World!"
	sleep 1
done
```
