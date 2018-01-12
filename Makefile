CC=gcc


main:
	${CC} calendar/*.c -o calendar/calendar
clean:
	rm calendar/calendar
