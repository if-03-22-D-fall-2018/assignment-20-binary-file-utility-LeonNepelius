init:
	g++ -c -Wall -g init.cpp
	g++ init.o -o init
	./init

list_all_students:
	g++ -c -Wall -g list_all_students.cpp
	g++ list_all_students.o -o list_all_students
	./list_all_students

new_student:
	g++ -c -Wall -g new_student.cpp
	g++ new_student.o -o new_student
	./new_student

ifeq (display_student, $(firstword $(MAKECMDGOALS)))
  runargs := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
  $(eval $(runargs):;@true)
endif

display_student:
	g++ -c -Wall -g display_student.cpp
	g++ display_student.o -o display_student
	./display_student $(runargs)

clean:
	rm -rf *o init list_all_students new_student display_student