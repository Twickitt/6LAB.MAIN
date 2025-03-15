TARGET = ./StudentBase.app
HDRS_DIR = \
		Add_Student \
		Delete_Student \
		Display_Student \  
		Edit_student \ 
		Find_Student \
		Structure 
SRCS = \
		Add_Student.c \
		Delete_Student.c \
		Display_Student.c \  
		Edit_student.c \ 
		Find_Student.c  

.PHONY: all, build, clean, run
$(TARGET):
		gcc -I $(HDRS_DIR) $(SRCS) -o $(TARGET)

all: clear build 

build: $(TARGET)

clean:
		rm -rf $(TARGET)
run:
		$(TARGET)

