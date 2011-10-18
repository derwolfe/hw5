#
# The executable is built when only "make" is typed. The two test
# targets will rebuild the executable as needed. 
#
KUID = 2054583 
LAB_NAME = stacks_and_queues

all: office_sim

office_sim: main.o Office.o Stack.o Queue.o Linked_List.o Document.o
	g++ -g main.o Office.o Stack.o Queue.o Linked_List.o Document.o -o office_sim

Document.o: Document.h Document.cpp
	g++ -g -c Document.cpp

Stack.o: Stack.cpp Stack.h Document.h Linked_List.h
	g++ -g -c Stack.cpp

Queue.o: Queue.cpp Queue.h Document.h Linked_List.h
	g++ -g -c Queue.cpp

Office.o: Office.h Office.cpp Document.h
	g++ -g -c Office.cpp

Linked_List.o: Linked_List.h Linked_List.cpp Document.h
	g++ -g -c Linked_List.cpp

main.o: main.cpp Office.h
	g++ -g -c main.cpp

#
# This test target should be left unchanged. It is provided as a
# reference to the student and as a way for the grader to verify that
# expected output is produced. The "diff" command compares the output
# to the output produced by the example solution. With some care to
# detail, students should be able to create a solution producing
# identical output, and thus no output from the "diff" command.
#
test1: office_sim
	@echo "  "
	@echo "Do not be confused by an \"error\" output from make"
	@echo "when the diff command finds a difference between the files."
	@echo "This is a programming convention. Make will not complain "
	@echo "of an error when there is no difference. "
	@echo "  "
	./office_sim infile.txt  > output1
	-diff output1 output1.correct

#
# This test target is provided for student convenience. Students can,
# of course, create other tests as they see fit during development.
#
test2: office_sim
	./office_sim infile2.txt > output2

tar-file: clean
	@if test -d ../$(KUID)_$(LAB_NAME) ; then \
		( cd .. ; \
		  tar cz $(KUID)_$(LAB_NAME) >$(KUID)_$(LAB_NAME).tar.gz ; \
	  	  echo ""; \
		  echo "**************************************************************"; \
		  echo "The TAR file for you to test and hand in "; \
		  echo "   has been made in the directory above:"; \
		  echo "     " $(KUID)_$(LAB_NAME).tar.gz ; \
		  echo "**************************************************************"; \
		) ; \
	else \
		( echo "*** ERROR ** ERROR ** ERROR ** ERROR ** ERROR ** ERROR ***"; \
		  echo "The <your KUID>_<lab-name> directory was not found. "; \
		  echo "Remember that you should rename the "; \
		  echo "\"starter-code\" directory created by the "; \
		  echo "starter TAR file and set the KUID " ; \
		  echo "variable in the Makefile"; \
		) ; \
	fi

clean:
	rm -f *.o office_sim output1 output2

