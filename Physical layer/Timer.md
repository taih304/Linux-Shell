### Commands

* ``date``: show current date
* ``cal``: print a calendar

### Environment variable

* ``SECONDS``: Return the total seconds that the current terminal has been running.

## Examples

**Example 1**: Using ``sleep``

Print out ``Hello, World!`` after every 1 second with ``sleep``

```sh
while [ true ]
do
	echo "Hello, World!"
	sleep 1
done
```
**Example 2**: Delay for a number of seconds using ``$SECONDS``

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