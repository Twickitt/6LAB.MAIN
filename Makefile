GC=gcc
Sources = main.o Add_Student.o Delete_Student.o Display_student.o Edit_Student.o Find_Student.o

all: base

base: $(Sources)
	$(GC) $(Sources) -o base

main.o: main.c
	$(GC) -c main.c

Add_Student.o: Add_Student.c
	$(GC) -c Add_Student.c

Delete_Student.o: Delete_Student.c
	$(GC) -c Delete_Student.c

Display_student.o: Display_student.c
	$(GC) -c Display_student.c

Edit_Student.o: Edit_Student.c 
	$(GC) -c Edit_Student.c

Find_Student.o: Find_Student.c
	$(GC) -c Find_Student.c

clean:
	rm -rf *.o base
